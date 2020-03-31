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
#include<bits/stdc++.h>


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
#define lmt 2520
//string to_string(ll n) { stack<ll>st; while(n) { st.push(n%10); n=n/10; } string A=""; while(!st.empty()) { A+=(char)(st.top()+'0'); st.pop(); } return A; }


             typedef pair<ll,ll> iPair;
 
             //ll dp[11][91][91][2][2];
             
    
             ll n,k;

         

             iPair dp[11][2][2];
             string A;



            
            iPair solve(ll pos,bool taken,bool flg)
            {


             // cout<<pos<<" "<<taken<<" "<<flg<<endl;
               
             if(pos==n)
               {
                  
                 return  mkpr(1LL,0LL) ;
               }

               iPair  & ret = dp[pos][taken][flg];

               if(ret.ff!=-1)return ret;

               ll sm=0,cnt=0;

               for(ll i=0;i<=9;i++)
               {

                 

                 if(!taken&&(A[pos]-'0')<i)continue;

                 bool tkn=taken;
                 bool  flag=flg;

                 if(i<A[pos]-'0')tkn=true;
                 if(i!=0)flag=true;

                 iPair res=solve(pos+1,tkn,flag);

                 
                 cnt+=res.ff;
                 sm +=res.ss;

                 if(i==0&& flg)sm+=res.ff;



               }

               return  ret=mkpr(cnt,sm);

              

               


            }

int main()
{          /*
           freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);*/





            ll test;

            cin>>test;

            tst(test)
            {


                ll l,r;

                sl2(l,r);

                A=to_string(r);

             
                n=A.size();
              
                memset(dp,-1,sizeof dp);

                iPair ans=solve(0,0,0);

               // cout<<ans.ff<<" aa "<<ans.ss<<endl;



                memset(dp,-1,sizeof dp);
       
               

                A=to_string(l-1);
                n=A.size();
                iPair p=solve(0,0,0);


                if(l-1<0)
                  p.ss=-1;



                //cout<<p.ss<<endl;

        
               

                

                printf("Case %d: %lld\n",cs,ans.ss-p.ss);
   

            }






              /**
             *    @author     : Ikbal Hossain
             *    @College    : RUET CSE 15
             *    @CodeForces : iAmrifat
             *    @UVA        : rifat_ikbal
             *    @link       : https://www.facebook.com/ikbal.rifat.5
             */

            /* ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
            /* ll dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
            /* ll dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
            /* ll dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

}

