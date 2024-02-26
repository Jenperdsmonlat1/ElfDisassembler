//
// Created by rayane on 10/02/24.
//

#ifndef ELFDISASSEMBLER_PARSER_H
#define ELFDISASSEMBLER_PARSER_H

#include <cstdint>

class Parser {

public:
    uint8_t *readFile(const char *filename);
    
};


#endif //ELFDISASSEMBLER_PARSER_H
