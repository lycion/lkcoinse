// Copyright (c) 2011-2014 The Lkcoinse Core developers
// Copyright (c) 2015-2018 The Lkcoinse Unlimited developers
// Copyright (c) 2017 The Lkcoinse developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LKCOINSE_QT_LKCOINSEADDRESSVALIDATOR_H
#define LKCOINSE_QT_LKCOINSEADDRESSVALIDATOR_H

#include <QValidator>

/**
 * Lkcoinse address entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class LkcoinseAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit LkcoinseAddressEntryValidator(const std::string &cashaddrprefix, QObject *parent);

    State validate(QString &input, int &pos) const;

private:
    std::string cashaddrprefix;
};

/** Lkcoinse address widget validator, checks for a valid lkcoinse address.
 */
class LkcoinseAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit LkcoinseAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // LKCOINSE_QT_LKCOINSEADDRESSVALIDATOR_H
