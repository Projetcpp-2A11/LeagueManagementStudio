#include "teamtypeform.h"
#include "ui_teamstype.h" // This is generated from teamstype.ui

TeamstypeForm::TeamstypeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // Set window title
    setWindowTitle("Best Performing Team");

    // Apply blue background style to all player labels
    QString labelStyle = "QLabel { color: white; font-weight: bold; font-size: 14px; background-color: rgba(0, 0, 255, 150); padding: 5px; border-radius: 5px; }";

    ui->GK->setStyleSheet(labelStyle);
    ui->LB->setStyleSheet(labelStyle);
    ui->CB1->setStyleSheet(labelStyle);
    ui->CB2->setStyleSheet(labelStyle);
    ui->RB->setStyleSheet(labelStyle);
    ui->CM1->setStyleSheet(labelStyle);
    ui->CM2->setStyleSheet(labelStyle);
    ui->CAM->setStyleSheet(labelStyle);
    ui->LW->setStyleSheet(labelStyle);
    ui->ST->setStyleSheet(labelStyle);
    ui->RW->setStyleSheet(labelStyle);
}

TeamstypeForm::~TeamstypeForm()
{
    delete ui;
}

void TeamstypeForm::setGK(const QString &name)
{
    ui->GK->setText(name);
}

void TeamstypeForm::setLB(const QString &name)
{
    ui->LB->setText(name);
}

void TeamstypeForm::setCB1(const QString &name)
{
    ui->CB1->setText(name);
}

void TeamstypeForm::setCB2(const QString &name)
{
    ui->CB2->setText(name);
}

void TeamstypeForm::setRB(const QString &name)
{
    ui->RB->setText(name);
}

void TeamstypeForm::setCM1(const QString &name)
{
    ui->CM1->setText(name);
}

void TeamstypeForm::setCM2(const QString &name)
{
    ui->CM2->setText(name);
}

void TeamstypeForm::setCAM(const QString &name)
{
    ui->CAM->setText(name);
}

void TeamstypeForm::setLW(const QString &name)
{
    ui->LW->setText(name);
}

void TeamstypeForm::setST(const QString &name)
{
    ui->ST->setText(name);
}

void TeamstypeForm::setRW(const QString &name)
{
    ui->RW->setText(name);
}
