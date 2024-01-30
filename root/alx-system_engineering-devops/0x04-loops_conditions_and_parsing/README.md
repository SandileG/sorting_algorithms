# Loops, Conditions, and Parsing (Intro to shell scripting and system admiin)

# How to create SSH keys:

SSH (Secure Shell) keys are cryptographic keys used to secure communication between two parties, typically a client and a server. To create SSH keys, you can use the ssh-keygen command. Here's a simple guide:

Open a terminal on your local machine.
Use the following command: ssh-keygen -t rsa -b 2048
Follow the prompts to specify the file location and passphrase (optional).
This generates a pair of public and private keys. The public key is shared with the server, and the private key is kept secure on your local machine.

# Advantage of using #!/usr/bin/env bash over #!/bin/bash:

The #!/usr/bin/env bash shebang is preferred over #!/bin/bash because it allows for better portability. Using env ensures that the system's PATH environment variable is used to locate the Bash interpreter. This can be useful when the Bash interpreter is not located in the same path on every system, providing a more flexible and portable script.

# How to use while, until, and for loops:

* while loop: Executes a set of commands as long as a given condition is true.

while [ condition ]; do
    # commands
done

* until loop: Executes a set of commands as long as a given condition is false.
until [ condition ]; do
    # commands
done

* for loop: Iterates over a sequence (like a range of numbers or elements in an array).

for variable in [list]; do
    # commands
done

# How to use if, else, elif, and case condition statements:

* if statement: Executes a block of code if a specified condition is true.

if [ condition ]; then
    # commands
fi

* else statement: Executes a block of code if the condition in the preceding if statement is false.

if [ condition ]; then
    # commands
else
    # commands
fi

* elif statement: Adds more conditions to be checked in sequence.

if [ condition1 ]; then
    # commands
elif [ condition2 ]; then
    # commands
else
    # commands
fi

* case statement: Provides a way to perform different actions based on the value of a variable.

case $variable in
    pattern1)
        # commands
        ;;
    pattern2)
        # commands
        ;;
    *)
        # default commands
        ;;
esac

# How to use the cut command:
The cut command is used to extract specific parts of a file or input stream.

cut -d',' -f1,3 file.csv

This command cuts fields 1 and 3 from a CSV file where ',' is the delimiter.

# Files and other comparison operators, and how to use them:

* File operators:
-e file: Checks if the file exists.
-f file: Checks if the file is a regular file.
-d file: Checks if the file is a directory.

* Comparison operators:
==: Equal to
!=: Not equal to
-eq: Equal to (numeric comparison)
-ne: Not equal to (numeric comparison)
-lt: Less than (numeric comparison)
-le: Less than or equal to (numeric comparison)
-gt: Greater than (numeric comparison)
-ge: Greater than or equal to (numeric comparison)

Example:

if [ -e file.txt ]; then
    # file.txt exists
fi

if [ "$a" -eq "$b" ]; then
    # a is equal to b
fi
