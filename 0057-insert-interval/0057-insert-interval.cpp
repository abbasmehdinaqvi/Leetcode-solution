class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& i, vector<int>& newInterval) {
        
        i.push_back(newInterval);
        
        stack<vector<int>> st;
        
        sort(i.begin(), i.end());
        
        for(auto j : i)
        {
            if(st.empty())
            {
                st.push(j);
                cout<<"a\n";
            }
            
            else
            {
                vector<int> a = st.top();
                st.pop();
                
                if(a[1] >= j[0])
                {
                    st.push({min(a[0], j[0]), max(a[1], j[1])});
                    cout<<"b\n";
                }
                
                else
                {
                    st.push(a);
                    st.push(j);
                    cout<<"c\n";
                }
            }
        }
        
        int n = st.size();
        
        vector<vector<int>> ans(n);
        while(!st.empty())
        {
            vector<int> b = st.top();
            ans[--n] = b;
            st.pop();
        }
        
        return ans;
    }
};