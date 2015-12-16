For using the Loopedia modules in Drupal, you need to copy the following
scripts into
/sites/default/scripts/
of the Drupal installation:
- edgelist_to_nickel.py
- minimalnickel.py
- mygslib.py
- neato_from_nickel.py
which you can find in this repo under
"graphstate/".

There is also the script "drushsqlbackup.bash" that uses drush to make a
sql dump (backup) of the drupal database. This script should be copied
to the root folder of the drupal site installation.
