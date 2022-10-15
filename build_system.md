# Build systems #

## Parts of an ESPIDF project ##

A “project” is a directory that contains all the files and configuration to build a single “app” (executable), as well as additional supporting elements such as a partition table, data/filesystem partitions, and a bootloader.

“Project configuration” is held in a single file called *sdkconfig* in the root directory of the project. This configuration file is modified via *idf.py menuconfig* to customise the configuration of the project. A single project contains exactly one project configuration.

### Detailed components of a project directory ###

* *cmakelist.txt* - set of directions regarding the configuration of the project
* *sddkconfig* - root directory of the project with default values for configuration which can be changed using `idf.py menuconfig`
* *components* - ontains components that are part of the project.ontains components that are part of the project.they themselves contain their own *kconfig* files ,*cmake lists*,and the code for the component.
* *main* - main is a special component file which contains the main scource code for the project, the name of this directory can be changed.

**Project Configuration** - project configuration refers to various aspects needed to configure an esp32, required to run an executable.EG -

* target for the code.
* wifi settings 
* Bluetooth settings

An **app** is an executable which is built by ESP-IDF.

* It has two parts the main executable - *project app*
* The second part is used to start up the project app - *Bootloader app*

#### idf.py ####

`idf.py` is a tool to manage and configure and manage the project.It manages the following tools-

* **cmake** helps configure the project
* **Ninja** builds the project
* **esptool.py** A Python-based, open-source, platform-independent utility to communicate with the ROM bootloader in Espressif chips.

When idf.py does something, it prints each command that it runs for easy reference. For example, the idf.py build command is the same as running these commands in a bash shell.For eg `idf.py`is a command for the command line which helps in compilation of the project file.what ii actually does is that it creates a build folder executes `cmake`command to configure the project, and runns the `ninja` command to build the project.

##### cmake #####

`cmake`is command to configure the project.

**Using cmake in IDE(Integrated development environment)**we can use the cmake with ide(Integrated development environment) ie a software application that provides comprehensive facilities to computer programmers for software development;The IDE will want to know the path to the project’s CMakeLists.txt file(CMakeLists. txt file contains a set of directives and instructions describing the project's source files and targets (executable, library, or both)).

** For further reference refer the [link](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) 



