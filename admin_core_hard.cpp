#include "admin_core_hard.h"
#include "ui_admin_core_hard.h"
#include "admin_homepage.h"
#include "ui_admin_homepage.h"

#include <QSqlDatabase>

admin_core_hard::admin_core_hard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_core_hard)
{
    ui->setupUi(this);
    QSqlDatabase qn_drop=QSqlDatabase::addDatabase("QSQLITE");
    qn_drop.setDatabaseName("C:/Users/Karishhaju/OneDrive/Desktop/QT-Quiz_Game-main (2)/QT-Quiz_Game-main/qn_drop.db");

    if(!qn_drop.open())
     ui->qn_db_status->setText("Not found");
    else
     ui->qn_db_status->setText("Connected");
}

admin_core_hard::~admin_core_hard()
{
    delete ui;
}

void admin_core_hard::on_submitbtn_clicked()
{
    QString qn_editor=ui->qn_editor->text();
    QString qn_number=ui->qn_number->text();
    QString choice_1=ui->choice_1->text();
    QString choice_2=ui->choice_2->text();
    QString choice_3=ui->choice_3->text();
    QString choice_4=ui->choice_4->text();
    QString crt_choice=ui->comboBox->currentText();

    //QSqlDatabase qn_drop
    //if(!qn_drop.isOpen())
    //qDebug()<<"DB is Connected is failed";

    QSqlQuery qry_qn;
    qry_qn.prepare("insert into question_core_hard(qn,qn_no,choice_1,choice_2,choice_3,choice_4,crt_choice)values ('"+qn_editor+"','"+qn_number+"','"+choice_1+"','"+choice_2+"','"+choice_3+"','"+choice_4+"','"+crt_choice+"')");
    if(qry_qn.exec())
    {
        QMessageBox::information(this,"Data stored","Question Dropped");
        ui->qn_number->clear();
        ui->qn_editor->clear();
        ui->choice_1->clear();
        ui->choice_2->clear();
        ui->choice_3->clear();
        ui->choice_4->clear();
    }
    else
        QMessageBox::information(this,"Data stored","Question Drop Unsuccessful");
}


void admin_core_hard::on_quit_clicked()
{
    QApplication::quit();
}

