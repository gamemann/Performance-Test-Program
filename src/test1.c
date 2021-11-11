#include <stdio.h>
#include <stdlib.h>
#include <linux/types.h>
#include <string.h>

#include "common.h"

int main(int argc, char *argv[])
{
    // Initialize command line structure and retrieve flag options.
    struct cmdline cmd = 
    {
        .count = 1e6    // Set default count to 1 million.
    };

    getcmdline(&cmd, argc, argv);

    // Verbose.
    fprintf(stdout, "Starting test...\n");
    fprintf(stdout, "Looping through %llu times.\n", cmd.count);

    __u64 i;
    __u32 highest = 0;
    __u32 lowest = __UINT32_MAX__;
    __u32 avg = 0;

    // Retrieve overall timestamp.
    __u32 tot1 = read_time();

    for (i = 0; i < cmd.count; i++)
    {
        // Retrieve first timestamp.
        __u32 t1 = read_time();

        // First initialize our string and copy "a string" to it.
        char str[256];
        strcpy(str, "a string");

        // Now create a character pointer and pass the string to it.
        char *data = str;
        
        // Retrieve second timestamp.
        __u32 t2 = read_time();

        __u32 profile = t2 - t1;

        // Add onto average.
        avg += profile;

        // Check for highest.
        if (profile > highest)
        {
            highest = profile;
        }

        // Check for lowest.
        if (profile < lowest)
        {
            lowest = profile;
        }
    }

    // Stop overall timestamp and set overall time.
    __u32 tot2 = read_time();
    __u32 tot = tot2 - tot1;

    // Divide average by i.
    avg /= i;

    fprintf(stdout, "%llu calls with an overall profile time of %u. Avg profile time => %u. Highest profile time => %u. Lowest profile time => %u.\n", i, tot, avg, highest, lowest);

    return 0;
}