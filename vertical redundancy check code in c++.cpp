#include<iostream>
using namespace std;
void addParity(int arr[]){
    int cnt=0;
    for(int i=0;i<7;i++){
        if(arr[i]==1)
        cnt++;
    }
    if(cnt%2!=0){
        arr[7]=1;
    }
}
void checkParity(int arr[]){
    int cnt=0;
    for(int i=0;i<8;i++){
      if(arr[i]==1)
      cnt++;
    }
    if(cnt%2==0){
        cout<<"Accepted"<<endl;
    }
    else{
        cout<<"rejected"<<endl;
    }
}
int main(){
int arr[8];
arr[7]=0;
cout<<"enter the code"<<endl;
for(int i=0;i<7;i++){
    cin>>arr[i];
}
addParity(arr);

checkParity(arr);
    return 0;
}
