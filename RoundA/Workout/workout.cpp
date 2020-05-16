#include<bits/stdc++.h>
using namespace std;
int getDiff(vector<int> arr, int n, int k) {
    vector <int> diff;
    for(int i=1;i<n;i++)
        diff.push_back(arr[i]-arr[i-1]);
    while(k--){
        auto it = max_element(diff.begin(),diff.end())-diff.begin();
        if(diff[it]==1)
            return 1;
        int value = (arr[it]+arr[it+1])/2;
        arr.insert(arr.begin()+it+1,value);
        diff[it] = arr[it+1]-arr[it];
        diff.insert(diff.begin()+it+1,arr[it+2]-arr[it+1]);
    }
    return *max_element(diff.begin(),diff.end());
}

int main() {
    int t, c=0;
    cin>>t;
    while(c!=t) {
        c++;
        int n,k,a;
        cin>>n>>k;
        vector <int> arr;
        for(int i=0;i<n;i++) {
            cin>>a;
            arr.push_back(a);
        }
        cout<<"Case #"<<c<<": "<<getDiff(arr,n,k)<<endl;
    }
}
