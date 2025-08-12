#include "passchecker.h"
#include "ui_passchecker.h"

passchecker::passchecker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::passchecker)
{
    ui->setupUi(this);
}

passchecker::~passchecker()
{
    delete ui;
}

void passchecker::on_CheckButton_clicked()
{
    QString pass = ui->Input->text();
    int size = pass.size();
    if (size<=8)
    {
        ui->Strength->setStyleSheet("QLabel { color: red; }");
        ui->Strength->setText("Weak");
    }
    else if(size<=16)
    {
        ui->Strength->setStyleSheet("QLabel { color: yellow; }");
        ui->Strength->setText("Medium");
    }
    else if(size<=24)
    {
        ui->Strength->setStyleSheet("QLabel { color: #01e519; }");
        ui->Strength->setText("Strong");
    }
    else
    {
        ui->Strength->setStyleSheet("QLabel { color: green; }");
        ui->Strength->setText("Very Strong");
    }
}


void passchecker::on_CancelButton_2_clicked()
{
    this->close();
}

