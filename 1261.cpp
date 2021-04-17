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
#define VI  vector<int>
#define Vll  vector<ll>
#define   all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)

bool check(int x,int pos){return  (bool)(x &(1<<pos));}
int st(int x,int pos){  return x= x |(1<<pos);}
int  Reset(int x,int pos ){ return x= x &~(1<<pos);}

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
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define  bug1(a)  cout<<a<<endl;
#define  bug2(a,b)  cout<<a<<" "<<b<<endl;
#define  bug3(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl;
#define  bug4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define spc <<" "<<
#define  pys puts("Yes");
#define  pno  puts("No");
#define bug puts("bug");
#define  pmn puts("-1");
#define zero puts("0");
#define limit 200006
#define md 1000000007

typedef pair<ll,ll> iPair;

int main()
{              /*
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
       ll test;
       cin>>test;
       tst(test)
       {
           int n,m,k;
           bool check[32];
           memset(check,false,sizeof check);

           si3(n,m,k);
           VI v[31];
           
           fr(i,1,n)
           {
              fr(j,1,k)
              {
                  string C;
                  cin>>C;
                  int x=0;
                  for(int l=1;l<C.size();l++)
                  {
                    x*=10;
                    x+=C[l]-'0';
                  }
                  if(C[0]=='+')v[i].pb(x);
                  else v[i].pb(-x);
              }
           }
           int mm;
           si(mm);
           fr(i,1,mm)
           {
             int a;
             si(a);
             check[a]=true;
           }

           bool no=false;

           fr(i,1,n)
           {
              bool ys=false;
              fr(j,0,k-1)
              {
                if(v[i][j]<0)
                 { 
                  if(!check[abs(v[i][j])]){//cout<<v[i][j]<<endl;
                    ys=true;}
                 }
                 else
                 {
                   if(check[v[i][j]])ys=true;
                 }
              }
              if(!ys)no=true;
            }
            
            printf("Case %d: ",cs);
            if(no)
            {
              pno
            }
            else
            {
              pys
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
 
 
 
 
