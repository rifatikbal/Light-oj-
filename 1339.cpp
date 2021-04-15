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
 
#define si(n) scanf("%d", &n)
#define si2(a,b) scanf("%d%d", &a,&b)
#define si3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define sf(n) scanf("%lf", &n)
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
#define  INFP ((ll)1<<62)
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
#define  bug1(a)  cout<<a<<endl;
#define  bug2(a,b)  cout<<a<<" "<<b<<endl;
#define  bug3(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl;
#define  bug4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
 
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define spc <<" "<<
#define  pys puts("YES");
#define  pno  puts("NO");
#define bug puts("bug");
#define  pmn puts("-1");
#define zero puts("0");
#define limit 100001
#define md 1000000007
 
int tree[4*limit+1];
int A[limit],prv[limit],nxt[limit];
void  create(int node,int b,int e)
{
  if(b==e)
  {
    tree[node]=1;
    return;
  }

  int l=2*node;
  int r=l+1;
  int m=(b+e)/2;
   
  create(l,b,m);
  create(r,m+1,e);

  int x=0;
  if(A[m]==A[m+1])
  {
    int p=min(e,nxt[m+1]);
    int q=max(b,prv[m]);
    x=max(x,p-q+1);
  }
  x=max(tree[l],x);
  x=max(tree[r],x);
  tree[node]=x;
}
 
 
 
int query(int node,int b,int e,int i,int j )
{
    if(b>j||e<i)return 0;
    if(i<=b&&e<=j)return tree[node];

    int l=2*node;
    int r=l+1;
    int m=(b+e)/2;
    int p=query(l,b,m,i,j);
    int q=query(r,m+1,e,i,j);
    int x=p;

     if(A[m]==A[m+1])
     {
        int p=min(j,nxt[m+1]);
        int q=max(i,prv[m]);
        x=max(x,p-q+1);
     }
     x=max(x,q);
     return x;
}

int main()
{
                     
/* freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);*/
   int test;
   cin>>test;
   tst(test)
   {
      memset(tree,0,sizeof tree);
      int n,c,q;
      si3(n,c,q);
      fr1(n)si(A[i]);

      for(int i=1;i<=n;)
      {
         int j;
         for( j=i;j<=n&&A[j]==A[i];j++)
         {
             prv[j]=i;
         }
         i=j;
      }

      for(int i=n;i>0;)
      {
        int j;
        for( j=i;j>0&&A[j]==A[i];j--)
        {
          nxt[j]=i;
        }
        i=j;
      }
      create(1,1,n);
      printf("Case %d:\n",cs);

      while(q)
      {
        int l,r;
        si2(l,r);
        printf("%d\n",query(1,1,n,l,r));
        q--;
      }   
   }
     
}
 
 
