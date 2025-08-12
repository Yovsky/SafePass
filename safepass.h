#ifndef SAFEPASS_H
#define SAFEPASS_H

#include "passchecker.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SafePass;
}
QT_END_NAMESPACE

class SafePass : public QMainWindow
{
    Q_OBJECT

public:
    SafePass(QWidget *parent = nullptr);
    ~SafePass();
    passchecker *checkerWindow = nullptr;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SafePass *ui;
};
#endif // SAFEPASS_H
