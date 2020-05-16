#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,c=0;
    cin>>t;
    while(c!=t) {
        c++;
        int n,k,p;
        cin>>n>>k>>p;
        int arr[n][k], sum[n+1][k+1];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                cin>>arr[i][j];
                sum[i+1][j+1] = sum[i+1][j] + arr[i][j];
            }
        }
        int dp[n+1][p+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=p;j++){
                dp[i][j] = 0;
                for(int x=0;x<=min(j,k);x++){
                    //main statement
                    dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x]);
                }
            }
        }
        cout<<"Case #"<<c<<": "<<dp[n][p]<<endl;
    }
    return 0;
}
