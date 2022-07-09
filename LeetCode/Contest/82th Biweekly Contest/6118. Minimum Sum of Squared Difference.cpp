class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll n= nums1.size();
        vector<ll> v(n+1);
        v[0]=0; ll sum=0;
        for(ll i=0;i<n;i++){
            v[i+1]= abs(nums1[i]-nums2[i]);
            sum+=v[i+1];
        }
        if(sum<=(k1+k2)) return 0;
        sort(v.begin(),v.end());
        ll k=k1+k2;
        long long ans=0;
        for(ll i=n-1;i>=0;i--){
            if(v[i]!=v[i+1]){
                ll dif= v[i+1]-v[i];
                ll dane= n-i;
                if(k>=(dane*dif)){
                    k-= (dane*dif);
                }
                else{
                    ll x= k/dane;
                    ll mod= k%dane;
                    ll val= v[i+1];
                    for(ll j=i+1;j<=n;j++){
                        if(mod) v[j]=val-x-1,--mod;
                        else v[j]=val-x;
                    }
                    break;
                }
            }
        }
        for(ll i=1;i<=n;i++) ans+= v[i]*v[i];
        
        return ans;
    }
};
