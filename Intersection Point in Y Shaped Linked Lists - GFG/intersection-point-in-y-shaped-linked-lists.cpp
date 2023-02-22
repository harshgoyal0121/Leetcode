//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
int len(Node *head){
    int size=0;
    while(head){
        size++;
        head=head->next;
    }
    return size;
}
//Function t1o find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int s1= len(head1), s2 = len(head2);
    if(!s1) return head2->data;
    else if(!s2)    return head1->data;
    if(s1<s2){
        for(int i=0; i<s2-s1; i++)  head2=head2->next;
    }
    else{
        for(int i=0; i<s1-s2; i++)  head1=head1->next;
    }
    while(head1 && head1->next && head2 && head2->next){
        if(head1 ==head2)   break;
        head1=head1->next;
        head2=head2->next;
        // x=head1->data;
    }
    return head1->data==head2->data?head1->data:-1;
}

