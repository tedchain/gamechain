// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#ifndef JSON_SPIRIT_UBJSON_H
#define JSON_SPIRIT_UBJSON_H

#include "json/json_spirit_utils.h"
#include "json/json_spirit_value.h"
#include "gamechain/gamechain.h"

using namespace std;
using namespace json_spirit;

#ifdef __cplusplus
extern "C" {
#endif

int ubjson_write(Value json_value,mc_Script *lpScript,int max_depth);
Value ubjson_read(const unsigned char *elem,size_t elem_size,int max_depth,int *err);


#ifdef __cplusplus
}
#endif

#endif /* JSON_SPIRIT_UBJSON_H */

