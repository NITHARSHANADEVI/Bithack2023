#ifndef ADMIN_CORE_MED_H
#define ADMIN_CORE_MED_H

#include <QDialog>

namespace Ui {
class admin_core_med;
}

class admin_core_med : public QDialog
{
    Q_OBJECT

public:
    explicit admin_core_med(QWidget *parent = nullptr);
    ~admin_core_med();

private slots:
    void on_admin_core_med_accepted();

    void on_quit_clicked();

private:
    Ui::admin_core_med *ui;
};

#endif // ADMIN_CORE_MED_H
