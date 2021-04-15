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

int suff[1000001];

ll int   kmp(char text[], char pattern[])
{
  int i=0,j=-1,sz=strlen(pattern);
  suff[0]=-1;

  while(i<sz)
  {
    while(j>=0&&pattern[i]!=pattern[j])
    {
      j=suff[j];
    }
    i++;
    j++;
    suff[i]=j;
  }

  i=0,j=0;
  ll n=strlen(text),c=0;
  
  while(i<n)
  {
    while(j>=0&&text[i]!=pattern[j])j=suff[j];
    i++;
    j++;
    if(j==sz)c++;
  }
  return c;
}

int main()
{
/*     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
   int a,b,p,q,r,s,n,m,x,y,sum,ans,mx,mn, cnt,z,c;
   bool ys,no;
   ll test;
   cin>>test;
   char A[1000001],B[1000001];
   tst(test)
   {
       scanf("%s",A);
       scanf("%s",B);
       ll ans=kmp(A,B);
       printf("Case %d: %lld\n",cs,ans);
   }
}

