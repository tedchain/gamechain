// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#include "custom/custom.h"

using namespace std;

bool custom_good_for_coin_selection(const CScript& script)
{
    return true;    
}

bool custom_accept_transacton(const CTransaction& tx, 
                              const CCoinsViewCache &inputs,
                              int offset,
                              bool accept,
                              string& reason,
                              uint32_t *replay)
{
    return true;
}

