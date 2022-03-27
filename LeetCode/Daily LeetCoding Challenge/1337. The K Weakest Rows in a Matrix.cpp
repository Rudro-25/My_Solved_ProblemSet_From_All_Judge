class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vp;
        for(int i=0;i<mat.size();i++){
            int ct=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) ct++;
            }
            vp.push_back({ct,i});
        }
        vector<int> ans;
        sort(vp.begin(),vp.end());
        for(int i=0;i<k;i++) ans.push_back(vp[i].second);
        
        return ans;
    }
};
