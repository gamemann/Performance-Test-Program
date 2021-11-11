#pragma once

#include <linux/types.h>

#define ARCH_X86_64

struct cmdline
{
    __u64 count;
};

static inline __u32 read_time(void);
static void getcmdline(struct cmdline *cmd, int argc, char *argv[]);