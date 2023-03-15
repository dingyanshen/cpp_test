//将图形基元（如线段、方格、圆、球、圆锥）组成继承体系，
//并将基类的打印函数和输入数据函数定义为虚函数，并在main函数中调用

#include<iostream>
using namespace std;
class Figure
{    public:
    virtual void draw() const=0;
    virtual void input_data()=0;
};
class Rectangle: public Figure
{
    protected:
        double left,top,right,bottom;
    public:
        void draw() const
        {    //...... //画矩形
            cout<<"Rectangle:"<<left<<","<<top<<";"<<right<<","<<bottom<<endl;
        }
        void input_data()
        {    cout << "请输入矩形的左上角和右下角坐标 (x1,y1,x2,y2) ：";
            cin >> left >> top >> right >> bottom;
        }
        double area() const
        { return (bottom-top)*(right-left); }
};
const double PI=3.1416;
class Circle: public Figure
{
    protected:
        double x,y,r;
    public:
        void draw() const
        {    //...... //画圆
            cout<<"Circle:"<<x<<","<<y<<":"<<r<<endl;
        }
        void input_data()
        {    cout << "请输入圆的圆心坐标和半径 (x,y,r) ：";
            cin >> x >> y >> r;
        }
        double area() const { return r*r*PI; }
};
class Line: public Figure
{
    protected:
        double x1,y1,x2,y2;
    public:
        void draw() const
        {    //...... //画线
            cout<<"Line:"<<x1<<","<<y1<<":"<<x2<<","<<y2<<endl;
        }
        void input_data()
        {    cout << "请输入线段的起点和终点坐标 (x1,y1,x2,y2) ：";
            cin >> x1 >> y1 >> x2 >> y2;
        }
};
class Sphere:public Figure{
    protected:
        double x,y,z,r;
    public:
        void draw() const
        {    //
            cout<<"Sphere:"<<x<<","<<y<<","<<z<<":"<<r<<endl;
        }
        void input_data()
        {    cout << "请输入球的球心坐标和半径 (x,y,z,r) ：";
            cin >> x >> y >> z>> r;
        }
};
class Cone:public Figure{
    protected:
        double x,y,z,a,b,c,r;
    public:
        void draw() const
        {    //...... //画
            cout<<"Cone:"<<a<<","<<b<<","<<c<<","<<x<<","<<y<<","<<z<<":"<<r<<endl;
        }
        void input_data()
        {    cout << "请输入锥形的顶点坐标，圆心坐标和半径 (a,b,c,x,y,z,r) ：";
            cin >>a>>b>>c>> x >> y >> z>> r;
        }
};


int  main(){
    const int MAX_NUM_OF_FIGURES=3;
    Figure *figures[MAX_NUM_OF_FIGURES];
    int count=0;
    //图形数据的输入：
    for (count=0; count<MAX_NUM_OF_FIGURES;    count++)
    {    int shape;
        do
        {    cout << "请输入图形的种类(0：线段，1：矩形，2：圆，3：球形，4：圆锥，-1：结束)：";
            cin >> shape;
        } while (shape < -1 || shape > 4);
        if (shape == -1) break;
        switch (shape)
        {    case 0: //线
            figures[count] = new Line;    break;
            case 1: //矩形
            figures[count] = new Rectangle; break;
            case 2: //圆
            figures[count] = new Circle; break;
            case 3://球形
            figures[count] = new Sphere; break;
            case 4://圆锥
            figures[count] = new Cone; break;
        }
        figures[count]->input_data(); //动态绑定到相应类的input_data
    }
    //图形的输出：
    for (int i=0; i<count; i++)
        figures[i]->draw();
    //通过动态绑定调用相应类的draw。
    return 0;
}
