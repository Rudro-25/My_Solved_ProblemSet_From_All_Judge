class Solution {
public:
    #define ll long long
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        map<ll,ll> mp;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        ll pos=0;
        bool ck=true;
        for(ll i=0;i<buses.size();i++){
            ll k=0;
            while(pos<passengers.size() && passengers[pos]<=buses[i] && k<capacity){
                mp[passengers[pos]]++; pos++; k++;
            }
            if(k==capacity) ck=false;
            else ck=true;
        }
        ll val;
        if(pos) pos--;
        val= passengers[pos];
        if(ck) val= buses[buses.size()-1];
        while(mp[val]){
            --val;
        }
        return val;
    }
};
