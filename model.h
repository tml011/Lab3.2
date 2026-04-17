#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QSettings>

class Model:public QObject
{
    Q_OBJECT

private:
    int a, b, c;
    QSettings *settings;

    void save();

public:
    explicit Model(QObject *parent = nullptr);
    int getA() const{return a;}
    int getB() const{return b;}
    int getC() const{return c;}

    void setA(int value);
    void setB(int value);
    void setC(int value);

signals:
    void dataChanged();
};
#endif // MODEL_H
