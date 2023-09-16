#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
* _printf - custom printf() to print formatted strings to stdout
* @format: format string to be printed
* Return: 0 if successful and -1 on error
*/
int _printf(const char *format, ...)
{
	int num_of_characters, _str_length;
	va_list list_of_args;

	num_of_characters = _str_length = 0;
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
				character_handler(va_arg(list_of_args, int));
				num_of_characters++;
			}
			else if (*format == 's')
			{
				_str_length = string_handler(va_arg(list_of_args, char*));
				num_of_characters += _str_length;
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (num_of_characters);
}
