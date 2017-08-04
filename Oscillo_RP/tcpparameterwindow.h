#ifndef TCPPARAMETERWINDOW_H
#define TCPPARAMETERWINDOW_H

#include <QDialog>
#include "./src_RP/TCP_API.h"

namespace Ui {
class TcpParameterWindow;
}

class TcpParameterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TcpParameterWindow(QWidget *parent = 0);
    ~TcpParameterWindow();
    bool connected;
    void connection_state(int err);

private slots:
    void on_ButtonDeconnexion_clicked();
    void on_ButtonConnexion_clicked();

private:
    Ui::TcpParameterWindow *ui;
    SOCKET *sock;
};


#endif // TCPPARAMETERWINDOW_H
