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


constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
ll cc;

void solve(){
    cout<<"Case "<<++cc<<": "<<endl;
   ll n,x,y;
   cin>>n;
   unordered_map<string,ll> mp;
   for(ll i=0;i<n;i++){
     string s; cin>>s;
     if(s.size()>2) sort(s.begin()+1,s.end()-1);
     mp[s]++;
   }
   ll q; cin>>q;
   cin.ignore(1,'\n');
   while(q--){
        ll ans=1;
        string s;
        getline(cin,s);
        stringstream str(s);
        while(str >> s){
            if(s.size()>2) sort(s.begin()+1,s.end()-1);
            ans*=mp[s];
        }
        
        cout<<ans<<endl;
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
