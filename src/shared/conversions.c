#include "conversions.h"

#include <stdlib.h>

int clamp(int value, long low, long high) {
    if(value > high) return high;
    if(value < low) return low;
    return value;
}

uint8_t  conv_ubyte(const char* data) { return clamp(atoi(data), 0, 0xFF); }
int8_t   conv_byte (const char* data) { return clamp(atoi(data), -0x80, 0x80); }
uint16_t conv_uword (const char* data) { return clamp(atoi(data), 0, 0xFFFF); }
int16_t  conv_word (const char* data) { return clamp(atoi(data), -0x7FFF, 0x7FFF); }
uint32_t conv_udword (const char* data) { return atoi(data); }
int32_t  conv_dword (const char* data) { return atoi(data); }