#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct staff{
	struct staff *next;
	char name[120];     //����
	double number;     //���
	int sex;          //�Ա�
	long age;           //����
	int degree;        //�ú�������ѧ��,���¶�һ��
	int position;
	char callphone[120];
	char address[1200];
	double salary;
	long non_work_day;//����������ڹ��ʼ�����ʹ��
}*staff_information;

void createstaff_information(staff_information &l)  //��ʼ��
{
	staff_information p;
	l=(staff_information)malloc(sizeof(staff));
	p=l;
	p->next=0;
}

void insert_new_staff_information(staff_information &l,staff_information &r) //������Ա����Ϣ
{
	staff_information p;
	p=(staff_information)malloc(sizeof(staff));
	if(l->next==0)   //������Ҫ����ִ��
	{
		r=l;
		r->next=p;
		p->next=0;
		cout<<"�����Ա�������֣�";
		cin>>p->name;
		cout<<"�����Ա���ı��(�벻Ҫ����ַ����������Ը�^^)��";
		cin>>p->number;
		cout<<"�����Ա�����Ա�"<<endl;
		cout<<"(��Ϊ�����1��Ů���2)"<<endl;
		cin>>p->sex;
		cout<<"�����Ա�������䣺";
		cin>>p->age;
		cout<<"�����Ա����ѧ����"<<endl;
		cout<<"(1����ʿ��2��˶ʿ��3��ѧʿ��4��������5������.����.Сѧ����ѧ���ߣ�)"<<endl;
		cin>>p->degree;
		cout<<"�����Ա����ְ�ƣ�"<<endl;
		cout<<"(1�����³���2���ܾ���3�����ž���4���Ƴ���5���鳤,6��һ��ְ����7������ְ����"<<" "<<"8����Ա��)"<<endl;
		cin>>p->position;
		cout<<"�����Ա�����ֻ����룺";
		cin>>p->callphone;
		cout<<"������Ա�������ڵ�(ֻ��Ҫ��������ʡ�ݾͿ�����)��"<<endl;
		cin>>p->address;
		p->non_work_day=0;
		p->salary=0;
		r=p;
		cout<<endl;
		cout<<endl;
	}
	else   //����
	{
		r->next=p;
		p->next=0;
		cout<<"�����Ա�������֣�";
		cin>>p->name;
		cout<<"�����Ա���ı��(�벻Ҫ����ַ����������Ը�^^)��";
		cin>>p->number;
		cout<<"�����Ա�����Ա�"<<endl;
		cout<<"(��Ϊ�����1��Ů���2)"<<endl;
		cin>>p->sex;
		cout<<"�����Ա�������䣺";
		cin>>p->age;
		cout<<"�����Ա����ѧ����"<<endl;
		cout<<"(1����ʿ��2��˶ʿ��3��ѧʿ��4��������5������.����.Сѧ����ѧ���ߣ�)"<<endl;
		cin>>p->degree;
		cout<<"�����Ա����ְ�ƣ�"<<endl;
		cout<<"(1�����³���2���ܾ���3�����ž���4���Ƴ���5���鳤,6��һ��ְ����7������ְ����"<<" "<<"8����Ա��)"<<endl;
		cin>>p->position;
		cout<<"�����Ա�����ֻ����룺";
		cin>>p->callphone;
		cout<<"������Ա�������ڵ�(ֻ��Ҫ��������ʡ�ݾͿ�����)��"<<endl;
		cin>>p->address;
		p->non_work_day=0;
		p->salary=0;
		r=p;
	}
	cout<<"����ɹ���";
	cout<<endl;
	cout<<endl;
}

void delete_staff_information(staff_information &l)   //ɾ��Ա����Ϣ
{   double i;
	cout<<"������Ҫɾ��Ա���ı�ţ�"<<endl;
	cin>>i;
	staff_information p,s;
	s=p=l;
	p=p->next;
	while(p->number!=i)
	{
		s=p;
		p=p->next;
		if(!p)
		{
			cout<<"û�������ŵ��ˡ�";
			return ;
		}
	}
	s->next=p->next;
	cout<<endl;
	cout<<endl;
}

