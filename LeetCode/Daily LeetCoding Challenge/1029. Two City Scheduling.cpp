class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> v;
        int ans=0;
        for(int i=0;i<costs.size();i++){
            ans+= costs[i][0];
            v.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size()/2;i++) ans+=v[i];
        
        return ans;
    }
};
