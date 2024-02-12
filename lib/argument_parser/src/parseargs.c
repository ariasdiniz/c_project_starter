#include "parseargs.h"
#include <stdlib.h>

HashTable *parse_args(int argc, char *argv[]) {
  HashTable *table = createhash();
  if (argc == 1) {
    return table;
  }
  char *arg;
  char *next_arg;
  for (int i=1; i<argc; i++) {
    arg = argv[i];
    next_arg = argv[i + 1];
    if (i < argc - 1 && arg[0] == '-' && next_arg[0] != '-') {
      addtohash(table, argv[i], argv[i + 1]);
      i++;
    } else {
      addtohash(table, argv[i], argv[i]);
    }
  }
  return table;
}
