#include "capacitycalc.h"
#include "ui_capacitycalc.h"

CapacityCalc::CapacityCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapacityCalc)
{
    ui->setupUi(this);
}

CapacityCalc::~CapacityCalc()
{
    delete ui;
}

void CapacityCalc::on_temp_button_clicked()
{
    TempCalc calcWin(this);
    calcWin.exec();
}

void CapacityCalc::on_end_button_clicked()
{
    EndCalc calcWin(this);
    calcWin.exec();
}

void CapacityCalc::on_during_button_clicked()
{
    DuringCalc calcWin(this);
    calcWin.exec();
}
