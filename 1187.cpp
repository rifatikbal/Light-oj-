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
 
 
#define  fr1(n)  for(int i=1;i<=n;i++)
#define  fr2(n)  for(int j=1;j<=n;j++)
#define  fr3(n)  for(int k=1;k<=n;k++)
#define  fr4(n)  for(int l=1;l<=n;l++)
 
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define spc <<" "<<
#define  pys puts("YES");
#define  pno  puts("NO");
#define bug puts("bug");
#define bug1 puts("bug1");
#define  pmn puts("-1");
#define zero puts("0");
#define limit 200006
#define md 1000000007
 
 
typedef pair<ll,ll> iPair;
 
 int A[100001],tree[400001];
 
 void create(int node,int b,int e)
 
 {
 
 
    if(b==e)
    {
 
        tree[node]=1;
 
        return ;
    }
 
   int m=(b+e)/2;
 
   int l=2*node;
   int r=l+1;
 
 
   create(l,b,m);
   create(r,m+1,e);
 
 
  tree[node]=tree[l]+tree[r];
 
 }
 
 
 
 
 
 void update(int node,int b,int e,int ind)
 {
 
 
 
 
    if(b==e)
    {
 
        tree[node]=0;
 
        return ;
    }
 
 
 
    int m=(b+e)/2;
 
 
    int l=2*node;
    int r=l+1;
 
 
  if(tree[l]<ind)
  {
 
    update(r,m+1,e,ind-tree[l]);
  }
 
  else
  {
 
    update(l,b,m,ind);
 
  }
 
  tree[node]=tree[l]+tree[r];
 
 }
 
 int query(int node,int b,int e)
 {
 
 
   if(b==e)return b;
 
 
   int m=(b+e)/2;
 
 
   int l=2*node;
   int r=l+1;
 
   if(tree[l])
    {
        return query(l,b,m);
    }
   else
    {
        return query(r,m+1,e);
    }
 
 }
 
 
int main()
{
 
               
      /* freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
 
 
 
                ll test;
                cin>>test;
                tst(test)
                {
                     memset(tree,0,sizeof tree);
 
                    int n;
 
                    si(n);
 
                    fr1(n)
                    {
 
                    si(A[i]);
 
                    }
 
                    create(1,1,n);
 
                    for(int i=n;i>1;i--)
                    {
 
                       int p=i-A[i];
 
                       update(1,1,n,p);
 
                     
 
 
                    }
           
 
 
 
                    printf("Case %d: %d\n",cs,query(1,1,n));
           
           
           
                   
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
 
 
