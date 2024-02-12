# Aria's C Argument Parser

## Overview
Aria's C Argument Parser is a lightweight, easy-to-use command line argument parser for C programs. It efficiently handles various command line arguments and organizes them into a convenient HashTable structure, making it simple to retrieve and manage command line inputs in C applications.

## Features
- Parses command line arguments prefixed with '-' or '--' as keys.
- Associates each key with its following value, unless the next argument is also a key.
- Treats arguments without a '-' prefix and not following a key as keys themselves, returning their own values.
- Easy retrieval of argument values using `getfromhash`.
- Memory management with `deletehash` for cleaning up the HashTable.

## Future Development
A function to return a helper message in case the program receives a `--help` key is planned. This will aid in providing users with guidance on how to use the command line arguments effectively.

## Usage

### Parsing Command Line Arguments
Include the parser header in your program:

```c
#include "argument_parser.h"
```

Use the `parse_args` function to parse command line arguments:

```c
HashTable* params = parse_args(argc, argv);
```

### Retrieving Argument Values
Retrieve the value for a specific key:

```c
char* value = getfromhash(params, "--key");
```

### Cleaning Up
Free the HashTable memory after use:

```c
deletehash(params);
```

## Example
Here's a simple example demonstrating how to use Aria's C Argument Parser:

```c
#include "aria_c_argument_parser/parser.h"

// Suppose the program was called like: ./main --key1 value1 value2
int main(int argc, char *argv[]) {
    HashTable* params = parse_args(argc, argv);

    char* value1 = getfromhash(params, "--key1"); // Returns value1
    char* value2 = getfromhash(params, "value2"); // Returns value2

    printf("Value for --key1: %s\n", value1);
    printf("Value for value2: %s\n", value2);

    deletehash(params);
    return 0;
}
```

In this example, `--key1` and `value2` are parsed from the command line arguments, and their values are retrieved and printed.
