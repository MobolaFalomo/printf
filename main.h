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

/**
 *char get_size(const char *format, unsigned int *ind);
 *int get_precision(const char *format, unsigned int *ind);
 *int get_width(const char *format, unsigned int *ind);
 *int get_flags(const char *format, unsigned int *ind);
 */

int conv_handler(va_list vlist, const char *format, unsigned int *ind);

/* PRINTERS */
int print_char(va_list vlist);

int print_str(va_list vlist);

int print_cent(va_list vlist);

void print_buf(char buffer[], unsigned int *ind);

int _printf(const char *format, ...);

#endif
