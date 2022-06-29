//insert/search only

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int SIZE=4;
ll ans;
struct node{
  bool endOfWord; ll cnt;
  node* TR[SIZE];
};

node* getNode(){
  node* n=new node;
  //n->endOfWord=false;
  n->cnt=0;

  for(int i=0;i<SIZE;i++){
    n->TR[i]=NULL;
  }
  return n;
}

void insert(node *root,string st){
  node *tempRoot = root;

  for(int i=0;i<st.size();i++){
    int index;
    if(st[i]=='A') index=0;
    else if(st[i]=='C') index=1;
    else if(st[i]=='G') index=2;
    else index=3;

    if(tempRoot->TR[index] == NULL){
      tempRoot->TR[index]=getNode();
    }
    tempRoot= tempRoot->TR[index];
    tempRoot->cnt++;
  }
  //tempRoot->endOfWord=true;
}
ll search(node *root,ll cur){
  node *tempRoot = root;
  for(ll i=0;i<4;i++){
        if(tempRoot->TR[i] != NULL)
           search(tempRoot->TR[i],cur+1);
    }
    ll val= tempRoot->cnt;
    //cout<<cur<<' '<<tempRoot->cnt<<endl;
    ans=max(ans,val*cur);
}
void del(node *root){
    node *tempRoot = root;
    for(ll i=0;i<4;i++){
        if(tempRoot->TR[i] != NULL)
           del(tempRoot->TR[i]);
    }
    delete(tempRoot);
}

int main(){


   ll t; cin>>t;
   for(ll j=1;j<=t;j++){
      node *root = getNode();
      ll n; cin>>n;
      while(n--){
        string s; cin>>s;
        insert(root,s);
      }
      ans=0;
      search(root,0);
      cout<<"Case "<<j<<": "<<ans<<endl;
      del(root);
   }

   return 0;
}
/*
1
code
1
codencode
2
code
2
cod

ans:
1
0
*/
