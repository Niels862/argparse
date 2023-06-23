#include "argparse.h"
#include <string.h>
#include <stdio.h>

int argparse_add(ArgumentParser *parser, char *name, char *help, void *data,
                 enum ArgumentType type, int options) {
    ArgumentDefinition *argdef = malloc(sizeof(ArgumentDefinition));
    argdef->name = name;
    argdef->help = help;
    argdef->data = data;
    argdef->type = type;
    argdef->options = options;
    argdef->name_len = strlen(name);
    argdef->next = parser->argdef;
    parser->argdef = argdef;
    return 0;
}

int argparse_parse(ArgumentParser *parser, int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 1;
}
