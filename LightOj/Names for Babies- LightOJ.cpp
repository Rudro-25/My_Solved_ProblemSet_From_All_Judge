//suffix array
//O(nlogn^2)
//Given a string sort all suffix
//https://lightoj.com/problem/names-for-babies

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll cc;

int main()
{   

    int test; cin>>test;
    while(test--){
            string s;
            cin>>s;
            s+='#';
            ll len=s.size();
            ll pos[s.size()];
            ll pre[len],pref[len];
            for(ll i=0;i<=len;i++) pref[i]=pre[i]=0;


            vector<pair<ll,ll>> temp;
            for(ll i=0;i<len;i++)
                temp.pb({(ll)s[i],i});
            sort(all(temp));
            pos[temp[0].second]=0;
            for(ll i=1,ok=0;i<len;i++){
                if(temp[i].first!=temp[i-1].first) ok++;
                pos[temp[i].second]=ok;
            }

            ll ans[len];
            for(ll k=1;k<=len;){
                k*=2;
                vector<pair<pair<ll,ll>,ll>> a;
                for(ll i=0;i<len;i++)
                    a.pb({{pos[i],pos[(i+k/2)%len]},i});
                sort(all(a));
                pos[a[0].second]=0;
                ans[0]=a[0].second;
                for(ll i=1,ok=0;i<len;i++){
                    if(a[i].first!=a[i-1].first) ok++;
                    pos[a[i].second]=ok;
                    ans[i]=a[i].second;
                }
            }
            ll lcp[len],cur=0;
            for(ll i=0;i<len;i++){
                cur=max(0LL,cur-1);
                if(pos[i]==0) cur=0;
                else{
                  ll bal= ans[pos[i]-1];
                  ll x1=i+cur,x2=bal+cur;
                  for( ; ; x1++,x2++){
                    if(x1==len || x2==len) break;
                    if(s[x1]!=s[x2]) break;
                    else cur++;
                  }
                }
                lcp[pos[i]]=cur;
            }

            ll no_of_dist_substring=0;
            for(ll i=1;i<len;i++){
                ll bal= len-i;
                pre[lcp[pos[i-1]]+1]++; pre[bal+1]--;
            }
            for(ll i=1;i<=len;i++){
                pre[i]+=pre[i-1];
                pref[i]+= pref[i-1]+pre[i];
            } 
            ll p,q; cin>>p>>q;
            cout<<"Case "<<++cc<<": "<<pref[q]-pref[p-1]<<endl;
    }
    
    

    return 0;
}
/*
1
abcdef
2 5

ans: 
Case 1: 14

*/