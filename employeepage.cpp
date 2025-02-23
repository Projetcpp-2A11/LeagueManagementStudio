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

}




employeePage::~employeePage()
{
    delete ui;
}


