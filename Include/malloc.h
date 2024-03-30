/**
 * @file
 * @brief Wrapper to the allocation functions.
 */

#ifndef _MALLOC
#define _MALLOC
#include "Include/defs.h"

/**
 * Allocates the given size of memory.
 * 
 * @param size the size of memory to allocate
 * @returns a pointer to the memory
 * @throws no more memory available
 */
void* Malloc(size_t size);

/**
 * Allocates the memory with the default value.
 *
 * @param length the number of elements to allocate
 * @param size the size of one object
 * @param element the default element, which must have a copy method
 * @returns a pointer to the memory
 * @throws no more memory available
 */
void* Calloc(size_t length, size_t size, void* element);
#endif