void display_all_staff_information(staff_information &l)  //չʾ����Ա����Ϣ
{
	staff_information p;
	p=l;
	p=p->next;
	if(!p)
	{
		cout<<"���ڻ�û�д洢Ա����Ϣ��";
		return;
	}
	cout<<"����Ա����Ϣ��"<<endl;
	while(p)
	{
		cout<<"Ա�������֣�";
		cout<<p->name<<endl;
		cout<<"Ա���ı�ţ�";
		cout<<p->number<<endl;
		cout<<"Ա�����Ա�";
		if(p->sex==1)
			cout<<"��"<<endl;
		else
			if(p->sex==2)
				cout<<"Ů"<<endl;
		cout<<"Ա�������䣺";
		cout<<p->age<<"��"<<endl;
		cout<<"Ա����ѧ����";
		switch(p->degree)
		{
			case 1: cout<<"��ʿ"<<endl;  break;
			case 2: cout<<"˶ʿ"<<endl;  break;
			case 3: cout<<"ѧʿ"<<endl;  break;
			case 4: cout<<"����"<<endl;  break;
			case 5: cout<<"����ѧ��"<<endl;  break;
		}
		cout<<"Ա����ְ�ƣ�";
		switch(p->position)
		{
			case 1: cout<<"���³�"<<endl;  break;
			case 2: cout<<"�ܾ���"<<endl;  break;
			case 3: cout<<"���ž���"<<endl;  break;
			case 4: cout<<"�Ƴ�"<<endl;  break;
			case 5: cout<<"�鳤"<<endl;  break;
			case 6: cout<<"һ��ְ��"<<endl;  break;
			case 7: cout<<"����ְ��"<<endl;  break;
			case 8: cout<<"��Ա"<<endl;  break;
		}
		cout<<"Ա�����ֻ����룺";
		cout<<p->callphone<<endl;
		cout<<"Ա���ļ��᣺";
		cout<<p->address<<endl;
		if(p->salary!=0)
			cout<<"Ա���Ĺ��ʣ�"<<p->salary<<"Ԫ"<<endl;
		else;
		if(p->non_work_day!=0)
			cout<<"Ա��һ��Ŀ���������"<<p->non_work_day<<"��"<<endl;
		else;
		p=p->next;
		cout<<"��һ��Ա������Ϣ��"<<endl;
		cout<<endl;
		cout<<endl;
	}
}

void staff_salary(staff_information &l)  //Ա��һ���нˮ
{
	staff_information p;
	p=l;
	p=p->next;
	if(!p)
	{
		cout<<"���ڻ�û�д洢Ա������Ϣ��";
		return;
	}
	while(p)
	{
		if(p->position==1)//���³�
			p->salary=100000;
		else 
			if(p->position==2)//�ܾ���
				p->salary=80000;
		else 
			if(p->position==3)//���ž���
				p->salary=50000;
		else 
			if(p->position==4)//�Ƴ�
				p->salary=40000;
		else 
			if(p->position==5)//�鳤
				p->salary=35000;
		else 
			if(p->position==6)//һ��ְ��
				p->salary=30000;
		else 
			if(p->position==7)//����ְ��
				p->salary=25000;
		else //��Ա
			p->salary=10000;
		if(p->degree==1)//��ʿ
			p->salary=p->salary+(p->salary)*0.5-100*p->non_work_day;//���˵ı���Ϊ��Ա������ɣ�ѧ��Խ��Խ��
		else 
			if(p->degree==2)//˶ʿ
				p->salary=p->salary+(p->salary)*0.4-100*p->non_work_day;
		else 
			if(p->degree==3)//ѧʿ
				p->salary=p->salary+(p->salary)*0.3-100*p->non_work_day;
		else 
			if(p->degree==4)//����
				p->salary=p->salary+(p->salary)*0.2-100*p->non_work_day;
		else //����ѧ��
			p->salary=p->salary+(p->salary)*0.1-100*p->non_work_day;
		p=p->next;
	}
	cout<<"������ɣ���Ա���鿴�Լ�����Ϣ���Ա�ȷ�Ϲ����ܶ"<<endl;
	cout<<endl;
	cout<<endl;
}

