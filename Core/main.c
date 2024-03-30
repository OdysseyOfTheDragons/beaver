/**
 * @file
 * @brief Entry point of the CLI.
 */

#include "Include/defs.h"

/** Whether the program is compiled or not. */
bool IS_COMPILED = false;

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
		}
		IS_COMPILED = true;
	} else if (argc == 5) {
		char    in[1024],
		        out[1024];

		if (strcmp(argv[1], "-c") == 0 && strcmp(argv[3], "-o") == 0) {
			sprintf(in, "%s", argv[2]);
			sprintf(out, "%s", argv[4]);
		} else if (strcmp(argv[3], "-c") == 0 && strcmp(argv[1], "-o") == 0) {
			sprintf(in, "%s", argv[4]);
			sprintf(out, "%s", argv[2]);
		} else {
			print_usage();
		}
		fprintf(stdout, "Compile file %s to %s\n", in, out);
		IS_COMPILED = true;
	} else {
		print_usage();
	}

	return EXIT_SUCCESS;
}
