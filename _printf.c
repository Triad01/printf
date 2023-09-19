#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - custom printf() to print formatted strings to stdout
 * @format: format string to be printed
 * @...: variable number of arguments to be formatted and printed
 * Return: the number of characters printed
 */
int _printf(const char *format, ...);
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

			switch (*format)
			{
				case 'c':
					{
						char character = va_arg(list_of_args, int);

						write(1, &character, 1);
						num_of_characters++;
						break;
					}
				case 's':
					{
						char *str = va_arg(list_of_args, char *);

						if (str == NULL)
							  str = "(null)";
						write(1, str, strlen(str));
						num_of_characters += strlen(str);
						break;
					}
				case 'd':
				case 'i':
					{
						int number = va_arg(list_of_args, int);
						char num_str[20];
						int len = snprintf(num_str, sizeof(num_str), "%d", number);

						write(1, num_str, len);
						num_of_characters += len;
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						num_of_characters++;
						break;
					}
				default:
					{
						write(1, format - 1, 2);
						num_of_characters += 2;
						break;
					}
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (num_of_characters);
}
