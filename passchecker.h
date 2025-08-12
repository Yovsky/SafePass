#ifndef PASSCHECKER_H
#define PASSCHECKER_H

#include <QDialog>

namespace Ui {
class passchecker;
}

class passchecker : public QDialog
{
    Q_OBJECT

public:
    explicit passchecker(QWidget *parent = nullptr);
    ~passchecker();

private slots:
    void on_CheckButton_clicked();

    void on_CancelButton_2_clicked();

private:
    Ui::passchecker *ui;
};

#endif // PASSCHECKER_H
