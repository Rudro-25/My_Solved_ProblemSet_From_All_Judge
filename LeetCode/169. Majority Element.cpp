class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size()/2,ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n) ans=nums[i];
        }
        return ans;
    }
};
