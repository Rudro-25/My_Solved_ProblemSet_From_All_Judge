//A. Segment Tree for the Sum

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e5+5;
const ll INF =1e18;

int ar[N];
int tree[N];

int query(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
// index: 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16
// array: 1 0 2 1 1 3 0 4  2 5  2  2  3  1  0  2
// tree:  1 1 2 4 1 4 0 12 2 7  2  11 3  4  0  29
// tree
// range: 1 1..2 3 1..4 5 5..6 7 1..8 9 9..10 11 9..12 13 1..14 15 1..16


int main(){
  FastIO

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
        cout<<"Case "<<tt<<":"<<endl;

        ll n,q,cnt=0;
        cin>>n>>q;
        for(ll i=1;i<=n+n;i++) tree[i]=0;

        for (int i = 1; i <= n; ++i) {
            cin >> ar[i];
            update(i, 1, 2*n);
            ++cnt;
        }

        ll pos=n;
        while(q--){
            char ch; ll x; 
            cin>>ch>>x;
            if(ch=='c'){
                if(x>cnt){
                    cout<<"none"<<endl;
                    continue;
                }
                ll l=1,r=pos;
                while(l<r){
                    ll mid= (l+r)/2;
                    ll sum= query(mid);
                    if(sum>=x){
                        r=mid;
                    }
                    else{
                        l=mid+1;
                    }
                }
                cout<<ar[l]<<endl;
                update(l,-1,2*n);
                --cnt;
            }
            else{
                ar[++pos]=x;
                update(pos,1,2*n);
                ++cnt;
            }
        }

        //cout<<"Case "<<tt<<": "<<ans<<endl;
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
