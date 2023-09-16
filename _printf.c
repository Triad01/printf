#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
* _printf - custom printf() to print formatted strings to stdout
* @format: format string to be printed
* Return: 0 if successfull and -1 on error
*/
int _printf(const char *format, ...)
{
	int num_of_characters, _str_length;
	char character;
	char *string;
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
		}
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
			string = va_arg(list_of_args, char*);
			while (string[_str_length] != '\0')
				_str_length++;
			write(1, string, _str_length);
			num_of_characters += _str_length;
		}
		format++;
	}
	va_end(list_of_args);
	return (num_of_characters);
}
