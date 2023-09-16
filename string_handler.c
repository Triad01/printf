#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
* string_handler - prints strings to the stdout
* @string: string to be printed out
* Return: length of the string
*/
int string_handler(char *string)
{
	int _str_len = 0;

	while (string[_str_len] != '\0')
		_str_len++;
	write(1, string, _str_len);
	return (_str_len);
}
