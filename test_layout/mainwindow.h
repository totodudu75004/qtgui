#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "lut.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupColorMapDemo(QCustomPlot *customPlot);
    LUT def;

private slots:
    void on_VSlider1_sliderMoved(int position);

    void on_VSlider2_sliderMoved(int position);

    void on_BitText_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
