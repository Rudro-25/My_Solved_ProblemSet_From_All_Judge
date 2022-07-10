class Solution {
public:
    #define ll long long
    #define pb push_back
    bool canChange(string start, string target) {
        string s1,s2;
        vector<ll> v1,v2;
        ll n= start.size();
        for(ll i=0;i<n;i++){
            if(start[i] != '_') s1+=start[i],v1.pb(i);
            if(target[i] != '_') s2+=target[i],v2.pb(i);
        }
        if(s1 != s2) return false;
        n= s1.size();
        for(ll i=0;i<n;i++){
            if(v1[i]>v2[i] && s1[i]=='R') return false;
            if(v1[i]<v2[i] && s1[i]=='L') return false;
        }
        
        return true;
    }
};
