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
#include <time.h>
 
 
using namespace std;
 
#define ll long long
#define mod (1LL<<32)
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
#define limit 100000008
 
 
typedef pair<ll,ll> iPair;

int prime[5761460],mulp[5761460];
int  check[(100000003/32)+3];

ll bitwise_sieve(ll n)
{ 
    int z,x=1;
    prime[0]=2;
    check[0]=check[0]|(1<<0);
    check[0]=check[0]|(1<<1);
 
    for(int i=3;i*i<=n;i+=2)
    { 
         if(!(bool)(check[i/32]&(1<<(i%32))))
         {
            prime[x]=i;
            x++;
            for(int j=i*i;j<=n;j+=i)
            {
                check[j/32]=check[j/32]|(1<<(j%32));
            }
        }
        z=i;
    }
 
    for(int j=4;j<=n;j+=2)
    {
         check[j/32]=check[j/32]|(1<<(j%32));
    }

    for(int j=z+1;j<=n;j++)
    {
        if(!(bool)(check[j/32]&(1<<(j%32))))
        {
            prime[x]=j;
            x++;
        }
    }
    return  x;
}

int main()
{
    int x=bitwise_sieve(100000000);
    mulp[0]=1;
    ll p=1;
    for(ll i=0;i<x;i++)
    {
        p=mulp[i]*prime[i];
        p=mulp[i]*prime[i];
        mulp[i+1]=p%mod;
        mulp[i+1]%=mod;
    }
    int test;
    cin>>test;
    ulli ans;
    tst(test)
    {
        int n;
        si(n);
        ans=1;
        for(ll i=0;prime[i]*prime[i]<=n;i++)
        {
            ll t=n/prime[i];
            while(t/prime[i])
            {
                t/=prime[i];
                ans*=prime[i];
                ans%=mod;
            }
        }
        ll pos=upper_bound(prime,prime+x,n)-prime;
        ans*=(mulp[pos]%mod);
        ans%=mod;
        printf("Case %d: %lld\n",cs,ans);
    }
}
 
