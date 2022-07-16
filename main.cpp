#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct staff{
	struct staff *next;
	char name[120];     //名字
	double number;     //编号
	int sex;          //性别
	long age;           //年龄
	int degree;        //用号数代表学历,以下都一样
	int position;
	char callphone[120];
	char address[1200];
	double salary;
	long non_work_day;//请假天数，在工资计算中使用
}*staff_information;

void createstaff_information(staff_information &l)  //初始化
{
	staff_information p;
	l=(staff_information)malloc(sizeof(staff));
	p=l;
	p->next=0;
}

void insert_new_staff_information(staff_information &l,staff_information &r) //插入新员工信息
{
	staff_information p;
	p=(staff_information)malloc(sizeof(staff));
	if(l->next==0)   //如果表空要另外执行
	{
		r=l;
		r->next=p;
		p->next=0;
		cout<<"请输出员工的名字：";
		cin>>p->name;
		cout<<"请输出员工的编号(请不要输出字符，否则后果自负^^)：";
		cin>>p->number;
		cout<<"请输出员工的性别："<<endl;
		cout<<"(若为男输出1，女输出2)"<<endl;
		cin>>p->sex;
		cout<<"请输出员工的年龄：";
		cin>>p->age;
		cout<<"请输出员工的学历："<<endl;
		cout<<"(1：博士，2：硕士，3：学士，4：技工，5：高中.初中.小学或无学历者：)"<<endl;
		cin>>p->degree;
		cout<<"请输出员工的职称："<<endl;
		cout<<"(1：董事长，2：总经理，3：部门经理，4：科长，5：组长,6：一级职工，7：二级职工，"<<" "<<"8：雇员：)"<<endl;
		cin>>p->position;
		cout<<"请键入员工的手机号码：";
		cin>>p->callphone;
		cout<<"请输入员工的所在地(只需要输入所属省份就可以了)："<<endl;
		cin>>p->address;
		p->non_work_day=0;
		p->salary=0;
		r=p;
		cout<<endl;
		cout<<endl;
	}
	else   //表不空
	{
		r->next=p;
		p->next=0;
		cout<<"请输出员工的名字：";
		cin>>p->name;
		cout<<"请输出员工的编号(请不要输出字符，否则后果自负^^)：";
		cin>>p->number;
		cout<<"请输出员工的性别："<<endl;
		cout<<"(若为男输出1，女输出2)"<<endl;
		cin>>p->sex;
		cout<<"请输出员工的年龄：";
		cin>>p->age;
		cout<<"请输出员工的学历："<<endl;
		cout<<"(1：博士，2：硕士，3：学士，4：技工，5：高中.初中.小学或无学历者：)"<<endl;
		cin>>p->degree;
		cout<<"请输出员工的职称："<<endl;
		cout<<"(1：董事长，2：总经理，3：部门经理，4：科长，5：组长,6：一级职工，7：二级职工，"<<" "<<"8：雇员：)"<<endl;
		cin>>p->position;
		cout<<"请键入员工的手机号码：";
		cin>>p->callphone;
		cout<<"请输入员工的所在地(只需要输入所属省份就可以了)："<<endl;
		cin>>p->address;
		p->non_work_day=0;
		p->salary=0;
		r=p;
	}
	cout<<"输入成功。";
	cout<<endl;
	cout<<endl;
}

void delete_staff_information(staff_information &l)   //删除员工信息
{   double i;
	cout<<"请输入要删除员工的编号："<<endl;
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
			cout<<"没有这个编号的人。";
			return ;
		}
	}
	s->next=p->next;
	cout<<endl;
	cout<<endl;
}

