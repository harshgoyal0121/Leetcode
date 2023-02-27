//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
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
*/


class Solution
{
public:
   Node *rev(Node *curr){
       Node *prev = NULL, *temp=NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        return prev;
   }
   int len(Node *head){
       int size=0;
       while(head){
           head=head->next;
           size++;
       }
       return size;
   }
    Node *reverse(Node *head, int k)
    {
        // code here
        int size = len(head);
        if(k>size)  return head;
        
        Node *temp = head, *a= new Node(0);
        Node *p =a;
        while(temp && k-->0){
            a->next = new Node(temp->data);
            a = a->next;
            temp=temp->next;
        }
        Node *first = rev(p->next);
        Node *second = rev(temp);
        Node *ans = first;
        while(first && first->next){
            first=first->next;
        }
        first->next = second;
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends