This is a simple shell project implemented in C. It supports basic shell commands, such as ls, cd, pwd, echo, and exit. The shell can also be used to pipe commands together and to execute commands in the background.


#Build Instructions

To build the shell, run the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


#Usage

To run the shell, simply type ./hsh. The shell will then prompt you for a command. Enter a command and press enter to execute it.


#Commands

The following commands are supported by the shell:

ls: List the contents of the current directory.
cd: Change the current directory.
pwd: Print the working directory.
echo: Print the arguments to the command to the console.
exit: Exit the shell.


#Piping Commands

To pipe commands together, use the | character. For example, to pipe the output of the ls command to the input of the grep command, you would type the following:

```bash
ls | grep "my_file.txt"

This would print the names of all files in the current directory that contain the string "my_file.txt".


##Examples

The following are some examples of how to use the shell:

```bash
## List the contents of the current directory
ls
```bash
## Change the current directory to /home/user
cd /home/user
```bash
## Print the working directory
pwd
```bash
## Print the string "Hello, world!" to the console
echo "Hello, world!"
```bash
## Exit the shell
exit


##info

The shell is still under development, and there are some known issues. For example, the shell does not support all shell commands, and it does not handle errors .
