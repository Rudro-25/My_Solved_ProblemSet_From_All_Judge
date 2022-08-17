#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*ordered_set<ll> s;
*s.find_by_order(x) //ans at x index in sorted order.
s.order_of_key(x); //index of x or if not find x , it show index no in sort array.*/

const int N= 1e3+5;
bool vis[1005][1005];
ll ele[1005][1005];
ll query(ll x,ll y){
	ll cur=0;
	while(x>0){
		ll yy=y;
		while(yy>0){
			cur+=ele[x][yy];
			yy-=(yy&-yy);
		}
		x-=(x&-x);
	}
	return cur;
}
void update(ll x,ll y){
	while(x<N){
		ll yy=y;
		while(yy<N){
			ele[x][yy]++;
			yy+= (yy&-yy);
		}
		x+=(x&-x);
	}
}

int main(){ 
   int Test=1;
   scanf("%d", &Test);
   for(ll tt=1;tt<=Test;tt++){
   	   printf("Case %d:\n", tt);
   	   memset(vis,0,sizeof(vis));
       memset(ele,0,sizeof(ele));
       ll q; cin>>q;
       for(ll i=0;i<q;i++){
       	 int t; 
       	 scanf("%d", &t);
       	 if(t==0){
       	 	int x,y;  //cin>>x>>y;
       	 	scanf("%d %d", &x, &y); 
       	 	x++, y++;
       	 	if(!vis[x][y]){
       	 		update(x,y);
       	 		vis[x][y]=1;
       	 	}
       	 }
       	 else{
       	 	int x1,y1,x2,y2; //cin>>x1>>y1>>x2>>y2;
       	 	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
       	 	x1++, y1++, x2++, y2++;
       	 	int ans= query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
       	 	printf("%d\n", ans);
       	 }
       }

   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
