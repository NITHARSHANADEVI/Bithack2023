#include "apt_category.h"
#include "ui_apt_category.h"
#include "apt_category.h"
#include "apt_easy_page.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <qsqlquery.h>

Apt_category::Apt_category(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apt_category)
{
    ui->setupUi(this);

}

Apt_category::~Apt_category()
{
    delete ui;
}


void Apt_category::on_apt_easy_btn_clicked()
{
//    hide();
    Apt_easy_page *easy_page;
    easy_page=new Apt_easy_page(this);
    easy_page->show();

}


void Apt_category::on_view_table_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT [email], [id] FROM login");
    if (query.exec())
    {
        model->setQuery(query);
        QTableView *tableView = new QTableView;
        tableView->setModel(model);
        tableView->show();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to fetch data from the database.");
    }
}
