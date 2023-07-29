#include<iostream>
#include<forward_list>
#include<stdlib.h>
#include"func.h"
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<queue>
using namespace std;
//将其他进制改变为十进制(n为数字，r为进制标识)
int OtherChangeToTen(string n, string r)
{
	int len = n.length();
	int* tempint = new int[len];//这是一个栈
	for (int i = 0; i < len; i++)
	{
		char tempchar = n[i];
		switch (tempchar)
		{
		    case 'A':
			{
				tempint[i] = 10;
				break;
			}
			case 'B':
			{
				tempint[i] = 11;
				break;
			}
			case 'C':
			{
				tempint[i] = 12;
				break;
			}
			case 'D':
			{
				tempint[i] = 13;
				break;
			}
			case 'E':
			{
				tempint[i] = 14;
				break;
			}
			case 'F':
			{
				tempint[i] = 15;
				break;
			}
			default :
			{
				tempint[i] = n[i] - '0';
				break;
			}
		}
	}
	int returnNum = 0;
	double top = len;
	//在栈顶操作,逐一取出数字
	for (int j = 0; j < len&&top>0; j++)
	{
		returnNum = returnNum + tempint[j]*pow((double)stoi(r), top - 1);
		top--;
	}
	return returnNum;
}
//改变进制(传入十进制数字n,转化为r进制数字)
void TenChangeOtherNum(int n, string r)
{
	vector<string> stack;//建栈
	stack.push_back("NULL");//哨兵
	int t = n;
	while (t > 0)
	{
		//取余数
		string chootemp = to_string((t % stoi(r)));
		//对于大于10的进行字母转换处理
		if (stoi(chootemp) >= 10)
		{
			switch (stoi(chootemp))
			{
			  case 10:
			  {
				chootemp = "A";
				break;
			  }
			  case 11:
			  {
				  chootemp = "B";
				  break;
			  }
			  case 12:
			  {
				  chootemp = "C";
				  break;
			  }
			  case 13:
			  {
				  chootemp = "D";
				  break;
			  }
			  case 14:
			  {
				  chootemp = "E";
				  break;
			  }
			  case 15:
			  {
				  chootemp = "F";
				  break;
			  }
			}
		}
		string temp = chootemp;
		stack.push_back(temp);
		t = t / stoi(r);//更新后的数字
	}
	//迭代器遍历
	vector<string>::iterator top = stack.end();
	while (top != stack.begin() + 1)
	{
		cout << *(--top);
	}
	cout << endl;
}


//银行
//打个UI
void UI()
{
	cout << "=========银行系统=========" << endl;
	cout << "按 1 :    取    号  ======" << endl;
	cout << "按 2 :    叫    号  ======" << endl;
	cout << "按 0 : 退 出 系 统  ======"<<endl;
	cout << "==========================" << endl;
}
//取号
void GetNum(queue<string>&num,string key)
{
	num.push(key);
	cout << "你的号码是" << key << "号" << endl;
}
//叫号
void CallNum(queue<string>&num)
{
	cout << "到" << num.front() << "号" << endl;
	cout << "请前往办理业务" << endl;
	cout << endl;
	num.pop();
}
//集成
void bank()
{
	queue<string> num;//创建队列
	string key = "0";
	int i = 1;
	char chose;
	while (1)
	{
			UI();
			cin >> chose;
			switch (chose)
			{
				case '1':
				{
					key = to_string(i);
					GetNum(num, key);
					i++;
					break;
				}
				case '2':
				{
					if (num.empty())
					{
						cout << "没号了！！！" << endl;
						cout<<endl;
						break;
					}
					else
					{
						CallNum(num);
						break;
					}
				}
				case '0':
				{
					cout << "系统已退出" << endl;
					return;
				}
			}
	}
			
		
		


	
}


//学生信息表



