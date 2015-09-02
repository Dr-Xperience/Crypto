#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_encryptAddFileButton_clicked();

    void on_encryptRemoveFile_clicked();

    void on_encryptKeyChooserButton_clicked();

    void on_encrptButton_clicked();

    void on_decryptAddFileButton_clicked();

    void on_decryptRemoveFile_clicked();

    void on_decryptKeyChooserButton_clicked();

    void on_decryptButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
