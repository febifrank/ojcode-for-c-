/*
题目描述

定义一个列表类，该列表包含属性：数值列表（用长度为100的数组表示），数据长度（实际的数据个数）；包含的方法：初始化、插入、删除、打印，方法定义为：

1）初始化，接受外来参数，把数据保存在数值列表中，未使用的列表部分全部初始化为-1

2）插入，接受外来参数的插入位置和插入数值，插入位置从0开始计算，注意从插入位置开始，原有数据都要往后移动一位，且数据长度+1

3）删除，接受外来参数的删除位置，删除位置从0开始计算，注意从删除位置后一位开始，原有数据都要往前移动一位，且数据长度-1

4）打印，把包含的数据按位置顺序输出一行，数据之间单个空格隔开

使用类模板的方法，使得这个类支持整数int类型和浮点数double类型

输入

第一行先输入参数n表示有n个数据，接着输入n个整数

第二行输入两个参数，表示插入位置和插入数值，数值为整数

第三行输入删除位置

第四行先输入参数n表示有n个数据，接着输入n个浮点数

第五行输入两个参数，表示插入位置和插入数值，数值为浮点数

第六行输入删除位置

输出

针对头三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的整数数据

针对接着的三行输入，分别执行初始化、插入操作和删除操作，调用打印方法输出列表包含的浮点数数据

样例输入

5 11 22 33 44 55
2 888
4
5 1.1 2.2 3.3 4.4 5.5
2 88.8
3
样例输出

11 22 888 33 55
1.1 2.2 88.8 4.4 5.5

*/



#include <iostream>
using namespace std;
template<class type>
class list{
protected:
    type a[100];
    int l;
public:
    list(){
        int i =0;
        for(i=0;i<100;i++)a[i]=-1;
    }
    void set(){
        int i=0;
        cin>>l;
        for(i=0;i<l;i++){
            cin>>a[i];
        }
    }
    void insert(int loc, type x){
        int i = 0;
        type tem;
        type a2[100];
        for(i=loc;i<l;i++){
            a2[i]=a[i];
        }
        a[loc]=x;
        for(i=loc+1;i<l+1;i++){
            a[i]=a2[i-1];
        }

    }
    void rm(int loc){
        int i = 0;
        for (i=loc;i<l+1;i++){
            a[i]=a[i+1];
        }
    }
    void print(){
        int i =0;
        for(i=0;i<l;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    list<int> t1;
    t1.set();
    int a,b;
    cin>>a>>b;
    t1.insert(a,b);
    cin>>a;
    t1.rm(a);
    t1.print();
    
    list<float> t2;
    t2.set();
    float c;
    cin>>a>>c;
    t2.insert(a,c);
    cin>>a;
    t2.rm(a);
    t2.print();
    return 0;
}