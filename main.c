#if defined(_WIN32) || defined(_WIN64)
  #error "Windows is not supported by this software."
#else
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "../lib/argument_parser/argument_parser.h"

  #define HELP "This is the C Project Starter.\n"\
               "Developed by Aria Diniz. https://github.com/ariasdiniz\n"\
               "Use this tool to generate a new folder with a simple \n"\
               "structure for a new C project.\n\n"\
               "Params: --name: name of the project.\n"\
               "        -c:     version of the C language. Defaults to 99.\n\n"\
               "Example: cgen --name my_project -c 23\n"

  #define MAIN "int main(int argc, char *argv[]) {\n"\
               "  return 0;\n"\
               "}\n"

  #define CMAKE "cmake_minimum_required(VERSION 3.15)\n"\
                "\n"\
                "project(%s)\n"\
                "\n"\
                "set(CMAKE_C_STANDARD %s)\n"\
                "set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")\n"\
                "\n"\
                "file(GLOB_RECURSE SOURCE \"src/*.c\" \"src/*.h\")\n"\
                "file(GLOB_RECURSE LIB \"src/*.c\" \"src/*.h\")\n"\
                "file(GLOB_RECURSE INCLUDE \"src/*.c\" \"src/*.h\")\n"\
                "\n"\
                "add_executable(\n"\
                                "%s\n"\
                                "main.c\n"\
                                "${SOURCE}\n"\
                                "${LIB}\n"\
                                "${INCLUDE})\n"\
                "\n"\
                "include_directories(src)\n"\
                "include_directories(lib)\n"\
                "include_directories(include)\n"\
  
  #define GITIGNORE "# Ignore compiled binaries\n"\
                    "*.exe\n"\
                    "*.out\n"\
                    "*.o\n"\
                    "*.a\n"\
                    "*.so\n"\
                    "*.dll\n"\
                    "\n"\
                    "# Ignore generated files\n"\
                    "*.dSYM/\n"\
                    "*.swp\n"\
                    "*~\n"\
                    "\n"\
                    "# Ignore editor-specific files\n"\
                    ".vscode/\n"\
                    ".idea/\n"\
                    "*.sublime-project\n"\
                    "*.sublime-workspace\n"\
                    "\n"\
                    "# Ignore build directories\n"\
                    "/build/\n"\
                    "/bin/\n"\
                    "\n"\
                    "#Ignore cmake build files\n"\
                    "CMakeCache.txt\n"\
                    "CMakeFiles/\n"\
                    "cmake_install.cmake\n"\
                    "Makefile\n"

#endif

static void make_dir(char *dir_name, struct stat *st) {
  if (stat(dir_name, st) == -1) {
    mkdir(dir_name, 0755);
  }
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("This software needs the --name or --help param to run.\n");
    exit(1);
  }

  HashTable *args = parse_args(argc, argv);

  if (strcmp(getfromhash(args, "--help"), "\0") || strcmp(getfromhash(args, "-h"), "\0")) {
    deletehash(args);
    printf(HELP);
    exit(0);
  }

  char *cversion = "99";
  if (strcmp(getfromhash(args, "-c"), "\0")) {
    cversion = getfromhash(args, "-c");
  }

  struct stat st = {0};

  deletehash(args);
  return 0;
}