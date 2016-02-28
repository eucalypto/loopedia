README

This is the main README file for the inner workings of loopedia. It is
written in the Github flavored version of Markdown.

1. What is Drupal

Drupal is a conntent management system (CMS) written in PHP. It is used
to manage and display content on the web. It uses a database (e.g.
MySQL) internally to store data (content) and preferences. This is why
it is used for Loopedia.

1.1 Modules

Drupal is modular, i.e. it uses plugins to extend the functionality of
an installation. These plugins are called modules and can be part of the
official Drupal project (Drupal core), be provided by the community
(contrib), or be written by yourself (custom).

1.1.1 How to write a custom module

The usual way to write a custom module is as follows. You make a new
folder in /sites/all/modules/custom/ and name it exactly as your module
name. Then you make three text files: "modulename.module",
"modulename.install" and "modulename.info". The info file contains basic
information about your module that drupal uses to display in its module
list. The main code is in your .module file but some code must be in the
.install file, where the installation steps of your module are defined.

Drupal uses special functions called "hooks". They are executed on
certain steps. In the Drupal documentation they are named
"hook_hook-name()". If you name one of your functions in the following
manner, it will be an implementation of this hook and will be executed
at the same time. To name it correctly, you have to replace "hook" with
"modulename" in the function definition: "modulename_hook-name()".

This is the usual way, there are tons of hooks. You just have to find
the right one and write an implementation of it. This way, you can alter
the behavior of Drupal or add new functionality.

1.2 How Drupal works

1.2.1 Separation of data and look

One important aspect of Drupal (or any CMS) is that it separates data
and the display (html) in the way that the website (html) is generated
on the fly, i.e. it is only generated if some browser requests a site.

This allows you to work on the data structures at one time and then
independently take care of the display. For this, there are "themes"
that you can install and customize. They define the look of your
website.

1.2.2 Code vs UI

You can work with Drupal and never see a line of code. A lot of
functionality is already there with contributed modules that can be
configured and used through the User Interface of the website. You just
have to log in as an administrator and you will see this administrative
UI. All these preferences are stored in the database.

A programmer, however, might want to manage functionality through code.
Especially when you need something that does not exist as a module. A
nice advantage of a custom module is that you can port it to any other
Drupal installation without having to re-create all steps through the
UI. Also, you can version control your code, which is a very huge plus.

1.2.3 Naming conventions

You should chose a module name that is not used so far. Googling it is a
good strategy. The names of your function should always begin with
"modulename_" to prevent collisions.

1.2.4 The Drupal Way

Many modules define special functions that you can call form your
functions. These are part of the application programming interface (API)
of this module and are very useful because they handle a lot of the
administrative stuff for you. An example for this is the connection to
the database. You can write a custom database query using SQL. But for
most of the things you want to do, there is already a function that
handles the database for you.

Not using the API will make your life very difficult.

1.2.4. Working with the Drupal API

Since the display is separated from the data, Drupal tries to generate
the html code as last as possible. Until then, the data is stored mostly
in PHP arrays and objects (classes). So most of the work with Drupal
consists of working with these ararys and objects.


2. Installation

2.1 Backup MySQL Database

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


2.2 Move Loopedia / Installation

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

10. Search

In order to provide search capabilities, we use the module "Serach API".
And the search index is managed by a separate "server" called Solr.

10.1.1 Exporting and Importing Views

In order to export a view you have to go to Home > Administration >
Structure > Views. In the "List"-tab you see a list of views. This list
has a column called "Operations". Here, you select "Export" from some
options and end up on a site with a window where the "exported" text is
displayed. This text was copied into
"loopedia/drupal/views_export/search_page"

To import the view you go again to Home > Administration > Structure >
Views. At the top you should see an "+ Import" link. There you can copy
and paste the definition from a file.


### Update Drupal with drush
To update drupal and all packages, use
```bash
$ drush up
```
which is an abbreviation of "drush pm-update"

### The following modules are useful:

* Chaos tools suite
* Devel
* example modules
* features
* Flags ?
* Diff
* Taxonomy manager?
* Views ui
