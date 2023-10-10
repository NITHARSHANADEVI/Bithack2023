#ifndef ADMIN_VERBAL_HARD_H
#define ADMIN_VERBAL_HARD_H

#include <QDialog>

namespace Ui {
class admin_verbal_hard;
}

class admin_verbal_hard : public QDialog
{
    Q_OBJECT

public:
    explicit admin_verbal_hard(QWidget *parent = nullptr);
    ~admin_verbal_hard();

private slots:
    void on_submitbtn_clicked();

    void on_quit_clicked();

private:
    Ui::admin_verbal_hard *ui;
};

#endif // ADMIN_VERBAL_HARD_H
