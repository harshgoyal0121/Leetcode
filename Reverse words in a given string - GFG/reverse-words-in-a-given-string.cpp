//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string temp = "";
        stack<string>st;
        for(int i=0; i<s.size();i++){
           char ch = s[i];
           if(ch == '.'){
               if(temp != "")   st.push(temp);
               temp = "";
           }
           else temp+=ch;
        }
        if(temp!="") st.push(temp);
        string ans = "";
        
        while(!st.empty()){
           ans+=(st.top()+".");
           st.pop();
        }
        ans.pop_back();
        
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends