#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "./src_RP/TCP_API.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void init_settings(char set[]);
    int R0;
    int Rf;
    int Npoint;
    SOCKET sock;

private slots:
    void get_setting(SOCKET sock);

signals:
    void setting_done();

private:
    Ui::Settings *ui;
    int dec;
    int Nline;
    int sector;
    int mode;

    void enable_lineedit();
    void disable_lineedit();
};

#endif // SETTINGS_H
