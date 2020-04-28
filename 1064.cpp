clude <stdio.h>
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
 
 ll n,x,dp[26][151];
 
 ll solve(ll pos,ll sm)
 {
  if(pos>n)
  {
 
    if(sm>=x)return 1;
    else return 0;
 
  }
 
  //if(sm>x)return 0;
 
 
 
 ll & ret=dp[pos][sm];
 
 if(ret !=-1)return ret;
 
ll c=0;
  for(ll i=1;i<=6;i++)
  {
 
 c+=solve(pos+1,sm+i);
 
  }
 
   return ret=dp[pos][sm]=c;
 
 
 
 }
 
 
 
int main()
{
 
               
       /*freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
*/
 
 
                ll test;
                cin>>test;
                tst(test)
                {
 
                  memset(dp,-1,sizeof dp);
 
 
                 
                  cin>>n>>x;
 
                  ll ans=solve(1,0);
 
                  ll p=1;
 
                  while(n)p*=6,n--;
 
                  ll gc=__gcd(ans,p);
                  ans/=gc;
                  p/=gc;
                  //cout<<ans<<endl;
 
                  printf("Case %d: ",cs);
 
                  if(p==1)printf("%lld\n",ans);
                  else {
             
 
                      printf("%lld/%lld\n",ans,p);
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
 
 
