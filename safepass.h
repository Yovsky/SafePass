#ifndef SAFEPASS_H
#define SAFEPASS_H

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

private slots:
    void on_pushButton_clicked();

    void on_Gobutton_clicked();

private:
    Ui::SafePass *ui;
};
#endif // SAFEPASS_H
