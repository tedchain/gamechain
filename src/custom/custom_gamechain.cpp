// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#include "gamechain/gamechain.h"

void* custom_get_blockchain_default(const char *param,int* size,void *param_in)
{
    *size=0;
    
    return NULL;
}

