/*
题目描述

某银行的支票账户分为两类，一类为基本支票账户BaseAccount，另一类为具有透支保护特性的BasePlus支票账户。
BaseAccount支票账户的信息包括：客户姓名(name)、账户(account)、当前结余(balance)；BaseAccount支票账户可以执行的操作包括：存款(deposit)、取款(withdraw)、显示账户信息(display)。注意：取款金额不能透支，否则显式出错信息“insufficient”。
BasePlus支票账户除包含BaseAccount的所有信息外，还包括以下信息：透支上限(limit：默认为5000)，当前透支总额(limit_sum)；BasePlus支票账户可执行的操作与BaseAccount相同，但有两种操作的实现不同：(1)对于取款操作，可以在透支上限范围内透支，超过则显示出错信息“insufficient” ；(2)对于存款操作，在有透支的情况下需要先还掉透支的部分；(3)对于显示操作，还需要显示limit_sum。 注意：当出现透支的情况下账户当前结余balance设为0。
请实现BaseAccount类和BasePlus类，其中BasePlus类继承于BaseAccount类，注意BaseAccount账户名称以BA开头，BasePlus账户名称以BP开头。

要求只使用一个基类指针，指向所建立的对象，然后使用指针调用类中的方法。

输入

测试案例组数 t

第一组测试数据：

第一行输入账户信息：姓名 帐号 当前余额

第二行输入四个整数，表示对账户按顺序存款、取款、存款、取款

第二组测试数据：

.........

输出

输出BaseAccount的信息

输出BasePlus的信息

样例输入

4
Tom BA008 1000
1000 2000 1000 1200
Bob BP009 1000
1000 2000 1000 7000
May BA001 2000
500 1000 500 1000
Lily BP002 1000
500 2000 500 3000
样例输出

insufficient
Tom BA008 Balance:1000
insufficient
Bob BP009 Balance:1000 limit_sum:0
May BA001 Balance:1000
Lily BP002 Balance:0 limit_sum:3000

*/
#include <iostream>
#include <string>
using namespace std;
class BaseAccount {
protected:
	string name, account;
	int balance;
public:
	BaseAccount(string n, string a, int b) :name(n), account(a), balance(b) {}
	virtual void deposit(int _d) {
		balance = balance + _d;
	}
	virtual void withdraw(int _w) {
		if (balance >= _w)
			balance = balance - _w;
		else
			cout << "insufficient" << endl;
	}
	virtual void display() {
		cout << name << " " << account << " Balance:" << balance << endl;
	}
	virtual ~BaseAccount() {
	}
};
class BasePlus :public BaseAccount {
protected:
	int limit;
	int limit_sum;
public:
	BasePlus(string n, string a, int b) :BaseAccount(n, a, b) {
		limit = 5000;
		limit_sum = 0;
	};
	virtual void deposit(int _d) {
		if (limit_sum > 0) {
			if (_d >= limit_sum) {
				balance = _d - limit_sum;
				limit_sum = 0;
			}
			else {
				limit_sum = limit_sum - _d;
				balance = 0;
			}
				
		}
		else
			balance = balance + _d;
	}
	virtual void withdraw(int _w) {
		if (_w <= (balance + limit)) {
			if (_w <= balance)
				balance = balance - _w;
			else {
				limit_sum = _w - balance;
				limit = 5000 - limit_sum;
				balance = 0;
			}
		}
		else
			cout << "insufficient" << endl;
	}
	virtual void display() {
		cout << name << " " << account << " Balance:" << balance << " limit_sum:" << limit_sum << endl;
	}
};
int main() {
	int T = 0;
	cin >> T;
	string name, account;
	int d1, w1, d2, w2, balance;
	while (T--) {
		cin >> name >> account >> balance;
		cin >> d1 >> w1 >> d2 >> w2;
		if (account[1] == 'A') {
			BaseAccount a1(name, account, balance);
			BaseAccount* p;
			p = &a1;
			
			p->deposit(d1);
			p->withdraw(w1);
			p->deposit(d2);
			p->withdraw(w2);
			p->display();
		}

		else if (account[1] == 'P') {
			BasePlus p1(name, account, balance);
			BaseAccount* p;
			p = &p1;
			
			p->deposit(d1);
			p->withdraw(w1);
			p->deposit(d2);
			p->withdraw(w2);
			p->display();
		}
	}
	return 0;
}