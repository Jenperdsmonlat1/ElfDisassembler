//
// Created by rayane on 10/02/24.
//

#include "parser.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>

#ifdef __linux__
    #include <sys/stat.h>
#elif WIN32
    #include <windows.h>
#endif


uint8_t *Parser::readFile(const char *filename) {

    char *fileContent;
    struct stat st;

    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;

    stat(filename, &st);
    fileContent = (char *)malloc(sizeof(char) * st.st_size);

    fgets(fileContent, st.st_size, file);
    fclose(file);

    return ((uint8_t *)fileContent);
}
