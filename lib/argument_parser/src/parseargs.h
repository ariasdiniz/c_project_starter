#ifndef ARIA_C_ARGUMENT_PARSER_PARSER_H
#define ARIA_C_ARGUMENT_PARSER_PARSER_H

#include "../lib/simple_data_structures/datastructures.h"

/*
 * Function: parse args
 * ------------------------------
 * Parses command line arguments and returns a HashTable containing
 * the parameters and their corresponding values. Parameters prefixed
 * with '-' or '--' are considered keys. Each key's value is the 
 * subsequent argument in the argv array, provided it does not also 
 * start with a '-'. If the next argument is another key (starts with '-'),
 * then the value for the current key is set to the key itself.
 *
 * Any argument not prefixed with '-' and not immediately following a key 
 * is also treated as a key, but its value is set to the key itself.
 * For example, in the command line "program --key1 value1 value2", 
 * "value2" is treated as a key with its value being "value2".
 *
 * Usage of the returned HashTable:
 * - Use getfromhash(table, key) to retrieve the value associated with a parameter.
 * - Use deletehash(table) to free the HashTable memory after use.
 *
 * Parameters:
 *   argc - Integer representing the number of command line arguments.
 *   argv - Array of strings containing the command line arguments.
 *
 * Returns:
 *   A HashTable containing the parsed command line arguments and their values.
 *
 * Example:
 *   HashTable* params = parseCommandLineArgs(argc, argv);
 *   char* value1 = getfromhash(params, "--key1"); // Gets "value1"
 *   char* value2 = getfromhash(params, "value2"); // Gets "value2" as key itself
 *   deletehash(params); // Clean up
 */
HashTable *parse_args(int argc, char *argv[]);

#endif // ARIA_C_ARGUMENT_PARSER_PARSER_H