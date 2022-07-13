#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define     bit_1(a)       __builtin_popcount(a)
#define     ull            unsigned long long
#define     ll             long long
#define     pb             push_back
#define     pf             push_front
#define     mpr            make_pair
#define     ins            insert
#define     ff             first
#define     ss             second
#define     vi             vector<int>
#define     vl             vector<ll>
#define     vstr           vector<string>
#define     si             set<int>
#define     sl             set<ll>
#define     li             list<int>
#define     pii            pair<int,int>
#define     pll            pair<ll,ll>
#define     mii            map<int,int>
#define     mll            map<ll,ll>
#define     ma             INT_MAX
#define     mi             INT_MIN
#define     mod            1000000007
#define     pi             3.14159265359
#define     e              2.71828182846
#define     inf            1000000000000000LL
#define     all(x)         x.begin(), x.end()
#define     lb(a,b,c)      lower_bound(a,a+b,c)-a
#define     ub(a,b,c)      upper_bound(a,a+b,c)-a
#define     lbv(a,c)       lower_bound(all(a),c)-a.begin()
#define     ubv(a,c)       upper_bound(all(a),c)-a.begin()
#define     srt1(a,b)      sort(a,a+b)
#define     srt2(a,b)      sort(a,a+b,greater<int>())
#define     gcd(a,b)       __gcd(a,b)
#define     lcm(a,b)       (a*(b/gcd(a,b)))
#define     harmonic(n)    0.57721566490153286l+log(n)
#define     mem(a, b)      memset(a, b, sizeof(a))
#define     orderset1      tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define     orderset2      tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>

const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

#define MAX 1000000000
int JaneCost[205][205],FireCost[205][205],t,r,c,tc,sr,sc;
string grid[205];
queue<pii>q;

void bfs(int mark)
{
    while(!q.empty()){
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(mark==1){
                int x=top.ff+fx[i];
                int y=top.ss+fy[i];
                if(x>=0 && x<r && y>=0 && y<c && grid[x][y]!='#' &&
                   JaneCost[x][y]==MAX){
                       JaneCost[x][y]=JaneCost[top.ff][top.ss]+1;
                       q.push(mpr(x,y));
                   }
            }
            else{
                int x=top.ff+fx[i];
                int y=top.ss+fy[i];
                if(x>=0 && x<r && y>=0 && y<c && grid[x][y]!='#' &&
                   FireCost[x][y]==MAX){
                       FireCost[x][y]=FireCost[top.ff][top.ss]+1;
                       q.push(mpr(x,y));
                   }
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)cin>>grid[i];
        for(int i=0;i<202;i++){
            for(int j=0;j<202;j++)
                JaneCost[i][j]=MAX;
        }
        while(!q.empty())q.pop();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='J'){
                    sr=i;
                    sc=j;
                    q.push(mpr(i,j));
                    JaneCost[i][j]=0;
                }
            }
        }
        bfs(1);
        for(int i=0;i<202;i++){
            for(int j=0;j<202;j++)
                FireCost[i][j]=MAX;
        }
        while(!q.empty())q.pop();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='F'){
                    sr=i;
                    sc=j;
                    FireCost[i][j]=0;
                    q.push(mpr(i,j));
                }
            }
        }
        bfs(2);
        int ans=MAX;
        for(int i=0;i<r;i++){
            if(FireCost[i][0]>JaneCost[i][0])
                ans=min(ans,JaneCost[i][0]);
            if(FireCost[i][c-1]>JaneCost[i][c-1])
                ans=min(ans,JaneCost[i][c-1]);
        }
        for(int i=0;i<c;i++){
            if(FireCost[0][i]>JaneCost[0][i])
                ans=min(ans,JaneCost[0][i]);
            if(FireCost[r-1][i]>JaneCost[r-1][i])
                ans=min(ans,JaneCost[r-1][i]);
        }
        if(ans==MAX)
            printf("Case %d: IMPOSSIBLE\n",++tc);
        else printf("Case %d: %d\n",++tc,ans+1);
    }
}
