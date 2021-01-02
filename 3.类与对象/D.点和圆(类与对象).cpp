/*
题目描述

设计一个点类Point，包含属性：x坐标和y坐标，方法：设定坐标（SetPoint），获取x坐标（GetX），获取y坐标（GetY）

设计一个圆类Circle，包含属性：圆心坐标x和y、半径r；方法包括：

1. 设定圆心（SetCenter），设置圆心x坐标和y坐标

2. 设定半径（SetRadius），设置半径长度

3. 计算面积（getArea），计算公式：面积=3.14*r*r

4. 计算周长（getLength），计算公式：周长=2*3.14*r

5. 包含（Contain），判断一个圆是否包含一个点，计算圆心到这个点的距离，然后和半径做比较，大于则不包含，小于等于则包含

注意：提交代码时必须用注释划分出三个区域：类定义、类实现、主函数，如下

//-----类定义------

class XXX

{  // 写类定义代码

};

//----类实现------

void XXX::Process()

{ // 写类定义代码

};

//-----主函数-----

int main()

{

  //自定义一些变量

  //创建一个圆对象和一个点对象

 //输入圆对象和点对象的属性数值，并做初始化

 //输出圆的面积和圆的周长

//输出圆是否包含点，包含则输出yes，否则输出no

  return 0;

}

输入

第一行输入圆的三个参数：圆心的x和y坐标，半径

第二行输入点的两个参数：x和y坐标

输出

第一行输出圆的面积和周长，结果之间用空格隔开，输出精度到小数点后2位

第二行输出圆是否包含点，包含则输出yes，否则输出no

在C++中，输出指定精度的参考代码如下：

#include <iostream>

#include <iomanip> //必须包含这个头文件

using namespace std;

void main( )

{ double a =3.14;

  cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位

样例输入

1 1 1
2 2
样例输出

3.14 6.28
no

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point{
public:
 int GetX() {
  return x;
 }
 int GetY() {
  return y;
 }
 void SetX(){
  cin>>x;
 }
 void SetY(){
  cin>>y;
 } 
private:
 int x,y;
};

class Circle{
public:
 void SetCenter(){
  cin>>x;
  cin>>y;
 }
 void SetRadius(){
  cin>>r;
 }
 double getArea(){
  return 3.14*r*r;
 }
 double getLength(){
  return 2*3.14*r;
 }
 int GetX() {
  return x;
 }
 int GetY() {
  return y;
 }
 int GetR() {
  return r;
 }
private:
 int x,y,r;
};


int main(){
 Circle yuan;
 yuan.SetCenter();
 yuan.SetRadius();
 Point dian;
 dian.SetX();
 dian.SetY();
 cout<<fixed<<setprecision(2)<<yuan.getArea()<<" "<<yuan.getLength()<<endl;
 double dis = sqrt((dian.GetX()-yuan.GetX())*(dian.GetX()-yuan.GetX())+(dian.GetY()-yuan.GetY())*(dian.GetY()-yuan.GetY()));
 if (dis > yuan.GetR()){
  cout<<"no"<<endl;
 }
 else
  cout<<"yes"<<endl;
 return 0;
} 