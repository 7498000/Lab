#include<iostream>
using namespace std;

struct node{
int coef;
int exp;
node*link;
};

node*createnode(){
    node*temp=new node;
    return temp;
}

node*attach(int c,int e,node*h){
    node*temp,*cur;
    temp=createnode();
    temp->coef=c;
    temp->exp=e;
    cur=h->link;
    while(cur->link!=h){
          cur=cur->link;
    }
    cur->link=temp;
    temp->link=h;
    return h;
}

node*readpoly(node*h){
   int c,e,i=1;
    
    char ch;
   do{
    cout<<"enter the "<<i++<<"terms"<<endl;
    cout<<"coeffient";
    cin>>c;
    cout<<"exponent";
    cin>>e;
    h=attach(c,e,h);
    
    cout<<"do you want to add more terms (y/n)";
    cin>>ch;
   }while(ch=='y' || ch=='Y');
   return h;
}

node*add_poly(node*h1,node*h2,node*h3){
    int c;
    node*ptr1;
    ptr1=h1->link;
    node*ptr2;
    ptr2=h2->link;
    
    while(ptr1!=h1 && ptr2!=h2){
        if(ptr1->exp==ptr2->exp){
            c=ptr1->coef+ptr2->coef;
            if(c!=0)
            h3=attach(c,ptr1->exp,h3);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->exp>ptr2->exp){
            h3=attach(ptr1->coef,ptr1->exp,h3);
            ptr1=ptr1->link;
        }
        else{
            h3=attach(ptr2->coef,ptr2->exp,h3);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=h1){
        h3=attach(ptr1->coef,ptr1->exp,h3);
        ptr1=ptr1->link;
    }
    while(ptr2!=h2){
        h3=attach(ptr2->coef,ptr2->exp,h3);
        ptr2=ptr2->link;
    }
     return h3;
}

void display(node*h){
    node*temp;
    if(h->link==h){
        cout<<"polynomial doesnt exist";
    }
    temp=h->link;
    while(temp!=h){
        cout<<temp->coef<<"x^"<<temp->exp;
        temp=temp->link;
        if(temp!=h)
        cout<<"+";
    }

}

int main()
{
    node *h1,*h2,*h3;
    h1=createnode();
    h2=createnode();
    h3=createnode();
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;

    cout<<"ENTER THE FIRST POLYNOMINAL:"<<endl;
    h1=readpoly(h1);
    cout<<"ENTER THE SECOND POLYNOMINAL:"<<endl;
    h2=readpoly(h2);

    h3=add_poly(h1,h2,h3);

    cout<<"FIRST POLYNOMIAL:";
    display(h1);
    cout<<endl;
    cout<<"SECOND POLYNOMIAL:";
    display(h2);
    cout<<endl;
    cout<<"THIRD POLYNOMINAL:";
    display(h3);
    cout<<endl;


}