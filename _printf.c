#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
* _printf - custom printf() to print formatted strings to stdout
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
			fprintf(stdout, format);
			num_of_characters++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				fprintf(stdout, format);
				num_of_characters++;
			}
			else if (*format == 'c')
			{
				character = va_arg(list_of_args, int);
				fprintf(stdout, &character);
				num_of_characters++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, char*);

				if (str == NULL)
				{
					fprintf(stdout, "(null)");
					num_of_characters += 6;
				}
				else
				{
					_str_length = 0;

					while (str[_str_length] != '\0')
					{
						fprintf(stdout, &str[_str_length]);
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

				fprintf(stdout, err_msg);
				num_of_characters += err_msg_len;
			}
		}
		format++;
	} va_end(list_of_args);
	return (num_of_characters);
}
