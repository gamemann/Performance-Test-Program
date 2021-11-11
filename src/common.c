#include <stdio.h>
#include <linux/types.h>
#include <getopt.h>
#include "common.h"

const struct option opts[] = 
{
    {"count", required_argument, NULL, 'c'},
    {NULL, 0, NULL, 0}
};

static void getcmdline(struct cmdline *cmd, int argc, char *argv[])
{
    int c = -1;

    while ((c = getopt_long(argc, argv, "c", opts, NULL)) != -1)
    {
        switch (c)
        {
            case 'c':
                char *val = strdup(optarg);
                cmd->count = strtoull((const char *)val, (char **)val, 0);

                break;

            default:
                fprintf(stdout, "Missing argument.\n");

                break;
        }
    }
}

static inline __u32 read_time(void)
{
    __u32 a = 0;
    #if defined(__GNUC__) && (defined(ARCH_X86) || defined(ARCH_X86_64))
    asm volatile( "rdtsc" :"=a"(a) ::"edx" );
    #elif defined(ARCH_PPC)
    asm volatile( "mftb %0" : "=r" (a) );
    #elif defined(ARCH_ARM)     // ARMv7 only
    asm volatile( "mrc p15, 0, %0, c9, c13, 0" : "=r"(a) );
    #endif

    return a;
}