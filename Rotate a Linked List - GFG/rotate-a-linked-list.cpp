//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list
    Node* rotate(Node* head, int k){ 
        int size =1;
        Node*temp=head;
        while(temp && temp->next){
            temp=temp->next;
            size++;
        }
        if(size==k)  return head;
        temp->next=head;
        k=size-k;
        if(k %= size)
            for(auto i=0; i<size-k; i++) temp = temp->next;
        Node* Nhead=temp->next;
        temp->next=NULL;
        return Nhead;
        // Node *temp = head;
        // for(int i=0;i<k-1;i++)    temp = temp->next;
        // if(temp->next == NULL) return head;

        // Node *ans = temp->next;
        // Node *end = temp;
        // while(temp->next!=NULL) temp=temp->next;
        // temp->next=head;
        // end->next=NULL;
        // return ans;
    }
};

//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends