// Copyright (c) 2009-2015 The Bitcoin Core developers
// Copyright (c) 2014-2020 The Minerium Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MINERIUM_QT_TEST_URITESTS_H
#define MINERIUM_QT_TEST_URITESTS_H

#include <QObject>
#include <QTest>

class URITests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void uriTests();
};

#endif // MINERIUM_QT_TEST_URITESTS_H
