#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new Model(this);
    updateView();

    connect(ui->spinBoxA, QOverload<int>::of(&QSpinBox::valueChanged), model, &Model::setA);
    connect(ui->sliderA, &QSlider::valueChanged, model, &Model::setA);
    connect(ui->lineEditA, &QLineEdit::editingFinished, this, [this](){
        model->setA(ui->lineEditA->text().toInt());
    });

    connect(ui->spinBoxB, QOverload<int>::of(&QSpinBox::valueChanged), model, &Model::setB);
    connect(ui->sliderB, &QSlider::valueChanged, model, &Model::setB);
    connect(ui->lineEditB, &QLineEdit::editingFinished, this, [this](){
        model->setB(ui->lineEditB->text().toInt());
    });

    connect(ui->spinBoxC, QOverload<int>::of(&QSpinBox::valueChanged), model, &Model::setC);
    connect(ui->sliderC, &QSlider::valueChanged, model, &Model::setC);
    connect(ui->lineEditC, &QLineEdit::editingFinished, this, [this](){
        model->setC(ui->lineEditC->text().toInt());
    });

    connect(model, &Model::dataChanged, this, &MainWindow::updateView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateView()
{
    ui->spinBoxA->setValue(model->getA());
    ui->sliderA->setValue(model->getA());
    ui->lineEditA->setText(QString::number(model->getA()));

    ui->spinBoxB->setValue(model->getB());
    ui->sliderB->setValue(model->getB());
    ui->lineEditB->setText(QString::number(model->getB()));

    ui->spinBoxC->setValue(model->getC());
    ui->sliderC->setValue(model->getC());
    ui->lineEditC->setText(QString::number(model->getC()));

    updateCount++;
    ui->labelCounter->setText(QString::number(updateCount));
}
