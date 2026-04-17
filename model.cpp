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
