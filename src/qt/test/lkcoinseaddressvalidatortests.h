// Copyright (c) 2017 The Lkcoinse Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LKCOINSE_QT_TEST_LKCOINSEADDRESSVALIDATORTESTS_H
#define LKCOINSE_QT_TEST_LKCOINSEADDRESSVALIDATORTESTS_H

#include <QObject>
#include <QTest>

class LkcoinseAddressValidatorTests : public QObject {
    Q_OBJECT

private Q_SLOTS:
    void inputTests();
};

#endif
