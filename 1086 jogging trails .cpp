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
#define  INFP ((ll)1<<40)
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

vctr(int)graph[16];
ll cost[16][16],n,sz;
ll dp[1<<17];
vctr(int) comb;
stack<int>st1,st2;

bool check(int mask,int pos)
{
  return (mask&1<<pos);
}

ll solve(int mask)
{
    ll & ret=dp[mask];

    if(mask==(1<<sz)-1)return 0;
    if(ret!=-1)return ret;
    
    ret=INFP;
    fr(i,0,sz-1)
    {
      if(check(mask,i))continue;
      fr(j,0,sz-1)
      {
        if(i==j)continue;
        if(check(mask,j))continue;
        ret=min(ret,cost[comb[i]][comb[j]]+solve(mask|1<<i|1<<j));
      }
    }

    return ret;
}

void initialize()
{
  comb.clear();
  fr(i,0,n-1)
    fr(j,0,n-1)cost[i][j]=INFP;

  fr(i,0,n-1)graph[i].clear();
}

void Belmnford()
{
    for(int k=0;k<n;k++)
    {
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(cost[i][j]>cost[i][k]+cost[k][j])cost[i][j]=cost[i][k]+cost[k][j];
        }
      }
    }
}

int main()
{
/*     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);*/
     ios_base::sync_with_stdio(0);
     cin.tie(nullptr);
     int test;
     cin>>test;
     tst(test)
     {
        int m;
        cin>>n>>m;
        initialize();

        ll ans=0;
        fr(i,1,m)
        {
          int a,b,c;
          cin>>a>>b>>c;
          graph[a-1].pb(b-1);
          graph[b-1].pb(a-1);
          cost[a-1][b-1]=min(cost[a-1][b-1],(ll)c);
          cost[b-1][a-1]=cost[a-1][b-1];
          ans+=c;
        }

        Belmnford();
        
        for(int i=0;i<n;i++)
        {
           if(graph[i].size()%2)comb.pb(i);
        }

        sz=comb.size();
        mmst(dp,-1);

        if(sz>0) ans+=solve(0);
        
        pcs 
        cout<<ans<<endl;
      }
    }

