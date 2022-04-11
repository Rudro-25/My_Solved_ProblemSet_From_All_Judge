class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        int len;
        while(k--){
            vector<int> v;
          for(int i=0;i<grid.size();i++){
              len= grid[i].size();
              v.push_back(grid[i][len-1]);
              for(int j=len-2;j>=0;j--){
                  grid[i][j+1]=grid[i][j];
              }
          }
          grid[0][0]= v[v.size()-1];
          for(int i=1;i<grid.size();i++){
              grid[i][0]= v[i-1];
          }
        }
        return grid;
    }
};
