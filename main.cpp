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
//���ֽ���ת��
int main1()
{
	while (1)
	{
		cout << "����������" << endl;
		string n; cin >> n;
		cout << "���������()����" << endl;
		string r; cin >> r;
		int num = OtherChangeToTen(n, r);
		cout << num << endl;
	}
}
int main2()
{
	while (1)
	{
		cout << "������ʮ���Ƶ�����" << endl;
		int n; cin >> n;
		cout << "������Ҫ�����()����" << endl;
		string r;
		while (1)
		{
			cin >> r;
			if (stoi(r) >= 16 || stoi(r) < 2)
			{
				cout << "ֻ֧��2-16����" << endl;
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
		cout << "����������" << endl;
		string n; cin >> n;
		cout << "���������()����" << endl;
		string r; cin >> r;
		int num = OtherChangeToTen(n, r);
		cout << "���뽫������ֱ�Ϊ���ٽ��Ƶģ�" << endl;
		string o; cin >> o;
		TenChangeOtherNum(num, o);
	}
	return 0;
}
//��ҵ2
int jinzhichange()
{
	while (1)
	{
		cout << "====================================================" << endl;
		cout << "����github�˻�����������������������������������====" << endl;
		cout << "https://github.com/FjrAndL/num-transformer" << endl;
		cout << "====================================================" << endl;
		cout << "ѡ��ģʽ:1.��������ת��Ϊ10����" << endl;
		cout << "ѡ��ģʽ:2.10����ת��Ϊ��������" << endl;
		cout << "ѡ��ģʽ:3.��������ת��Ϊ��������" << endl;
		cout << "һ��ѡ������ξ�ֻ�������������д�л��Ĵ�����" << endl;
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
				cout << "��������" << endl;
				break;
			}
		}
	}
}//��mian��ֱ����
//��ҵ3
int maint()
{
	bank();
	return 0;
}
//��ҵ1
void mainh()
{
	slist* head =NULL;//����ͷָ��
	char key;
	while (1)
	{
		cout << "����ѡ��:" << endl;
		cout << "1.��ѧ��  2.ɾ�����¼����ѧ��   3.����ָ�����ֵ�ѧ��  4.��ʾ����ѧ��  0.�˳�" << endl;
		cout << "==========================================================" << endl;
		cin >> key;
		switch (key)
		{
		  case '1':
		  {
			  string name, age, work, sex, tag;
			  cout << "����ѧ����:" << endl;
			  cout << "����:" << endl;
			  cin >> name;
			  cout << "����:" << endl;
			  cin >> age;
			  cout << "רҵ:" << endl;
			  cin >> work;
			  cout << "�Ա�:" << endl;
			  cin >> sex;
			  cout << "ѧ��:" << endl;
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
			  cout << "��������:" << endl;
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
			cout << "�˳���" << endl;
			return;
		  }
		  default:
		  {
			  cout << "��������" << endl;
			  break;
		  }
		}
	}

}
//��ҵһ���Ա�


//============================
void main()
{
	maint();
}
