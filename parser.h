//
// Created by rayane on 10/02/24.
//

#ifndef ELFDISASSEMBLER_PARSER_H
#define ELFDISASSEMBLER_PARSER_H

#include <cstdint>
#include <iostream>


class Parser {

public:

    std::string filename;

    Parser(std::string filename);
    ~Parser();
    uint8_t *readFile();
    struct stat getFileInfo();
};


#endif //ELFDISASSEMBLER_PARSER_H
