#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ulli unsigned ll int
#define all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)
#define lb(v,x)  lower_bound(all(v),x)
#define  mmst(A,val)  memset(A,val,sizeof A);
#define  pll pair <ll, ll>
#define  vctr(n) vector<n>
#define  pb push_back
#define  pf push_front
#define  mkpr  make_pair
#define  ff   first
#define  ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define  rsrt(V)  sort(V.rbegin(),V.rend());
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define  nl cout<<"\n";  
#define  PI  2*acos(0.0);
#define  INFP ((ll)1<<62)
#define  INFN (0-(ll)1<<62)
#define  fr(i,a,b) for(int i=a;i<=b;i++)
#define  frr(i,a,b) for(int i=a;i>=b;i--)
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define  pys cout<<"YES\n";
#define  pno cout<<"NO\n";
#define  bug cout<<"bug\n";
#define  pmn cout<<"-1\n";
#define  limit 300001
#define  md 100000007
#define  sq(n)  n*n
#define pcs cout<<"Case "<<cs<<": ";
typedef pair<ll,ll> iPair;
int dp[45][2],n;

void printkth_finumber(int pos,int prv,int k,bool flg)
{
   if(pos==n)return;
    
   if(prv==1)
   {
     cout<<"0";
     printkth_finumber(pos+1,0,k,flg);
     return;
   }

   if(dp[pos+1][0]<k)
   {
      cout<<"1";
      printkth_finumber(pos+1,1,k-dp[pos+1][0],true);
   }
   else
   {
     if(flg)cout<<"0";
      printkth_finumber(pos+1,0,k,flg);
   }
}

int main()
{
/*     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr);
     n=44;
     mmst(dp,0);
     dp[n][0]=1;
     dp[n][1]=1;
     for(int i=n-1;i>=0;i--)
     {
        dp[i][0]=dp[i+1][0]+dp[i+1][1];
        dp[i][1]=dp[i+1][0];
     }
    
     ll test;
     cin>>test;
     tst(test)
     {
        int k;
        cin>>k;
        k++;
        pcs
        printkth_finumber(0,0,k,false);
        nl
     } 
}
