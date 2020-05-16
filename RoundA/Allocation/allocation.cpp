#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, c=0;
    cin>>t;
    while(c!=t){
        c++;
        int n,b;
        cin>>n>>b;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int count = 0;
        for(int i=0;i<n;i++){
            if(b<arr[i])
                break;
            else{
                b -= arr[i];
                count++;
            }
        }
        cout<<"Case #"<<c<<": "<<count<<endl;
    }
    return 0;
}
