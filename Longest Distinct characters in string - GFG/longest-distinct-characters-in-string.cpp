//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    if(s.size()==1) return 1;
    string str="";
    int ans=0;
    for(int i=0; i<s.size(); i++){
        string x="";
        x+=s[i];
        if(str.find(x) == string::npos){
            str.push_back(s[i]);
        }
        else{
            if(ans<=str.size())  ans=str.size();
            int  pos = str.find(s[i]);
            string n_str = str.substr(pos+1);
            str.clear();
            str+=n_str;
            str.push_back(s[i]);
        }
    }
    int x =str.size();
    ans = max(ans, x);
    return ans;
}