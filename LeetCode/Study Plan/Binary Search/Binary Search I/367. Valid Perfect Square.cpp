class Solution {
public:
    #define ll long long
    bool isPerfectSquare(int num) {
        ll l=1,r=50000;
        while(l<=r){
            ll mid= (l+r)/2;
            ll bal= mid*mid;
            if(bal==num) return true;
            if(bal>num) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
