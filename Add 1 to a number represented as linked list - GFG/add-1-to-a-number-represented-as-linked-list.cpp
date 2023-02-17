//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 
struct Node{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{   
    public:
    Node* addOne(Node *head){
        if(head==NULL)  return NULL;
        int c=1;
        c=ans(head, c);
        if(c==1){
            Node *temp = new Node(1);
            temp->next=head;
            return temp;
        }
        return head;
    }
    int ans(Node *head, int c){
        if(head->next!=NULL){
        c=ans(head->next, c);

        }
        head->data+=c;
        c = head->data/10;
        head->data = head->data%10;
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends