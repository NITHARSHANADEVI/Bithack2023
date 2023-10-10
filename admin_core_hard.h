#ifndef ADMIN_CORE_HARD_H
#define ADMIN_CORE_HARD_H

#include <QDialog>

namespace Ui {
class admin_core_hard;
}

class admin_core_hard : public QDialog
{
    Q_OBJECT

public:
    explicit admin_core_hard(QWidget *parent = nullptr);
    ~admin_core_hard();

private slots:
    void on_submitbtn_clicked();

    void on_quit_clicked();

private:
    Ui::admin_core_hard *ui;
};

#endif // ADMIN_CORE_HARD_H
