/*
题目描述

编写一个进行升序排序的函数模板，其中数组为具有n个元素，类型为T。

注意：必须使用模板函数

输入

第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符型，S表示字符串型，D表示双精度数类型；然后输入n表示数组长度。

第三行输入n个数据

依次输入t个实例

输出

每行输出一个结果

样例输入

4
I 10
15 3 51 27 9 35 78 14 65 8
D 3
-11.3 25.42 13.2
C 6
a b g e u q
S 4
sandy david eason cindy
样例输出

3 8 9 14 15 27 35 51 65 78 
-11.3 13.2 25.42 
a b e g q u 
cindy david eason sandy 

*/
#include<iostream>
using namespace std;
template<class T>
		void Sort(T a[],int n) {
		int i,j;
		T temp;
		for(i=0; i<n-1; i++)
			for(j=i+1; j<n; j++)
				if(a[i]>a[j]) {
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
}
int main(){
	int t,i,j,n;
	char a;
	cin>>t;
	while(t--){
		cin>>a>>n;
		switch(a){
			case 'I':{
				int b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				Sort(b,n);
				for(i=0;i<n;i++)	
					cout<<b[i]<<" ";
				cout<<endl;
				break;
			}
			case 'C':{
				char b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				Sort(b,n);
				for(i=0;i<n;i++)	
					cout<<b[i]<<" ";
				cout<<endl;
				break;
			}
			case 'S':{
				string b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				Sort(b,n);
				for(i=0;i<n;i++)	
					cout<<b[i]<<" ";
				cout<<endl;
				break;
			}
			case 'D':{
				double b[n];
				for(i=0;i<n;i++)
					cin>>b[i];
				Sort(b,n);
				for(i=0;i<n;i++)	
					cout<<b[i]<<" ";
				cout<<endl;
				break;
			}
		}
	}
}
