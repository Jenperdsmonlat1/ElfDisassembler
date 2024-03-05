#ifndef DESIGNHEADER_H
#define DESIGNHEADER_H

#include <cstdint>
#include <iostream>
#include <QLabel>


typedef struct labelHexa_t {
    std::string color;
    std::string backgroundColor;
    uint8_t margin;
    QLabel text;
} labelHexa;

#endif // DESIGNHEADER_H
