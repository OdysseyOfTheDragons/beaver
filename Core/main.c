/**
 * @file
 * @brief Entry point of the CLI.
 */

#include "Include/defs.h"

/** Whether the program is compiled or not. */
bool IS_COMPILED = false;

/** Prints the usage of the CLI in case of error. */
void print_usage() {
	fprintf(stderr,
			"Usage:\n" "\tbeaver\tLaunch the REPL\n"
			"\tbeaver [file].bv\tInterpret the file\n"
			"\tbeaver -c [file].bv [-o [outfile]]\tCompile the file\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	if (argc < 1) {
		print_usage();
		return EXIT_FAILURE;
	}

	if (argc == 1) {
		fprintf(stdout, "Launching REPL.\n");
	} else if (argc == 2) {
		fprintf(stdout, "Interpret the file %s\n", argv[1]);
	} else if (argc == 3) {
		if (strcmp(argv[1], "-c") == 0) {
			fprintf(stdout, "Compile the file %s\n", argv[2]);
		} else {
			fprintf(stderr, "Command unknown\n");
			print_usage();
			return EXIT_FAILURE;
		}
		IS_COMPILED = true;
	} else if (argc == 5) {
		int length2 = strlen(argv[2]) + 1,
			length4 = strlen(argv[4]) + 1;
		char    *in,
		        *out;

		if (strcmp(argv[1], "-c") == 0 && strcmp(argv[3], "-o") == 0) {
			in = (char*)malloc(length2 * sizeof(char));
			out = (char*)malloc(length4 * sizeof(char));

			memcpy(in, argv[2], length2);
			memcpy(out, argv[4], length4);
			// snprintf(in, "%s", argv[2]);
			// sprintf(out, "%s", argv[4]);
		} else if (strcmp(argv[3], "-c") == 0 && strcmp(argv[1], "-o") == 0) {
			in = (char*)malloc(length4 * sizeof(char));
			out = (char*)malloc(length2 * sizeof(char));

			memcpy(in, argv[4], length4);
			memcpy(out, argv[2], length2);
			// sprintf(in, "%s", argv[4]);
			// sprintf(out, "%s", argv[2]);
		} else {
			print_usage();
			return EXIT_FAILURE;
		}
		fprintf(stdout, "Compile file %s to %s\n", in, out);
		IS_COMPILED = true;

		free(in);
		free(out);
	} else {
		print_usage();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
