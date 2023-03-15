#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<QPainter>
#include<iostream>
#include<QMouseEvent>
#include<QFile>
#include<QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       w=800;
       h=800;
       isDrawing=false;
       isStarted=false;
       p=QPixmap(w,h);

       this->resize(w,h);
       p.fill(Qt::white);
       ptemp=p;
       t=line;
       update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadButton_clicked()
{
    p=QPixmap(w,h);
    p.fill(Qt::white);
    ptemp=p;
    data.clear();


    QFile outFile("out.txt");
    if (!outFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream of(&outFile);
    int t;
    int x1,y1,x2,y2;
    while(!of.atEnd()){
        of>>t>>x1>>y1>>x2>>y2;
        data.push_back(Graph(graphType(t),x1,y1,x2,y2));
    }
    QPainter painter(&p);
    for(auto i: data){
//cout<<"draw:"<<i.t<<" "<<i.x1<<" "<<i.y1<<" "<<i.x2<<
  //    " "<<i.y2<<"\n";
        switch (i.t) {
        case line:
            painter.drawLine(i.x1,i.y1,i.x2,i.y2);break;
        case rect1:
            painter.drawRect(i.x1,i.y1,i.x2-i.x1,i.y2-i.y1);break;

        }
    }
    outFile.close();
    isDrawing=false;
    isStarted=false;
    update();


}


void MainWindow::on_clearButton_clicked()
{
    p=QPixmap(w,h);
    p.fill(Qt::white);
    ptemp=p;
    data.clear();
    update();

}


void MainWindow::on_saveButton_clicked()
{
    QFile outFile("out.txt");
    if (!outFile.open(QIODevice::WriteOnly |QIODevice::Truncate| QIODevice::Text))
            return;
    QTextStream of(&outFile);
    for(auto i: data){
        of<<i.t<<" "<<i.x1<<" "<<i.y1<<" "<<i.x2<<" "<<
            i.y2<<" ";
      //  cout<<"save:"<<i.t<<" "<<i.x1<<" "<<i.y1<<" "<<i.x2<<
       //               i.y2<<"\n";
    }
    outFile.close();

}
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    auto i=event->pos();
    x2=i.x();
    y2=i.y();

    if(isStarted) {
        isDrawing=true;
        ptemp=p;
        QPainter painter(&ptemp);
        switch (t) {
        case line:
            painter.drawLine(x1,y1,x2,y2);break;
        case rect1:
            painter.drawRect(x1,y1,x2-x1,y2-y1);break;

        }
        //painter.drawLine(x1,y1,x2,y2);
    }
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    auto i=event->pos();
    isStarted=true;
    x1=i.x();
    y1=i.y();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    auto i=event->pos();
    x2=i.x();
    y2=i.y();
    QPainter painter(&p);
    switch (t) {
    case line:
        painter.drawLine(x1,y1,x2,y2);break;
    case rect1:
        painter.drawRect(x1,y1,x2-x1,y2-y1);break;

    }
    //painter.drawLine(x1,y1,x2,y2);
    data.push_back(Graph(t,x1,y1,x2,y2));
    update();
};
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if(isDrawing)
        painter.drawPixmap(0,0,ptemp);
    else
        painter.drawPixmap(0,0,p);

};

void MainWindow::on_lineButton_clicked()
{
    t=line;
}


void MainWindow::on_rectButton_clicked()
{
    t = rect1;
}

