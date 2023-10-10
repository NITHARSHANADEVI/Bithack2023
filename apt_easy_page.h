#ifndef APT_EASY_PAGE_H
#define APT_EASY_PAGE_H

#include <QDialog>

namespace Ui {
class Apt_easy_page;
}

class Apt_easy_page : public QDialog
{
    Q_OBJECT

public:
    explicit Apt_easy_page(QWidget *parent = nullptr);
    ~Apt_easy_page();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Apt_easy_page *ui;
};

#endif // APT_EASY_PAGE_H
