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
#define  pys puts("YES");
#define  pno  puts("NO");
#define bug puts("bug");
#define  pmn puts("-1");
#define zero puts("0");
#define limit 100001
#define md 1000000007
 
 
 
 
   typedef pair<int,int> iPair;
   int par[limit][20],pmx[limit][20],n,lavel[limit];
 
   VI graph[limit];
 
   void  sparse(int n)
   {
 
   for(int j=1;(1<<j)<=n;j++)
   {
 
      for(int i=0;i<n;i++)
      {      
 
        if(par[i][j-1]==-1)continue;
 
        par[i][j]=par[par[i][j-1]][j-1];
 
        pmx[i][j]=max(pmx[i][j-1],pmx[par[i][j-1]][j-1]);
 
 
      }
 
   }
 
 
   }
 
 
   int query(int x,int y)
   {
 
 
    int l=0,h=lavel[x]-1;
 
    //cout<<h<<endl;
 
 
    while(l<h)
    {          
 
             // cout<<l<<" aa "<<h<<endl;
 
 
                int m=(l+h+1)/2;
 
                int p=m;
                int xx=x;
             
 
                for(int i=log2(n)+1;i>=0;i--)
                {
                 
 
                  if((1<<i)<=p)
                  {
 
                    //cout<<i<<endl;
 
                    xx=par[xx][i];
 
                    p-=(1<<i);
                  }
 
                }
 
               //cout<<xx<<" yy "<<p<<endl;
 
                p=lavel[xx];
                int mx=0;
               
 
                 for(int i=log2(n)+1;i>=0;i--)
                {
 
                  if((1<<i)<=p)
                  {
 
                 //   cout<<i<<endl;
 
                    mx=max(mx,pmx[xx][i]);
 
                    xx=par[xx][i];
 
                    p-=(1<<i);
                  }
 
                }
 
                //cout<<mx<<" dd "<<p<<endl;
 
                if(mx<y)
                {
 
                  h=m-1;
                }
                else
                {
 
                  l=m;
                }
 
               // cout<<l<<" sss "<<h<<endl;
               
     }
 
     //cout<<l<<" ss "<<endl;
 
              int p=l;
 
             
 
 
                 for(int i=log2(n)+1;i>=0;i--)
                {
 
                  if((1<<i)<=p)
                  {
 
                    x=par[x][i];
                    p-=(1<<i);
                  }
 
                }
 
                //cout<<x<<endl;
 
                return x;
 
 
 
 
 
   }
 
 
 
   void dfs(int u,int pr)
   {
 
 
    for(int i=0;i<graph[u].size();i++)
    {
 
      int v=graph[u][i];
 
      if(v==pr)continue;
         lavel[v]=lavel[u]+1;
      dfs(v,u);
    }
   }
 
 
int main()
{
 
               
     /*  freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
 
                int test;
                cin>>test;
                tst(test)
                {    
                   
                    memset(pmx,0,sizeof pmx);
                    memset(par,-1,sizeof par);
 
                    memset(lavel,0,sizeof lavel);
                    int m;
 
                    si2(n,m);
                    graph[0].clear();
 
                    for(int i=1;i<n;i++)
                    {
 
                      int a,b;
 
                      si2(a,b);
 
                      graph[a].pb(i);
                      graph[i].pb(a);
                   
 
                      par[i][0]=a;
                      pmx[i][0]=b;
                      graph[i].clear();
                    }
                    pmx[0][0]=1;
 
                      lavel[0]=1;
                     dfs(0,-1);
                    sparse(n);
 
                    //cout<<lavel[5]<<endl;
 
                   
 
                    printf("Case %d:\n",cs);
                 
 
                    fr(i,1,m)
                    {
                     
                      int x,y;
                      si2(x,y);
 
                      printf("%d\n",query(x,y));
 
 
                    }
 
                   
                }
 
                //cout<<pmx[0][0]<<endl;
       
 
 
 
 
 
   
 
 
 
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
 
 
 
 
 
