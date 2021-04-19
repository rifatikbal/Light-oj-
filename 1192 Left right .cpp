#include<bits/stdc++.h>
using namespace std;
// Alice could move gray pieces to the left
// Bob could move white pieces to the right
// started with gray pieces 
// number of pieces ar alternates
//2
// corner cases no corner cases
//0 3 7 9
int main()
{
    int tcase,cs=1;
    cin>>tcase;
    while(cs<=tcase)
    {
        int n,z=-1,dsum=0;
        cin>>n;
        n*=2;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(z==-1)z=a;
            else dsum+=(a-z-1),z=-1;
        }
        //cout<<dsum<<endl;
        cout<<"Case "<<cs<<": ";
        if(dsum%2)cout<<"Alice\n";
        else cout<<"Bob\n";
        cs++;
    }
}