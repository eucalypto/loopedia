me=papara@mpp.mpg.de
# baseurl=https://wwwth.mpp.mpg.de/test
# dataurl=$baseurl/internal
datadir=/home/pcl305/members/papara/lootest

umask 027
PATH=/usr/local/bin:$PATH
shopt -s nullglob
shopt -s nocasematch

export LC_CTYPE=en_US.ISO8859-1

httpheaders() {
  cat << _EOF_
Content-type: text/html; charset=ISO-8859-1
Cache-Control: "no-cache, no-store, must-revalidate"
Expires: "$(date --date='3 seconds ago')"

<link rel="stylesheet" type="text/css"
 href="https://wwwth.mpp.mpg.de/css/main.css">

<html>
<head><title>$1</title></head>
<body bgcolor="#ffffff">
_EOF_
}

