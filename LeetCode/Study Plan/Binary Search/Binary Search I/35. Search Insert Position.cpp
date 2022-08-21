class Solution {
public:
    #define ll long long
    int searchInsert(vector<int>& nums, int target) {
        ll l=0,r=nums.size()-1,ans=-1;
        if(nums[0]>target) return 0;
        while(l<=r){
            cout<<l<<' '<<r<<endl;
            ll mid= (l+r)/2;
            if(nums[mid]==target){
                ans=mid; break;
            }
            if(nums[mid]>=target){
                if(mid && nums[mid-1]<target){ ans=mid; break; }
                r=mid-1;
            }
            else l=mid+1; 
        }
        if(ans==-1) ans=nums.size();
        return ans;
    }
};
