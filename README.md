## Our Simple Shell

![N|Solid](https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg)

This is our project making a simple shell similiar to the _SH_
Shell is simply a macro processor that executes commands. The term macro processor means functionality where text and symbols are expanded to create larger expressions.
The shell is a program that takes commands from the keyboard and gives them to the operating system to perform On most Linux systems a program called bash 

## Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to 

## Compilation 

Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c`

## Downloading

You can download this repository like this:

`git clone https://github.com/Fedejalife99/holbertonschool-simple_shell`

## Testing

Shells can be used in interactively or non-interactively modes. In interactive mode, they accept input typed from the keyboard and when is executing non-interactively, shells execute commands read from a file.

Our shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

Our shell should work like this in non interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## Authors

Santiago Vidarte
Federico Jalife
