#ifndef PORTS_H
#define PORTS_H

#include "std_types.h"

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t out);

#endif
