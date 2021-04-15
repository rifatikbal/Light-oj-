#include<bits/stdc++.h>
using namespace std;
int n,d,dp[10][1<<10][1001],pw[10];
string S;

int solve(int pos,int mask,int rem)
{
    if(pos==-1)
    {
        if(rem%d==0)return 1;
        return 0;
    }
    int & ret=dp[pos][mask][rem];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=0;i<n;i++)
    {
        if(mask&1<<i)continue;
        ret+=solve(pos-1,mask|1<<i,(rem+(pw[pos]%d*(S[i]-'0')%d)%d)%d);
    }
    return ret;
}


int main()
{
   int fct[11],frq[11];
   fct[0]=1;
   for(int i=1;i<=10;i++)
   {
       fct[i]=fct[i-1]*i;
   }
   pw[0]=1;
   for(int i=1;i<10;i++)
   {
       pw[i]=pw[i-1]*10;
   }
   int tstcase,cs=1;
    cin>>tstcase;
    while(cs<=tstcase)
    {
        memset(dp,-1,sizeof(dp));
        memset(frq,0,sizeof(frq));
        cin>>S>>d;
        
        n=S.size();
        int ans=solve(n-1,0,0);
        for(int i=0;i<S.size();i++)
        {
            frq[S[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        {
            ans/=fct[frq[i]];
        }
      
        cout<<"Case "<<cs<<": ";
        cout<<ans<<"\n";
        cs++;
    }
   
}