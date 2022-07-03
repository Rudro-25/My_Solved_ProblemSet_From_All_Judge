#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
const ll MAX = 1e3+5;
vector<int> Primes;
bool isPrime[MAX+1];
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
void PrimeFactorize(int n){
    Factorization.clear();
  for(int i=0;Primes[i]*Primes[i]<=n&& i<Primes.size();++i){
    if(n%Primes[i]==0){
        while(n%Primes[i]==0){
            n/=Primes[i];
        }
        Factorization.pb(Primes[i]);
    }
  }
  if(n>1) Factorization.pb(n);
  //PrimeFactorize(n);
}

int main(){
   dhoom3; 
   int Test=1;
   sieve();
   cin>>Test;
   for(ll k=1;k<=Test;k++){
       ll a,b; cin>>a>>b;
       ll step[1005];
       for(ll i=a;i<=b;i++) step[i]=1e9;
       step[a]=0;
       for(ll i=a;i<=b;i++){
        if(step[i]==1e9) continue;
         PrimeFactorize(i);
         for(ll j=0;j<Factorization.size();j++){
          if(Factorization[j]==i) continue;
           if(i+Factorization[j]<=b){
             step[i+Factorization[j]]=min(step[i+Factorization[j]],step[i]+1);
           }
           else break;
         }
       }
       if(step[b]==1e9) step[b]=-1;

       cout<<"Case "<<k<<": "<<step[b]<<endl;


    
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
