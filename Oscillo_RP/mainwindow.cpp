#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tpw(nullptr)
{
    ui->setupUi(this);
    tpw=new TcpParameterWindow(this);
    connect(ui->actionTCP_parameters, SIGNAL(triggered()), this, SLOT(tpw_show()));
    connect(tpw, SIGNAL(rejected()), this, SLOT(set_connection()));

    ui->ColorBox->setStyleSheet("QLineEdit { background-color: red; }");
    ui->Label_connection->setText("Not connected");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tpw_show()
{
    tpw->show();
}

void MainWindow::set_connection()
{
    if (tpw->connected==true)
    {
        ui->ColorBox->setStyleSheet("QLineEdit { background-color: green; }");
        ui->Label_connection->setText("Connected");
    }
    else
    {
        ui->ColorBox->setStyleSheet("QLineEdit { background-color: red; }");
        ui->Label_connection->setText("Not connected");
    }
}
