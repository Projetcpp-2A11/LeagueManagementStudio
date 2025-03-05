#include "matchpage.h"

#include <QVBoxLayout>

matchPage::matchPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::matchPage)
{
    setWindowTitle("Employee Page");
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

}




matchPage::~matchPage()
{
    delete ui;
}



void matchPage::on_homeButton_clicked()
{

}

