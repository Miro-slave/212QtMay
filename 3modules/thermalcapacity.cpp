#include "thermalcapacity.h"
#include "ui_ThermalCapacity.h"
#include <QDir>

ThermalCapacity::ThermalCapacity(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ThermalCapacity)
{
    ui->setupUi(this);

    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->icon->setPixmap(pix.scaled(ui->icon->size(),Qt::KeepAspectRatio));
    }

    Sheet excelTable;
    excelTable.setPath((dir.absoluteFilePath("tables/test.csv").toStdString()));
    auto measurements = excelTable.readAsFloat();

    for (const auto& measurement : measurements)
        {
            Q.push_back(measurement[0]);
            C.push_back(measurement[1]);
            M.push_back(measurement[2]);
            m.push_back(measurement[3]);
            P.push_back(measurement[4]);
            K.push_back(measurement[5]);
            n.push_back(measurement[6]);
            L.push_back(measurement[7]);
            fuelType.push_back(measurement[8]);
        }
}

ThermalCapacity::~ThermalCapacity()
{
    delete ui;
}

void ThermalCapacity::on_CalcL0_clicked()
{
    L0 = ThermalCapacityFunc.FuelRatio(M, K, C);
    globalStorage.set_L0(L0);
    ui->PrintL0->setNum(L0);
}



void ThermalCapacity::on_CalcQnpV_2_clicked()
{
    QnpV = ThermalCapacityFunc.FuelVolume(Q, C);
    globalStorage.set_QnpV(QnpV);
    ui->PrintQnpV->setNum(QnpV);
}


void ThermalCapacity::on_CalcQnpm_clicked()
{
    Qnpm = ThermalCapacityFunc.FuelWeight(Q, C, M, n, P, fuelType);
    globalStorage.set_Qnpm(Qnpm);
    ui->PrintQnpm->setNum(Qnpm);
}

