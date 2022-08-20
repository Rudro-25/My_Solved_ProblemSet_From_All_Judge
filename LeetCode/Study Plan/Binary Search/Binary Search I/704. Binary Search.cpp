class Solution {
public:
    #define ll long long
    int search(vector<int>& nums, int target) {
        ll l=0,r=nums.size()-1;
        ll pos=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(nums[mid]==target) pos=mid;
            if(nums[mid]<=target) l=mid+1;
            else r=mid-1;
        }
        return pos;
    }
};
