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
 
 
ll int prime[6548];
bool  check[(1<<16)+8];
ll int   sieve(ll int n){
ll int z,x=1;
prime[0]=2;
check[1]=check[0]=true;
 
 
for(int i=3;i*i<=n;i+=2){
 
if(!check[i]){
prime[x]=i;
x++;
    for(int j=i*i;j<=n;j+=i){
 
        check[j]=true;
    }
}
z=i;
}
for(int j=4;j<=n;j+=2){
    check[j]=true;
 
}
for(int j=z+1;j<=n;j++){
 
    if(!check[j]){
prime[x]=j;
x++;
 
    }
}
return  x;
 
}
 
bool visited[100008];
int main()
{
/*
 freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
*/

 
 
ll x=sieve(1<<16);
 
//cout<<(1<<16)<<endl; 
 

 //cout<<x<<endl;
ll test;
 
cin>>test;


 
tst(test){
 
memset(visited,false,sizeof visited);
ll a,b;
 
sl2(a,b);
 if(a==1)a++;


ll ans=0;
for(ll i=0;i<x&&prime[i]<=b;i++){
 

 
ll p=(a/prime[i])*prime[i];



if(p<a){

    p+=prime[i];
}

if(p<(1<<16)&&!check[p]){

    p+=prime[i];
}


 


 
for(ll j=p;j<=b;j+=prime[i]){
 
 
//cout<<j<<" ";
visited[j-a]=true;
 
 
}
//bug1
 
 
 
}
 
for(ll j=a;j<=b;j++){
 
if(!visited[j-a]){
 

 //cout<<j<<" ";
//  cout<<j<<" ";
 
    ans++;
}
 
}
 
printf("Case %d: %lld\n",cs,ans);
}
 
 
 
}
 