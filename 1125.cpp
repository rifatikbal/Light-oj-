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
#define limit 200006
 
 
typedef pair<ll,ll> iPair;
 
 
 ll dp[201][21][12],A[201], n,m,d;
 
 ll solve(ll pos,ll md,ll cnt)
 {
 
    if(cnt==m)
    {
 
      if(md==0)return 1;
      else return 0;
    }
 
 
 
      if(pos>n)
      {
         
          return 0;
         
 
      }
 
 
       ll & ret=dp[pos][md][cnt];
 
      if(ret!=-1)return ret;
 
 
 
 
           ll ppp=abs(A[pos])/d;
 
           if(abs(A[pos])%d)ppp++;
 
           ppp=d*ppp;
 
return ret=solve(pos+1,(A[pos]+md+ppp)%d,cnt+1)+solve(pos+1,md,cnt);
 
}
 
int main()
{
 
               
   /*    freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
         
 
                  ll test;
                  cin>>test;
                  tst(test)
                  {
 
                    ll q;
 
                    sl2(n,q);
 
                    for(ll i=1;i<=n;i++)sl(A[i]);
 
                   
                    printf("Case %d:\n",cs);
 
                      for(ll i=0;i<q;i++)
                      {
 
                        memset(dp,-1,sizeof dp);
                         sl2(d,m);
 
                         printf("%lld\n",solve(1,0,0));
 
 
                      }
 
             
             
             
             
                     
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
 
 
