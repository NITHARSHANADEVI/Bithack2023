#include "admin_apt_hard.h"
#include "ui_admin_apt_hard.h"
#include "admin_homepage.h"
#include "ui_admin_homepage.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

admin_apt_hard::admin_apt_hard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_apt_hard)
{
    ui->setupUi(this);
    QSqlDatabase qn_drop = QSqlDatabase::addDatabase("QSQLITE");
    qn_drop.setDatabaseName("C:/Users/Karishhaju/OneDrive/Desktop/QT-Quiz_Game-main (2)/QT-Quiz_Game-main/qn_drop.db");

    if (!qn_drop.open())
        ui->qn_db_status->setText("Not Found");
    else
        ui->qn_db_status->setText("Connected");
}

admin_apt_hard::~admin_apt_hard()
{
    delete ui;
}

void admin_apt_hard::on_submitbtn_clicked()
{
    QString qn_number = ui->qn_number->text();
    QString qn_editor = ui->qn_editor->text();
    QString choice_1 = ui->choice_1->text();
    QString choice_2 = ui->choice_2->text();
    QString choice_3 = ui->choice_3->text();
    QString choice_4 = ui->choice_4->text();
    QString crt_choice = ui->comboBox->currentText();

    QSqlQuery qry_qn;
    qry_qn.prepare("insert into question_apt_hard(qn_no, qn, choice_1, choice_2, choice_3, choice_4, crt_choice) values ('" + qn_number + "','" + qn_editor + "','" + choice_1 + "','" + choice_2 + "','" + choice_3 + "','" + choice_4 + "','" + crt_choice + "')");

    if (qry_qn.exec())
    {
        QMessageBox::information(this, "Data stored", "Question Dropped");
        ui->qn_number->clear();
        ui->qn_editor->clear();
        ui->choice_1->clear();
        ui->choice_2->clear();
        ui->choice_3->clear();
        ui->choice_4->clear();
    }
    else
        QMessageBox::information(this, "Data stored", "Question Drop Unsuccessful");
}

void admin_apt_hard::on_exportCSV_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save CSV File"), "", tr("CSV Files (*.csv)"));

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            QString line = stream.readLine();
            QStringList fields = line.split(",");

            QSqlQuery query;
            query.exec("insert into question_core_hard(qn_no,qn,choice_1,choice_2,choice_3,choice_4,crt_choice)");
            qDebug()<<fields;

            while (query.next())
            {
               QString qn_no= query.value(0).toString();
                QString qn = query.value(1).toString();
               QString choice1 = query.value(2).toString();
                QString choice2 = query.value(3).toString();
                QString choice3 = query.value(4).toString();
                QString choice4 = query.value(5).toString();
                QString crt_choice = query.value(6).toString();

                stream << qn_no << "," << qn << "," << choice1 << "," << choice2 << "," << choice3 << "," << choice4 << "," << crt_choice << "\n";

            }

            file.close();
            QMessageBox::information(this, "Export CSV", "Data exported to CSV file successfully.");
        }
        else
        {
            QMessageBox::critical(this, "Export CSV", "Could not create CSV file.");
        }
    }
}

void admin_apt_hard::on_quit_clicked()
{
    QApplication::quit();
}
