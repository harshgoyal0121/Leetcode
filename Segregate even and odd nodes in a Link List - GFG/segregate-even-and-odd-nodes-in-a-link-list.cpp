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
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
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

    Node* divide(int N, Node *head){
        // code here
        if(N==1)    return head;
        Node *temp = new Node(0);
        Node * even = temp;
        Node *temp1 = new Node(0);
        Node * odd = temp1;
        
        while(head){
            if(head->data%2==0){
                even -> next = new Node(head->data);
                even = even -> next;
            }
            else {
                odd->next = new Node(head->data);
                odd = odd->next;
            }
            head=head->next;
            
        }
        Node *ans;
        if(!temp->next)   return temp1->next;
        else if(!temp1->next) return temp->next;
        else{
            ans = temp->next;
            while(temp && temp->next)   temp= temp->next;
            temp->next = temp1->next;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends