#include "model.h"

Model::Model(QObject *parent):QObject(parent)
{
    settings = new QSettings("MyCompany", "Lab3_MVC", this);

    a = settings->value("valueA", 0).toInt();
    b = settings->value("valueB", 50).toInt();
    c = settings->value("valueC", 100).toInt();
};

void Model::save()
{
    settings->setValue("valueA", a);
    settings->setValue("valueB", b);
    settings->setValue("valueC", c);

}

void Model::setA(int value)
{
    if (value < 0) value = 0;
    if (value > 100) value = 100;

    if (this ->a == value) return;

    this->a = value;
    if (a > b) b = a;
    if (b > c) c = b;

    save();
    emit dataChanged();
}

void Model::setB(int value)
{
    if (value < a) value = a;
    if (value > c) value = c;

    if (this->b == value) return;
    this->b = value;

    save();
    emit dataChanged();
}

void Model::setC(int value)
{
    if (value < 0) value = 0;
    if (value > 100) value = 100;

    if (this->c == value) return;

    this->c = value;
    if (c < b) b = c;
    if (b < a) a = c;

    save();
    emit dataChanged();
}
