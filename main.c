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
               "Example: cgen --name my_project\n"
#endif

int main(int argc, char* argv[]) {
  if (argc == 1) {
    printf("This software needs the --name or --help param to run.\n");
    exit(1);
  }

  HashTable *args = parse_args(argc, argv);

  if (strcmp(getfromhash(args, "--help"), "\0") || strcmp(getfromhash(args, "-h"), "\0")) {
    printf(HELP);
    exit(0);
  }
  
  return 0;
}