#include "safepass.h"
#include "ui_safepass.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QString>
#include <QCheckBox>
#include <random>

std::string Upper_pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string Lower_pool = "abcdefghijklmnopqrstuvwxyz";
std::string Num_pool = "1234567890";
std::string Symbol_pool = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

SafePass::SafePass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SafePass)
{
    ui->setupUi(this);
    ui->pass_length->setValidator(new QIntValidator(1, 256, this));
}

SafePass::~SafePass()
{
    delete ui;
}

void SafePass::on_pushButton_clicked()
{
    QString pass;
    QString Ssize = ui->pass_length->text();
    int size = Ssize.toInt();
    std::string pool;
    if (ui->upper->isChecked())
        pool += Upper_pool;
    if (ui->lower->isChecked())
        pool += Lower_pool;
    if (ui->nums->isChecked())
        pool += Num_pool;
    if (ui->symbols->isChecked())
        pool += Symbol_pool;
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<> dist(0, pool.size() - 1);
    for (int i = 0; i < size; i++)
    {
        pass += pool[dist(generator)];
    }
    ui->result->setText(pass);
}

