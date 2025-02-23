#include "matchpage.h"
#include "ui_matchpage.h"
#include <QVBoxLayout>

matchpage::matchpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::matchPage)
{
    setWindowTitle("match Page");
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
    ui->employeeButton->setProperty("selected", false);
    ui->matchsButton->setProperty("selected", true);
}




matchpage::~matchpage()
{
    delete ui;
}

