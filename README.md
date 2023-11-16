0x16. C - Simple Shell

What is Shell
A Shell is a UNIX term for the interactive user interface with an operating system. The shell is the layer of programming that understands and executes the commands a user enters. In some systems, the shell is called a command interpreter. A shell usually implies an interface with a command syntax (think of the DOS operating system and its "C:>" prompts and user commands such as "dir" and "edit").

As the outer layer of an operating system, a shell can be contrasted with the kernel, the operating system's inmost layer or core of services.

How does a shell work?
The C shell operates one line at a time. Each line is tokenized into a set of words separated by spaces or other characters with special meaning, including parentheses, piping and input/output redirection operators, semicolons, and ampersands.

Basic statements
A basic statement is one that simply runs a command. The first word is taken as name of the command to be run and may be either an internal command, e.g., echo, or an external command. The rest of the words are passed as arguments to the command.
