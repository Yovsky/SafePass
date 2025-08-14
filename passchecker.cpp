#include "passchecker.h"
#include "ui_passchecker.h"
#include "safepass.h"

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

void passchecker::on_Hide_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1)
    {
        ui->Input->setEchoMode(QLineEdit::Password);
    }
    else if (!arg1)
    {
        ui->Input->setEchoMode(QLineEdit::Normal);
    }
}

void passchecker::on_CheckButton_clicked()
{
    QString pass = ui->Input->text();
    int strength = strength_check(pass);
    if (strength <= 1)
    {
        ui->Strength->setStyleSheet("QLabel { color: red; }");
        ui->Strength->setText("Weak");
    }
    else if(strength <= 2)
    {
        ui->Strength->setStyleSheet("QLabel { color: yellow; }");
        ui->Strength->setText("Medium");
    }
    else if(strength <= 3)
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
