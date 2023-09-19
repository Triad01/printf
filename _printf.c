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

int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int num_of_characters, _str_length;
	int number;
	va_list list_of_args;
	char num_str[20], character;

	num_of_characters = 0;

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
				write(1, format, 1);
				num_of_characters++;
			}
			else if (*format == 'c')
			{
				character = va_arg(list_of_args, int);
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
					_str_length = 0;

					while (str[_str_length] != '\0')
					{
						write(1, &str[_str_length], 1);
						_str_length++;
					}
					num_of_characters += _str_length;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				number = va_arg(list_of_args, int);
				snprintf(num_str, sizeof(num_str), "%d", number);
				write(1, num_str, strlen(num_str));
				num_of_characters += strlen(num_str);
			}
			else
			{
				char err_msg[7];
				int err_msg_len = snprintf(err_msg, sizeof(err_msg), "%%%c", *format);

				write(1, err_msg, err_msg_len);
				num_of_characters += err_msg_len;
			}
		}
		format++;
	} va_end(list_of_args);
	return (num_of_characters);
}