void seach_staff(staff_information &l)//����ĳ��Ա������Ϣ
{
	staff_information p;
	double i;
	p=l;
	p=p->next;
	cout<<"������Ա���ı�ţ�";
	cin>>i;
	cout<<endl;
	while(p->number!=i)
	{
		p=p->next;
		if(!p)
			cout<<"û�������ŵ��ˡ�";
		return ;
	}
	cout<<"Ա�������֣�";
	cout<<p->name<<endl;
	cout<<"Ա���ı�ţ�";
	cout<<p->number<<endl;
	cout<<"Ա�����Ա�";
	if(p->sex==1)
		cout<<"��"<<endl;
	else
		if(p->sex==2)
			cout<<"Ů"<<endl;
	cout<<"Ա�������䣺";
	cout<<p->age<<"��"<<endl;
	cout<<"Ա����ѧ����";
	switch(p->degree)
	{
		case 1: cout<<"��ʿ"<<endl;  break;
		case 2: cout<<"˶ʿ"<<endl;  break;
		case 3: cout<<"ѧʿ"<<endl;  break;
		case 4: cout<<"����"<<endl;  break;
		case 5: cout<<"����ѧ��"<<endl;  break;
	}
	cout<<"Ա����ְ�ƣ�";
	switch(p->position)
	{
		case 1: cout<<"���³�"<<endl;  break;
		case 2: cout<<"�ܾ���"<<endl;  break;
		case 3: cout<<"���ž���"<<endl;  break;
		case 4: cout<<"�Ƴ�"<<endl;  break;
		case 5: cout<<"�鳤"<<endl;  break;
		case 6: cout<<"һ��ְ��"<<endl;  break;
		case 7: cout<<"����ְ��"<<endl;  break;
		case 8: cout<<"��Ա"<<endl;  break;
	}
	cout<<"Ա�����ֻ����룺";
	cout<<p->callphone<<endl;
	cout<<"Ա���ļ��᣺";
	cout<<p->address<<endl;
	if(p->salary!=0)
		cout<<"Ա���Ĺ��ʣ�"<<p->salary<<"Ԫ"<<endl;
	else;
	if(p->non_work_day!=0)
		cout<<"Ա��һ��Ŀ���������"<<p->non_work_day<<"��"<<endl;
	else;
	cout<<endl;
	cout<<endl;
}

void become_staff_information(staff_information &l)//�޸�Ա����Ϣ
{
	staff_information p;
	double i;
	p=l;
	p=p->next;
	cout<<"������Ա���ı�ţ�"<<endl;
	cin>>i;
	cout<<endl;
	while(p->number!=i)
	{
		p=p->next;
		if(!p)
		{
			cout<<"û�������ŵ��ˡ�";
			return ;
		}
	}
	cout<<"Ա�������֣�";
	cin>>p->name;
	cout<<endl;
	cout<<"�����Ա�����Ա�"<<endl;
	cout<<"(��Ϊ�����1��Ů���2)"<<endl;
	cin>>p->sex;
	cout<<endl;
	cout<<"Ա�������䣺";
	cin>>p->age;
	cout<<endl;
	cout<<"Ա����ѧ����"<<endl;
	cout<<"(1����ʿ��2��˶ʿ��3��ѧʿ��4��������5������.����.Сѧ����ѧ���ߣ�)"<<endl;
	cin>>p->degree;
	cout<<endl;
	cout<<"Ա����ְ�ƣ�"<<endl;
	cout<<"(1�����³���2���ܾ���3�����ž���4���Ƴ���5���鳤,6��һ��ְ����7������ְ����"<<" "<<"8����Ա��)"<<endl;
	cin>>p->position;
	cout<<endl;
	cout<<"Ա�����ֻ����룺";
	cin>>p->callphone;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}

void guard_staff_information(staff_information &l)//Ա���Ŀ���ʱ��
{
	staff_information p;
	p=l;
	p=p->next;
	while(p)
	{
		cout<<"��������Ϊ"<<p->number<<"��Ա���Ŀ���ʱ�䣺";
		cin>>p->non_work_day;
		p=p->next;
	}
	cout<<endl;
	cout<<endl;
}
int main()
{
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"--------------Ա������ϵͳ---------------------------------------------------"<<endl;
	cout<<"--------------����ߣ�������-------------------------------------------------"<<endl;
	cout<<"--------------�༶��0803-----------------------------------------------------"<<endl;
	cout<<"--------------ѧ�ţ�0812107607-----------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	int f,g;
	staff_information l,r;
	createstaff_information(l);  //�����Ƚ��ձ�
	while(f!=EOF)
	{
		cout<<"����1������Ϣ������2ɾ��ĳ��Ա����Ϣ������3�������Ա����Ϣ������4����Ա��нˮ������5����ĳ��Ա����Ϣ������6�޸�ĳ��Ա������Ϣ������7������Ա��Ա���Ŀ�������"<<"  "<<"ͳ�ƣ�";
		cin>>g;
		if(g==1||g==2||g==3||g==4||g==5||g==6||g==7)
		{
			switch(g)
			{
				case 1: insert_new_staff_information(l,r); break;
				case 2: delete_staff_information(l); break;
				case 3: display_all_staff_information(l); break;
				case 4: staff_salary(l); break;
				case 5: seach_staff(l); break;
				case 6: become_staff_information(l); break;
				case 7: guard_staff_information(l); break;
			}
		}
		else
			cout<<"�������û������ܡ�";
		cout<<endl;
		cout<<endl;
	}
	return 0;
}

