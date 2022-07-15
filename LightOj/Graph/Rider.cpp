#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<ll> s;
//*s.find_by_order(x) //ans at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.

const int N= 11;
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};
char ch[N][N];
ll n,m;
bool vis[N][N];
ll dis[N][N],ans[N][N],ct[N][N];

void bfs(ll x,ll y,ll val){
queue<pair<ll,ll>> q;
q.push({x,y});
vis[x][y] = true;
dis[x][y]=0;
ct[x][y]++;
while (!q.empty()) {
    int xx=q.front().first,yy=q.front().second;
    q.pop();
    for(ll i=0;i<8;i++){
		ll newx=xx+dx[i],newy=yy+dy[i];
		if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy]){
			vis[newx][newy]=1;
			dis[newx][newy]= dis[xx][yy]+1;
			ct[newx][newy]++;
			ans[newx][newy]+= (dis[newx][newy]+val-1)/val;
			q.push({newx,newy});
		}
	}
  } 
}

int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
	   for(ll k1=0;k1<n;k1++)
		 for(ll k2=0;k2<m;k2++)
		    ans[k1][k2]=ct[k1][k2]=0;
       cin>>n>>m;
	   ll cnt=0;
	   for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>ch[i][j];
			if(ch[i][j] != '.'){
				++cnt;
				for(ll k1=0;k1<n;k1++)
				  for(ll k2=0;k2<m;k2++)
				     vis[k1][k2]=dis[k1][k2]=0;
				ll val= ch[i][j]-'0';
				bfs(i,j,val);
			}
		}
	   }
	   ll answer= 1e9;
	   for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(ct[i][j]==cnt){
				answer= min(answer,ans[i][j]);
			}
		}
	   }
	   if(answer == 1e9) answer=-1;

	   cout<<"Case "<<tt<<": "<<answer<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
