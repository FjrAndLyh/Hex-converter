#include<iostream>
#include<forward_list>
#include<string>
#include<stdlib.h>
#include"func.h"
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<queue>
using namespace std;
//三种进制转换
int main1()
{
	while (1)
	{
		cout << "请输入数字" << endl;
		string n; cin >> n;
		cout << "这个数字是()进制" << endl;
		string r; cin >> r;
		int num = OtherChangeToTen(n, r);
		cout << num << endl;
	}
}
int main2()
{
	while (1)
	{
		cout << "请输入十进制的数字" << endl;
		int n; cin >> n;
		cout << "请输入要更变成()进制" << endl;
		string r;
		while (1)
		{
			cin >> r;
			if (stoi(r) >= 16 || stoi(r) < 2)
			{
				cout << "只支持2-16进制" << endl;
			}
			else
			{
				break;
			}
		}
		TenChangeOtherNum(n, r);
	}
	return 0;
}
int main3()
{
	while (1)
	{
		cout << "请输入数字" << endl;
		string n; cin >> n;
		cout << "这个数字是()进制" << endl;
		string r; cin >> r;
		int num = OtherChangeToTen(n, r);
		cout << "你想将这个数字变为多少进制的？" << endl;
		string o; cin >> o;
		TenChangeOtherNum(num, o);
	}
	return 0;
}
//作业2
int jinzhichange()
{
	while (1)
	{
		cout << "====================================================" << endl;
		cout << "个人github账户：：：：：：：：：：：：：：：：：====" << endl;
		cout << "https://github.com/FjrAndL/num-transformer" << endl;
		cout << "====================================================" << endl;
		cout << "选择模式:1.其他进制转化为10进制" << endl;
		cout << "选择模式:2.10进制转化为其他进制" << endl;
		cout << "选择模式:3.其他进制转化为其他进制" << endl;
		cout << "一旦选择功能这次就只能用这个，懒得写切换的代码了" << endl;
		char a;
		cin >> a;
		switch (a)
		{
		    case '1':
			{
				main1();
				break;
			}
			case '2':
			{
				main2();
			}
			case '3':
			{
				main3();
			}
			default:
			{
				cout << "重新输入" << endl;
				break;
			}
		}
	}
}//放mian里直接用
//作业3
int maint()
{
	bank();
	return 0;
}
//作业1
void mainh()
{
	slist* head =NULL;//设置头指针
	char key;
	while (1)
	{
		cout << "输入选择:" << endl;
		cout << "1.加学生  2.删除最新加入的学生   3.查找指定名字的学生  4.显示所有学生  0.退出" << endl;
		cout << "==========================================================" << endl;
		cin >> key;
		switch (key)
		{
		  case '1':
		  {
			  string name, age, work, sex, tag;
			  cout << "输入学生的:" << endl;
			  cout << "姓名:" << endl;
			  cin >> name;
			  cout << "年龄:" << endl;
			  cin >> age;
			  cout << "专业:" << endl;
			  cin >> work;
			  cout << "性别:" << endl;
			  cin >> sex;
			  cout << "学号:" << endl;
			  cin >> tag;
			  addman(&head, name, tag, work, sex, age);
			  break;
		  }
		  case'2':
		  {
			  deleteman(&head);
			  break;
		  }
		  case'3':
		  {
			  cout << "输入名字:" << endl;
			  string name;
			  cin >> name;
			  findman(head, name);
			  break;
		  }
		  case'4':
		  {
			  printkk(head);
			  break;
		  }
		  case'0':
		  {
			cout << "退出了" << endl;
			return;
		  }
		  default:
		  {
			  cout << "重新输入" << endl;
			  break;
		  }
		}
	}

}
//作业一线性表


//============================
void main()
{
	maint();
}
