#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QListWidget>
#include<QDebug>

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

void MainWindow::on_encryptAddFileButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open File");

    ui->encryptListWidget->addItems(fileNames);

}

void MainWindow::on_encryptRemoveFile_clicked()
{    
    // To Remove Single File
    //ui->encryptListWidget->takeItem(ui->encryptListWidget->currentRow());

    // To Remove Multiple File custom algo

    qDeleteAll(ui->encryptListWidget->selectedItems());
}

void MainWindow::on_encryptKeyChooserButton_clicked()
{
    QString vFileName = QFileDialog::getOpenFileName(this,"Select Encryption Key","","Key File (*.key)");

    ui->encryptKeyEdit->setText(vFileName);
}

void MainWindow::on_decryptAddFileButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open File","","Encrypt File(*.encrypt)");

    ui->decryptListWidget->addItems(fileNames);

}

void MainWindow::on_decryptRemoveFile_clicked()
{
        qDeleteAll(ui->decryptListWidget->selectedItems());
}

void MainWindow::on_decryptKeyChooserButton_clicked()
{
    QString vFileName = QFileDialog::getOpenFileName(this,"Select Encryption Key","","Key File (*.key)");

    ui->decryptKeyEdit->setText(vFileName);
}


void MainWindow::on_encrptButton_clicked()
{
    for(int i=0 ; i<ui->encryptListWidget->count(); i++)
    {
        qDebug() << ui->encryptListWidget->item(i)->text();
    }
}

void MainWindow::on_decryptButton_clicked()
{
    for(int i=0 ; i<ui->decryptListWidget->count(); i++)
    {
        qDebug() << ui->decryptListWidget->item(i)->text();
    }
}
