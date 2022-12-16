//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(int i,int j,int n,int m){

    if(i>=0 && i<n && j>=0 && j<m) return true;

    return false;

}

    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)

    {

        // code here

       

        vector<pair<int,int>>step1odd={{-1,0},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

        vector<pair<int,int>>step1even={{-1,0},{-1,1},{0,1},{1,0},{0,-1},{-1,-1}};

        vector<pair<int,int>>step2odd={{-1,-2},{-1,-1},{-2,0},{-1,1},{-1,2},{0,2},{1,2},{2,1},{2,0},{2,-1},{1,-2},{0,-2}};

        vector<pair<int,int>>step2even={{-2,-1},{-2,0},{-2,1},{-1,2},{0,2},{1,2},{1,1},{2,0},{1,-1},{1,-2},{0,-2},{-1,-2}};

        int newi,newj;

        int ans=0;

        if(ty==0){//step1

          if((j&1)!=0){//odd

              for(auto &p:step1odd){

                  newi=i+p.first;

                  newj=j+p.second;

                  if(isvalid(newi,newj,n,m)){

                      ans+=mat[newi][newj];

                  }

              }

          }else{//even

              for(auto &p:step1even){

                  newi=i+p.first;

                  newj=j+p.second;

                  if(isvalid(newi,newj,n,m)){

                      ans+=mat[newi][newj];

                  }

              }

              

          }

        }else{

          if((j&1)!=0){//odd

              for(auto &p:step2odd){

                  newi=i+p.first;

                  newj=j+p.second;

                  if(isvalid(newi,newj,n,m)){

                      ans+=mat[newi][newj];

                  }

              }

              

          }else{//even

              for(auto &p:step2even){

                  newi=i+p.first;

                  newj=j+p.second;

                  if(isvalid(newi,newj,n,m)){

                      ans+=mat[newi][newj];

                  }

              }

              

          }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends