/************************************************************************
 * Copyright (c) 2020, Gil Treibush
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * A copy of the full GNU General Public License is included in this
 * distribution in a file called "COPYING" or "LICENSE".
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "editor.h"

#define BHE_VERSION         0.1
#define FILE_BUF_MAX_SIZE   2000000L

static void print_usage(void)
{
    printf( "Usage: bhe [OPTIONS] [Input File]\n"
            "Options:\n"
            "\t-h, --help           - Print this help menu and quit.\n"
            "\t-v, --version        - Print program version and quit.\n");
}

static void print_version(void)
{
    printf("bhe - Basic Hex Editor, version %.1f\n", BHE_VERSION);
}

static int load_file(char *fname)
{
    uint8_t *file_buf;
    int fd;
    struct stat sb;
    int ret_val = 0;
    off_t buf_size;

    fd = open(fname, O_RDWR | O_CREAT);
    if (fd == -1) {
        fprintf(stderr, "Could not open file %s (%d) ", fname, errno);
        perror("");
        return -1;
    }

    if (stat(fname, &sb) == -1) {
        fprintf(stderr, "Could not get file %s size (%d) ", fname, errno);
        perror("");
        return -1;
    }

    buf_size = (sb.st_size > FILE_BUF_MAX_SIZE) ? FILE_BUF_MAX_SIZE : sb.st_size;

    file_buf = malloc(buf_size);
    if (!file_buf) {
        fprintf(stderr, "Could not allocate file buffer (size: %ld)\n", buf_size);
        return -1;
    }

    ret_val = bhe_run_editor(fd, file_buf, buf_size);

    free(file_buf);

    return ret_val;
}

int main(int argc, char** argv)
{
    while (1) {

        int c, ret_val = 0;
        static struct option long_options[] = {
            {"help",        no_argument,    0, 'h'},
            {"version",     no_argument,    0, 'v'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "hv", long_options, NULL);
        if (c == -1)
            break;

        switch (c)
        {
            case 'v':
                print_version();
                return ret_val;

            case 'h':
                ret_val--;

            default:
                print_usage();
                ret_val++;
                return ret_val;
        }
    }

    if (argc == 1)
        printf("%s: No input file specified\n", argv[0]);
    else if (argc > 2)
        printf("%s: Only single input file supported\n", argv[0]);

    return load_file(argv[1]);
}

