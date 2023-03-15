#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum graphType {line,rect1};
class Graph{
public:
    graphType t;
    int x1;
    int y1;
    int x2;
    int y2;
    Graph(graphType  t1, int x10,int y10,int x20,int y20){
        t=t1;
        x1=x10;
        y1=y10;
        x2=x20;
        y2=y20;
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_rectButton_clicked();

    void on_lineButton_clicked();

    void on_clearButton_clicked();

    void on_loadButton_clicked();

    void on_saveButton_clicked();


private:
    Ui::MainWindow *ui;
    int w;
    int h;
    QPixmap p,ptemp;
    int x1,y1,x2,y2;
    bool isDrawing;
    bool isStarted;
    QVector<Graph> data;
    graphType t;
};

#endif // MAINWINDOW_H


