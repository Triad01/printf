#include "main.h"
#include <unistd.h>
/**
* character_handler - prints a character to the stdout
* @character: character to be printed
* Return: always character
*/
char character_handler(char character)
{
	return (write(1, &character, 1));
}
