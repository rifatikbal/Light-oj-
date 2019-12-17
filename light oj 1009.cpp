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
#define limit 20000
 
 
typedef pair<ll,ll> iPair;
 
vector<ll>graph[limit+2];
 
ll x=0,y=0;
ll rac[limit+2];
bool visited[limit+2];
 
 
void  bfs(ll node){
 
 
queue<ll>q;
q.push(node);
 
 
rac[node]=-1;
 
while(!q.empty()){
 
 
ll u=q.front();
//cout<<u<<" ";
if(rac[u]==-1){
//    cout<<"a"<<u<<" ";
    x++;}
else{
      //cout<<"b"<<u<<" ";
 
    y++;
}
 
visited[u]=true;
q.pop();
 
for(ll i=0;i<graph[u].size();i++){
 
ll v=graph[u][i];
 
 
if(!visited[v]){
    visited[v]=true;
if(rac[u]==-1){
 
    rac[v]= 1;
}
else{
rac[v]=-1;    
}
 
    q.push(v);
}
 
}
 
 
}
 
 
 
}
 
int main()
{
 /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
ll test;
 
cin>>test;
 
tst(test){
 
ll n;
 
sl(n);
for1(20001){
 
 
    visited[i]=true;
}
 
for(ll i=0;i<n;i++){
ll a,b;
sl2(a,b);
//xz=a;
visited[a]=false;
visited[b]=false;
graph[a].pb(b);
 
graph[b].pb(a);
 
}
 
 
 
for(ll i=1;i<=20000;i++){
 
 
    if(visited[i])continue;
 
    //cout<<i<<"\n";
}
 
ll ans=0;
x=0;
y=0;
for(ll i=1;i<=20000;i++){
 
 
if(visited[i])continue;
 
x=0;
y=0;
bfs(i);
 
 
//nl
//cout<<i<<" "<<x<<" aa "<<y<<endl;
 
ans+=max(x,y);
 
 
}
 
 
printf("Case %d: %lld\n",cs,ans);
 
 
for1(20001){
 
    graph[i].clear();
}
}
 
 
}
 