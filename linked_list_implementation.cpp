//introduction to linked list 
//insertion at head ,middle ,tail;
//it a way to store data in linear form but it is differnt from array
//arrays are continues and linked list are not continues differnt part of memory is linked together 


#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node*next;
        
        node(int d)  //constructor for the node
        {
            data=d;
            next=NULL;
        }
};

void insert_at_head(node*(&head) ,int d)
{
    node*newnode;
    newnode=new node(d);
    newnode->data=d;
    newnode->next=head;
    (head)=newnode;

}
//in order to insert at middle we have to take jump of (pos-1)  

void insert_at_middle(node*(&head),int d,int pos)
{
    node* temp;
    temp=head;
    int count=1;
    if (head==NULL || pos==0)
    {
        insert_at_head(head,d);
        return;
    }
    while(temp->next!=NULL && count<pos)
    {
        temp=temp->next;
        count++;
    }
    node*newnode;
    newnode=new node(d);
    newnode->data=d;
    newnode->next=temp->next;
    temp->next=newnode;
}

void insert_at_end(node*(&head),int d)
{
    node*temp;
    temp=head;
    if(temp==NULL)
    {
        insert_at_head(head,d);
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    node*newnode=new node(d);
    newnode->data=d;
    newnode->next=temp->next;
    temp->next=newnode;
    
}
//deletion of linked list from head,middle,or at end of linked list

void delete_at_head(node*(&head))
{
    if (head==NULL)
    {
        return;
    }
    node*temp;
    temp=head;
    head=head->next;
    delete temp;
    
}
//delete at tail 
void delete_at_tail(node*(&head))
{
    if (head==NULL)
    {
        return;
    }
    node*temp;
    temp=head;
    if (head->next==NULL)
    {
        
        head=NULL;
        delete temp;
    }
    
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node*temp1=temp->next;
    temp->next=NULL;
    delete temp1;
}
//2nd approach to delete element at end of linked list

void delete_at_end(node*&head)
{
    node*temp;
    node*prev=NULL;
    temp=head;
    if (head==NULL)
    {
        return;
    }
    if (temp->next==NULL)
    {
        delete temp;
        return;
    }
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
}

void delete_at_middle(node*&head ,int pos)
{
    if (pos==0 || head==NULL)
    {
        return;
    }
    else  if (pos==1)
    {
        delete_at_head(head);
    }
    long int count=1;
    node*prev=NULL;
    node*temp=head;
    while(temp->next!=NULL && count<pos)
    {
        prev=temp;
        temp=temp->next;
        count++;
    }
    prev->next=NULL;
    delete temp;
}

int search_element(node*&head,int d)
{
    node*temp;
    temp=head;
    if (head==NULL)
    {
        return 0;
    }
    while(temp!=NULL)
    {
        if (temp->data==d)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}



void print(node*(&head))
{
    node*temp;
    temp=(head);
    while((temp)!=NULL)
    {
        cout<<(temp)->data<<" ";
        (temp)=(temp)->next;
    }
}

void build_list(node*&head)
{
    long int data;
    cin>>data;
    while(data!=-1)
    {
        insert_at_head(head,data);
        cin>>data;
    }
}
void reverse_linked_list(node*&head)
{
    node*curr;
    node*prev;
    node*forw;
    curr=head;
    prev=NULL;
    forw=NULL;
    while(curr!=NULL)
    {
        forw=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forw;
    }
    head=prev;
}
node* middle_element_of_linked_list(node*&head)
{
    node*temp;
    temp=head;
    if (temp==NULL || temp->next==NULL)
    {
        return temp;
    }
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void find_kth_node_from_end(node*&head,int k)
{
    if (head==NULL)
    {
        cout<<-1<<endl;
    }
    node*fast=head;
    node*slow=head;
    long int t=1;
    while(fast->next!=NULL && t<k)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
}
//one of the most important Question asked about this function

node*merge_two_sorted_linked_list(node*head1,node*head2)
{
    if (head1==NULL)
    {
        return head2;
    }
    else if (head2==NULL)
    {
        return head1;
    }
    else
    {
        node*c;
        if ((head1->data)<head2->data)
        {
            c=head1;
            c->next=merge_two_sorted_linked_list(head1->next,head2);
        }
        else
        {
            c=head2;
            c->next=merge_two_sorted_linked_list(head1,head2->next);
        }
        return c;
    }  
}

// merge sort of linked list is one of the most important question asked in interview
//we will use the concept of merge sort of array 

node*merge_sort(node*head)
{
    //base case of merge sort 
    if (head->next!=NULL || head!=NULL)
    {
        return head;
    }
    
    //now to find the mid point of linked list 
    node*mid=middle_element_of_linked_list(head);

    node*a;
    node*b;
    a=head;
    b=mid->next;
    mid->next=NULL;

    //recursively sort the array 
    a=merge_sort(a);
    b=merge_sort(b);
    
    //merge the two linked list 
    node*c=merge_two_sorted_linked_list(a,b);

    return c;

}

bool detect_cycle_in_linked_list(node*head)
{
    if (head==NULL)
    {
        return false;
    }
    node*fast=head;
    node*slow=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            return true;
        }
    }
    return false;
}

// most important algo for breaking cycle;

void to_make_cyclic_linked_list_to_linear_linked_list(node*&head)
{
    if (head==NULL)
    {
        cout<<"NO CYCLE"<<endl;
    }
    node*fast=head;
    node*slow=head;
    node*fast2;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (slow==fast)
        {
            fast2=slow;
            break;
        }
        
    }
    slow=head;
    fast=fast2;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    fast=fast->next;
    while(fast->next!=slow)
    {
        fast=fast->next;
    }
    fast->next=NULL;
}

int main()
{
    node*head1;
    node*head2;
    head2=NULL;
    head1=NULL;
    /*insert_at_head(head1,1);
    insert_at_head(head1,2);
    insert_at_head(head1,3);
    insert_at_head(head1,4);
    insert_at_middle(head1,9,1);
    insert_at_middle(head1,10,1);
    insert_at_middle(head1,17,0);
    insert_at_end(head1,5);
    print(head1);*/
    cout<<endl;
    build_list(head2);
    print(head2);
    cout<<endl;
    //reverse_linked_list(head2);
    //print(head2);
    //find_kth_node_from_end(head2, 1);
    //node*head3=NULL;
    //cout<<endl;
    //build_list(head3);
    //reverse_linked_list(head3);
    //node*head4=merge_two_sorted_linked_list(head2,head3);
    //print(head4);
    
    //merge sort for linked list 
    node*head5=merge_sort(head2);
    print(head5);

    cout<<endl;
    return 0;
}
