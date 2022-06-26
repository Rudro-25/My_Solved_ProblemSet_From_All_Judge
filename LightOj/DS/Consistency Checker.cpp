//insert/search only

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int SIZE=10;
bool ck;
struct node{
  bool endOfWord; ll cnt;
  node* TR[SIZE];
};

node* getNode(){
  node* n=new node;
  n->endOfWord=false;
  n->cnt=0;

  for(int i=0;i<SIZE;i++){
    n->TR[i]=NULL;
  }
  return n;
}

void insert(node *root,string st){
  node *tempRoot = root;

  for(int i=0;i<st.size();i++){
    int index=st[i]-'0';

    if(tempRoot->TR[index] == NULL){
      tempRoot->TR[index]=getNode();
    }
    tempRoot= tempRoot->TR[index];
    tempRoot->cnt++;
    if(tempRoot->cnt > 1 && tempRoot->endOfWord) ck=true;
  }
  tempRoot->endOfWord=true;
  if(tempRoot->cnt > 1 && tempRoot->endOfWord) ck=true;
}

void del(node *root){
    node *tempRoot = root;
    for(ll i=0;i<10;i++){
        if(tempRoot->TR[i] != NULL)
           del(tempRoot->TR[i]);
    }
    delete(tempRoot);
}

int main(){


   int Test; cin>>Test;
   for(ll i=1;i<=Test;i++){
    ck=false;
    node *root = getNode();
     ll n; cin>>n;
     while(n--){
        string s; cin>>s;
        insert(root,s);
     }
     cout<<"Case "<<i<<": ";
     if(ck==true) cout<<"NO"<<endl;
     else cout<<"YES"<<endl;
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
