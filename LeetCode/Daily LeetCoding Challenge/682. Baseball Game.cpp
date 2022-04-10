class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto it: ops){
            if(it=="+"){
                int v1=v.back();
                v.pop_back();
                int v2=v.back();
                v.push_back(v1); v.push_back(v1+v2);
            }
            else if(it=="C"){
                v.pop_back();
            }
            else if(it=="D"){
                int v1= v.back();
                v.push_back(v1*2);
            }
            else{
                v.push_back(stoi(it));
            }
        }
        int sum=0;
        for(int i=0;i<v.size();i++) sum+=v[i];
        
        return sum;
    }
};
