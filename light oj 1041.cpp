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

 
ll pr[102];
 



ll int pfind(ll int n){
 
if(pr[n]==n) {return n;}
 
return pr[n]=pfind(pr[n]);
}



void unionmake(ll int x,ll int y){
 
    x=pfind(x);
    y=pfind(y);
 
pr[y]=x;
 
 
}

ll x,y;

vector<ll>graph[102];
vector<ll>graph1[102];
bool visited[102];
ll cc=0;
void dfs(ll u){

visited[u]=true;

graph1[cc].pb(u);
for(ll i=0;i<graph[u].size();i++){

ll v=graph[u][i];
if(visited[v])continue;
dfs(v);


}


}

int main()
{
/* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/


ll test;

cin>>test;

tst(test){

ll n;

sl(n);
ll c=1;
map<string,ll>mp;

ll cost[102][102];

for(ll i=0;i<=100;i++){


	for(ll j=0;j<=100;j++){
		cost[i][j]=limit;
	}
}


for(ll i=0;i<n;i++){

ll xx;
string A,B;
cin>>A>>B>>xx;
if(mp[A]==0){


	mp[A]=c;
c++;
}

if(mp[B]==0){


	mp[B]=c;
c++;
}
 x=mp[A];
 y=mp[B];

cost[x][y]=min(cost[x][y],xx);
cost[y][x]=min(cost[x][y],xx);;

if(xx==0){

	graph[x].pb(y);

	graph[y].pb(x);
}

}
 cc=1;
 // /cout<<c<<endl;
for(ll i=1;i<c;i++){

if(visited[i])continue;

dfs(i);
//nl
cc++;


}

//cout<<cc<<endl;
vector<pair<ll,iPair> >an;

for(ll i=1;i<cc;i++){

for(ll j=i+1;j<cc;j++){


ll mn=limit;

for(ll k=0;k<graph1[i].size();k++){



	for(ll l=0;l<graph1[j].size();l++){


mn=min(cost[graph1[i][k]][graph1[j][l]],mn);

	}
}

if(mn>=limit)continue;

an.pb(mkpr(mn,mkpr(i,j)));
}

}


for(ll i=0;i<=100;i++){

	pr[i]=i;
}
sort(an.begin(),an.end());
ll ans=0;

for(ll i=0;i<an.size();i++){



 x=an[i].ss.ff;
 y=an[i].ss.ss;
ll cost=an[i].ff;
 

    x=pfind(x);
    y=pfind(y);

    

    if(x==y)continue;
unionmake(x,y);

ans+=cost;

}

ll pp=pfind(1);
bool no=false;


for(ll i=2;i<cc;i++){

ll pf=pfind(i);
	if(pp!=pf){


		no=true;
		//break;
	
	}
}
if(no){
	printf("Case %d: Impossible\n",cs);


}
else{

printf("Case %d: %lld\n",cs,ans);

}


for(ll i=0;i<=100;i++){


	graph1[i].clear();
	graph[i].clear();

visited[i]=false;
}

}

}
