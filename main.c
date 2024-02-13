#if defined(_WIN32) || defined(_WIN64)
  #error "Windows is not supported by this software."
#elif defined(__MACH__) || defined(__APPLE__)
  #error "Apple platforms are not supported by this software."
#else
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "../lib/argument_parser/argument_parser.h"

  #define HELP "This is the C Project Starter.\n"\
               "Developed by Aria Diniz. https://github.com/ariasdiniz\n\n"\
               "Use this tool to generate a new folder with a simple \n"\
               "structure for a new C project.\n\n"\
               "Params: --name: name of the project.\n"\
               "        -c:     version of the C language. Defaults to 99.\n\n"\
               "Example: cgen --name my_project -c 23\n"

  #define MAIN "#include <stdio.h>\n"\
               "\n"\
               "int main(int argc, char *argv[]) {\n"\
               "  printf(\"Hello World!\\n\");\n"\
               "  return 0;\n"\
               "}\n"

  #define CMAKE "cmake_minimum_required(VERSION 3.15)\n"\
                "\n"\
                "project(%s)\n"\
                "\n"\
                "set(CMAKE_C_STANDARD %s)\n"\
                "set(CMAKE_C_FLAGS \"${CMAKE_C_FLAGS} -O3\")\n"\
                "\n"\
                "set(SOURCE\n"\
                "    main.c)\n"\
                "\n"\
                "set(LIB\n"\
                "   )\n"\
                "\n"\
                "set(HEADER\n"\
                "   )\n"\
                "\n"\
                "add_executable(%s\n"\
                "               main.c\n"\
                "               ${SOURCE}\n"\
                "               ${LIB}\n"\
                "               ${HEADER})\n"\
                "\n"\
                "target_include_directories(%s PUBLIC src lib include)\n"
  
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
  } else {
    printf("Directory with name %s already exists!\n", dir_name);
    exit(1);
  }
}

static void make_file(char *dir_name, char *file_name, char *content, ...) {
  va_list args;
  va_start(args, content);
  char buffer[100];
  sprintf(buffer, "%s/%s", dir_name, file_name);
  printf("Generating %s...\n", buffer);
  FILE *file = fopen(buffer, "w");
  if (file == NULL) {
    printf("Error creating file %s!\n", buffer);
    exit(1);
  }
  vfprintf(file, content, args);
  fclose(file);
  va_end(args);
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

  char *name = getfromhash(args, "--name");
  if (strcmp(name, "\0") == 0 || strcmp(name, "--name") == 0) {
    printf("This software needs the --name param to run.\n");
    exit(1);
  }

  char *cversion = "99";
  if (strcmp(getfromhash(args, "-c"), "\0")) {
    cversion = getfromhash(args, "-c");
  }

  struct stat st = {0};
  char buffer[100];

  printf("Creating project directories...\n");
  make_dir(name, &st);

  sprintf(buffer, "%s/%s", name, "src");
  make_dir(buffer, &st);

  sprintf(buffer, "%s/%s", name, "lib");
  make_dir(buffer, &st);

  sprintf(buffer, "%s/%s", name, "include");
  make_dir(buffer, &st);

  make_file(name, "CMakeLists.txt", CMAKE, name, cversion, name, name);
  make_file(name, ".gitignore", GITIGNORE);
  make_file(name, "main.c", MAIN);

  printf("Process finished with success!\n");

  deletehash(args);
  return 0;
}