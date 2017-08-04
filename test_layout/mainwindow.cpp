#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lut.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->VSlider1->setMinimum(0);
    ui->VSlider1->setMaximum(100);
    ui->VSlider1->setValue(50);
    ui->VSlider2->setMinimum(0);
    ui->VSlider2->setMaximum(100);
    ui->VSlider2->setValue(50);

    def.limit(-1.0,1.0);

    setupColorMapDemo(ui->customPlot);
    ui->customPlot->replot();

    ui->Text_minsig->setMaxLength(5); //set number of characters than are display
    ui->Text_minsat->setMaxLength(5);
    ui->Text_maxsig->setMaxLength(4);
    ui->Text_maxsat->setMaxLength(4);

    ui->Text_maxsat->setText(ui->Text_maxsig->text());
    ui->Text_minsat->setText(ui->Text_minsig->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_VSlider1_sliderMoved(int position)
{
    double sat = (100.0-position)*def.sigmin/50.0;
    ui->Text_minsat->setText(QString::number(sat));
    def.limit(sat,def.xmax);
    setupColorMapDemo(ui->customPlot);
    ui->customPlot->replot();
}

void MainWindow::on_VSlider2_sliderMoved(int position)
{
    double sat = position*def.sigmax/50.0;
    ui->Text_maxsat->setText(QString::number(sat));
    def.limit(def.xmin,sat);
    setupColorMapDemo(ui->customPlot);
    ui->customPlot->replot();
}

void MainWindow::setupColorMapDemo(QCustomPlot *customPlot)
{

  // configure axis rect:
  //customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
  customPlot->axisRect()->setupFullAxesBox(true);
  //customPlot->xAxis->setLabel("x");
  //customPlot->yAxis->setLabel("y");

  // set up the QCPColorMap:
  QCPColorMap *colorMap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
  colorMap->setInterpolate(false); // no interpolation between points
  int nx = 50;
  int ny = 50;
  colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
  colorMap->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions
  // now we assign some data, by accessing the QCPColorMapData instance of the color map:
  double x, y, z;
  int zi;
  for (int xIndex=0; xIndex<nx; ++xIndex)
  {
    for (int yIndex=0; yIndex<ny; ++yIndex)
    {
      colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
      double r = 3*qSqrt(x*x+y*y)+1e-2;
      z = 2*x*(qCos(r+2)/r-qSin(r+2)/r); // the B field strength of dipole radiation (modulo physical constants)
      zi = def.linear(z); //"LUT" play with gray scale
      def.siglim(z); //define maximum and minimum value of the signal
      colorMap->data()->setCell(xIndex, yIndex, zi);
    }
  }
  ui->Text_minsig->setText(QString::number(def.sigmin));
  ui->Text_maxsig->setText(QString::number(def.sigmax));

  // add a color scale:
  QCPColorScale *colorScale = new QCPColorScale(customPlot);
  QCPRange range(0.0, def.maxlut); //range of the display for 8 bits 256 gray levels
  //customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
  //colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
  colorScale->setDataRange(range); //set range
  colorMap->setColorScale(colorScale); // associate the color map with the color scale
  //colorScale->axis()->setLabel("Magnetic Field Strength");

  // set the color gradient of the color map to one of the presets:
  colorMap->setGradient(QCPColorGradient::gpGrayscale); //colormap in gray scale
  // we could have also created a QCPColorGradient instance and added own colors to
  // the gradient, see the documentation of QCPColorGradient for what's possible.

  // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
  //colorMap->rescaleDataRange();

  // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
  QCPMarginGroup *marginGroup = new QCPMarginGroup(customPlot);
  customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
  colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

  // rescale the key (x) and value (y) axes so the whole color map is visible:
  customPlot->xAxis->setRange(-4.0, 4.0);
  customPlot->yAxis->setRange(-4.0, 4.0);
  customPlot->yAxis->setScaleRatio(customPlot->xAxis, 1.0); //to have same scale on x and y
  //customPlot->rescaleAxes();
}

void MainWindow::on_BitText_textChanged(const QString &arg1)
{
    def.bitNumber(arg1.toInt());
}
