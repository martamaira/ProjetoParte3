#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "plotter.h"
#include <cstdlib>
#include "QMessageBox"
#include "QProcess"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSliderX->setMaximum(ui->widgetP->nx-1);
    ui->horizontalSliderY->setMaximum(ui->widgetP->ny-1);
    ui->horizontalSliderZ->setMaximum(ui->widgetP->nz-1);
    ui->horizontalSliderRaio->setMaximum(ui->widgetP->nx/2 -1);
    ui->horizontalSliderRx->setMaximum(ui->widgetP->nx/2 -1);
    ui->horizontalSliderRy->setMaximum(ui->widgetP->ny/2 -1);
    ui->horizontalSliderRz->setMaximum(ui->widgetP->nz/2 -1);

    ui->horizontalSliderR->setMaximum(255);
    ui->horizontalSliderG->setMaximum(255);
    ui->horizontalSliderB->setMaximum(255);
    ui->horizontalSliderA->setMaximum(255);
    ui->horizontalSliderR->setMinimum(1);
    ui->horizontalSliderG->setMinimum(1);
    ui->horizontalSliderB->setMinimum(1);
    ui->horizontalSliderA->setMinimum(1);
    ui->horizontalSliderR->setSliderPosition(1);
    ui->horizontalSliderG->setSliderPosition(1);
    ui->horizontalSliderB->setSliderPosition(1);
    ui->horizontalSliderA->setSliderPosition(1);

        connect(ui->actionPutVoxel,
                SIGNAL(triggered(bool)),
                ui->widgetP,
                SLOT(Alteraf1()));
        connect(ui->actioncutVoxel,
                SIGNAL(triggered(bool)),
                ui->widgetP,
                SLOT(Alteraf2()));
         connect(ui->actionputBox,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf3()));
         connect(ui->actioncutBox,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf4()));
         connect(ui->actionPutSphere,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf5()));
         connect(ui->actionCutSphere,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf6()));
         connect(ui->actionPutEllipsoid,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf7()));
         connect(ui->actionCutEllipsoid,
                 SIGNAL(triggered(bool)),
                 ui->widgetP,
                 SLOT(Alteraf8()));
         connect(ui->horizontalSliderX,
                 SIGNAL(valueChanged(int)),
                  ui->widgetP,
                 SLOT(Altera_X(int)));

             connect(ui->horizontalSliderY,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_Y(int)));

             connect(ui->horizontalSliderZ,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_Z(int)));

             connect(ui->horizontalSliderRaio,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_R(int)));

             connect(ui->horizontalSliderRx,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_Rx(int)));

             connect(ui->horizontalSliderRy,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_Ry(int)));

             connect(ui->horizontalSliderRz,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(Altera_Ry(int)));

             connect(ui->horizontalSliderR,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(AlteraR(int)));

             connect(ui->horizontalSliderG,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(AlteraG(int)));

             connect(ui->horizontalSliderB,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(AlteraB(int)));

             connect(ui->horizontalSliderA,
                     SIGNAL(valueChanged(int)),
                     ui->widgetP,
                     SLOT(AlteraAlfa(int)));
             connect(ui->actionSalvar,
                         SIGNAL(triggered(bool)),
                         ui->widgetP,
                         SLOT(SalvaOff()));
             connect(ui->actionquit,
                         SIGNAL(triggered(bool)),
                         ui->widgetP,
                         SLOT(quit()));

             connect(ui->horizontalSlidereixo,
                         SIGNAL(triggered(bool)),
                         ui->widgetP,
                         SLOT(AlteraPlano()));

             connect(ui->pushButtonQuit,
                     SIGNAL(clicked(bool)),
                     this,
                     SLOT(quit()));







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Desenho()
{

    ui->horizontalSliderX->setMaximum(ui->widgetP->nx-1);
    ui->horizontalSliderY->setMaximum(ui->widgetP->ny-1);
    ui->horizontalSliderZ->setMaximum(ui->widgetP->nz-1);
    ui->horizontalSliderRaio->setMaximum(ui->widgetP->nx/2 -1);
    ui->horizontalSliderRx->setMaximum(ui->widgetP->nx/2 -1);
    ui->horizontalSliderRy->setMaximum(ui->widgetP->ny/2 -1);
    ui->horizontalSliderRz->setMaximum(ui->widgetP->nz/2 -1);
    ui->horizontalSlidereixo->setMaximum(ui->widgetP->nz -1);

}

void MainWindow::quit()
{
    exit(0);
}





