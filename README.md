<!DOCTYPE  htm>

<html>
<header>

<title>readme</title>

<body>

This is a simple shell project implemented in C. It supports basic shell commands, such as ls, cd, pwd, echo, and exit. The shell can also be used to pipe commands together and to execute commands in the background.


<h1>Build Instructions</h2>

To build the shell, run the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


<h1>Usage</h2>

To run the shell, simply type ./hsh. The shell will then prompt you for a command. Enter a command and press enter to execute it.


<h1>Commands</h1>

The following commands are supported by the shell:

ls: List the contents of the current directory.
cd: Change the current directory.
pwd: Print the working directory.
echo: Print the arguments to the command to the console.
exit: Exit the shell.


<h2>Piping Commands</h2>
To pipe commands together, use the | character. For example, to pipe the output of the ls command to the input of the grep command, you would type the following:

```bash
ls | grep "my_file.txt"
This would print the names of all files in the current directory that contain the string "my_file.txt".



<h2>Examples</h2>

The following are some examples of how to use the shell:

```bash
<h3> List the contents of the current directory</h3>
ls

```bash
<h3> Change the current directory to /home/user</h3>
cd /home/user

```bash
<h3> Print the working directory</h3>
pwd

```bash
<h3> Print the string "Hello, world!" to the console</h3>
echo "Hello, world!"

```bash
<h3> Exit the shell</h3>
exit


<h2>info</h2>

The shell is still under development, and there are some known issues. For example, the shell does not support all shell commands, and it does not handle errors .
</body>
