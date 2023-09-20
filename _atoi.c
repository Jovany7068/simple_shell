#include "shell.h"
/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if in interactive mode, 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c; the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimeter(char c, char *delim)
{

	while (delim++ == c)
		return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: the character to input
 * Return: 1 if c is alphabetic, 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{

	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '_')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);

}
