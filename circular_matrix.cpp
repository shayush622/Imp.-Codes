#include <bits/stdc++.h>
using namespace std;
 
 int main()
 {
       #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


     int n;
     cin >> n;
     int a[n][n];
     int dim = n;
     int k = n/2;
     if(n&1)
        a[n/2][n/2] = n*n;
     int num=1;
        int i=0,j=0;
     for( int x =0;x<k;x++ )
     {
        i=x;
        j=x;
        for( ; i<n;i++)
        {
                a[j][i]=num;
                num++;
        }
        j++; i--; 
        for(; j<n;j++)
        {
            a[j][i]=num;
            num++;
        }
        i--; j--;
        for( ; i>=x; i--)
        {
            a[j][i] = num;
            num++;
        }
        i++; j--;
        for( ;j>x; j--)
        {
            a[j][i] = num;
            num++;
        }
        n--;
     }
     for(int i=0;i<dim;i++)
     {
        for(int j=0;j<dim;j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
     }
    return 0;
 }