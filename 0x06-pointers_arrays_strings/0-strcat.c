#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 *
 * Return: Pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
        char *s = dest; /* save a copy of dest pointer */

        /* Find the end of the destination string */
        while (*dest != '\0')
        {
                dest++;
        }

        /* Append the source string to the destination string */
        while (*src != '\0')
        {
                *dest = *src;
                dest++;
                src++;
        }

        /* Add the null terminator to the end of the concatenated string */
        *dest = '\0';

        /* Return a pointer to the concatenated string */
        return (s);
}
