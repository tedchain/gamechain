// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#ifndef BITCOIN_RFC6979_HMAC_SHA256_H
#define BITCOIN_RFC6979_HMAC_SHA256_H

#include "crypto/hmac_sha256.h"

#include <stdint.h>
#include <stdlib.h>

/** The RFC 6979 PRNG using HMAC-SHA256. */
class RFC6979_HMAC_SHA256
{
private:
    unsigned char V[CHMAC_SHA256::OUTPUT_SIZE];
    unsigned char K[CHMAC_SHA256::OUTPUT_SIZE];
    bool retry;

public:
    /**
     * Construct a new RFC6979 PRNG, using the given key and message.
     * The message is assumed to be already hashed.
     */
    RFC6979_HMAC_SHA256(const unsigned char* key, size_t keylen, const unsigned char* msg, size_t msglen);

    /**
     * Generate a byte array.
     */
    void Generate(unsigned char* output, size_t outputlen);

    ~RFC6979_HMAC_SHA256();
};

#endif // BITCOIN_RFC6979_HMAC_SHA256_H
