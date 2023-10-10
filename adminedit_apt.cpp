#include "adminedit_apt.h"
#include "ui_adminedit_apt.h"
#include "admin_homepage.h"
#include "ui_admin_homepage.h"
#include <QFileDialog>

#include <QSqlDatabase>

Adminedit_apt::Adminedit_apt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminedit_apt)  
{
    ui->setupUi(this);     //db connection setup
    QSqlDatabase qn_drop=QSqlDatabase::addDatabase("QSQLITE");
    qn_drop.setDatabaseName("C:/Users/Karishhaju/OneDrive/Desktop/QT-Quiz_Game-main (2)/QT-Quiz_Game-main/qn_drop.db");

    if(!qn_drop.open())   //db status connection
     ui->qn_db_status->setText("Not found");
    else
     ui->qn_db_status->setText("Connected");

}

Adminedit_apt::~Adminedit_apt()
{
    delete ui;
}

void Adminedit_apt::on_submitbtn_clicked()  //on submit button clicked
{
    QString qn_editor=ui->qn_editor->text();
    QString qn_number =ui->qn_number->text();
    QString choice_1 =ui->choice_1->text();
    QString choice_2 =ui->choice_2->text();
    QString choice_3 =ui->choice_3->text();
    QString choice_4 =ui->choice_4->text();
    QString crt_choice=ui->comboBox->currentText();

//    QSqlDatabase qn_drop;
//    if(!qn_drop.isOpen())
//        qDebug()<<"DB is connceted is failed";

    QSqlQuery qry_qn;  //INSERTION QUERY
    qry_qn.prepare("insert into question_apt_easy(qn,qn_no,choice_1,choice_2,choice_3,choice_4,crt_choice)values ('"+qn_editor+"','"+qn_number+"','"+choice_1+"','"+choice_2+"','"+choice_3+"','"+choice_4+"','"+crt_choice+"')");
    if(qry_qn.exec())
    {
        QMessageBox::information(this,"Data Stored","Question Dropped");
        ui->qn_number->clear();
        ui->qn_editor->clear();
        ui->choice_1->clear();
        ui->choice_2->clear();
        ui->choice_3->clear();
        ui->choice_4->clear();

    }
    else
       QMessageBox::information(this,"Data Stored","Question Drop Unsuccessful");

}
void Adminedit_apt::on_quit_clicked()
{
    QApplication::quit();
}


void Adminedit_apt::on_import_btn_clicked()
{
    QString filename =QFileDialog::getOpenFileName(this,tr("Open file"),"C://","Äll files (*.*);;CSV(*.csv)");
    QMessageBox::information(this,tr("File name"),filename);
}

