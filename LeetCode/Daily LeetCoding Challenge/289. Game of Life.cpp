class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        //temp matrix
        vector<vector<int>>a(n,vector<int>(m,0));
         //all 8 directions
        int dx[8]={1,0,1,0,-1,-1,1,-1};
        int dy[8]={1,1,0,-1,0,-1,-1,1};
        // go to every single cells and check
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               //cell is dead 
                if(board[i][j]==0){
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 and nx<=n-1 and ny>=0 and ny<=m-1 and board[nx][ny]==1){
                            cnt++;
                        }
                    }
                    if(cnt==3){
                        a[i][j]=1;
                    }
                }else{
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 and nx<=n-1 and ny>=0 and ny<=m-1 and board[nx][ny]==1){
                            cnt++;
                        }
                    }
                    if(cnt<2){
                        a[i][j]=0;
                    }else if(cnt==2 or cnt==3){
                        a[i][j]=1;
                    }else if(cnt>3){
                        a[i][j]=0;
                    }
                }
            }
        }
        // copy the temp matrix into given 
       board=a;
    }
};
