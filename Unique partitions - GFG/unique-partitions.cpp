//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
    void help(int num, int target, vector<int> &v)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }

        if (num == 0)
            return;

        if (target >= num)
        {
            v.push_back(num);
            help(num, target - num, v);
            v.pop_back();
        }

        help(num - 1, target, v);
    }
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        ans.clear();
        vector<int> v;
        help(n, n, v);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends