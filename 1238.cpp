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
#define  INFP  ((ll)1<<62)
#define  INFN ((ll)1<<62)
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
 
vector<iPair>graph[406];
ll pos[22][22];
 
priority_queue< iPair, vector<iPair>,greater<iPair> >pq;
 
ll dis[402];
 
void  diakstra(ll n){
 
    dis[n]=0;
 
    pq.push(mkpr(0,n));
 
 
    while(!pq.empty()){
 
ll u=pq.top().ss;
pq.pop();
 
for(ll i=0;i<graph[u].size();i++){
    ll v=graph[u][i].ff;
    ll cost=graph[u][i].ss;
 
    if(dis[v]>dis[u]+cost){
 
 
 
        dis[v]=dis[u]+cost;
 
 
        pq.push(mkpr(dis[v],v));
    }
 
 
 
 
}
 
 
 
    }
 
 
}
 
 
 
int main()
{
       ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};
    
 
       ll c=1;
 
      for(ll i=0;i<20;i++)
      {
       
       
       
          for(ll j=0;j<20;j++)
          {
       
       
              pos[i][j]=c;
                c++;
          }
      }
/*
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
 
 
      ll test;
 
      cin>>test;
 
      tst(test){

            for(ll i=0;i<=402;i++)
            {
             
                dis[i]=INFP;
            }
       
             ll n,m;
       
             sl2(n,m);
       
             char A[22][22];
            for(ll i=0;i<n;i++)
            {
             
            scanf("%s",&A[i]);
             
            }
     
          ll hm;
   
          for(ll i=0;i<n;i++)
          {
           
                for(ll j=0;j<m;j++)
                {
                 
                    if(A[i][j]=='h'){
                     
                    hm=pos[i][j];
                     
                    }
   
                    ll u=pos[i][j];
                    for(ll k=0;k<4;k++){
                     
                     
                    ll x=dx[k]+i;
                    ll y=dy[k]+j;
                     
                     
                    if(x>n||y>m||x<0||y<0||A[x][y]=='#'||A[x][y]=='m')continue;
                     
                    ll v=pos[x][y];
                     
                    graph[u].pb(mkpr(v,1));
                   
                    }
   
               }
   
         }
 

           
          diakstra(hm);
          ll  mx=0;
 
          for(ll i=0;i<n;i++){
           
           
              for(ll j=0;j<m;j++)
              {
           
           
                  if(A[i][j]=='a'||A[i][j]=='b'||A[i][j]=='c')
                  {
                   
                   
                      mx=max(mx,dis[pos[i][j]]);
                  }
           
              }
          }
 
           
          for(ll i=0;i<=402;i++)graph[i].clear();
           
          printf("Case %d: %lld\n",cs,mx);
 
 
      }
 
/* ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* ll dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* ll dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* ll dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
 
}
 