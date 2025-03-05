#include "teamspage.h"
#include "ui_teamspage.h"
#include <QVBoxLayout>

teamsPage::teamsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teamsPage)
{
    setWindowTitle("Employee Page");
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

    //ui->employeeButton->setStyleSheet("  background-color: blue; border-radius: 15px;  color: white; border: none; padding: 10px 20px;" );
}




teamsPage::~teamsPage()
{
    delete ui;
}
