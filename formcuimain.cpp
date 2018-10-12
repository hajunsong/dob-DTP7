#include "formcuimain.h"
#include "ui_formcuimain.h"
#include "cuiecat.h"
#include "dob.h"

extern "C" void* createTestWidget()
{
    FormCUIMain* pW = new FormCUIMain();

    return (void*)pW;
}

FormCUIMain::FormCUIMain(QWidget *parent) : QWidget(parent), ui(new Ui::FormCUIMain)
{
    ui->setupUi(this);
}

FormCUIMain::~FormCUIMain()
{
    delete ui;
}

void FormCUIMain::on_pushButton_2_clicked()
{
    CUIApp* pApp = CUIApp::getInstance();

    pApp->setDTPBuzzerOn(1, 0);
    pApp->setStandardMode(true);
}

void FormCUIMain::on_pushButton_clicked()
{
    uint num_body = 6;
    DOB dob(num_body);
    dob.run();
    ui->label_tot->setText(QString::number(dob.total_time));
    ui->label_ave->setText(QString::number(dob.average_time));

    CUIApp* pApp = CUIApp::getInstance();
    pApp->setDTPBuzzerOn(1, 0);
}
