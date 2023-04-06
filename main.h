#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUF 1024



/**
 * struct conversions - struct of conversions
 *
 * @ch: conversion string
 * @func: pointer to type_handler
 */

typedef struct conversions
{
	char ch;
	int (*func)(va_list vlist, char buffer[], unsigned int *buffind);
} convs;

int conv_handler(va_list vlist, const char *format, unsigned int *ind
		 , char buffer[], unsigned int *buffind);

/* PRINTERS */
/* Chars */
int print_char(va_list vlist, char buffer[], unsigned int *buffind);

int print_str(va_list vlist, char buffer[], unsigned int *buffind);

int print_cent(va_list vlist, char buffer[], unsigned int *buffind);

int print_Str(va_list vlist, char buffer[], unsigned int *buffind);

/* Ints */
int print_int(va_list vlist, char buffer[], unsigned int *buffind);

int print_binary(va_list vlist, char buffer[], unsigned int *buffind);

int print_octal(va_list vlist, char buffer[], unsigned int *buffind);

int print_dec(va_list vlist, char buffer[], unsigned int *buffind);

int print_x(va_list vlist, char buffer[], unsigned int *buffind);

int print_X(va_list vlist, char buffer[], unsigned int *buffind);

/* Buffer */
int buff_handler(char ch, char buffer[], unsigned int *ind);

int _printf(const char *format, ...);

/* Utils */
char *getX(unsigned int n);

#endif
