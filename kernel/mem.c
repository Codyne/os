#include "mem.h"

void memcpy(uint8_t *dst, uint8_t *src, uint32_t nbytes) {
	for (uint32_t i = 0; i < nbytes; i++)
		*(dst + i) = *(src + i);
}

void memset(uint8_t *dst, uint8_t val, uint32_t nbytes) {
	for (uint32_t i = 0; i < nbytes; i++)
		*(dst + i) = val;
}
