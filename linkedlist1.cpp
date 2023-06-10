#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int empid,salary;
	string name,mob,design;
	struct node*next;
};

struct node*create_record(){
	
	struct node*temp;
	temp=new node;
//	temp=(node*)malloc(sizeof(node));
	
	cout<<"Enter id for employee:";
	cin>>temp->empid;
	cout<<"Enter the name for employee:";
	cin>>temp->name;
	cout<<"Enter the designation for employee:";
	cin>>temp->design;
	cout<<"Enter the mobile no for employee:";
	cin>>temp->mob;
	cout<<"Enter the salary for employee:";
	cin>>temp->salary;
	temp->next=NULL;
	return temp;	
}

struct node*create_list(){
	node*temp,*head=NULL,*ptr;
	char ch;
	do{
	
		temp=create_record();
		if(temp==NULL){
			cout<<"Memory is not allocated\n";
		}
		else{
			if(head==NULL)
				head=temp;
			else{
				ptr=head;
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=temp;
			}
			cout<<" Do you wants to add more record(Y/N):";
			cin>>ch;
		}
	}while(ch=='y' || ch=='Y');
	return head;
}

void display(node*head){
	node*temp;
	if(head==NULL){
		cout<<"Record not present\n";
	}
	else{
		temp=head;
		while(temp!=NULL){
			cout<<"emp ID:"<<temp->empid<<"->";
			cout<<"emp NAME:"<<temp->name<<"->";
			cout<<"emp DESIGNATION:"<<temp->design<<"->";
			cout<<"emp MOBILE NO.:"<<temp->mob<<"->";
			cout<<"emp SALARY:"<<temp->salary<<"->";
			temp=temp->next;
			cout<<"\n";
		}
		cout<<"end\n";
	}
}



struct node* insert_front(node *head){
	node *temp,*ptr;
	temp=create_record();
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		ptr=head;
		temp->next=ptr;
		head=temp;
	}
	return head;
}
void insert_middle(node* head)
{
	node *temp,*ptr;
	int key,f=0;
	temp=create_record();
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		ptr=head;
		cout<<"Enter the employee id after which new record wil be inserted:";
		cin>>key;
		while(ptr!=NULL){
			if(ptr->empid==key){
				temp->next=ptr->next;
				ptr->next=temp;
				f=1;
			}
		 	ptr=ptr->next;
		}
		if(f==0){
			cout<<"Record not found new record will inserted\n";
		}
		else{
			cout<<"record is inserted\n";
		}
	}
}
void insert_end(node *head){
	node *temp,*ptr;
	temp=create_record();
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
struct node* delete_front(node* head){
	node *ptr1,*ptr2;
	int f=0;
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		ptr1=head;
		ptr2=ptr1->next;
		head=ptr2;
		delete ptr1;
		cout<<"front record is deleted\n";
	}
	return head;
}
void delete_middle(node* head){
	node *ptr1,*ptr2;
	int key,f=0;
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		cout<<"Enter the emp id for deletion of record:";
		cin>>key;
		ptr1=head;
		while(ptr1->next!=NULL){
			if(ptr1->empid==key){
				ptr2->next=ptr1->next;
				delete ptr1;
				f=1;
				break;
			}
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		if(f==0){
			cout<<"record is not present for deletion\n";
		
		}
		else{
			cout<<"Record is successfully deleted \n";
		}
	}
}
void delete_end(node* head){
	node *ptr1,*ptr2;
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		ptr1=head;
		while(ptr1->next!=NULL){
			ptr2=ptr1;
			ptr1=ptr1->next;
			
		}
		ptr2->next=NULL;
		delete ptr1;
		cout<<"Record deleted\n";
		
	}
}
void search(node* head){
	node *ptr;
	int key,f=0;
	if(head==NULL){
		cout<<"List is empty\n";
	}
	else{
		cout<<"Enter the id for searching a record:";
		cin>>key;
		ptr=head;
		while(ptr!=NULL){
			if(ptr->empid==key){
				cout<<"Emp ID:"<<ptr->empid<<"->";
				cout<<"Emp NAME:"<<ptr->name<<"->";
				cout<<"Emp DESIGNATION:"<<ptr->design<<"->";
				cout<<"Emp MOBILE NO.:"<<ptr->mob<<"->";
				cout<<"Emp SALARY:"<<ptr->salary<<endl;
				f=1;
			}
			ptr=ptr->next;
		}
		if(f==0){
			cout<<"Record is not found \n";
		}
	}
}

void count_nodes(node*head){
//	emp*ptr;
	int count=0;
	if(head==NULL){
		cout<<"linked list is empty"<<endl;
	}
	struct node*ptr=NULL;
	ptr=head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	cout<<"total no of employees :"<<count<<endl;
}


int main()
{
	node *temp;
	int ch;
	char f;
	cout<<"1.create a list\n2.Insert At Front\n3.Insert At Middle\n4.Insert at end\n5.Delete At Front\n6.Delete At Middle\n7.Delete at End\n8.Search\n9.Display\n10.count\n11.Exit\n";

	do{
		cout<<"Enter your choise:";
		cin>>ch;
		switch(ch){
			case 1:
				temp=create_list();
				break;
			case 2:
				temp=insert_front(temp);
				break;
			case 3:
				insert_middle(temp);
				break;
			case 4:
				insert_end(temp);
				break;
			case 5:
				temp=delete_front(temp);
				break;
			case 6:
				delete_middle(temp);
				break;
			case 7:
				delete_end(temp);
				break;
			case 8:
				search(temp);
				break;
			case 9:
				display(temp);
				break;
			case 10:
				count_nodes(temp);
				break;
			case 11:
				cout<<"End!!!\n";
				exit(0);
				break;
		}
		cout<<"Do you wants to continue (Y/N):";
		cin>>f;
	}while(f=='Y' || f=='y');

	return 0;
}