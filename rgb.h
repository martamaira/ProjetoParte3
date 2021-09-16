#ifndef RGB_H
#define RGB_H

#include <QWidget>

class RGB : public QWidget
{
    Q_OBJECT
public:
    explicit RGB(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:

    void setR(int _r);
    void setG(int _g);
    void setB(int _b);
    void setA(int _a);
private:
    int r,g,b,a;
};


#endif // RGB_H
