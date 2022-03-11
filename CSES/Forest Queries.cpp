#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                  long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)           ((x+y-1)/y)
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=1e3+5;
ll ul[N][N],dl[N][N],ur[N][N],dr[N][N];
ll row[N],col[N];
char ch[N][N];

void solve(){
   ll n,q,cnt=0,all=0;
   cin>>n>>q;
   for(ll i=1;i<=n;i++){
    cnt=0;
    for(ll j=1;j<=n;j++){
        cin>>ch[i][j];
        if(ch[i][j]=='*') cnt++;
        ul[i][j]=ul[i-1][j]+cnt;
        row[i]=row[i]+ (ch[i][j]=='*');
        col[j]=col[j]+ (ch[i][j]=='*');
        all+= (ch[i][j]=='*');

    }
   }
   for(ll i=1;i<=n;i++){
    row[i]+=row[i-1];
    col[i]+=col[i-1];
   }
   for(ll i=1;i<=n;i++){
    cnt=0;
    for(ll j=n;j>=1;j--){
        if(ch[i][j]=='*') cnt++;
        ur[i][j]=ur[i-1][j]+cnt;
    }
   }

   for(ll i=n;i>=1;i--){
    cnt=0;
    for(ll j=n;j>=1;j--){
        if(ch[i][j]=='*') cnt++;
        dr[i][j]=dr[i+1][j]+cnt;
    }
   }

   for(ll i=n;i>=1;i--){
    cnt=0;
    for(ll j=1;j<=n;j++){
        if(ch[i][j]=='*') cnt++;
        dl[i][j]=dl[i+1][j]+cnt;
    }
   }
   while(q--){
    ll x1,y1,x2,y2,x3,y3,x4,y4; cin>>x1>>y1>>x4>>y4;
    x2=x1,y2=y4,x3=x4,y3=y1;
    ll baki = row[x1-1]+(row[n]-row[x4]);
    baki += col[y1-1]+(col[n]-col[y4]);
    baki-= ul[x1-1][y1-1] + ur[x2-1][y2+1] + dl[x3+1][y3-1] + dr[x4+1][y4+1];
    cout<<all-baki<<endl;
   }

   

}

int main(){
   InTheNameOfGod;
   ll Test=1;
   //cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
