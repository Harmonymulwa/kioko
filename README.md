# Simple_Shell

## Table of Content

- [About](#about)
- [Rules](#rules)
  - [General Rules](#general-rules)
  - [Output](#output)
  - [Allowed Functions and system calls](#allowed-functions-and-system-calls)
- [Checks](#checks)
- [Compilation](#compilation)
  - [Requirements](#requirements)
  - [How to compile](#how-to-compile)
- [Samples](#samples)
- [Authors](#authors)

## About

This project is an implementation of a simple shell for UNIX-like systems.

It was done in fulfilment of the
[ALX Software Engineering Programme](https://www.alxafrica.com/ "ALX SE")'s syllabus.

## Rules

### General Rules

- All files to be compiled on **Ubuntu 20.04 LTS** using `gcc`, using the
options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code should use [Betty](https://github.com/holbertonschool/Betty "Betty Style") style
- Your shell should not have any memory leaks
- No more than 5 functions per file
- Use system calls only when you need to
- All header files should be include-guarded
- All files should end with a new line
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository.

### Output

- Unless specified otherwise, your program must have the exact same output as `sh (/bin/sh)` as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]`

### Allowed Functions and System Calls

- access `(man 2 access)`
- chdir `(man 2 chdir)`
- close `(man 2 close)`
- closedir `(man 3 closedir)`
- execve `(man 2 execve)`
- exit `(man 3 exit)`
- exit `(man 2 _exit)`
- fflush `(man 3 fflush)`
- fork `(man 2 fork)`
- free `(man 3 free)`
- getcwd `(man 3 getcwd)`
- getline `(man 3 getline)`
- getpid `(man 2 getpid)`
- isatty `(man 3 isatty)`
- kill `(man 2 kill)`
- malloc `(man 3 malloc)`
- open `(man 2 open)`
- opendir `(man 3 opendir)`
- perror `(man 3 perror)`
- read `(man 2 read)`
- readdir `(man 3 readdir)`
- signal `(man 2 signal)`
- stat (__xstat) `(man 2 stat)`
- lstat (__lxstat) `(man 2 lstat)`
- fstat (__fxstat) `(man 2 fstat)`
- strtok `(man 3 strtok)`
- wait `(man 2 wait)`
- waitpid `(man 2 waitpid)`
- wait3 `(man 2 wait3)`
- wait4 `(man 2 wait4)`
- write `(man 2 write)`

## Checks

- :heavy_check_mark: Write a beautiful code that passes the Betty checks
- :heavy_check_mark: Handle command lines with arguments
- :heavy_check_mark: Handle the PATH
- :heavy_check_mark: Implement the exit built-in, that exits the shell
- :heavy_check_mark: Write your own getline function
- :heavy_check_mark: You are not allowed to use strtok
- :heavy_check_mark: Implement the builtin command cd
- :heavy_check_mark: Handle variables replacement
- :heavy_check_mark: Handle comments (#)
- :heavy_check_mark: Your shell can take a file as a command line argument

## Compilation

### Requirements

- Ubuntu 20.04 LTS
- GCC compiler

### How to compile

The source files to be compiled using
`-Wall -Werror -Wextra -pedantic -std=gnu89` flags.

The samples below illustrate the usage and compilation.

## Samples

```console
ian@github:~/shell$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
ian@github:~/shell$ ./simple_shell

$ env
USER=ian
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/ian
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=ian
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
$ ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
$ ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
$ ^C

ian@github:~/shell$
```

## Author(s)

[Ian Duncan](https://github.com/dr8co/ "Ian").
