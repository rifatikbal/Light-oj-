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
#define limit 33*50006
 
 
typedef pair<ll,ll> iPair;
int node;
int  tree[limit][3];
void insert(int mask){
 
int  pos=1;
 
 
for(int i=31;i>=0;i--){
 
bool p=(bool)(mask&(1<<i));
 
if(tree[pos][p]!=-1){
 
 
    pos=tree[pos][p];
}
 
 
else{
 
 
    tree[pos][p]=node;
pos=node;
    node++;
}
 
}
 
}
 
int  checkmx(int mask){
 
 
 
//cout<<mask<<endl;
int  pos=1;
int  ans=0;
 
for(int i=31;i>=0;i--){
 
bool p=!((bool)(mask&(1<<i)));
 
//cout<<p<<" "<<tree[pos][p]<<" ";
 
if(tree[pos][p]!=-1){
 
 
    pos=tree[pos][p];
 
ans=(ans<<1);
ans++;
 
 
}
else{
 
 
    pos=tree[pos][!p];
 
    ans=(ans<<1);
    //node++;
}
 
}
return ans;
}
 
 
int   checkmn(int mask){
int  pos=1;
int ans=0;
 
for(int i=31;i>=0;i--){
 
bool p=(bool)(mask&(1<<i));
 
 
 
if(tree[pos][p]!=-1){
 
 
    pos=tree[pos][p];
 
ans=(ans<<1);
 
}
else{
 
 
    pos=tree[pos][!p];
 
    ans=(ans<<1);
 
//ans=(ans<<1);
ans++;  //node++;
}
 
}
return ans;
}
 
int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 
 
    int test;
 
    cin>>test;
 
    tst(test){
 
        node=2;
 
        memset(tree,-1,sizeof tree);
int n;
 
si(n);
insert(0);
 
int  s=0,mn=(1LL<<31-1),mx=0;
for(int i=1;i<=n;i++){
ll a;
si(a);
 
s^=a;
 
mn=min(mn,checkmn(s));
mx=max(mx,checkmx(s));
 
//bug
//cout<<mx<<endl;
 
 
insert(s);
}
 
printf("Case %d: %d %d\n",cs,mx,mn);
 
//cout<<test<<endl;
 
    }
 
//Case 1: 14 2
 
 
}
 
