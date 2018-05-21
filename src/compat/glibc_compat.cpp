// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#if defined(HAVE_CONFIG_H)
#include "config/bitcoin-config.h"
#endif

#include <cstddef>

#if defined(HAVE_SYS_SELECT_H)
#include <sys/select.h>
#endif

// Prior to GLIBC_2.14, memcpy was aliased to memmove.
extern "C" void* memmove(void* a, const void* b, size_t c);
extern "C" void* memcpy(void* a, const void* b, size_t c)
{
    return memmove(a, b, c);
}

extern "C" void __chk_fail(void) __attribute__((__noreturn__));
extern "C" FDELT_TYPE __fdelt_warn(FDELT_TYPE a)
{
    if (a >= FD_SETSIZE)
        __chk_fail();
    return a / __NFDBITS;
}
extern "C" FDELT_TYPE __fdelt_chk(FDELT_TYPE) __attribute__((weak, alias("__fdelt_warn")));
