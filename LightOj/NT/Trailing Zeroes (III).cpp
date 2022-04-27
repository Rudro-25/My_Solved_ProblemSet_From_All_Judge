#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int sum(int x)
{
    int ans=0;
    while(x)//Find the number of five in a number
    {
        ans+=x/5;
        x/=5;
    }
    return ans;
}
int main()
{
    int t,o=1;
    int q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&q);
        int l=0,r=10000000000,mid;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int kk=sum(mid);
            if(kk==q)
            {
                ans=mid;
                r=mid-1;
            }
            else if(kk<q)
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(!ans)
            printf("Case %d: impossible\n",o++);
        else
            printf("Case %d: %d\n",o++,ans);
    }
    return 0;
}
