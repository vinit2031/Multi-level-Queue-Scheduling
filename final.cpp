#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int i,j,n,at[10],ct[10],bt[10],rt[10],pr[10],q1[50],q2[10],p[10];
int qt,t,temp,count=0,f2=-1,r2=-1,f1=-1,r1=-1;
int wt[10],tat[10],flag=1,time=0;
//Function to check if queue is empty or not
bool isempty(int front,int rear)
{
 if(front == -1 && rear == -1)
 return true;
 else
 return false;
}
//function to enter elements in queue1
void enqueue1(int value )
{
 if ((r1 + 1) == f1)
    cout<<"Queue is full \n";
 else
 {
  if( f1 == -1)
     f1 = 0;
 r1 = (r1+1);
   q1[r1] = value;
 }
}
//function to enter elements in queue2
void enqueue2(int value)
{
 if ((r2 + 1) == f2)
    cout<<"Queue is full \n";
 else
 {
  if( f2 == -1)
     f2 = 0;
 r2 = (r2+1);
   q2[r2] = value;
 }
}

//function to delete/remove element from queue1
int dequeue1()
{
 if( isempty(f1,r1) )
  cout<<"Queue is empty\n";
 else
 //only one element
 if( f1 == r1 )
  f1 = r1 = -1;
 else
  f1 = (f1 + 1);
  return p[f1-1];
}
//function to delete/remove element from queue2
int dequeue2()
{
 if( isempty(f2,r2) )
  cout<<"Queue is empty\n";
 else
 //only one element
 if( f2 == r2 )
  f2 = r2 = -1;
 else
  f2 = (f2 + 1);
  return p[f2-1];
}

void takevalues()
{
	for(i=0;i<n;i++)
	{
		cout<<"Query "<<i+1<<"\n";
		cout<<"Arrival Time";
		cin>>at[i];
		cout<<"Burst Time";
		cin>>bt[i];
		cout<<"Priority(1 for Faculty and 2 for Student)";
		cin>>pr[i];
		rt[i]=bt[i];
		p[i]=i;
	}
}
/*void check(int x);
{
	
}*/
void show()
{
	cout<<"Summary\n\n";
	cout<<"Query Number\tArrival Time\tBurst Time\tPriority\tTurn-around Time\tWaiting Time\n";
	for(i=0;i<n;i++)
	{
		cout<<"Query "<<p[i]+1<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<wt[i]<<"\n";
	}
	cout<<"\n\nThe given Quantum Time was ",qt;
}
void calculate()
{
	if(pr[0]==1)
	enqueue1(p[0]);
	else
 	enqueue2(p[0]);	
 	
	while(flag==1)
	{
		
		if(isempty(f1,r1)!=true)
		{
			while(r1<=f1)
			{
				
				j=dequeue1();
				cout<<"q1"<<j<<"\n";
				if(rt[j]>t&&rt[j]>0)
				{
					rt[j]-=t;
					time+=t;
					t=qt;
				}
				else if(rt[j]<t&&rt[j]>0)
				{
					t-=rt[j];
					time+=(qt-t);
					ct[j]=time;
				}
				else 
				{
					time+=t;
					ct[j]+=time;
					rt[j]=0;
					t=qt;
			    }
			    //check(j);
			    for(i=at[j];i<=time;i++)
				{
					if(at[i]<time&&pr[i]==1)
					{
						enqueue1(p[i]);
					}
					if(at[i]<time&&pr[i]==2)
					{
						enqueue2(p[i]);
					}						
				}
				if(rt[j]>0)
			    	enqueue1(p[j]);  
		    }   
		}
		else
		{
			while(isempty(f2,r2)!=true)
			{
				j=dequeue2();
				cout<<"q2"<<j<<"\n";
				while(rt[j]>0)
				{
					if(rt[j]>t&&rt[j]>0)
					{
						rt[j]-=t;
						time+=t;
						t=qt;
					}
					else if(rt[j]<t&&rt[j]>0)
					{
						t-=rt[j];
						time+=(qt-t);
						ct[j]=time;
					}
					else 
					{
						time+=t;
						ct[j]+=time;
						rt[j]=0;
						t=qt;
				    }
				    //check(j);
				    for(i=at[i];i<=time;i++)
					{
						if(at[i]<time&&pr[i]==1)
						{
							enqueue1(p[i]);
						}
						if(at[i]<time&&pr[i]==2)
						{
							enqueue2(p[i]);
						}						
					}
				}
			}
			flag=0;
		}
			
	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}
main()
{
	cout<<"Welcome to the Query session of the Linux Expert Mr. Sudesh Sharma\n\n\n";
	cout<<"Enter the number of queries you want to ask(Maximum 10)\n";
	cin>>n;
	count=n;
	cout<<"Now enter the arrival time, burst time, priority and the name of the process\n";
	cout<<"Enter the processes according to their arrival timr in ascending order\n\n";
	takevalues();
	cout<<"Enter the time to be given to each query\n";
	cin>>qt;
	t=qt;
	calculate();
	show();
	
}
