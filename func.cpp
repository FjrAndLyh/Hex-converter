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
//���������Ƹı�Ϊʮ����(nΪ���֣�rΪ���Ʊ�ʶ)
int OtherChangeToTen(string n, string r)
{
	int len = n.length();
	int* tempint = new int[len];//����һ��ջ
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
	//��ջ������,��һȡ������
	for (int j = 0; j < len&&top>0; j++)
	{
		returnNum = returnNum + tempint[j]*pow((double)stoi(r), top - 1);
		top--;
	}
	return returnNum;
}
//�ı����(����ʮ��������n,ת��Ϊr��������)
void TenChangeOtherNum(int n, string r)
{
	vector<string> stack;//��ջ
	stack.push_back("NULL");//�ڱ�
	int t = n;
	while (t > 0)
	{
		//ȡ����
		string chootemp = to_string((t % stoi(r)));
		//���ڴ���10�Ľ�����ĸת������
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
		t = t / stoi(r);//���º������
	}
	//����������
	vector<string>::iterator top = stack.end();
	while (top != stack.begin() + 1)
	{
		cout << *(--top);
	}
	cout << endl;
}


//����
//���UI
void UI()
{
	cout << "=========����ϵͳ=========" << endl;
	cout << "�� 1 :    ȡ    ��  ======" << endl;
	cout << "�� 2 :    ��    ��  ======" << endl;
	cout << "�� 0 : �� �� ϵ ͳ  ======"<<endl;
	cout << "==========================" << endl;
}
//ȡ��
void GetNum(queue<string>&num,string key)
{
	num.push(key);
	cout << "��ĺ�����" << key << "��" << endl;
}
//�к�
void CallNum(queue<string>&num)
{
	cout << "��" << num.front() << "��" << endl;
	cout << "��ǰ������ҵ��" << endl;
	cout << endl;
	num.pop();
}
//����
void bank()
{
	queue<string> num;//��������
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
						cout << "û���ˣ�����" << endl;
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
					cout << "ϵͳ���˳�" << endl;
					return;
				}
			}
	}
			
		
		


	
}


//ѧ����Ϣ��



//���ѧ��(������fowaedlist���ú���̫��֣���ϰ��)
void addStu(forward_list<Student>& student)
{
	Student temp;
	cout << "����������:" << endl;
	cin >> temp.name;
	cout << "������ѧ��:" << endl;
	cin >> temp.tag;
	cout << "�������Ա�:" << endl;
	cin >> temp.sex;
	cout << "����������:" << endl;
	cin >> temp.age;
	cout << "������רҵ:" << endl;
	cin >> temp.work;
	student.push_front(temp);
}
//ɾ��ѧ��
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
	cout << "ɾ���ɹ�" << endl;
}



//�Լ�д����������
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
//����
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
//������ӡ
void printkk(slist* head)
{
	while (head!=NULL)
	{
		cout << "����:" << head->data.name << endl;
		cout << "ѧ��:" << head->data.tag << endl;
		cout << "�Ա�:" << head->data.sex << endl;
		cout << "����:" << head->data.age << endl;
		cout << "רҵ:" << head->data.work << endl;
		cout << "===========================" << endl;
		head = head->next;
	}
}
//ɾ������
void deleteman(slist**head)
{
	slist* temp = *head;
	if (*head == NULL)
	{
		cout << "�����Ѿ�Ϊ��" << endl;
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

//���Ҹ���(��������)
void findman(slist*head,string name)
{
	slist* temp = head;
	if (temp == NULL)
	{
		cout << "���޴���" << endl;
		return;
	}
	//Ӧ�����ж��Ƿ�ΪNULL����Ȼtemp����dataʱ�����
	while (temp != NULL&&name != temp->data.name)
	{
		temp = temp->next;
	}
	if (temp!= NULL)
	{
		cout << "����:" << temp->data.name << endl;
		cout << "ѧ��:" << temp->data.tag << endl;
		cout << "�Ա�:" << temp->data.sex << endl;
		cout << "����:" << temp->data.age << endl;
		cout << "רҵ:" << temp->data.work << endl;
		cout << "===========================" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
		return;
	}
}


//=====================================˳���ʵ��
Student addstu(string name, string age)
{
	Student temp;
	temp.age = age;
	temp.name = name;
	return temp;
}

//����
void serchstu(string name, vector<Student> stu)
{
	vector<Student>::iterator begin = stu.begin();
	vector<Student>::iterator end = stu.end();
	while (begin != end && begin->name != name)
	{
		begin++;
	}
	cout << "���ҵ���:" << endl;
	cout << "����:" << begin->name << endl;
	cout << "����" << begin->age << endl;
}
void listc()
{
	vector<Student> stu;
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
			string name, age;
			cout << "����ѧ����:" << endl;
			cout << "����:" << endl;
			cin >> name;
			cout << "����:" << endl;
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
			cout << "��������:" << endl;
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
				cout << "����:" << begin->name << endl;
				cout << "����:" << begin->age << endl;
				begin++;
			}
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

