/*
题目描述

采用面向对象思想实现手机取款的过程
假设银行账户有卡号、绑定手机号、动态密码、余额等属性，包含获取各种属性、校验动态密码、取款操作。属性全是整数数据。
使用对象数组来保存n个银行账户。
用户通过手机取款的步骤如下：(一般在主函数实现)
1、用户输入手机号，在n个银行账户中找到相应的银行账户。
	如果查找成功则往下执行，否则输出信息“手机号不存在”，不再往下执行；
2、用户输入动态密码，然后校验动态密码的是否正确
	如果密码正确则往下执行，否则输出信息“密码错误”，不再往下执行；
3、用户输入取款金额，然后执行取款操作
	如果余额不足就拒绝取款并给出信息“卡号XXX--余额不足”；如果取款成功给出信息“卡号XXX--余额YYY”，其中XXX表示卡号，YYY表示余额
上述描述只是方便说明，可以一次输入所有数据再执行各个操作。
输入

第一行输入n，表示有n个账户
下一行输入第一个账户的信息：卡号、绑定手机号、动态密码、余额
连续输入n行
接着输入k，表示要执行k次取款操作
下一行输入手机号、动态密码、取款金额
连续输入k行
输出

输出k行，每行输出操作结果

样例输入

5
1001 138111 111 1000
1002 135222 222 200
1003 136333 333 300
1004 133444 444 400
1005 132555 555 500
4
136333 333 600
133444 444 300
133555 555 200
138111 222 900
样例输出

卡号1003--余额不足
卡号1004--余额100
手机号不存在
密码错误
*/
#include<iostream>
using namespace std;

class BankAccount {
protected:
 int cardNo;
 int telephone;
 int password;
 int balance;
public:
 BankAccount(int cardNo = 0, int telephone = 0, int password = 0, int balance = 0) {
  this->cardNo = cardNo;
  this->telephone = telephone;
  this->password = password;
  this->balance = balance;
 }
 int getCardNo() {
  return cardNo;
 }
 int getTelephont() {
  return telephone;
 }
 int getPassword() {
  return password;
 }
 int getBalance() {
  return balance;
 }
 bool checkPassword(const int p) {
  if (this->password == p)
   return true;
  else
   return false;
 }
 void drawMoney(const int m) {
  if (balance >= m) {
   balance -= m;
   cout << "卡号" << cardNo << "--余额" << balance << endl;
  }
  else
   cout << "卡号" << cardNo << "--余额不足" << endl;
 }
};

int main() {
 int num, searchNum;
 int cardNo, telephone, password, balance;
 cin >> num;
 BankAccount* bankAccount = new BankAccount[num];
 for (int i = 0; i < num; i++) {
  cin >> cardNo >> telephone >> password >> balance;
  bankAccount[i] = BankAccount(cardNo, telephone, password, balance);
 }
 cin >> searchNum;
 while (searchNum--) {
  int draw;
  cin >> telephone >> password >> draw;
  bool teleExist = false;
  for (int i = 0; i < num; i++) {
   if (bankAccount[i].getTelephont() == telephone) {
    teleExist = true;
    if (bankAccount[i].checkPassword(password))
     bankAccount[i].drawMoney(draw);
    else
     cout << "密码错误" << endl;
    break;
   }
  }
  if (teleExist == false) {
   cout << "手机号不存在" << endl;
  }
 }
 return 0;
}