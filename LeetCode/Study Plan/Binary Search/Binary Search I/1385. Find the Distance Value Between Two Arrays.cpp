class Solution {
public:
    #define ll long long
    int findTheDistanceValue(vector<int>& ar1, vector<int>& ar2, int d) {
        sort(ar2.begin(),ar2.end());
        ll ans=0;
        for(ll i=0;i<ar1.size();i++){
            ll l=0,r=ar2.size()-1;
            bool ck=false;
            while(l<=r){
                ll mid= (l+r)/2;
                ll dif= abs(ar2[mid]-ar1[i]);
                if(dif<=d) {ck=true; break;}
                if(ar2[mid]<ar1[i]) l=mid+1;
                else r=mid-1;
            }
            if(!ck){
                ++ans;
            }
        }
        return ans;
    }
};
