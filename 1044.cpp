#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
 
using namespace std;

#define ll long long
#define ulli  unsigned ll int
#define sl(n) scanf("%lld", &n)
#define sl2(a,b) scanf("%lld%lld", &a,&b)
#define sl3(a,b,c) scanf("%lld%lld%lld", &a,&b,&c)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define mkpr  make_pair
#define   ff   first
#define   ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define nl printf("\n");
#define  PI  2*acos(0.0);
#define  INFP 100000000000000000
#define  INFN (0-(ll)1<<62)
#define  loop(a,b)  for(int g=a;g<=b;g++)
#define  for1(n)  for(int i=0;i<n;i++)
#define  for2(n)  for(int j=0;j<n;j++)
#define  for3(n)  for(int k=0;k<n;k++)
#define  for4(n)  for(int l=0;l<n;l++)
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define spc <<" "<<
#define  pys puts("YES");
#define  pno  puts("NO");
#define bug puts("bug");
#define bug1 puts("bug1");
#define  pmn puts("-1");
#define zero puts("0");
#define limit 2367362131
typedef pair<ll,ll> iPair;

 string A;
 ll n,dp[1001][1001];
 ll hass1[1001],hass1r[1001],pww[1001];
 long long   x,y;
 void  extend_Euclid(ll int a,ll int b)
 {
    if(b==0)
    {
        x=a;y=0;
        return ;
    }
    extend_Euclid(b,a%b);
    ll int x1=y;
    ll int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}
bool check(ll x,ll y)
{
    ll p=hass1[y]-hass1[x]+limit;
    p%=limit;
    p*=pww[x];
    p%=limit;
    ll q=hass1r[n-x]-hass1r[n-y]+limit;
    q%=limit;
    q*=pww[n-y];
    q%=limit;
    return p==q?true:false;
}

ll solve(ll prv,ll pos)
{
    ll & ret=dp[prv][pos];
    if(pos==n-1)
    {
        return  check(prv,pos+1) ? 1:pos-prv+1;
    }
    if(ret!=-1)return ret;
    ll p=INFP,q=INFP;
    p=check(prv,pos+1)?1+solve(pos+1,pos+1):INFP;
    q=solve(prv,pos+1);
    return ret=min(p,q);
}


int main()
{          
  /*     freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
      ll pw=1;
      ll val=1000004497;
      pww[0]=1;
      for(ll i=1;i<1001;i++)
      {
        pw*=val;
        pw%=limit;
        extend_Euclid(pw,limit);
        x+=limit;
        x%=limit;
        pww[i]=x;
      }
      ll test;
      cin>>test;
      tst(test)
      { 
          memset(dp,-1,sizeof dp);
          string X;
          cin>>X;
          n=X.size();
          pw=1;
          val=1000004497;
          for(ll i=1; i<=n; i++)
          {
              pw*=val;
              pw%=limit;
              hass1[i]=hass1[i-1]+((X[i-1]-'A'+1)*pw)%limit;
              hass1[i]%=limit;
          }   
          pw=1;
          val=1000004497;
          hass1r[0]=0;
          for(ll i=1; i<=n; i++)
          {
              pw*=val;
              pw%=limit;
              hass1r[i]=hass1r[i-1]+((X[n-i]-'A'+1)*pw)%limit;
              hass1r[i]%=limit;
          }
          ll  ans= solve(0,0);
          printf("Case %d: %lld\n",cs,ans);
      }
        /**
       *    @author     : Ikbal Hossain
       *    @University  : RUET CSE 15
       *    @CodeForces : iAmrifat
       *    @UVA        : rifat_ikbal
       *    @facebook   : https://www.facebook.com/ikbal.rifat.5
       */
 
      /* ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
      /* ll dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
      /* ll dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
      /* ll dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
 
}
 
 
