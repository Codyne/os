#ifndef MEM_H
#define MEM_H

#include "std_types.h"

void memcpy(uint8_t *dst, uint8_t *src, uint32_t nbytes);
void memset(uint8_t *dst, uint8_t val, uint32_t nbytes);

#endif
