#include<iostream>
#include<list>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void reverseUtil(node* curr,node* prev,node** head)
{
    if(!curr->next)
    {
       *head=curr;
       curr->next=prev;
       return;
    }
    node* next=curr->next;
    curr->next=prev;
    reverseUtil(next,curr,head);
}

void reverse(node** head)
{
    if(!head)
     return;
reverseUtil(*head,NULL,head);
}
node* newNode(int key)
{
    node* temp= new node();
   temp->data=key;
   temp->next=NULL;
   return temp;
}
void print(node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
   
    int n;
    cin>>n;
    int i=0;
    node* head=newNode(i);
     node* curr=head;     //change
    while (n--)
    {
        cin>>i;
        curr->next=newNode(i);   //change
        curr=curr->next;          //change
    }
    cout<<"given linked lsit"<<endl;
    print(head->next);              //change
    reverse(&head->next);           //change
    cout<<"after reverse"<<endl;
    print(head->next);              //chan

}