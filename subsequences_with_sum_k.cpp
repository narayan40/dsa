#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int idx,int n,int target,vector<int> &v,int currsum){
    if(idx==n){
        if(currsum==target){
            for(auto i:v){
                cout<<i<<" ";
            }cout<<endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    currsum+=arr[idx];
    solve(arr,idx+1,n,target,v,currsum);
    v.pop_back();
    currsum-=arr[idx];
    solve(arr,idx+1,n,target,v,currsum);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    int currsum=0;
    vector<int> v;
    cin>>target;
    solve(arr,0,n,target,v,currsum);
    return 0;
}
