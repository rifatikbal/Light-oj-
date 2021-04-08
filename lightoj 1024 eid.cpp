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
//this templete is collected from someone else 
string multiply( string a, long long b )
{
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

ll int prime[10000];
bool  check[10007];
ll int   sieve(ll int n)
{
    ll int z,x=1;
    prime[0]=2;
    check[1]=check[0]=true;
    for(int i=3;i*i<=n;i+=2)
    {
        if(!check[i])
        {
            prime[x]=i;
            x++;
            for(int j=i*i;j<=n;j+=i)
            {
                check[j]=true;
            }
        }
        z=i;
    }
    for(int j=4;j<=n;j+=2)
    {
        check[j]=true;
    }
    for(int j=z+1;j<=n;j++)
    {
        if(!check[j])
        {
            prime[x]=j;
            x++;
        }
    }
    return  x;
}

int main()
{
 /*freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);*/
    ll x=sieve(10000);
    ll test;
    cin>>test;
    tst(test)
    {
        int A[1005];
        int cnt[10002];
        memset(cnt,0,sizeof(cnt));
        
        ll n;
        sl(n);
        for(ll i=0;i<n;i++)sl(A[i]);

        for1(n)
        {
            int s=A[i];
            for(ll j=0;j<25&&prime[j]*prime[j]<=A[i];j++)
            {
                int  c=1;
                while(s%prime[j]==0)
                {
                    s/=prime[j];
                    c*=prime[j];
                }
                if(c==1)continue;
                cnt[prime[j]]=max(cnt[prime[j]],c);
            }
            if(s!=1)
            {
                cnt[s]=max(cnt[s],s);
            }
        }

        string ans="1";
        for(ll i=0;i<x;i++)
        {
            if(cnt[prime[i]]==0)continue;
            ans=multiply(ans,cnt[prime[i]]);
        }

        char Ans[2000007];
        for(ll i=ans.size()-1;i>=0;i--)Ans[ans.size()-i-1]=ans[i];

        Ans[ans.size()]='\0';
        printf("Case %d: %s\n",cs,Ans);
    }
}
