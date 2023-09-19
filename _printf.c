#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - custom printf() to print formatted strings to stdout
 * @format: format string to be printed
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				if (str != NULL)
				{
					while (*str)
					{
						putchar(*str);
						str++;
						printed_chars++;
					}
				}
				else
				{
					printf("(null)");
					printed_chars += 6;
				}
			}
			else
			{
				char err_msg[7];
				int err_msg_len = snprintf(err_msg, sizeof(err_msg), "%%%c", *format);

				write(1, err_msg, err_msg_len);
				printed_chars += err_msg_len;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
