class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int val;
        unordered_map<int,int> cnt;
        for(int i=0;i<nums.size();i++){
            if(cnt[nums[i]]) val=nums[i];
            cnt[nums[i]]++;
        }
        return val;
    }
};
