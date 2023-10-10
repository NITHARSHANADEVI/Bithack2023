#include "apt_easy_page.h"
#include "ui_apt_easy_page.h"
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QTableView>
#include <qsqlquerymodel.h>
#include <qsqlquery.h>

Apt_easy_page::Apt_easy_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apt_easy_page)
{
    ui->setupUi(this);
    QSqlDatabase qn_drop=QSqlDatabase::addDatabase("QSQLITE");
    qn_drop.setDatabaseName("C:/Users/Karishhaju/OneDrive/Desktop/QT-Quiz_Game-main (2)/QT-Quiz_Game-main/qn_drop.db");

    if(!qn_drop.open())
     ui->qn_db_status->setText("Not found");
    else
     ui->qn_db_status->setText("Connected");
}
Apt_easy_page::~Apt_easy_page()
{
    delete ui;
}


void Apt_easy_page::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
       QSqlQuery query;

       query.prepare("SELECT [qn] FROM question_apt_easy");
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

