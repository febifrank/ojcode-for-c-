/*
题目描述

江湖中有一个传言，只要倚天剑和屠龙刀中暗藏的秘密拼到一起，就能得到天下无敌的内功秘笈。设计一个函数模板，完成拼凑的功能（将倚天剑的秘密连接到屠龙刀的后面），并将秘笈输出. 其中每个秘密由n个元素组成，类型为T。

输入

第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数据类型，I表示整数类型，D表示双精度数类型，C表示字符型；然后输入n表示数据个数。

第三行输入倚天剑的n个数据

第四行输入屠龙刀的n个数据

依次输入t个实例

输出

每行输出一个结果

样例输入

2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello
样例输出

2700515351279
hellokitty

*/
#include<iostream>
#include <cstring>
using namespace std;
template<class T>
void sword(T a[],T b[],int n) {
	int i,j;
	T answer[2*n];
	for(i=0;i<n;i++){
		answer[i]=b[i];
	}
	for(i=n;i<2*n;i++){
		answer[i]=a[i-n];
	}
	for(i=0;i<2*n;i++)
		cout<<answer[i];
	cout<<endl;
}
int main() {
	int t,i,j,n;
	char a;
	cin>>t;
	while(t--) {
		cin>>a>>n;
		switch(a) {
			case 'I': {
				int b[n],c[n];
				for(i=0; i<n; i++)
					cin>>b[i];
				for(i=0;i<n;i++)
					cin>>c[i];
				sword(b,c,n);
				break;
			}
			case 'C': {
				char b[n],c[n];
				for(i=0; i<n; i++)
					cin>>b[i];
				for(i=0;i<n;i++)
					cin>>c[i];
				sword(b,c,n);
				break;
			}
			case 'S': {
				string b[n],c[n];
				for(i=0; i<n; i++)
					cin>>b[i];
				for(i=0;i<n;i++)
					cin>>c[i];
				sword(b,c,n);
				break;
			}
			case 'D': {
				double b[n],c[n];
				for(i=0; i<n; i++)
					cin>>b[i];
				for(i=0;i<n;i++)
					cin>>c[i];
				sword(b,c,n);
				break;
			}
		}
	}
}
