#ifndef COMMON_H
#define COMMON_H

#include <LittleLibrary/LittleLibrary.h>


extern "C" {


#define MAXINT32 2147483647
#define MININT32 -2147483648


// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   uint32;
typedef          int   int32;
typedef unsigned short uint16;
typedef          short int16;
typedef unsigned char  uint8;
typedef          char  int8;

typedef uint32 size_t;

void memcpy(void *dest, const void *src, uint32 len);
void memset(void *dest, uint8 val, uint32 len);
//void memset(uint32 *dest, uint32 val, uint32 len);
int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strlen(char *src);

#define ASSERT(b) ((b) ? (void)0 : PanicAssert(__FILE__, __LINE__, #b))


void   outb(uint16 port, uint8 value);
uint8  inb(uint16 port);
uint16 inw(uint16 port);



}


typedef struct {
   size_t ds;                  // Data segment selector
   size_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   size_t int_no, err_code;    // Interrupt number and error code (if applicable)
   size_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} Registers;



// outputs a character to the debug console
#define BochsConsolePrintChar(c) outportb(0xe9, c)
// stops simulation and breaks into the debug console
#define BochsBreak() outportw(0x8A00,0x8A00); outportw(0x8A00,0x08AE0);
 
 
#endif