void display_all_staff_information(staff_information &l)  //展示所有员工信息
{
	staff_information p;
	p=l;
	p=p->next;
	if(!p)
	{
		cout<<"现在还没有存储员工信息。";
		return;
	}
	cout<<"所有员工信息："<<endl;
	while(p)
	{
		cout<<"员工的名字：";
		cout<<p->name<<endl;
		cout<<"员工的编号：";
		cout<<p->number<<endl;
		cout<<"员工的性别：";
		if(p->sex==1)
			cout<<"男"<<endl;
		else
			if(p->sex==2)
				cout<<"女"<<endl;
		cout<<"员工的年龄：";
		cout<<p->age<<"岁"<<endl;
		cout<<"员工的学历：";
		switch(p->degree)
		{
			case 1: cout<<"博士"<<endl;  break;
			case 2: cout<<"硕士"<<endl;  break;
			case 3: cout<<"学士"<<endl;  break;
			case 4: cout<<"技工"<<endl;  break;
			case 5: cout<<"其他学历"<<endl;  break;
		}
		cout<<"员工的职称：";
		switch(p->position)
		{
			case 1: cout<<"董事长"<<endl;  break;
			case 2: cout<<"总经理"<<endl;  break;
			case 3: cout<<"部门经理"<<endl;  break;
			case 4: cout<<"科长"<<endl;  break;
			case 5: cout<<"组长"<<endl;  break;
			case 6: cout<<"一级职工"<<endl;  break;
			case 7: cout<<"二级职工"<<endl;  break;
			case 8: cout<<"雇员"<<endl;  break;
		}
		cout<<"员工的手机号码：";
		cout<<p->callphone<<endl;
		cout<<"员工的籍贯：";
		cout<<p->address<<endl;
		if(p->salary!=0)
			cout<<"员工的工资："<<p->salary<<"元"<<endl;
		else;
		if(p->non_work_day!=0)
			cout<<"员工一年的旷工天数："<<p->non_work_day<<"天"<<endl;
		else;
		p=p->next;
		cout<<"下一个员工的信息："<<endl;
		cout<<endl;
		cout<<endl;
	}
}

void staff_salary(staff_information &l)  //员工一年的薪水
{
	staff_information p;
	p=l;
	p=p->next;
	if(!p)
	{
		cout<<"现在还没有存储员工的信息。";
		return;
	}
	while(p)
	{
		if(p->position==1)//董事长
			p->salary=100000;
		else 
			if(p->position==2)//总经理
				p->salary=80000;
		else 
			if(p->position==3)//部门经理
				p->salary=50000;
		else 
			if(p->position==4)//科长
				p->salary=40000;
		else 
			if(p->position==5)//组长
				p->salary=35000;
		else 
			if(p->position==6)//一级职工
				p->salary=30000;
		else 
			if(p->position==7)//二级职工
				p->salary=25000;
		else //雇员
			p->salary=10000;
		if(p->degree==1)//博士
			p->salary=p->salary+(p->salary)*0.5-100*p->non_work_day;//所乘的倍数为对员工的提成，学历越高越多
		else 
			if(p->degree==2)//硕士
				p->salary=p->salary+(p->salary)*0.4-100*p->non_work_day;
		else 
			if(p->degree==3)//学士
				p->salary=p->salary+(p->salary)*0.3-100*p->non_work_day;
		else 
			if(p->degree==4)//技工
				p->salary=p->salary+(p->salary)*0.2-100*p->non_work_day;
		else //其他学历
			p->salary=p->salary+(p->salary)*0.1-100*p->non_work_day;
		p=p->next;
	}
	cout<<"输入完成，请员工查看自己的信息，以便确认工资总额。"<<endl;
	cout<<endl;
	cout<<endl;
}

