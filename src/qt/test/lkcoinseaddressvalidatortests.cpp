// Copyright (c) 2017 The Lkcoinse Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/test/lkcoinseaddressvalidatortests.h"
#include "chainparams.h"
#include "qt/lkcoinseaddressvalidator.h"
#include <QValidator>

void LkcoinseAddressValidatorTests::inputTests() {
    const std::string prefix = Params(CBaseChainParams::MAIN).CashAddrPrefix();
    LkcoinseAddressEntryValidator v(prefix, nullptr);

    int unused = 0;
    QString in;

    // invalid base58 because of I, invalid cashaddr
    in = "BIIC";
    QVERIFY(QValidator::Invalid == v.validate(in, unused));

    // invalid base58, invalid cashaddr
    in = "LKCOINSECASHH";
    QVERIFY(QValidator::Invalid == v.validate(in, unused));

    // invalid base58 because of I, but could be a cashaddr prefix
    in = "BITC";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));

    // invalid base58, valid cashaddr
    in = "LKCOINSECASH:QP";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));

    // valid base58, invalid cash
    in = "BBBBBBBBBBBBBB";
    QVERIFY(QValidator::Acceptable == v.validate(in, unused));
}
