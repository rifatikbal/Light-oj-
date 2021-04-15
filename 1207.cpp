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
#define limit 100001
typedef pair<ll,ll> iPair;

int tree[8*limit+1];
int prop[8*limit+1];
void update(int node,int b,int e,int i,int j ,int val)
{
    if(b>j||e<i)return;
    if(i<=b&&e<=j)
    {
      prop[node]=val;
      tree[node]=val;
     return;
    }

    int l=2*node;
    int r=l+1;
    int m=(b+e)/2;

    if(prop[node]!=-1)
    {
        prop[l]=prop[node];
        prop[r]=prop[node];
        tree[l]=prop[node];
        tree[r]=prop[node];
        prop[node]=-1;
    }

    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[node]=tree[l]|tree[r]; 
}

int query(int node,int b,int e,int i,int j )
{
    if(b>j||e<i)return 0;
    if(i<=b&&e<=j) return tree[node];

    ll l=2*node;
    ll r=l+1;
    ll m=(b+e)/2;

    if(prop[node]!=-1)
    {
        prop[l]=prop[node];
        prop[r]=prop[node];
        tree[l]=prop[node];
        tree[r]=prop[node];
        prop[node]=-1;
    }
    return query(l,b,m,i,j)|query(r,m+1,e,i,j);
 }
 
pair<int,int>A[limit];
int main()
{
    /*  freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/ 
    ll test;
    cin>>test;
    tst(test)
    {
        memset(prop,-1,sizeof prop);
        memset(tree,0,sizeof tree);
        int n;
        si(n);
        for1(n)
        {
            si(A[i].ff);
            si(A[i].ss);
        }

        reverse(A,A+n);
        update(1,1,2*n,1,2*n,1);
        int ans=0;

        for1(n)
        {
         if(query(1,1,2*n,A[i].ff,A[i].ss))ans++;
         update(1,1,2*n,A[i].ff,A[i].ss,0);
        }

        printf("Case %d: %d\n",cs,ans);
    }
}
 
