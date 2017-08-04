#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpparameterwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void tpw_show();
    void set_connection();

private:
    Ui::MainWindow *ui;
    TcpParameterWindow *tpw;
};

#endif // MAINWINDOW_H
