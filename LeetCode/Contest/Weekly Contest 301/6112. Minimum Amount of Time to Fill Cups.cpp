class Solution {
public:
    #define ll long long
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        if(amount[2]>(amount[0]+amount[1])){
            return amount[2];
        }
        else{
            ll sum= (amount[0]+amount[1]+amount[2]);
            return (sum+1)/2;
        }
    }
};
