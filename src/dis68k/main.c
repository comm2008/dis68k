#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#include "dbg.h"

int main(int argc, char **argv)
{
    int ret = EXIT_FAILURE;

    // 1. Validate program arguments
    if(argc != 4)
    {
        log_err("Invalid number of arguments.\n");
        goto error_0;
    }

    // Calculate the input/output file paths
    char *input_file_path = argv[1];
    char *output_file_path = argv[2];

    // Calculate the load offset
    int i = -1;
    if(sscanf(argv[3], "%i", &i) == 0 || i < 0)
    {
        log_err("Invalid LOAD-OFFSET given.");
        goto error_0;
    }

    // 2. Open input/output files
    int input_file = open(input_file_path, O_RDONLY);
    if(input_file < 0)
    {
        log_err("Failed to open input file.\n\tFILE: %s", input_file_path);
        goto error_0;
    }

    int output_file = open(output_file_path, O_WRONLY|O_CREAT);
    if(output_file < 0)
    {
        log_err("Failed to open output file.\n\tFILE: %s", output_file_path);
        goto error_1;
    }

    // 3. Calculate length of input files
    struct stat s;
    fstat(input_file, &s);

    int input_file_len = s.st_size;

    // 4. Pre-allocate data structures
    uint8_t *acknowledged_label_array = malloc((input_file_len / 8) + 1);
    uint32_t *pending_basic_blocks[2];

    // High-Level Algorithm:
    // ---------------------
    // In order to disassemble 68000 binaries, we must be able to:
    //   a) Decode individual 68000 instructions
    //   b) Accumulate instructions that make up basic-blocks
    //   c) Calculate statically absolute addresses used in branches, jumps, and subroutine calls.
    //   d) Keep track of basic-block offsets in source binary
    //   e)
    //
    // Steps of algorithm:
    //   1) Calculate the entry point address
    //   2) Set 'r' to a tree consisting of
    //   tip consisting of the entire file
    //   3) Read basic
    //   Begin with an initial data-chunk that
    //
    // Memory


error_2:
    if(close(output_file))
    {
        log_err("Failed to close output file handle.");
    }
error_1:
    if(close(input_file))
    {
        log_err("Failed to close input file handle.");
    }
error_0:
    if(ret == EXIT_FAILURE)
    {
        // Determine the name which the user uses to refer to this program
        char *exectuable_path;
        if(argc > 0 && argv[0])
        {
            exectuable_path = argv[0];
        }
        else
        {
            exectuable_path = "dis68k";
        }

        fprintf(stderr, "USAGE: %s INPUT-FILE OUTPUT-FILE LOAD-OFFSET\n", exectuable_path);
    }

    return ret;
}
