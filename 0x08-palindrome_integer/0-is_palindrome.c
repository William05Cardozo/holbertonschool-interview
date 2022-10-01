#include "palindrome.h"
#define PALINDROME 1
#define NOT_PALINDROME 0
/**
 * flip - flip a number
 * @n: number
 * @temp: auxiliary variable
 * Return: result the flip
 **/
unsigned long int flip(unsigned long n, unsigned long temp)
{
	if (!n)
		return (temp);
	temp = (temp * 10) + (n % 10);
	return (flip(n / 10, temp));
}
/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 **/
int is_palindrome(unsigned long n)
{
	unsigned long temp = 0;

	temp = flip(n, temp);
	if (temp == n)
		return (PALINDROME);
	else
		return (NOT_PALINDROME);
}
