<img src="https://raw.githubusercontent.com/MelissaN/simple_shell/master/shell.gif">
## Simple Shell
> In this project, we coded from scratch a simple Unix shell. A shell is an interactive
> command-line interpreter. We created a shell that would utilize the command line
> interface (CLI). It allows users to type in a defined set of
> commands (e.g. "rm" to remove files, "cat" to combine word documents, etc) and have the
> operating system run the appropriate function. It is slightly different from a graphical user
> interface (GUI). For instance, instead of using a mouse to click to open folders and delete files, a user
> can type in a command (i.e. "ls" or "rm") and have the files be displayed or
> modified in a list on the command line. GUI and CLI both have the same purpose to interact
> with the operating system but their input methods are different and some developers
> prefer the CLI to interact with the shell because their typing is quicker than
> clicking and dragging. There are a few
> versions of Unix shells, from the very first (Ken Thompson's) shell that can
> be activated by typing ```sh``` in the terminal to today's most popular Bash
> (Bourne Again Shell). Later versions of the shell handle memory leaks better and
> have more functionality. Our shell is a simple version that handles memory leaks
> very well and has basic functionality. You can create/write/read/open/remove
> folders, print things to the terminal, change directories, print where you are
> in the system, etc. [To read more on how a shell works behind the scenes, visit our
 blog here](https://medium.com/@MelissaNg__/how-a-shell-works-8a5a461c1910).


### Synopsis
> This repository holds all the code necessary for our custom simple shell to run.
> Our shell currently handles the executions of executables found in the
> environmental variable PATH, with or without their full paths. Sample commands
> that our shell supports include ```ls``` (```/bin/ls```), ```pwd```, ```echo```,
> ```which```, ```whereis```, etc. We've also created the following builtins.

### Builtins
* ```exit``` exits shell (```Usage: exit [status]```)
* ```env``` prints environmental variables (Usage: ```env```)
* ```setenv``` creates or modifies an environmental variable (Usage: ```setenv name value```)
* ```unsetenv``` removes an envrionmental variable (Usage: ```unsetenv name value```)
* ```cd``` changes directories (Usage: ```cd [-][~][path]```)

### Functions and system calls used
```read```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```chdir```, ```access```, ```execve```, ```wait```, ```write```,  ```exit```

### Description of what each file shows:
```
man_3_shell ------------------------ custom manpage for our simple shell
main.c ----------------------------- holds entrance into program
shell.h ---------------------------- holds prototypes of functions spread across all files
```
Helper files
```
prompt.c --------------------------- handles outline of shell's reprompting and executing
non_interactive.c ------------------ handles output when shell is called outside of shell
_realloc.c ------------------------- helper function handles reallocation
_strcat.c -------------------------- concatenates two strings
_strcmp.c -------------------------- compares if two strings match
_strcpy.c -------------------------- copies a string
_strdup.c -------------------------- duplicates a string
_str_tok.c -------------------------- (custom) tokenizes user's command input and returns array
c_str_tok.c ------------------------- tokenizes PATH to include ":" as Null, checks current dir
get_line.c ------------------------- (custom) reads user's typed input into buffer
_which.c --------------------------- appends command to PATHs, fleshes paths out, returns match
_cd.c ------------------------------ changes directories
linked_lists.c --------------------- adds and deletes nodes; prints and frees linked list
get_env.c -------------------------- finds and returns copy of environmental variable
env_linked_list.c ------------------ prints and creates linked list of envrionmental variables
set_unset_env.c -------------------- finds environment variable index node, sets and unsets
free_double_ptr -------------------- frees double pointers (user's command, arrays)
_execve.c -------------------------- executes and frees command, then exits program
__exit.c --------------------------- handles if user types exit or exit(value)
int_to_string.c -------------------- converts int to string to write error messages
print_error.c ---------------------- prints special error messages for certain fails
```
### Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/MelissaN/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell
```
**Non-Interactive Mode**
```
echo "ls -l" | ./simple_shell
```
**Interactive Mode***
Activate the shell
```
(your_terminal)$ ./simple_shell
$
```
Sample Usage
```
$ ls -al
total 4
-rw-rw-r-- 1 vagrant vagrant   234 Mar 28 19:32 file1.c
-rw-rw-r-- 1 vagrant vagrant    69 Mar 28 19:32 file2.c
$ echo "This is a pretty cool!"
This is pretty cool!
$ man ./man_1_simple_shell (opens our manpage for more information)
```
Stop and return to your original shell
```
$ exit
(your_terminal)$
```


### To Do
* More functionality can still be added (e.g. handle aliases, pipelines, and redirections)

---
### Authors
Kevin Yook [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/yook00627)
Melissa Ng [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/MelissaNg__)
