//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0; i<M.size(); i++){
            st.push(i);
        }
        for(int i=M.size()-1; i>=0; i--){
            int top = st.top();
            if(M[top][i]==1){
                st.pop();
            }
            // else{
            //     if(M[top][top]==0){
            //         int sum1=0, sum2=0;
            //         for(int i= 0; i<M.size(); i++){
            //             sum1=sum1+M[top][i];
            //             sum2=sum2+M[i][top];
            //         }
            //         cout <<sum1<<" "<<sum2<<endl;
            //         if(sum1==0 && sum2==M.size()-1){
            //             return top;
            //         }
            //     }
            // }
            else{
                
                if(st.size()>1){
                    int top = st.top();
                    st.pop();
                    int top2=st.top();
                    st.pop();
                    if(M[top2][top]==0){
                        st.push(top2);
                    }
                    else {
                        st.push(top);
                    }
                
                }
                
            }
        }
        int top=st.top();
        int sum1=0, sum2=0;
        for(int i=0; i<M.size(); i++){
            sum1=sum1+M[top][i];
            sum2=sum2+M[i][top];
        }
        if(sum1==0 && sum2==M.size()-1){
            return top;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends