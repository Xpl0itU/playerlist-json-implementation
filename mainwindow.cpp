#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile inFile("C:/Users/samue/Documents/jsontest/test.json");
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = inFile.readAll();
        inFile.close();
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonArray value = json.array();
    int i = 0;
    for(auto _: value) {
        qDebug() << value[i].toObject().value("name").toString();
        qDebug() << bool(value[i].toObject().value("default").toInt());
        ui->comboBox->addItem(value[i].toObject().value("name").toString());
        if(bool(value[i].toObject().value("default").toInt()) == true) {
            ui->comboBox->setCurrentIndex(i);
        }
        i++;
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

