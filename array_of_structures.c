#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct record{
	int roll_no;
	int sem;
	char name[10];
	char branch[10];
};
struct record s[100];
int main()
{
	int n,ch;
	printf("enter number of students:\n");
	scanf("%d",&n);
	while(1)
	{
	printf("1.create\n2.insert\n3.delete\n4.search\n5.display\n");
	printf("enter choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create(n,s);
			break;
		case 2:
			insertion(&n,s);
			break;
		case 3:
			del(&n,s);
			break;
		case 4:
			search(n,s);
			break;
		case 5:
			display(n,s);
			break;
		case 6:
			exit(0);
			break;
	}
	}
return 0;
}
void create(int n,struct record s[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the roll no.\n");
		scanf("%d",&s[i].roll_no);
		printf("enter the name:\n");
		scanf("%s",s[i].name);
		printf("enter the branch:\n");
		scanf("%s",s[i].branch);
		printf("entre the semester:\n");
		scanf("%d",&s[i].sem);
	}
}
void insertion(int *n,struct record s[])
{
	int i,pos,num,roll,semester;
	char na[10],bran[10];
	printf("enter the position to be inserted:\n");
	scanf("%d",&pos);
	printf("enter the roll no.\n");
	scanf("%d",&roll);
	printf("enter the name:\n");
	scanf("%s",na);
	printf("enter the branch:\n");
	scanf("%s",bran);
	printf("entre the semester:\n");
	scanf("%d",&semester);
	for(i=*n-1;i>=pos-1;i--)
	{
		strcpy(s[i+1].name,s[i].name);
		strcpy(s[i+1].branch,s[i].branch);
		s[i+1].roll_no=s[i].roll_no;
		s[i+1].sem=s[i].sem;
	}
	s[pos-1].roll_no=roll;
	strcpy(s[pos-1].name,na);
	strcpy(s[pos-1].branch,bran);
	s[pos-1].sem=semester;
	*n=*n+1;
}
void display(int n,struct record s[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("roll no %d\n",s[i].roll_no);
		printf("name %s\n",s[i].name);
		printf("branch %s\n",s[i].branch);
		printf("semester %d\n",s[i].sem);
	}
}
void del(int *n,struct record s[])
{
	int i,position;
	printf("enter the number to be deleted:\n");
	scanf("%d",&position);
	for(i=position-1;i<*n-1;i++)
	{
		s[i]=s[i+1];
	}
	*n=*n-1;
}
void search(int n,struct record s[])
{
	int i,number;
	int flag=0;
	printf("enter the roll number to be  searched:\n");
	scanf("%d",&number);
	for(i=0;i<n;i++)
	{
		if(s[i].roll_no==number)
		{
			printf("Record found: roll number : %d,name :%s,branch: %s,semester: %d\n",s[i].roll_no,s[i].name,s[i].branch,s[i].sem);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("record not found:\n");
	}
}
