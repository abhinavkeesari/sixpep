#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
class student
{
	public:
		long int age;
		char name[80],district[50];
		void input()
		{
			cout<<"\n Enter name: ";
			gets(name);
			cout<<"\n Enter age: ";
			cin>>age;
			fflush(stdin);
			cout<<"\n Enter district: ";
			gets(district);
		}
		void display()
		{
			system("CLS");
			cout<<"\t\tDisplay Records";
			cout<<"\n";
			cout<<"\n Name - "<<name;
			cout<<"\n age. - "<<age;
			cout<<"\n district - "<<district;
			cout<<"\n";
			system("PAUSE");
			system("CLS");
		}
		bool operator == (student a)
		{
			if(age==a.age)
				return true;
			else
				return false;
		}
};
vector <student>v;
int search_age(long int age,int &i);
void get_file()
{
	student x;
	int i=0;
	fstream f;
	f.open("College.txt",ios::in);
	if(f)
	{
		f.read((char *) &x,sizeof(class student));
		while(!f.eof())
		{
			v.push_back(x);
			f.read((char *) &x,sizeof(class student));
		}
	}
	else
		;
	f.close();
}
void bubblesort()
{
	int i,j;
	student x;
	for(i=0;i<v.size();i++)
		for(j=0;j<v.size()-i-1;j++)
			if(v[j].age>v[j+1].age)
			{
				x=v[j];
				v[j]=v[j+1];
				v[j+1]=x;
			}	
}
void insert_new()
{
	char ch='y';
	int ta;
	while(ch=='y')
	{
		fflush(stdin);
		student x;
		x.input();
		if(search_age(x.age,ta)==0)
			v.push_back(x);
		else
			cout<<"\nTHE REGISTRATION NO. ALREADY EXIST!!!\nCANNOT ADD";
		cout<<"\n Press [Y] to enter more: ";
		cin>>ch;
		fflush(stdin);
	}
}
void write_file()
{
	bubblesort();
	fstream f;
	f.open("College.txt",ios::out);
	for(int i=0;i<v.size();i++)
	{
		student x=v[i];
		f.write((char *) &x,sizeof(class student));
	}
	f.close();
}
int search_age(long int age,int &i)
{
	int ta=0;
	for(i=0;i<v.size();i++)
		if(v[i].age==age)
		{
			ta=1;
			break;
		}
	return ta;
}
int search_name(char name[],vector<int> &vi)
{
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].name,name)==0)
		{
			ta=1;
			vi.push_back(i);
		}
	return ta;
}
int search_district(char district[],vector<int> &vj)
{
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].district,district)==0)
		{
			ta=1;
			vj.push_back(i);
		}
	return ta;
}
void search_and_show()
{
	int ch,i,ta=0;
	char name[80],district[50];
	vector <int>vi; 
	vector <int>vj;
	long int age;
	poi:
	cout<<"\n1.Press to search reg no."
	<<"\n2.Press to search name"
	<<"\n3.Press to search district";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter age no.: ";
			cin>>age;
			if(search_age(age,i)==1)
				v[i].display();
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		case 2:
			cout<<"\nEnter name: ";
			fflush(stdin);
			gets(name);
			if(search_name(name,vi)==1)
			{
				for(int j=0;j<vi.size();j++)
					v[vi[j]].display();
			}
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		case 3:
			cout<<"\nEnter district: ";
			fflush(stdin);
			gets(district);
			if(search_district(district,vj)==1)
			{
				for(int j=0;j<vj.size();j++)
					v[vj[j]].display();
			}
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		default:
			cout<<"\nWrong CHOICE!!!";
			goto poi;
	}
}
void show()
{
	int i;
	for(i=0;i<v.size();i++)
		v[i].display();
}
void delete_data()
{
	int i,j;
	long int age;
	vector <student>::iterator p=v.begin();
	cout<<"\nEnter age. no.: ";
	cin>>age;
	if(search_age(age,i)==1)
	{
		student x=v[i];
		cout<<"\nThe following data is being deleted";
		x.display();
		p+=i;
		v.erase(p,p+1);
	}
}
void edit_data()
{
	int i,j;
	long int age;
	vector <student>vi;
	cout<<"\nEnter Reg. no.: ";
	cin>>age;
	if(search_age(age,i)==1)
	{
		cout<<"\nEnter new data:";
		fflush(stdin);
		v[i].input();
	}
}
int main()
{
	int i=1;
	get_file();
	while(i)
	{
		system("CLS");
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\t\t\t     Simple College Management System\n";
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\n\t\t\tEnter <1> to Add new student"
			<<"\n\t\t\tEnter <2> to Display all student"
			<<"\n\t\t\tEnter <3> to Remove student"
			<<"\n\t\t\tEnter <4> to Edit student"
			<<"\n\t\t\tEnter <5> to Search student"
			<<"\n\t\t\tEnter <0> to Exit\n";
		cout<<"\n\n\t\t\tEnter Your Choice:";	
		cin>>i;
		switch(i)
		{
			case 1 :
				insert_new();
				break;
			case 2 :
				show();
				break;
			case 3 :
				delete_data();
				break;
			case 4 :
				edit_data();
				break;
			case 5 :
				search_and_show();
				break;
			case 0 :
				write_file();
				break;
			default :
				cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
		}
	}
	return 0;
}
