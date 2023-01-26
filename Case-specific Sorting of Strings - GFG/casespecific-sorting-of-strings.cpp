//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        
        
        string small="",big="",ans="";
        for(auto x:str){
            if(isupper(x)){
                big+=x;
            }
            else{
                small+=x;
            }
            
        }
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        int i=0,j=0;
        for(auto x:str){
            if(isupper(x)){
                ans+=big[j];
                j++;
            }
            else{
                ans+=small[i];
                i++;
            }
            
        }
        return ans;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends