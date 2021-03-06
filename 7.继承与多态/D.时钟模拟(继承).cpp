/*
题目描述

定义计数器类，包含保护数据成员value,公有函数increment计数加1。

定义循环计算器继承计数器类，增加私有数据成员：最小值min_value，最大值max_value,

重写公有函数increment，使得value在min_value~max_value区间内循环+1。

定义时钟类，数据成员是私有循环计数器对象小时hour、分钟minute、秒second，公有函数time(int s)计算当前时间经过s秒之后的时间，即hour,minute,second的新value值。

定义时钟类对象，输入当前时间和经过的秒数,调用time函数计算新时间。

根据题目要求，增加必要的构造函数、析构函数和其他所需函数。

因为clock是系统内置函数，为了避免重名，请不要使用clock作为类名或者函数名

输入

第一行测试次数n

2行一组，第一行为当前时间（小时 分钟 秒），第二行为经过的秒数。

输出

输出n行

每行对应每组当前时间和经过秒数后计算得到的新时间（小时：分钟：秒）。

样例输入

2
8 19 20
20
23 30 0
1801
样例输出

8:19:40
0:0:1

*/
#include <iostream> 

#include <cstring>
using namespace std;

class cnt{
protected:
	int value;
public:
	cnt(){
		value=0;
	}
	cnt(int v){
		value=v;
	}
	virtual int increment(){
		return 0;
	};
};

class cnt1:public cnt{
protected:
	int min_value,max_value;
public:
	cnt1(){
	}
	cnt1(int v,int min,int max){
		value = v;
		min_value=min;
		max_value=max;
	}
	int increment(){
		value++;
		if(value==max_value){
			value=min_value;
			return 1;
		}
        return;
	}
	int get(){return value;}
};

class timeclock{
private:
	cnt1 hour,minute,second;
public:
	timeclock(){}
	timeclock(int h,int m,int s):hour(h,0,24),minute(m,0,60),second(s,0,60){}
	void time(int s){
		while(s--){
			if(second.increment()==1){
				if(minute.increment()==1){
					hour.increment();
				}
			}
		}
		cout << hour.get() <<':'<< minute.get() <<':'<< second.get() <<endl;
	}
};

int main(){
    int n,h,m,s,sec;
    cin >> n;
    while(n--)
    {
        cin >> h >> m >> s>> sec;
         
        timeclock c(h,m,s);
        c.time(sec);
    }
	return 0;
}


