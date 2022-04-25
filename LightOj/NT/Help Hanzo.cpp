//https://www.spoj.com/problems/PRIME1/

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

constexpr ll mod = 1e9  + 7;
constexpr ll N = 1e5  + 7;
ll cc;

const ll MAX = 1e6+5;
vector<ll> Primes;
bool isPrime[MAX];
void sieve(){ //precalculate
  for(int i=2;i<MAX;++i) isPrime[i]=true;
  for(int i=3;i*i<MAX;i+=2){
    if(isPrime[i]){
        for(int j=i*i;j<MAX;j+=i){
            isPrime[j]=false;
        }
    }
  }
  Primes.PSB(2);
  for(int i=3;i<MAX;i+=2)
    if(isPrime[i]) Primes.PSB(i);
}

void find_Prime_LtoR(ll l,ll r){
  ll maxN= r-l+1;
  vector<ll> chk(maxN,1LL);

  for(ll i=0;Primes[i]*Primes[i]<=r;i++){
    ll j= (l/Primes[i])*Primes[i];
    if(j<l) j+=Primes[i];
    for( ;j<=r;j+=Primes[i]){
      if(j!=Primes[i]) chk[j-l]=0;
    }
  }
  ll ans=0;
  for(ll i=0;i<maxN;i++){
    if(chk[i] && (l+i)>1) ++ans;
  }
  cout<<ans<<endl;
}

int main(){
  FastIO
  sieve();

  ll Test=1; cin>>Test;
  while(Test--){
    cout<<"Case "<<++cc<<": ";
    ll l,r; cin>>l>>r;
    find_Prime_LtoR(l,r);
    //cout<<endl;
  }



  return 0;
}

/*
2
1 10
3 5

ans:
2
3
5
7

3
5
*/
