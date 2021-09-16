#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QtDebug>
#include <QMessageBox>
#include <QDialog>
#include <QString>
#include <QProcess>
#include <vector>
#include <iostream>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) : QWidget(parent){
        nx = 50; ny = 50; nz=50;
        matriz = new Sculptor(nx,ny,nz);

        eixo=0; plano=1;
        sizeX=0; sizeY=0; sizeZ=0; rad=0;radX=0;radY=0;radZ=0;
        r = 1; g=1; b=1; a = 255;
        f=1;
    }

    void Plotter::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        QPen pen;
        QBrush brush;
        pen.setColor(QColor(0,0,0));
        pen.setWidth(2);

        painter.setPen(pen);
        brush.setColor(QColor(255,255,255));
        brush.setStyle(Qt::SolidPattern);

        painter.setBrush(brush);
        fig.clear();
        fig= matriz ->readMx(eixo,plano);

        int dim1 = width()/fig[0].size();
        int dim2 = height()/fig.size();

        if(dim1>dim2){
            sizeSquare=dim2;
        }
        else if(dim2>=dim1) {
            sizeSquare=dim1;
        }


        for(unsigned int i =0; i<fig.size(); i++){
            for(unsigned int j =0; j<fig[0].size(); j++){
                painter.drawRect(i*sizeSquare,j*sizeSquare,sizeSquare, sizeSquare);
            }
        }

        for(unsigned int i=0; i<fig.size();i++){
           for(unsigned int j=0; j<fig[0].size();j++){
                if(fig[i][j].isOn){
                        brush.setColor(QColor(fig[i][j].r,fig[i][j].g,fig[i][j].b,fig[i][j].a));
                        brush.setStyle(Qt::SolidPattern);
                        painter.setBrush(brush);
                        int xcenter =i*sizeSquare;
                        int ycenter =j*sizeSquare;
                        painter.drawEllipse(xcenter,ycenter,sizeSquare,sizeSquare);
                }
           }
        }

    }

    void Plotter::mouseMoveEvent(QMouseEvent *event){
        emit mX(event->x());
        emit mY(event->y());

        mouseX = (event->x())/sizeSquare;
        mouseY = (event->y())/sizeSquare;

        switch(plano){
        case 1:
            pX=mouseX;
            pY=mouseY;
            pZ=eixo;
        break;
        case 2:
            pX=mouseY;
            pY=eixo;
            pZ=mouseX;
        break;
        case 3:
            pX=eixo;
            pY=mouseX;
            pZ=mouseY;
        break;
        case 4:
            pX=mouseY;
            pY=ny-1-mouseX;
            pZ=eixo;
        break;
        case 5:
            pX=nx-1-mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 6:
            pX=eixo;
            pY=mouseY;
            pZ=nz-1-mouseX;
        break;
        case 7:
            pX=nx-1-mouseX;
            pY=ny-1-mouseY;
            pZ=eixo;
        break;
        case 8:
            pX=nx-1-mouseY;
            pY=eixo;
            pZ=nz-1-mouseX;
        break;
        case 9:
            pX=eixo;
            pY=ny-1-mouseX;
            pZ=nz-1-mouseY;
        break;
        case 10:
            pX=nx-1-mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 11:
            pX=mouseX;
            pY=eixo;
            pZ=nz-1-mouseY;
        break;
        case 12:
            pX=eixo;
            pY=ny-1-mouseY;
            pZ=mouseX;
        break;
        case 13:
            pX=mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 14:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 15:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        case 16:
            pX=mouseX;
            pY=nx-1-mouseY;
            pZ=eixo;
        break;
        case 17:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 18:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        case 19:
            pX=nx-mouseX;
            pY=ny-mouseY;
            pZ=eixo;
        break;
        case 20:
            pX=mouseY;
            pY=eixo;
            pZ=mouseX;
        break;
        case 21:
            pX=eixo;
            pY=mouseX;
            pZ=mouseY;
        break;
        case 22:
            pX=mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 23:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 24:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        }
        emit mL(pX+1);
        emit mC(pY+1);

        Plotter::drawforma(f,mousePressed);


    }

    void Plotter::mousePressEvent(QMouseEvent *event){
      if(event->button() == Qt::LeftButton){
        emit cX(event->x());
        emit cY(event->y());
        mousePressed = true;
        mouseX = (event->x())/sizeSquare;
        mouseY = (event->y())/sizeSquare;

        switch(plano){
        case 1:
            pX=mouseX;
            pY=mouseY;
            pZ=eixo;
        break;
        case 2:
            pX=mouseY;
            pY=eixo;
            pZ=mouseX;
        break;
        case 3:
            pX=eixo;
            pY=mouseX;
            pZ=mouseY;
        break;
        case 4:
            pX=mouseY;
            pY=ny-1-mouseX;
            pZ=eixo;
        break;
        case 5:
            pX=nx-1-mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 6:
            pX=eixo;
            pY=mouseY;
            pZ=nz-1-mouseX;
        break;
        case 7:
            pX=nx-1-mouseX;
            pY=ny-1-mouseY;
            pZ=eixo;
        break;
        case 8:
            pX=nx-1-mouseY;
            pY=eixo;
            pZ=nz-1-mouseX;
        break;
        case 9:
            pX=eixo;
            pY=ny-1-mouseX;
            pZ=nz-1-mouseY;
        break;
        case 10:
            pX=nx-1-mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 11:
            pX=mouseX;
            pY=eixo;
            pZ=nz-1-mouseY;
        break;
        case 12:
            pX=eixo;
            pY=ny-1-mouseY;
            pZ=mouseX;
        break;
        case 13:
            pX=mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 14:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 15:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        case 16:
            pX=mouseX;
            pY=nx-1-mouseY;
            pZ=eixo;
        break;
        case 17:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 18:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        case 19:
            pX=nx-mouseX;
            pY=ny-mouseY;
            pZ=eixo;
        break;
        case 20:
            pX=mouseY;
            pY=eixo;
            pZ=mouseX;
        break;
        case 21:
            pX=eixo;
            pY=mouseX;
            pZ=mouseY;
        break;
        case 22:
            pX=mouseY;
            pY=mouseX;
            pZ=eixo;
        break;
        case 23:
            pX=mouseX;
            pY=eixo;
            pZ=mouseY;
        break;
        case 24:
            pX=eixo;
            pY=mouseY;
            pZ=mouseX;
        break;
        }
        emit mL(pX+1);
        emit mC(pY+1);

        Plotter::drawforma(f,mousePressed);
      }
    }

    void Plotter::mouseReleaseEvent(QMouseEvent *event)
    {
        if(event->button() == Qt::LeftButton){
           mousePressed = false;
        }
    }

    void Plotter::drawforma(int f, bool mousePressed){

      if(mousePressed){
        if(f == 1)
        {
           matriz->setColor(r,g,b,a);
           matriz->putVoxel(pX,pY,pZ);
        }
        if(f == 2)
        {
           matriz->cutVoxel(pX,pY,pZ);
        }
        if(f == 3)
        {
            matriz->setColor(r,g,b,a);
            matriz->putBox(pX,(pX+sizeX),pY,(pY+sizeY),pZ,(pZ+sizeZ));

        }
        if(f == 4)
        {
           matriz->cutBox(pX,(pX+sizeX),pY,(pY+sizeY),pZ,(pZ+sizeZ));
        }
        if(f == 5)
        {
            matriz->setColor(r,g,b,a);
            matriz->putSphere(pX,pY,pZ,rad);

        }
        if(f == 6)
        {
           matriz->cutSphere(pX,pY,pZ,rad);
        }
        if(f == 7)
        {
            matriz->setColor(r,g,b,a);
            matriz->putEllipsoid(pX,pY,pZ,radX,radY,radZ);

        }
        if(f == 8)
        {
           matriz->cutEllipsoid(pX,pY,pZ,radX,radY,radZ);
        }
        repaint();
        }
    }

    void Plotter::AlteraR(int red)
    {
        r = red;
    }
    void Plotter::AlteraG(int green)
    {
        g = green;
    }
    void Plotter::AlteraB(int blue)
    {
        b = blue;
    }
    void Plotter::AlteraAlfa(int alpha)
    {
        a = alpha;
    }

    void Plotter::Altera_X(int size)
    {
        sizeX=size;
    }
    void Plotter::Altera_Y(int size)
    {
        sizeY=size;
    }
    void Plotter::Altera_Z(int size)
    {
        sizeZ=size;
    }
    void Plotter::Altera_R(int raio)
    {
        rad=raio;
    }
    void Plotter::Altera_Rx(int radx)
    {
        radX=radx;
    }
    void Plotter::Altera_Ry(int rady)
    {
        radY=rady;
    }
    void Plotter::Altera_Rz(int radz)
    {
        radZ=radz;
    }
    void Plotter::AlteraPlano(int plano_)
    {
        eixo = plano_;
        repaint();
    }



    void Plotter::Alteraf1() //PV
    {
        f = 1;


    }
    void Plotter::Alteraf2()
    {
        f = 2;

    }
    void Plotter::Alteraf3()
    {
        f = 3;

    }
    void Plotter::Alteraf4()
    {
        f = 4;

    }
    void Plotter::Alteraf5()
    {
        f = 5;

    }
    void Plotter::Alteraf6()
    {
        f = 6;

    }
    void Plotter::Alteraf7()
    {
        f = 7;

    }
    void Plotter::Alteraf8()
    {
        f = 8;

    }

    void Plotter::SalvaOff()
    {
        matriz->writeOFF("desenho.off");

    }



