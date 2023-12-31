#include "shell.h"

/**
 **_memset - Fills a memory area with a constant byte.
 * @s: The pointer to the memory area.
 * @b: The byte to fill the memory with.
 * @n: The number of bytes that can be filled.
 *
 * Return: A pointer to the memory areas.
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return s;
}

/**
 * ffree - Frees a string array.
 * @pp: The string array to be freed.
 */
void ffree(char **pp)
{
char **current = pp;

if (!pp)
return;

while (*pp)
free(*pp++);

free(current);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: The pointer to the previous block.
 * @old_size: The original size of the block.
 * @new_size: The new size of the block.
 *
 * Return: A pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;

if (!ptr)
return malloc(new_size);

if (!new_size) {
free(ptr);
return NULL;
}

if (new_size == old_size)
return ptr;

new_ptr = malloc(new_size);

if (!new_ptr)
return NULL;

old_size = old_size < new_size ? old_size : new_size;

while (old_size--)
new_ptr[old_size] = ((char *)ptr)[old_size];

free(ptr);
return new_ptr;
}

