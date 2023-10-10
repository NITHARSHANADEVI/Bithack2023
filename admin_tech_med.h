#ifndef ADMIN_TECH_MED_H
#define ADMIN_TECH_MED_H

#include <QDialog>

namespace Ui {
class admin_tech_med;
}

class admin_tech_med : public QDialog
{
    Q_OBJECT

public:
    explicit admin_tech_med(QWidget *parent = nullptr);
    ~admin_tech_med();

private slots:
    void on_submitbtn_clicked();

    void on_quit_clicked();

private:
    Ui::admin_tech_med *ui;
};

#endif // ADMIN_TECH_MED_H
