#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"
#include <QAction>
#include <QColor>
#include <QTimerEvent>
#include <vector>


class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void drawforma(int f, bool mousePressed);


    int nx,ny,nz;
    int sizeX,sizeY,sizeZ;
    int rad,radX,radY,radZ;
    int eixo;
    unsigned int plano;
    int r, g, b, a;



    private:
    Sculptor *matriz;
    vector<vector<Voxel>> fig;

     bool mousePressed;
     int mouseX;
     int mouseY;
     int pX;
     int pY;
     int pZ;
     int sizeSquare;
     unsigned int f;

    signals:

     void mX(int);
     void mY(int);
     void cX(int);
     void cY(int);
     void mL(int);
     void mC(int);

    public slots:

    void Altera_X(int size);
    void Altera_Y(int size);
    void Altera_Z(int size);
    void Altera_R(int raio);
    void Altera_Rx(int radx);
    void Altera_Ry(int rady);
    void Altera_Rz(int radz);
    void AlteraR(int red);
    void AlteraG(int green);
    void AlteraB(int blue);
    void AlteraAlfa(int alpha);
    void AlteraPlano(int plano_);
    void SalvaOff();
    void Alteraf1();
    void Alteraf2();
    void Alteraf3();
    void Alteraf4();
    void Alteraf5();
    void Alteraf6();
    void Alteraf7();
    void Alteraf8();

};

#endif // PLOTTER_H
