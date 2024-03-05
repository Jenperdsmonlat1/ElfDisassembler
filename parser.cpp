//
// Created by rayane on 10/02/24.
//

#include "parser.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#ifdef __linux__
    #include <sys/stat.h>
#elif WIN32
    #include <windows.h>
#endif


Parser::Parser(const std::string filename) {
    this->filename = filename;
}

Parser::~Parser() {
    delete this;
}

uint8_t *Parser::readFile() {

    char *fileContent;
    struct stat st;

    FILE *file = fopen(filename.c_str(), "r");
    if (file == NULL) return NULL;

    stat(filename.c_str(), &st);
    fileContent = (char *)malloc(sizeof(char) * st.st_size);

    fgets(fileContent, st.st_size, file);
    fclose(file);

    return ((uint8_t *)fileContent);
}

struct stat Parser::getFileInfo() {

    struct stat st;
    stat(filename.c_str(), &st);

    return st;
}
