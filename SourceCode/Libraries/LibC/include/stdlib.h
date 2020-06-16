#ifndef __LIBRARY_LIBC_STDLIB_H__
#define __LIBRARY_LIBC_STDLIB_H__

#include <stdint.h>

#define DEFAULT_STRING_LEN 256

void memcpy(void *dest, const void *src, uint32_t bytes);

void putc(char c);
void print(const char *str);

int printf(const char * format, ...);

#endif // __LIBRARY_LIBC_STDLIB_H__