#include "shell.h"

/**
 * bfree - Frees all pointers and nulls the address.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
/* Check if the pointer and the value it points to are not NULL */
if (ptr && *ptr)
{
/* Free the memory block and set the pointer to NULL */
free(*ptr);
*ptr = NULL;
return 1; /* Return 1 to indicate that the memory was freed */
}

/* Return 0 to indicate that the memory was not freed */
return 0;
}

