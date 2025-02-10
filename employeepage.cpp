#include "employeepage.h"
#include "ui_employeepage.h"
#include <QVBoxLayout>

employeePage::employeePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::employeePage)
{
    setWindowTitle("Employee Page");
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
    ui->employeeButton->setProperty("selected", true);

    //ui->employeeButton->setStyleSheet("  background-color: blue; border-radius: 15px;  color: white; border: none; padding: 10px 20px;" );
}




employeePage::~employeePage()
{
    delete ui;
}
