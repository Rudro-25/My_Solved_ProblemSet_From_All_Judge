class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n= graph.size(),mx= (1<<n)-1;
        queue<pair<int,pair<int,int>>> q;  // value,distance,mask
        set<pair<int,int>> vis;
        for(int i=0;i<n;i++){
            int mask= (1<<i); //2^i
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int val= it.first, dist= it.second.first, mask= it.second.second;
            for(auto temp: graph[val]){
                int newMask= (mask | (1<<temp)); //0001 | 0010 = 0011
                if(newMask == mx)
                    return dist+1;
                else if(vis.count({temp,newMask})) continue;
                
                vis.insert({temp,newMask});
                q.push({temp,{dist+1,newMask}});
            }
        }
        return 0;
    }
};
