#include <bits/stdc++.h>
using namespace std;

void printSub(vector<int>& arr, int n, int idx, vector<int>& v,vector<vector<int> >&store) {
   // vector<int> temp;
    if (idx == n) {
        if(v.size()==0){
            vector<int>temp={0};
            store.push_back(temp);
        }
        else
       store.push_back(v);
       
        return;
    }

    v.push_back(arr[idx]);
    printSub(arr, n, idx + 1, v,store);
    v.pop_back();
    printSub(arr, n, idx + 1, v,store);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: "<<endl;
    cin >> n;

    vector<int> arr(n, 0);
    cout << "Enter all the elements: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //int x = 1;
   
     
    vector<int> v;
    vector<vector<int> >store;
    printSub(arr, n, 0, v,store);
    cout<<"size of store"<<store.size()<<endl;

     for(auto i:store){
         for(auto j:i){
             cout<<j<<" ";
         }cout<<endl;
     }

    return 0;
}

