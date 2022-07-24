class Solution {
public:
    #define pb push_back
    #define ll long long
    long long countExcellentPairs(vector<int>& nums, int k) {
        ll n=nums.size(),ans=0;
        vector<ll> v;
        unordered_map<ll,ll> mp;
        for(ll i=0;i<n;i++){
            if(mp[nums[i]]) continue;
            mp[nums[i]]++;
            ll ct=0;
            while(nums[i]){
                if(nums[i]%2) ct++;
                nums[i]/=2;
            }
            v.pb(ct);
            //cout<<ct<<endl;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            auto it= lower_bound(v.begin(),v.end(),k-v[i]);
            ans+= (v.end()-it);
        }
        return ans;
    }
};
