#include<bits/stdc++.h>
using namespace std;
int white[101];
int main()
{
        freopen("input.txt","r",stdin);
/*    freopen("output.txt","w",stdout);*/
    int tstcase,cs=1;
    cin>>tstcase;
    while(cs<=tstcase)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>white[i];
        int xr=0;
        for(int i=1;i<=n;i++)
        {
            int black;
            cin>>black;
            xr^=(black-white[i]-1);
        }
        cout<<"Case "<<cs<<": ";
        if(xr)cout<<"white wins\n";
        else cout<<"black wins\n";
        cs++;
    }
}
