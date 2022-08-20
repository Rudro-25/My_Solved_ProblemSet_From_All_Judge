class Solution {
public:
    #define ll long long
    int guessNumber(int n) {
        ll l=1,r=n,target;
        while(l<=r){
            ll mid=(l+r)/2;
             ll val= guess(mid);
            cout<<l<<' '<<r<<' '<<mid<<' '<<val<<endl;
            if(val==0) {
                target=mid; break;
            }
           if(val==1) l=mid+1;
            else r=mid-1;
        }
        return target;
    }
};
