#include "safepass.h"
#include "ui_safepass.h"
#include "passchecker.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QString>
#include <QCheckBox>
#include <QClipboard>
#include <QMessageBox>
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
    connect(ui->Pass_checker, &QAction::triggered, this, [this]() {
        passchecker dlg(this);
        dlg.exec();
    });

}

SafePass::~SafePass()
{
    delete ui;
}

void SafePass::on_pushButton_clicked()
{
    ui->Strength->setText("");
    ui->result->setText("");
    ui->is_copied->setText("");
    QString pass;
    QString Ssize = ui->pass_length->text();
    int size = Ssize.toInt();
    if (size < 1 || size > 256)
    {
        QMessageBox::warning(this, "Warning", "Please insert a valid size (1 - 256).");
        return;
    }
    if (!ui->upper->isChecked() && !ui->lower->isChecked() && !ui->nums->isChecked() && !ui->symbols->isChecked())
    {
        QMessageBox::warning(this, "Warning", "Please select one or more of the character types.");
        return;
    }
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

void SafePass::on_pushButton_2_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->result->toPlainText());
    if (clipboard->text() == ui->result->toPlainText())
    {
        ui->is_copied->setStyleSheet("QLabel {font: bold; color: gray;}");
        ui->is_copied->setText("Copied!");
    }
}


