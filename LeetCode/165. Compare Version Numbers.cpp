class Solution {
public:
    int compareVersion(string s1, string s2) {
        vector<int> v1,v2;
        int cnt=0;
        int val=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='.'){
                if(val){
                    for(int j=0;j<cnt;j++) v1.push_back(0);
                    v1.push_back(val); val=0,cnt=0;
                }
                else{
                    cnt++;
                }
            }
            else{
                int cur= s1[i]-'0';
                val*=10; val+=cur;
            }
        }
        if(val){
            for(int j=0;j<cnt;j++) v1.push_back(0);
            v1.push_back(val);
        }
        val=0,cnt=0;
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='.'){
                if(val){
                    for(int j=0;j<cnt;j++) v2.push_back(0);
                    v2.push_back(val); val=0,cnt=0;
                }
                else cnt++;
            }
            else{
                int cur= s2[i]-'0';
                val*=10; val+=cur;
            }
        }
        if(val){
            for(int j=0;j<cnt;j++) v2.push_back(0);
            v2.push_back(val);
        }
        //cout<<v1.size()<<' '<<v2.size()<<endl;
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]>v2[i]) return 1;
            else if(v2[i]>v1[i]) return -1;
        }
        if(v1.size()>v2.size()) return 1;
        if(v1.size()<v2.size()) return -1;
        else return 0;
    }
};
