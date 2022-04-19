#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


#define BUFFERSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

/**
 * struct stackvar - struct for required custom conversion specifiers
 * @char1: type char for buffer allocation
 * @char2: type char for validate n after %
 * @char3: type char for validate n n after %
 * @char4: auxiliar;
 * @i: for arrays.
 * @error: type int replaces stdbool.h
 * @flag: type int for modifiers flags
 * @space: type int for space printing
 * @counter: type int for counter between index arrays
 * @counter_b: type int for counter between buffer and char
 * @buffer: type char pointer to buffer
 * @format: type char pointer to format str
 * @arguments: arguments.
 */
typedef struct stackvar
{
	int i;
	char char1;
	char char2;
	char char3;
	char char4;
	int error;
	int flag;
	int space;
	int counter;
	int counter_b;
	char *buffer;
	const char *format;
	va_list *arguments;
} stackvar;

stackvar *stackinit(va_list *arguments_list, const char *format);
int create_buffer(stackvar *stack);
int printf_int(stackvar *stack);
int printf_string(va_list val);
int place_buffer(stackvar *stack, char *str);
int _strlen(char *s);
int printf_lint(stackvar *stack);
int create_int(stackvar *stack, long int n);
int printf_rot13(stackvar *stack);
int printf_r_str(stackvar *stack);
int (*printf_max_l_h(stackvar *stack))(stackvar *);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);

int _putchar(char c);
int printf_exit(stackvar *stack);
int _printf(const char *format, ...);
#endif
