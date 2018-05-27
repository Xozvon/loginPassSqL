#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSQL()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Qt\\SQLiteStudio\\io.db");
    if(db.open()){
        qDebug() << "LOAD CHEATS FOR MINECRAFT";
    }
    else{
        qDebug() << "ERROR CONNECT CHEATS";
    }
}

void MainWindow::insert(Users user)
{
    QSqlQuery query(db);
    int prepare = query.prepare("INSERT INTO loginPass(login,password) "
                                "VALUES (?,?)");
    if(!prepare){
        qDebug() << "ERROR" << query.lastError();
    }
    else{
    query.bindValue(0,user.login);
    query.bindValue(1,user.password);
    if(query.exec() == true){
        qDebug() << "SUCESS";
    }
    else{
        qDebug() << "BAD";
    }
    }
}


void MainWindow::on_pushButton_clicked()
{
    Users u(ui->lineLogin_2->text(),ui->linePassword_2->text());
    if(ui->checkBox->isChecked()){
    this->insert(u);
            int m = QMessageBox::information(this,"GYD HLOPCHE","“€ «¿–≈√¿À—ﬂ");

    }
    else{
        int m = QMessageBox::warning(0,"ERROR","“€ ¡Œ“ ﬂ Õ≈ œ”Ÿ”");

    }
}
