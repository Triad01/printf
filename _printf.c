#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
* _printf - custom printf() to print formatted strings to stdout
* description:a function that produces output according to a format.
* @format: format string to be printed
* Return: 0 if successful and -1 on error
*/

int _printf(const char *format, ...)
{
    int num_of_characters = 0;
    va_list list_of_args;

    if (format == NULL)
        return (-1);

    va_start(list_of_args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            num_of_characters++;
        }
        else
        {
            format++;

            if (*format == '\0')
                break;

            if (*format == '%')
            {
                write(1, "%", 1);
                num_of_characters++;
            }
            else if (*format == 'c')
            {
                char character = va_arg(list_of_args, int);
                write(1, &character, 1);
                num_of_characters++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(list_of_args, char*);

                if (str == NULL)
                {
                    write(1, "(null)", 6);
                    num_of_characters += 6;
                }
                else
                {
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        num_of_characters++;
                    }
                }
            }
        }
        format++;
    }

    va_end(list_of_args);

    return num_of_characters;
}
