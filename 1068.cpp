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
#include<bits/stdc++.h>
 
 
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
#define lmt 2520
//string to_string(ll n) { stack<ll>st; while(n) { st.push(n%10); n=n/10; } string A=""; while(!st.empty()) { A+=(char)(st.top()+'0'); st.pop(); } return A; }
typedef pair<ll,ll> iPair;
 
ll dp[11][91][91][2][2],n,k;
string A;

ll solve(ll pos,ll num,ll dig,bool taken,bool flg)
{
   if(pos==n)
   {
      if(dig==0&&num==0)return 1;
      else return 0;
   }

   ll  & ret =dp[pos][num][dig][taken][flg];
   if(ret!=-1)return ret;

   ll sm=0;
   for(ll i=0;i<=9;i++)
   {
     if(!taken&&(A[pos]-'0')<i)continue;
     
     bool tkn=taken;
     bool  flag=flg;
     if(i<A[pos]-'0')tkn=true;
     if(i!=0)flag=true;

     sm+=solve(pos+1,(num*10+i)%k,(dig+i)%k,tkn,flag);
   }

   return  ret=sm;
}
 
int main()
{   /*      
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    ll test;
    cin>>test;
    tst(test)
    {
        ll l,r;
        sl3(l,r,k);

        A=to_string(r);
        n=A.size();
        
        if(k>=90)
        {
          printf("Case %d: 0\n",cs);
          continue;
        }

        memset(dp,-1,sizeof dp);
        
        ll ans=solve(0,0,0,0,0);
        
        memset(dp,-1,sizeof dp);
        
        ll p=0;
        A=to_string(l-1);
        n=A.size();
        p=solve(0,0,0,0,0);
        
        printf("Case %d: %lld\n",cs,ans-p);
    }
              /**
             *    @author     : Ikbal Hossain
             *    @College    : RUET CSE 15
             *    @CodeForces : iAmrifat
             *    @UVA        : rifat_ikbal
             *    @link       : https://www.facebook.com/ikbal.rifat.5
             */
 
            /* ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
            /* ll dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
            /* ll dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
            /* ll dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
 
}
 
 
