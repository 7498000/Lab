#include<iostream>
using namespace std;

int key[10],n,chain[10];
int i;

class student
{
	public:
		int rollno,prn;
		string name,address;
		float per;
		void declare();
		void table();
		void accept();
		
}h[10];

void student:: declare()
{
	cout<<"Enter the no.of student:";
	cin>>n;
	cout<<"Enter the keys:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>key[i];
	}
	for(i=0;i<10;i++)
	{
		h[i].prn=-1;
		chain[i]=0;
	}
}

void student:: table()
{
	cout<<"\nPRN\tRollNo\tName\tAddress\tPer\tChain";
	for(i=0;i<10;i++)
	{
		cout<<"\n"<<h[i].prn<<"\t"<<h[i].rollno<<"\t"<<h[i].name<<"\t"<<h[i].address<<"\t"<<h[i].per<<"\t"<<chain[i];
		
	}
	
}
void student::accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        do
        {
	        if(h[no].prn==-1)
	        {
	            h[no].prn=key[i];
	            cout<<"\nEnter the roll no.:";
	            cin>>h[no].rollno;
	            cout<<"\nEnter the Name:";
	            cin>>h[no].name;
	            cout<<"\nEnter the Address:";
	            cin>>h[no].address;
	            cout<<"\nEnter the Percentage:";
	            cin>>h[no].per;
	            break;
	        }
	        else
	        {
	        	chain[no]=no+1;
	            no++;
	            if(no>10)
	            {
	            	chain[no]=no+1;
	                no=0;
	            }
	        }
    	}while(no<10);
    }

}

int main()
{
    student obj;
    char ch;
    do
    {
    	obj.declare();
    	obj.accept();
    	obj.table();
		cout<<"\nWant to continue(y/n):";
		cin>>ch;	
	}while(ch=='y' || ch=='Y');
    
    return 0;
}


