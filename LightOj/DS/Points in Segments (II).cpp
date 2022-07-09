//A. Segment Tree for the Sum

#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      mp          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e5+5;
const ll INF =1e18;

int main(){
  FastIO

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
        cout<<"Case "<<tt<<":"<<endl;

        ll n,q;
        cin>>n>>q;
        map<ll,ll> mp,mpp;
        vector<ll> a(n),b(n),v;
        ll mn= 1e9,mx=0;
        for(ll i=0;i<n;i++){
            cin>>a[i]>>b[i];
            mp[a[i]]++,mp[b[i]+1]--;
            v.pb(a[i]); v.pb(b[i]+1);
            mn=min(mn,a[i]); mx=max(mx,b[i]+1);
        }
        sort(v.begin(),v.end());
        ll cnt=0;
        for(ll i=0;i<v.size();i++){
            if(i && v[i-1]==v[i]) continue;
            cnt+= mp[v[i]];
            mpp[v[i]]=cnt;
        }

        while(q--){
            ll x,ans,xx,yy; cin>>x;
            if(x>=mx) {cout<<"0"<<endl; continue;}
            else if(x<=mn) {cout<<v[0]<<endl; continue;}
            auto it= lower_bound(v.begin(),v.end(),x);
            xx=*it,yy=*(it-1),ans=mpp[yy];
            if(x==xx) yy=*(it+1),ans=mpp[xx];
            cout<<ans<<endl;
        }
   }

  return 0;
}
/*
1
5 1
6 5 3 2 1
c 1


ans:
11
8
14

*/
