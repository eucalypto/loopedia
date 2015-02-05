#! /bin/bash

. `dirname $0`/config.sh
httpheaders "Application Submission"

cd "$datadir"

ids=`echo *`
dir=100
for id in $ids ; do
  : $((id >= dir ? dir = id + 1 : 0))
done

mkdir -p $dir/lock
cd $dir

( cat << _EOF_
Content-Type: $CONTENT_TYPE
Content-Transfer-Encoding: binary

_EOF_
  cat
) > raw

sed '
	/[; ]name=[^;]*.pdf/ s/filename=[^;]*//
	/filename=/! s/name=[^;]*/file&/
' raw | ripmime --no-nameless --formdata -i -
# in sed you can separate commands with a semicolon or a
# newline. Ripmime saves files with the filenames given in
# 'filename="..."'. But we want to save them with the
# 'name="..."'-entry as filename. The first sed command searches for
# lines with (name="*.pdf") and deletes the string
# (filename="something"). The second command searches for lines
# without "filename" and replaces "name" with "filename". Now the
# result of this replacments is piped into ripmime


# remove CR and delete empty files
for file in * ; do
  case "`file -bi \"$file\"`" in
  text/plain*)  dos2ux "$file" 2> /dev/null ;;
  application/x-directory*) continue ;;
  esac
  test "`stat -c%s "$file"`" -le 2 && rm -f "$file"
done

uploads=`sed -n '/^Content-Disposition.*filename="[^"]/{
  s/^.*[; ]name="\([^"]*\).*filename="\([^"]*\).*$/\1 (original name: \2)/
  p
}' raw`

gzip raw

########################## check for duplicates

dup=
email=$(<email)

for id in $ids ; do
  test -e ../$id/email || continue
  set -- `IFS='
 ,;'
    tmp=($(<../$id/email) $email)
    echo "${tmp[*]}" | sort | uniq -id`
  test $# -eq 0 && continue
  mkdir -p ../$id/tags/auto:dup:out
  mv -f ../$id/letters .
  dup=$id
done

rmdir lock

########################## html confirmation page

err=""
for file in email title name address ; do
  test -f $file || err="$err
$file missing"
done

recs=
for file in rec*.email ; do
  rec_email=`grep -o '\b[-+.%_A-Za-z0-9]*@[-._A-Za-z0-9]*\b' $file`
  rec_verify=`grep -o '\b[-+.%_A-Za-z0-9]*@[-._A-Za-z0-9]*\b' ${file/.email/.verify}`
  test "$rec_email" = "$rec_verify" || {
    err="$err
e-mail $rec_email does not match verification $rec_verify"
    continue
  }
  echo "$rec_email" > $file
  test -z "$rec_email" || {
    rec_name=$(<${file/.email/.name})
    recs="$recs
${rec_name:-$rec_email}${rec_name:+ <$rec_email>}"
  }
done
test -z "$recs" && err="$err
No valid recommender e-mail addresses given"

for file in *.pdf ; do
  case `file -bi $file` in
  application/pdf*) ;;
  *) err="$err
`echo "$uploads" | grep "^$file"` not PDF" ;;
  esac
done

test -n "$err" && {
  cat << _EOF_
<h1>Invalid or incomplete data</h1>
<pre>$err</pre>
</body>
</html>
_EOF_
  cd ..
  rm -fr $dir
  exit
}

cat << _EOF_
<meta http-equiv="refresh" content="5;url=http://wwwth.mpp.mpg.de">

<h1>Your application has been received.</h1>

<hr>

<p>A confirmation has been sent by e-mail.</p>

<hr>

<p>Thank you for your interest in the MPP Theory Group.</p>

</body>
</html>
_EOF_


########################## confirmation e-mail

show() {
  for file in "$@" ; do
    s="(not given)"
    test -f "$file" && s="$(<$file)"
    echo "$s"
  done
}

mail -r "MPP Theory Group <$me>" \
     -s "Your Application in the MPP Theory Group" \
     "$email" << _EOF_
Dear `show name`,

your application has been received.
Thank you for your interest in the MPP Theory Group.

The following items are on record:

Submission ID $dir

e-mail:
`show email`

Name:
`show title` `show name`

Address:
`show address`

Field of Research:
`show field*`

Recommendation Letters from:$recs

Uploaded files:
$uploads

${dup:+Note: This submission supersedes submission $dup.
}
If this information is incomplete or incorrect, please re-submit
your application or e-mail us at $me.


Kind Regards,

The MPP Theory Group

_EOF_

########################## referee requests

mkdir -p letters

for rec in rec*.email ; do
  rec_email=$(<$rec)
  test -f letters/$rec_email && continue

  rec_name=$(<${rec/.email/.name})
  token=`token`
  cat << _EOF_ > "letters/$rec_email"
$token
${rec_name:-$rec_email}
_EOF_

  mail -r "MPP Theory Group <$me>" \
       -s "Recommendation Letter for `show name`" \
       "$rec_email" << _EOF_
Dear ${rec_name:-$rec_email},

`show name` is applying for a postdoc position at 
the Max Planck Institute for Physics in Munich and is 
asking you to provide a letter of recommendation.

Please click on the following URL to upload your letter
(no registration required; pdf preferred, ps/doc/docx/txt ok):

$baseurl/cgi-bin/upload.cgi?token=$token

If the upload does not work for you, send your letter by
e-mail to $me.

Thank you very much for your cooperation.


Best Wishes,

The MPP Theory Group

_EOF_

  mail -r "MPP Theory Group <$email>" \
       -s "`show name`'s Postdoc Application at the MPP Munich" \
       "$rec_email" << _EOF_
Dear ${rec_name:-$rec_email},

`show name` is applying for a postdoc position at 
the Max Planck Institute for Physics in Munich and is
asking you to provide a letter of recommendation.

This precursor e-mail is just to ascertain that your
e-mail address is correct.  You will receive upload 
instructions in a separate e-mail.  You can safely
delete this message.


Dear `show name`,

if you receive a bounce of this e-mail this means you
mistyped ${rec_name:-$rec_email}'s e-mail address
$rec_email.

Please re-submit your application with the correct address.


Best Wishes,

The MPP Theory Group

_EOF_
done

