//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string s1, string s2) 
    {
        if(s2.size()==0 && s1.size()==0)  return true;
        int x=0;
        for(int i=0; i<s2.size(); i++){
            if(s1[x]==s2[i])    x++;
        }
        return (x==s1.size())?true:false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends