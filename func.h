#pragma once
#include<iostream>
#include<forward_list>
#include<string>
#include<stdlib.h>
#include"func.h"
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stdlib.h>
using namespace std;
class Student
{
public:
	string tag;//ѧ��
	string name;//����
	string sex;//�Ա�
	string age;//����
	string work;//רҵ
};
//����
class slist
{
public:
	Student data;//������
	slist* next;//ָ����

};
slist* createnewnode( string name, string tag, string work, string sex, string age);
//=============================================
extern void TenChangeOtherNum(int n, string r);
extern int OtherChangeToTen(string n, string r);
//=============================================
extern void bank();
extern void UI();
extern void CallNum(queue<string>& num);
extern void GetNum(queue<string>& num, string key);
//=============================================
void addStu(forward_list<Student>& student);
void deleteStu(forward_list<Student>& student,string name);
bool NameTrue(const Student &stu);
//===============
void addman(slist** head, string name, string tag, string work, string sex, string age);
void printkk(slist* head);
void deleteman(slist**head);
void findman(slist*head,string name);
//==============================================
void serchstu(string name, vector<Student> stu);
void listc();
Student addstu(string name, string age);