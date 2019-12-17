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
#define limit 30000


typedef pair<int,int > iPair;

ll dis[limit+3];
bool visited[limit+3];

vector<iPair>graph[limit+3];

void  bfs(ll node){


queue<int>q;
q.push(node);
dis[node]=0;
while(!q.empty()){


ll u=q.front();

//ll cost=q.front().ss;

visited[u]=true;
//cout<<u<<endl;
q.pop();
for(ll i=0;i<graph[u].size();i++){

ll v=graph[u][i].ff;
ll cost=graph[u][i].ss;

if(!visited[v]){

    dis[v]=dis[u]+cost;

    q.push(v);
}



}


}



}

int main()
{
/* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
ll  test;
cin>>test;

tst(test){


ll  n;

sl(n);

for(ll i=1;i<n;i++){


ll a,b,c;

sl3(a,b,c);


graph[a].pb(mkpr(b,c));
graph[b].pb(mkpr(a,c));
}

//bug1
bfs(0);

ll z,mx=0;
for(ll i=0;i<n;i++){


if(dis[i]>=mx){

    mx=dis[i];

    z=i;
}

dis[i]=0;
visited[i]=false;
}


bfs(z);
mx=0;

for(ll i=0;i<n;i++){



if(dis[i]>=mx){

    mx=dis[i];

  
}

dis[i]=0;

visited[i]=false;
graph[i].clear();
}



printf("Case %d: %lld\n",cs,mx);




}


}