void seach_staff(staff_information &l)//查找某个员工的信息
{
	staff_information p;
	double i;
	p=l;
	p=p->next;
	cout<<"请输入员工的编号：";
	cin>>i;
	cout<<endl;
	while(p->number!=i)
	{
		p=p->next;
		if(!p)
			cout<<"没有这个编号的人。";
		return ;
	}
	cout<<"员工的名字：";
	cout<<p->name<<endl;
	cout<<"员工的编号：";
	cout<<p->number<<endl;
	cout<<"员工的性别：";
	if(p->sex==1)
		cout<<"男"<<endl;
	else
		if(p->sex==2)
			cout<<"女"<<endl;
	cout<<"员工的年龄：";
	cout<<p->age<<"岁"<<endl;
	cout<<"员工的学历：";
	switch(p->degree)
	{
		case 1: cout<<"博士"<<endl;  break;
		case 2: cout<<"硕士"<<endl;  break;
		case 3: cout<<"学士"<<endl;  break;
		case 4: cout<<"技工"<<endl;  break;
		case 5: cout<<"其他学历"<<endl;  break;
	}
	cout<<"员工的职称：";
	switch(p->position)
	{
		case 1: cout<<"董事长"<<endl;  break;
		case 2: cout<<"总经理"<<endl;  break;
		case 3: cout<<"部门经理"<<endl;  break;
		case 4: cout<<"科长"<<endl;  break;
		case 5: cout<<"组长"<<endl;  break;
		case 6: cout<<"一级职工"<<endl;  break;
		case 7: cout<<"二级职工"<<endl;  break;
		case 8: cout<<"雇员"<<endl;  break;
	}
	cout<<"员工的手机号码：";
	cout<<p->callphone<<endl;
	cout<<"员工的籍贯：";
	cout<<p->address<<endl;
	if(p->salary!=0)
		cout<<"员工的工资："<<p->salary<<"元"<<endl;
	else;
	if(p->non_work_day!=0)
		cout<<"员工一年的旷工天数："<<p->non_work_day<<"天"<<endl;
	else;
	cout<<endl;
	cout<<endl;
}

void become_staff_information(staff_information &l)//修改员工信息
{
	staff_information p;
	double i;
	p=l;
	p=p->next;
	cout<<"请输入员工的编号："<<endl;
	cin>>i;
	cout<<endl;
	while(p->number!=i)
	{
		p=p->next;
		if(!p)
		{
			cout<<"没有这个编号的人。";
			return ;
		}
	}
	cout<<"员工的名字：";
	cin>>p->name;
	cout<<endl;
	cout<<"请输出员工的性别："<<endl;
	cout<<"(若为男输出1，女输出2)"<<endl;
	cin>>p->sex;
	cout<<endl;
	cout<<"员工的年龄：";
	cin>>p->age;
	cout<<endl;
	cout<<"员工的学历："<<endl;
	cout<<"(1：博士，2：硕士，3：学士，4：技工，5：高中.初中.小学或无学历者：)"<<endl;
	cin>>p->degree;
	cout<<endl;
	cout<<"员工的职称："<<endl;
	cout<<"(1：董事长，2：总经理，3：部门经理，4：科长，5：组长,6：一级职工，7：二级职工，"<<" "<<"8：雇员：)"<<endl;
	cin>>p->position;
	cout<<endl;
	cout<<"员工的手机号码：";
	cin>>p->callphone;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}

void guard_staff_information(staff_information &l)//员工的旷工时间
{
	staff_information p;
	p=l;
	p=p->next;
	while(p)
	{
		cout<<"请输出编号为"<<p->number<<"的员工的旷工时间：";
		cin>>p->non_work_day;
		p=p->next;
	}
	cout<<endl;
	cout<<endl;
}
int main()
{
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"--------------员工管理系统---------------------------------------------------"<<endl;
	cout<<"--------------设计者：周晓俊-------------------------------------------------"<<endl;
	cout<<"--------------班级：0803-----------------------------------------------------"<<endl;
	cout<<"--------------学号：0812107607-----------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	int f,g;
	staff_information l,r;
	createstaff_information(l);  //必须先建空表
	while(f!=EOF)
	{
		cout<<"输入1插入信息，输入2删除某个员工信息，输入3输出所有员工信息，输入4计算员工薪水，输入5查找某个员工信息，输入6修改某个员工的信息，输入7，管理员对员工的旷工进行"<<"  "<<"统计：";
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
			cout<<"输入错误，没有这项功能。";
		cout<<endl;
		cout<<endl;
	}
	return 0;
}

