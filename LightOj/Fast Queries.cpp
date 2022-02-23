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
const ll N=3e6+5;
ll a[N],cc,mid;
ll counts[N];
ll answer[N];
struct node{
   int l; int r; int i;
};
struct node str[50005];

bool cmp(node x,node y){
   if(x.l/mid==y.l/mid) return x.r < y.r;
   return x.l/mid < y.l/mid;
}

void solve(){

   cout<<"Case "<<++cc<<": "<<endl;
   ll n,m;
   cin>>n>>m;
   for(ll i=1;i<=n;i++) cin>>a[i];

   mid= sqrt(n);
   for(ll i=0;i<m;i++){
      ll l,r; cin>>l>>r;
      str[i].l=l;
      str[i].r=r;
      str[i].i=i;
   }

   sort(str,str+m,cmp);

   memset(counts,0,sizeof(counts));
   ll ans=1,curL=1,curR=1;
   counts[a[1]]++;

   for(ll i=0;i<m;i++){
      ll x= str[i].l;
      ll y= str[i].r;

      while(curL<x){
         counts[a[curL]]--;
         if(counts[a[curL]]==0) ans--;
         curL++;
      }
      while(curL>x){
         curL--;
         counts[a[curL]]++;
         if(counts[a[curL]]==1) ans++;
      }

      while(curR>y){
         counts[a[curR]]--;
         if(counts[a[curR]]==0) ans--;
         curR--;
      }
      while(curR<y){
         curR++;
         counts[a[curR]]++;
         if(counts[a[curR]]==1){
            ans++; //cout<<a[curR]<<endl;
         }
      }

      answer[str[i].i]=ans;
      //cout<<str[i].i<<' '<<ans<<endl;
   }

   for(ll i=0;i<m;i++){
      cout<<answer[i]<<endl;
   }


}

int main(){
   InTheNameOfGod;
   ll Test=1;
   cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
