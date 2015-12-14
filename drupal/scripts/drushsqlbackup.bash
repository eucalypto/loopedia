#! /bin/bash
# drushsqlbackup.bash

# If you want an automatic git commit after sql export, you have to
# give "git" as parameter to this script:
# ./drushsqlbackup.bash git

drush cc all
drush sql-dump --ordered-dump > sql_backup/loopedia_drupal_test.sql


if [[ "$1" == "git" ]]; then
  git commit -am"Database Update"
fi
  

