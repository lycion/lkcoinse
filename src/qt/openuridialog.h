// Copyright (c) 2011-2015 The Lkcoinse Core developers
// Copyright (c) 2015-2018 The Lkcoinse Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LKCOINSE_QT_OPENURIDIALOG_H
#define LKCOINSE_QT_OPENURIDIALOG_H

#include <QDialog>

class Config;

namespace Ui
{
class OpenURIDialog;
}

class OpenURIDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenURIDialog(const Config *cfg, QWidget *parent);
    ~OpenURIDialog();

    QString getURI();

protected Q_SLOTS:
    void accept();

private Q_SLOTS:
    void on_selectFileButton_clicked();

private:
    Ui::OpenURIDialog *ui;
    const Config *cfg;
};

#endif // LKCOINSE_QT_OPENURIDIALOG_H
