/**
 * @file
 * @brief Wrapper to the allocation functions.
 */

#include "Include/malloc.h"

/** Message to show in case there is no more space on the computer. */
void print_error() {
	fprintf(stdout, "Unexpected error: no more space available.\n");
	exit(EXIT_FAILURE);
}

void* Malloc(size_t size) {
	if (size < 0) { return NULL; }
	
	void* space = (void*)malloc(size);
	if (space == NULL) { print_error(); }
	return space;
}

void* Calloc(size_t length, size_t size, void* element) {
	// TODO: element must implement a copy method
	if (length < 0 || size < 0) { return NULL; }

	void* space = (void*)malloc(length * size);
	if (space == NULL) { print_error(); }
	return space;
}
