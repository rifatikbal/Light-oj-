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




typedef pair<ll,ll> iPair;

char A[limit],B[limit];
int main()
{
 
     /*          
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);*/

        int test;
        cin>>test;
        tst(test)
        {
              scanf("%s",A);

              printf("Case %d: ",cs);


              int n=strlen(A);
              B[0]='\0';


              for(int i=0;i<n/2;i++)
              {


                B[i]=A[i];
                B[n-i-1]=A[i];

              }
              
              B[n]='\0';

              if(n%2)B[n/2]=A[n/2];
                  
             


              bool ys=false;
              for(int i=0;i<n;i++)
              {

                if(A[i]<B[i]){ys=true;break;}
                if(A[i]>B[i])break;

               }

             
              if(ys)printf("%s\n",B);
              else
              {

                int z=n/2;

                if(n%2)z++;
                int zz=-1;

                for(int i=z-1;i>=0;i--)
                {

                  if(A[i]<'9')
                  {
                    zz=i;
                    break;
                  }
                }

                if(zz==-1)
                {
                  cout<<"1";
                  for(int i=1;i<n;i++)cout<<"0";
                    
                    cout<<"1";
                    nl

                }
                else
                {

                    A[zz]=A[zz]+1;

                    for(int i=zz+1;i<z;i++)A[i]='0';


                    for(int i=0;i<n/2;i++)
                    {

                      B[i]=A[i];
                      B[n-i-1]=A[i];
                    }

                    B[n]='\0';

                    if(n%2)B[n/2]=A[n/2];
                   
                     printf("%s\n",B);

                }



              }


      }
       




}
 
 
 
 