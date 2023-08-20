//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int nums[], int n, int k)
    {
        long long ans = 0;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            int rem = nums[i]%k;
            if(rem!=0)
                ans+=m[(k-nums[i]%k)];
            else    ans+=m[0];
            m[rem]++;  
        }

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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends