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
        int i, j;

        /* Find the end of the destination string */
        i = 0;
        while (dest[i] != '\0')
        {
                i++;
        }

        /* Append the source string to the destination string */
        j = 0;
        while (src[j] != '\0')
        {
                dest[i] = src[j];
                i++;
                j++;
        }

        /* Add the null terminator to the end of the concatenated string */
        dest[i] = '\0';

        /* Return a pointer to the concatenated string */
        return (dest);
}
