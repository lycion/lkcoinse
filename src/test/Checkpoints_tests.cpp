// Copyright (c) 2011-2015 The Lkcoinse Core developers
// Copyright (c) 2015-2017 The Lkcoinse Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "chainparams.h"
#include "test/test_lkcoinse.h"
#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_FIXTURE_TEST_SUITE(Checkpoints_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(sanity)
{
    const CCheckpointData &checkpoints = Params(CBaseChainParams::MAIN).Checkpoints();
    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate(checkpoints) >= 134444);
}

BOOST_AUTO_TEST_SUITE_END()