#ifndef ADMIN_VERBAL_MED_H
#define ADMIN_VERBAL_MED_H

#include <QDialog>

namespace Ui {
class admin_verbal_med;
}

class admin_verbal_med : public QDialog
{
    Q_OBJECT

public:
    explicit admin_verbal_med(QWidget *parent = nullptr);
    ~admin_verbal_med();

private slots:
    void on_submitbtn_clicked();

    void on_quit_clicked();

private:
    Ui::admin_verbal_med *ui;
};

#endif // ADMIN_VERBAL_MED_H
