#include "argparse.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char argv[]) {
    int c;
    ArgumentParser parser = {0, NULL};
    argparse_add(&parser, "c", "Amount of elements", &c, ArgLong, 0);
    argparse_parse(&parser, argc, argv);

    return 0;
}
