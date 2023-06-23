#include <stdlib.h>

#ifndef ARGPARSE_H
#define ARGPARSE_H

#define ARG_REQUIRED 0x1
#define ARG_ARRAY    0x2

// ArgBool is 1 if the argument is passed, else 0
// All other arguments take the value of the next entry in arg,
// or all other values until the next name if an array is specified.
enum ArgumentType {
    ArgLong, ArgString, ArgBool, ArgDouble
};

typedef struct {
    char *name;
    char *help;
    void *data;
    void *next;
    enum ArgumentType type;
    int options;
    size_t name_len;
} ArgumentDefinition;

typedef struct {
    int n;
    ArgumentDefinition *argdef;
} ArgumentParser;

int argparse_add(ArgumentParser *parser, char *name, char *help, void *data,
                 enum ArgumentType type, int options);
int argparse_parse(ArgumentParser *parser, int argc, char *argv[]);

#endif
