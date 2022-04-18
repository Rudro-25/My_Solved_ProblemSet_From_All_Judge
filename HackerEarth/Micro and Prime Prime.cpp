//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                 long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)          ((x+y-1)/y)
#define      gcd(a,b)           __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;

const ll MAX = 1e6 + 5;
vector<int> Primes;
bool isPrime[MAX];
ll PrefPrime[N],PrimePrime[N];
void sieve(){ //precalculate
  for(int i=2;i<MAX;++i) isPrime[i]=true;
  for(int i=2;i*i<MAX;i++){
    if(isPrime[i]){
        for(int j=i*i;j<MAX;j+=i){
            isPrime[j]=false;
        }
    }
  }
  for(ll i=2;i<MAX;i++){
    PrefPrime[i] = PrefPrime[i-1] + isPrime[i];
    PrimePrime[i]= PrimePrime[i-1] + isPrime[PrefPrime[i]];
  }
}

void solve(){
   ll l,r; cin>>l>>r;
   ll ans= PrimePrime[r]-PrimePrime[l-1];
   cout<<ans<<endl;
}

int main(){
   InTheNameOfGod;
   sieve();
   ll Test=1;
   cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}

