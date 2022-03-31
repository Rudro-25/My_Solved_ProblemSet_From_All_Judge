class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low=0,high=0;
        for(auto it: nums){
            high+=it;
            low=max(low,it);
        }
        int ans= high;
        while(low<=high){
            int mid= (low+high)/2;
            int cnt=1;
            int cur=0;
            for(int i=0;i<nums.size();i++){
                if(cur+nums[i]<=mid) cur+=nums[i];
                else cur=nums[i],cnt++;
            }
            if(cnt<=m){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};
