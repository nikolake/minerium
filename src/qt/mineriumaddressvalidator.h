// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2014-2020 The Minerium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MINERIUM_QT_MINERIUMADDRESSVALIDATOR_H
#define MINERIUM_QT_MINERIUMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MineriumAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MineriumAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Minerium address widget validator, checks for a valid minerium address.
 */
class MineriumAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MineriumAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // MINERIUM_QT_MINERIUMADDRESSVALIDATOR_H
