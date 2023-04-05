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
	int (*func)(va_list vlist);
} convs;

int conv_handler(va_list vlist, const char *format, unsigned int *ind);

/* PRINTERS */
/* Chars */
int print_char(va_list vlist);

int print_str(va_list vlist);

int print_cent(va_list vlist);

/* Ints */
int print_int(va_list vlist);

int print_binary(va_list vlist);

int print_octal(va_list vlist);

int print_dec(va_list vlist);

int print_x(va_list vlist);

int print_X(va_list vlist);

void print_buf(char buffer[], unsigned int *ind);

int _printf(const char *format, ...);

#endif