//添加学生(废弃，fowaedlist内置函数太奇怪，不习惯)
void addStu(forward_list<Student>& student)
{
	Student temp;
	cout << "请输入姓名:" << endl;
	cin >> temp.name;
	cout << "请输入学号:" << endl;
	cin >> temp.tag;
	cout << "请输入性别:" << endl;
	cin >> temp.sex;
	cout << "请输入年龄:" << endl;
	cin >> temp.age;
	cout << "请输入专业:" << endl;
	cin >> temp.work;
	student.push_front(temp);
}
//删除学生
bool NameTrue(const Student&stu)
{
	string temp;
	cin >> temp;
	if (temp == stu.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void deleteStu(forward_list<Student>& student,string name)
{
	student.remove_if(NameTrue);
	cout << "删除成功" << endl;
}



//自己写个链表算了
slist* createnewnode(string name,string tag,string work,string sex,string age)
{
	slist* node = (slist*)malloc(sizeof(slist));
	node->next = NULL;
	node->data.tag = tag;
	node->data.name = name;
	node->data.age = age;
	node->data.sex = sex;
	node->data.work = work;
	return node;
}
//加人
void addman(slist** head, string name, string tag, string work, string sex, string age)
{
	slist* newnode = new slist;
	newnode->data.age = age;
	newnode->data.name = name;
	newnode->data.sex = sex;
	newnode->data.tag = tag;
	newnode->data.work = work;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		slist* temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
//遍历打印
void printkk(slist* head)
{
	while (head!=NULL)
	{
		cout << "姓名:" << head->data.name << endl;
		cout << "学号:" << head->data.tag << endl;
		cout << "性别:" << head->data.sex << endl;
		cout << "年龄:" << head->data.age << endl;
		cout << "专业:" << head->data.work << endl;
		cout << "===========================" << endl;
		head = head->next;
	}
}
//删除个人
void deleteman(slist**head)
{
	slist* temp = *head;
	if (*head == NULL)
	{
		cout << "链表已经为空" << endl;
		return;
	}
	if (temp->next == NULL)
	{
		delete temp;
		*head = NULL;
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}

//查找个人(输入名字)
void findman(slist*head,string name)
{
	slist* temp = head;
	if (temp == NULL)
	{
		cout << "查无此人" << endl;
		return;
	}
	//应该先判断是否为NULL，不然temp访问data时会出错
	while (temp != NULL&&name != temp->data.name)
	{
		temp = temp->next;
	}
	if (temp!= NULL)
	{
		cout << "姓名:" << temp->data.name << endl;
		cout << "学号:" << temp->data.tag << endl;
		cout << "性别:" << temp->data.sex << endl;
		cout << "年龄:" << temp->data.age << endl;
		cout << "专业:" << temp->data.work << endl;
		cout << "===========================" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
		return;
	}
}


//=====================================顺序表实现
Student addstu(string name, string age)
{
	Student temp;
	temp.age = age;
	temp.name = name;
	return temp;
}

//找人
void serchstu(string name, vector<Student> stu)
{
	vector<Student>::iterator begin = stu.begin();
	vector<Student>::iterator end = stu.end();
	while (begin != end && begin->name != name)
	{
		begin++;
	}
	cout << "你找的是:" << endl;
	cout << "名字:" << begin->name << endl;
	cout << "年龄" << begin->age << endl;
}
void listc()
{
	vector<Student> stu;
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
			string name, age;
			cout << "输入学生的:" << endl;
			cout << "姓名:" << endl;
			cin >> name;
			cout << "年龄:" << endl;
			cin >> age;
			Student temp = addstu(name, age);
			stu.push_back(temp);
			break;
		}
		case'2':
		{
			stu.pop_back();
			break;
		}
		case'3':
		{
			cout << "输入名字:" << endl;
			string name;
			cin >> name;
			serchstu(name, stu);
			
			break;
		}
		case'4':
		{
			vector<Student>::iterator begin = stu.begin();
			vector<Student>::iterator end = stu.end();
			while (begin != end)
			{
				cout << "名字:" << begin->name << endl;
				cout << "年龄:" << begin->age << endl;
				begin++;
			}
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

