README

This is the main README file for the inner workings of loopedia.

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


2. Migrate Loopedia

2.1 Backup MySQL Database

To make a backup of the database you can use drush:
  ~$ drush cc all
  ~$ drush sql-dump --ordered-dump > ~/my-sql-dump-file-name.sql
The first line clears the caches of drupal and the second one dumps the
database into the given sql-file.

I've written a script (drushsqlbackup.bash) that executes those two
commands and writes the sql dump to
`sql_backup/loopedia_drupal_test.sql`


2.2 Move Loopedia / Installation

My test server environment is an ubuntu pc. You have to have the
following programs/packages installed:
  ~$ sudo apt-get install apache2 apache2-utils php5 php5-mysql php-pear php5-gd  php5-mcrypt php5-curl mysql-server libapache2-mod-auth-mysql php5-mysql

For the Nickel manipulation capability you have to install the python
library "GraphState". The easiest way is to use pip:
  ~$ sudo apt-get install python-pip graphviz
  ~$ sudo python -m pip install graphstate


Graphviz is needed to have the programm "neato", which generates graphs
as (vector) pictures.

This website
(http://linoxide.com/ubuntu-how-to/install-drupal-7-x-apache-2-x-ubuntu/)
shows how the installation can work.


2.3 Migrate Files

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

2.4 Configure MySQL

To migrate the database, you can export it with drush (see corresponding
chapter). Then, on the new system you have to set up MySQL:
  ~$ mysql -u root -p
  mysql> CREATE USER 'wernerheisenberg'@'localhost' IDENTIFIED BY 'iwouldnevertortureacat';
  mysql> CREATE DATABASE loopedia_drupal_test;
  mysql> GRANT ALL PRIVILEGES ON loopedia_drupal_test.* TO 'wernerheisenberg'@'localhost';
  mysql> FLUSH PRIVILEGES;
  mysql> exit;


2.5 Configure Apache2

In order to have nice urls, the drupal option "clean URLs" can be
enabled and needs the apache2 module mod_rename according to
[Step 1 - Method B: apache2.conf](https://www.drupal.org/node/134439):
  $ sudo a2enmod rewrite


Then add the following lines to `/etc/apache2/apache2.conf`:
  <Directory /var/www/your_drupal_site>
      AllowOverride All
  </Directory>


Then reload the apache2 server:
  $ sudo service apache2 reload
  $ sudo service apache2 restart


3. Install and Set up Loopedia

In order to run Drupal with Loopedia you need to do the following things:
- Set up a web server (apache2)
- Install drush
- Install helper programs and libraries
- Install Drupal
- Install Loopedia module

Let's have a closer look at those steps.

3.1 Set up a Web Server

3.2 Install Drush

This website (http://docs.drush.org/en/master/install/) shows you how
to install drush. And these steps are the easiest way:

- Download "installer" for composer from https://getcomposer.org/installer
  or https://github.com/composer/getcomposer.org/blob/master/web/installer
- Run this file with PHP in command line:
    ~$ php installer
  It will produce a binary (executable) file "composer.phar"
- Execute
    ~$ php composer.phar require drush/drush
  This will download drush with some other php modules in a subfolder
  structure. The drush executable is located in vendor/drush/drush/.

You can now use this executable directly or make it globally available.

3.3 Install Helper Programs and Libraries

3.3.1 Solr

You can find installation steps for Solr in a later chapter.

3.4 Install Drupal
- Download
- Web browser: installation script
- Secure file permissions

Enable the following Drupal Core modules:
- Database logging
- Statistics
- Syslog

Install contributed Drupal modules:
- Search API (search_api)
- Entity API (entity)
- Solr search (search_api_solr)
- Facet API (facetapi)
- Views (views)
- Chaos tools (ctools)


3.5 Install Loopedia Module

From this repository you have to copy some files to the Drupal
installation.

3.5.1 Scripts

Copy the scripts
- edgelist_to_nickel.py
- minimalnickel.py
- mygslib.py
- neato_from_nickel.py
from "loopedia/graphstate/" to "drupal/sites/default/scripts/".


3.5.2 Loopedia Module

Copy the folders "loopedia" and "nickelplay" from
"loopedia/drupal/modules/" to "drupal/sites/all/modules/custom/".

Then go to the administrator page of Drupal and navigate to the Modules
section and enable the modules "Loopedia" and "Nickelplay".


3.6 Configure Drupal

You have to do some steps in the Drupal admin interface.

Configure search: see "10. Search"

Set User Permissions in "Administration > People > Permissions". Check
the following permissions for "Authenticated User" under Node:
- View own unpublished content
- Integral: Create new content
- Integral: Edit own content 






#### Import MySQL dump

Now to import the sql file you have to use the following commands:
  ~$ drush sql-drop       # this deletes the current drupal
                          # database
  ~$ drush sql-cli < /path/to/my-sql-dump-file-name.sql

voila. Drush knows which database to use because this information is
stored in  `sites/default/settings.php`.


3. Security

3.1 File Permissions and Ownership

The web server must not have write (change) permissions to files it
executes. But it should have read permissions to all files in the drupal
folder.

Special case: settings.php

The file settings.php contains the database username and password for
drupal in plain text. So you should
- remove all permissions for "other" users


10. Search

In order to provide search capabilities, we use the module "Serach API".
And the search index is managed by a separate "server" called Solr.

10.2 Solr Search Engine

This guide (https://www.drupal.org/node/2502221) is good. This chapter
is just a summary of this guide.

10.2.1 Install Solr

- Download solr-5.5.0.tgz and unpack it somewhere. It does not have to
  be where Drupal is installed.
- Create new folder structure "solr_install/server/solr/drupal/conf" for
  the new Solr core. Here "drupal" is just a name.
- Install the Drupal module Search API Solr Search (search_api_solr)
- Copy config files from the folder structure of this module
  (.../search_api_solr/solr-conf/5.x/) to the "conf" folder of the Solr
  core you created earlier.
- Replace the file "mapping-ISOLatin1Accent.txt" with the same file from
  "solr_install/server/solr/configsets/sample_techproducts_configs/conf/"

Now you can run Solr by executing "solr_install/bin/solr start".

10.2.2 Configure Solr

When Solr is running, go to its admin screen:
(http://localhost:8983/solr/). Click on "Core Admin", then "Add Core"
and use the core name ("drupal" in our example) in the fields "name" and
"instanceDir" to create a new Solr core.

10.2.3 Configure Search API Solr Search Module

In the Drupal admin interface go to Configuration > (Search and
Metadata) > Search API and click on "Add server". Choose a name and
"Solr service" for Service class. The default configuration should be
enough. Only for Solr path you need to append the Solr core name to the
path: "/solr/drupal" (in our case).

Having set up a server in the Search API module, add an Index by going
again to the Search API Configuration page and clicking on "Add index".
As name choose "Integral Index" so that the machine name reads
"integral_index". For "Item type" choose Node and then check "Integral";
and as Server choose the one you configured. In the next step of the
Index creation choose the fields you want to be indexed.


10.1.1 Export and Import Views

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
  ~$ drush up
which is an abbreviation of "drush pm-update".




### The following internetsites could be useful:

http://www.sitepoint.com/building-multi-page-wizard-like-form-drupal/

http://webcheatsheet.com/sql/mysql_backup_restore.phphttp://webcheatsheet.com/sql/mysql_backup_restore.php

http://www.mmtek.com/dp20090929/node/14

http://www.sitepoint.com/creating-a-new-drupal-node-type/

http://drupal.stackexchange.com/questions/96622/how-to-use-t-function-for-a-text-with-anchor-links

http://linoxide.com/ubuntu-how-to/install-drupal-7-x-apache-2-x-ubuntu/

http://www.webomelette.com/taxonomy-vocabulary-term-programatically-drupal-7

### The following modules are useful:

* Chaos tools suite
* Devel
* example modules
* features
* Flags ?
* Diff
* Taxonomy manager?
* Views ui
