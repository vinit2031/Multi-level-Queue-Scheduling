#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int i,j,n,at[10],bt[10],rt[10],q[50];
int qt,temp,count=0,front=-1,rear=-1;
boolean isempty(int x[])
{
	if(front==-1&&rear==-1)
	return true;
	else
	return true;
}
void faculty()
{
	cout<<"Enter the number of queries you want to ask(Maximum 10)\n";
	cin>>n;
	count=n;
	cout<<"Now enter the arrival time and the time needed for the query to be executed(Burst Time)\n";
	cout<<"";
	for(i=0;i<n;i++)
	{
		cout<<"Process ",i+1," \n";
		cout<<"Arrival Time ",at[i];
		cout<<"Burst Time ",bt[i];
	}
	cout<<"Now enter the quantum time or the time given to each query at once";
	cin>>qt;
	
	//Loop for sorting the processes according to their arrival times
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(at[j]>atj+[1])
			{
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
			}
		}
	}
	while(isempty(q)!=true)
	{
		
	}
	
}
main()
{
	int x;
	cout<<"Welcome to the Query session of the Linux Expert Mr. Sudesh Sharma\n";
	cout<<"Select the correct queue for your query\n";
	cout<<"1. For the Faculty queue\n";
	cout<<"2. For the Student queue\n";
	cout<<"Enter your choice\n";
	cin>>x;
	switch(x)
	{
		case 1:cout<<"Welcome to the Faculty query session\n";
				faculty();
				break;
		case 2: cout<<"Welcome to the Studdent query session\n";
				break;
		default:cout<<"You made a wrong choice. Execute the program again to make the correct choice\n";
				break;
	}
	cout<<"Thankyou for using the query system\n";
}
