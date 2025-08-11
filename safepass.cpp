#include "safepass.h"
#include "ui_safepass.h"

SafePass::SafePass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SafePass)
{
    ui->setupUi(this);
}

SafePass::~SafePass()
{
    delete ui;
}
