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

const ll MAX = 1e6;
vector<int> Primes;
bool isPrime[MAX+1];
ll ans=0;
void sieve(){ //precalculate
  for(int i=0;i<=MAX;++i) isPrime[i]=true;
  for(int i=3;i*i<=MAX;i+=2){
    if(isPrime[i]){
        for(int j=i*i;j<=MAX;j+=i){
            isPrime[j]=false;
        }
    }
  }
  Primes.pb(2);
  for(int i=3;i<=MAX;i+=2)
    if(isPrime[i]) Primes.pb(i);
}

vector<int>Factorization;
void PrimeFactorize(ll n){
  for(int i=0;Primes[i]*Primes[i]<=n&& i<(int)Primes.size();++i){
    if(n%Primes[i]==0){
        ll ct=0;
        while(n%Primes[i]==0){
            n/=Primes[i];
            ct++;
        }
        ans *= (ct+1);
    }
  }
  if(n>1) ans*=2;
}


int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   sieve();
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n; cin>>n;
       ans=1;
       PrimeFactorize(n);
       cout<<"Case "<<tt<<": "<<ans-1<<endl;
   }

   return 0;
}
/*

*/
