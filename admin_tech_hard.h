#ifndef ADMIN_TECH_HARD_H
#define ADMIN_TECH_HARD_H

#include <QDialog>

namespace Ui {
class admin_tech_hard;
}

class admin_tech_hard : public QDialog
{
    Q_OBJECT

public:
    explicit admin_tech_hard(QWidget *parent = nullptr);
    ~admin_tech_hard();

private slots:
    void on_submitbtn_clicked();

    void on_quit_clicked();

private:
    Ui::admin_tech_hard *ui;
};

#endif // ADMIN_TECH_HARD_H
