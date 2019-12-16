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
#define limit 10000



typedef pair<ll,ll> iPair;
ll frq[limit+2];
ll col[limit+2];
ll high[limit+2];
ll low[limit+2];
bool visited[limit+2];
vector<ll>graph[limit+2];
stack<ll>st;
ll cc=0;

void  dfs(int u,int pr,int depth){
    visited[u]=true;

    st.push(u);
    high[u]=low[u]=depth;
    int child=0;
    for (int i = 0; i < graph[u].size(); i++) {
        
 
        int v=graph[u][i];
        if(visited[v]== true&& v!= pr ) {
 
            low[u]=min(low[u],high[v]);
 
        
        }
        else if(visited[v]!= true) {
 
 
 
            dfs(v, u, depth + 1);
 
            low[u]=min(low[u],low[v]);
      
        }
 
 
    }


 if(high[u]==low[u]){
cc++;

while(!st.empty()){

col[st.top()]=cc;



    if(u==st.top()){
    st.pop();
    break;
}

st.pop();
}



 }
 
}

int main()
{
/* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

ll test;

cin>>test;

tst(test){
    cc=0;
ll n,m;

sl2(n,m);

for(ll i=0;i<m;i++){

ll a,b;
sl2(a,b);

graph[a].pb(b);
graph[b].pb(a);


}

dfs(0,-1,0);


ll ans=0;

for(ll i=0;i<n;i++){

for(ll j=0;j<graph[i].size();j++){


    ll v=graph[i][j];

if(col[i]==col[v])continue;


//cout<<i<<" "<<v<<endl;
frq[col[i]]++;
frq[col[v]]++;


}


}


for(ll i=0;i<=cc;i++){
//cout<<frq[i]<<endl;

if(frq[i]==2){


frq[i]=0;

    ans++;
}
frq[i]=0;
}

frq[cc+1]=0;

printf("Case %d: %lld\n",cs,(ans+1)/2);

for(ll i=0;i<n;i++){
    graph[i].clear();

    visited[i]=false;
    col[i]=0;

}


}

}
