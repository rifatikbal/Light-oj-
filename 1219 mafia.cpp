#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ulli unsigned ll int
#define all(v)  v.begin(),v.end()
#define ub(v,x)  upper_bound(all(v),x)
#define lb(v,x)  lower_bound(all(v),x)
#define  mmst(A,val)  memset(A,val,sizeof A);
#define  pll pair <ll, ll>
#define  vctr(n) vector<n>
#define  pb push_back
#define  pf push_front
#define  mkpr  make_pair
#define  ff   first
#define  ss  second
#define  srt(V)  sort(V.begin(),V.end());
#define  rsrt(V)  sort(V.rbegin(),V.rend());
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define  nl cout<<"\n";  
#define  PI  2*acos(0.0);
#define  INFP ((ll)1<<62)
#define  INFN (0-(ll)1<<62)
#define  fr(i,a,b) for(int i=a;i<=b;i++)
#define  frr(i,a,b) for(int i=a;i>=b;i--)
#define  tst(n)  for(int cs=1;cs<=n;cs++)
#define  pys cout<<"YES\n";
#define  pno cout<<"NO\n";
#define  bug cout<<"bug\n";
#define  pmn cout<<"-1\n";
#define  limit 300001
#define  md 100000007
#define  sq(n)  n*n
#define pcs cout<<"Case "<<cs<<": ";
typedef pair<ll,ll> iPair;
int value[limit],ans=0;
vctr(int) graph[limit];
bool visited[limit];
int dfs(int u)
{
   if(visited[u])return 0;
   visited[u]=true;
   int extra=value[u]-1;
   for(int adj:graph[u])
   {
     int temp=dfs(adj);
     extra+=temp;
     ans+=abs(temp);
   }
   return extra;
}

int main()
{
/*     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr);
     ll test;
     cin>>test;
     tst(test)
     {
        int n;
        cin>>n;
        fr(i,1,n)visited[i]=false,graph[i].clear();
        fr(i,1,n)
        {
          ll node,val,adj;
          cin>>node>>val>>adj;
          value[node]=val;
          fr(i,1,adj)
          {
            ll nd;
            cin>>nd;
            graph[node].pb(nd);
            graph[nd].pb(node);
          }
        }
        ans=0;
        dfs(1);
        pcs
        cout<<ans<<"\n";
     }  
}
