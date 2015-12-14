# README

This is the main README file for the inner workings of loopedia. It is
written in the Github flavored version of Markdown.

### Backup MySQL

To make a backup of the database you can use drush:
```
:~$ drush cc all
:~$ drush sql-dump --ordered-dump > ~/my-sql-dump-file-name.sql
```

The first line clears the caches of drupal and the second one dumps the
database into the given sql-file.

I've written a script (drushsqlbackup.bash) that executes those two
commands and writes the sql dump to
`sql_backup/loopedia_drupal_test.sql`


### Move Loopedia / Installation

My test server environment is an ubuntu pc. You have to have the
following programs/packages installed:

```
$ sudo apt-get install apache2 apache2-utils php5 php5-mysql php-pear php5-gd  php5-mcrypt php5-curl mysql-server libapache2-mod-auth-mysql php5-mysql
```

For the Nickel manipulation capability you have to install the python
library "GraphState". The easiest way is to use pip:

```
$ sudo apt-get install python-pip graphviz
$ sudo python -m pip install graphstate
```

Graphviz is needed to have the programm "neato", which generates graphs
as (vector) pictures.

This
[website](http://linoxide.com/ubuntu-how-to/install-drupal-7-x-apache-2-x-ubuntu/)
shows how the installation can work.

#### Migrate Files

You have to transfer the files (the drupal project folder) and the
database. The files are easily copied. Only remember hidden files like a
git folder.  
On ubuntu/apache the websites are stored as folders in
`/var/www/html/`. Then you have to configure the write permissions
(ownership) of some folders. Usually the "code" (php-scripts) have to be
read only to the web server (usually www-data). But some folders have to
be writeable to the web server - they are configured in the drupal admin
page: `Configuration -> File system`. So you have to execute `sudo chown
--recursive :www-data /paths/to/folders/` in order to  change at least
the group of the folders and subfolders to www-data.

#### Configure MySQL

To migrate the database, you can export it with drush (see corresponding
chapter). Then, on the new system you have to set up MySQL:

```bash
$ mysql -u root -p
mysql> CREATE USER 'wernerheisenberg'@'localhost' IDENTIFIED BY 'iwouldnevertortureacat';
mysql> CREATE DATABASE loopedia_drupal_test;
mysql> GRANT ALL PRIVILEGES ON loopedia_drupal_test.* TO 'wernerheisenberg'@'localhost';
mysql> FLUSH PRIVILEGES;
mysql> exit;
```

#### Configure Apache2

In order to have nice urls, the drupal option "clean URLs" can be
enabled and needs the apache2 module mod_rename according to
[Step 1 - Method B: apache2.conf](https://www.drupal.org/node/134439):

```
$ sudo a2enmod rewrite
```

Then add the following lines to `/etc/apache2/apache2.conf`:

```
<Directory /var/www/your_drupal_site>
    AllowOverride All
</Directory>
```

Then reload the apache2 server:

```
$ sudo service apache2 reload
$ sudo service apache2 restart
```

#### Install drush

This [website](http://docs.drush.org/en/master/install/) shows you how
to install drush. I did just the git clone method. In either case, you
need to [install
composer](https://getcomposer.org/doc/00-intro.md#globally). You just
download the  "installer" php file, run it with php, and copy the
resulting "composer.phar" file as `/usr/local/bin/composer`.

#### Import MySQL dump

Now to import the sql file you have to use the following commands:

```bash
:~$ drush sql-drop       # this deletes the current drupal
                         # database
:~$ drush sql-cli < /path/to/my-sql-dump-file-name.sql
```

voila. Drush nows which database to use because this information is
stored in  `sites/default/settings.php`.



### The following internetsites could be useful:

http://www.sitepoint.com/building-multi-page-wizard-like-form-drupal/

http://webcheatsheet.com/sql/mysql_backup_restore.phphttp://webcheatsheet.com/sql/mysql_backup_restore.php

http://www.mmtek.com/dp20090929/node/14

http://www.sitepoint.com/creating-a-new-drupal-node-type/

http://drupal.stackexchange.com/questions/96622/how-to-use-t-function-for-a-text-with-anchor-links

http://linoxide.com/ubuntu-how-to/install-drupal-7-x-apache-2-x-ubuntu/

http://www.webomelette.com/taxonomy-vocabulary-term-programatically-drupal-7



### Update Drupal with drush
To update drupal and all packages, use
```bash
$ drush up
```
which is an abbreviation of "drush pm-update"
