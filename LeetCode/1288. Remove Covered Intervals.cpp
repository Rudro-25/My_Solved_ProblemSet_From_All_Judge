class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals){
        vector<pair<int,int>> vp;
        for(int i=0;i<intervals.size();i++){
                vp.push_back({intervals[i][0],-intervals[i][1]});
        }
        sort(vp.begin(),vp.end());
        int mn= 100000,ans=vp.size();
        for(int i=0;i<vp.size();i++){
            int bal= vp[i].second;
            if(bal>=mn) -- ans;
            mn=min(bal,mn);
        }
        return ans;
    }
};
