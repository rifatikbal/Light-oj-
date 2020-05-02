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
#define limit 50001
#define md 1000000007
 
 
 
 
   typedef pair<int,int> iPair;
   int lavel[limit],par[limit][19],pmx[limit][19],pr[limit];
 
   vector<iPair>graph[limit];
 
   ll int pfind(ll int n)
   {
 
    if(pr[n]==n) {return n;}
     
    return pr[n]=pfind(pr[n]);
 
 
  }
 
   void dfs(int u,int pp)
   {
           //cout<<u<<" "<<pp<<endl;
 
    for(int i=0;i<graph[u].size();i++)
    {
 
       int v=graph[u][i].ff;
 
 
 
       if(v==pp)continue;
 
       //cout<<v<<" ";
       int cst=graph[u][i].ss;
       lavel[v]=lavel[u]+1;
       pmx[v][0]=cst;
       par[v][0]=u;
 
       dfs(v,u);
    }
    //nl
 
   }
 
   void  sparse(int n)
   {
 
   for(int j=1;(1<<j)<=n;j++)
   {
 
      for(int i=1;i<=n;i++)
      {      
 
        if(par[i][j-1]==-1)continue;
 
        par[i][j]=par[par[i][j-1]][j-1];
 
        pmx[i][j]=max(pmx[i][j-1],pmx[par[i][j-1]][j-1]);
 
 
      }
 
   }
 
 
   }
 
 
   int query(int x,int y)
   {
 
 
       if(lavel[x]<lavel[y])
       {
         int z=x;
          x=y;
          y=z;
 
       }
 
       int p=18,mx=0;
                     
       for(int i=p;i>=0;i--)
       {
 
              if(lavel[x]-(1<<i)>=lavel[y])
              {
                   mx=max(mx,pmx[x][i]);
 
 
                    x=par[x][i];
 
             
              }
 
       }
 
       if(x==y)return mx;
 
       for(int i=p;i>=0;i--)
       {
 
           
          if(par[x][i]!=-1&&(par[x][i]!=par[y][i]))
          {
 
            mx=max(mx,pmx[x][i]);
            mx=max(mx,pmx[y][i]);
 
            x=par[x][i];
            y=par[y][i];
             
 
          }
 
     
 
       }
           mx=max(mx,pmx[x][0]);
          mx=max(mx,pmx[y][0]);
 
       return mx;
 
 
 
   }
 
 
 
 
 
 
int main()
{/*
 
               
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/
 
                int test;
                cin>>test;
                tst(test)
                {    
                    memset(par,-1,sizeof par);
                    memset(pmx,0,sizeof pmx);
                    int n,m;
 
                    si2(n,m);
 
                    fr(i,1,n)pr[i]=i,graph[i].clear();
 
                    vector< pair<int,iPair> >v;
 
                    fr(i,1,m)
                    {
 
                      int a,b,c;
                      si3(a,b,c);
                      v.pb(mkpr(c,mkpr(a,b)));
 
                    }
 
                   // bug
 
                   // for(int i=1;i<=n;i++)
 
                    srt(v);
 
                    fr(i,0,m-1)
                    {
 
                      int x=pfind(v[i].ss.ff);
                      int y=pfind(v[i].ss.ss);
 
             
 
                      if(x!=y)
                      {
 
                        pr[y]=x;
 
                        graph[v[i].ss.ff].pb(mkpr(v[i].ss.ss,v[i].ff));
                        graph[v[i].ss.ss].pb(mkpr(v[i].ss.ff,v[i].ff));
 
                      }
 
                    }
 
                    lavel[1]=0;
 
                   
 
                    dfs(1,-1);
 
                 
 
                    sparse(n);
                   
 
                    printf("Case %d:\n",cs);
                    int q;
                    si(q);
 
                    fr(i,1,q)
                    {
                     
                      int x,y;
                      si2(x,y);
 
                      printf("%d\n",query(x,y));
 
 
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
 
 
 
 
