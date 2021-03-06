// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Lkcoinse Core developers
// Copyright (c) 2015-2017 The Lkcoinse Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LKCOINSE_UTILTIME_H
#define LKCOINSE_UTILTIME_H

#include <stdint.h>
#include <string>

int64_t GetTime();
int64_t GetTimeMillis();
int64_t GetTimeMicros();
int64_t GetLogTimeMicros();
void SetMockTime(int64_t nMockTimeIn);
void MilliSleep(int64_t n);
uint64_t GetStopwatch(); // Returns a monotonically increasing time for interval measurement (in nSec)
std::string DateTimeStrFormat(const char *pszFormat, int64_t nTime);

#endif // LKCOINSE_UTILTIME_H
