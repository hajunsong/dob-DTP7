#ifndef FORMCUIMAIN_H
#define FORMCUIMAIN_H

#include <QWidget>
#include "cuiapi.h"
#include <QTime>
#include <QDebug>

namespace Ui {
class FormCUIMain;
}

class FormCUIMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormCUIMain(QWidget *parent = 0);
    ~FormCUIMain();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormCUIMain *ui;
};

#endif // FORMCUIMAIN_H
