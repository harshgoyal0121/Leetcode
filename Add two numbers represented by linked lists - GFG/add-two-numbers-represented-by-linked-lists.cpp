//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
class Solution{
    public:
    //Function to add two numbers represented by linked list.
    int len(struct Node* head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }
     Node * New_List(Node *head, int size){
         for(int i=0; i<size; i++){
             Node *c =new Node(0);
             c->next=head;
             head=c;
         }
         return head;
    }
    struct Node* addTwoLists(struct Node* head1, struct Node* head2){
        // code here
        if(head1==NULL || head2==NULL)  return NULL;
        
        int size1=len(head1), size2=len(head2);
        if(size1<size2) head1=New_List(head1, size2-size1);
        else    head2=New_List(head2, size1-size2);
        int c=0;
        
        c = ans(head1, head2, c);
        if(c>0){
            Node *temp = new Node(1);
            temp->next=head2;
            return temp;
        }
        return head2;
    }
    int ans(Node*head1, Node *head2, int c){
        if(head1->next!=NULL && head2->next!=NULL){
           c=ans(head1->next, head2->next, c);
        }
        head2->data+=head1->data+c;
        c=head2->data/10;
        head2->data %= 10;
        return c;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends