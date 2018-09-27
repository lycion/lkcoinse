// Copyright (c) 2009-2015 The Lkcoinse Core developers
// Copyright (c) 2015-2018 The Lkcoinse Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "config/lkcoinse-config.h"
#endif

#include "lkcoinseaddressvalidatortests.h"
#include "guiutiltests.h"
#include "util.h"
#include "uritests.h"
#include "compattests.h"

#ifdef ENABLE_WALLET
#include "paymentservertests.h"
#endif

#include <QCoreApplication>
#include <QObject>
#include <QTest>

#include <openssl/ssl.h>

#if defined(QT_STATICPLUGIN)
#include <QtPlugin>
#endif

// This is all you need to run all the tests
int main(int argc, char *argv[])
{
    SetupEnvironment();
    bool fInvalid = false;

    // Don't remove this, it's needed to access
    // QCoreApplication:: in the tests
    QCoreApplication app(argc, argv);
    app.setApplicationName("Lkcoinse-Qt-test");

    SSL_library_init();

    URITests test1;
    if (QTest::qExec(&test1) != 0)
        fInvalid = true;
#ifdef ENABLE_WALLET
    PaymentServerTests test2;
    if (QTest::qExec(&test2) != 0)
        fInvalid = true;
#endif
    GUIUtilTests test5;
    if (QTest::qExec(&test5) != 0) fInvalid = true;
    LkcoinseAddressValidatorTests test6;
    if (QTest::qExec(&test6) != 0) fInvalid = true;

    return fInvalid;
}
