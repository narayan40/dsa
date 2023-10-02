#include<iostream>
#include<queue>
using namespace std;
class heap{
 public:
 int arr[100];
 int size;
 heap(){
	arr[0]=-1;
	size=0;
 }
 void insert(int val){
	//insertion time complexity O(log n);
	size=size+1;
	int index=size;
	arr[index]=val;
	while(index>1){
		int parent=index/2;
		if(arr[index]>arr[parent]){
			swap(arr[index],arr[parent]);
			index=parent; 
		}
		else{
			 return; 
		}
	}
 }
 void print(){
	for(int i=1;i<=size;i++){
		cout<<arr[i]<<" ";
	}cout<<endl; 
 }
 void deleteFromHeap(){
	//deletion complexity is O(log n);
	//1.Repalce first element that is root with last element
	//2.delete last element
	//3.Place root node to its correct position
	if(size==0){
		cout<<"Nothing to delete"<<endl;
		return;
	}
	//1.replacing root with the last element
	arr[1]=arr[size];
	//2.Remove last element
	size--;
	//3.take root to its correct position
	int i=1;
	while(i<size){
		int leftIndex=2*i;
		int rightIndex=2*i+1;
		if(leftIndex<size && arr[i]<arr[leftIndex]){
			swap(arr[i],arr[leftIndex]);
			i=leftIndex;
		}
		else if(rightIndex<size && arr[i]<arr[rightIndex]){
			swap(arr[i],arr[rightIndex]);
			i=rightIndex;
		}
		else{
			return;
		}
	}
 } 
};
void heapify(int arr[],int n,int i){
	//time complexity of building heap is O(n)
	int largest=i;
	int left=2*i;
	int right=2*i+1;
	if(left<=n && arr[largest]<arr[left]){
		largest=left;
	}
	if(right<=n && arr[largest]<arr[right]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[],int n){
	//time complexity is O(nlogn);
	//steps first build heap then apply the heapsort function we have used here
	//in our case heap was already build so we directly usef the heapsort function

	int size=n;
	while(size>1){
		//step 1:swap 
		swap(arr[size],arr[1]);
		size--;
		//step 2:
		heapify(arr,size,1);
	}
}
int main(){
heap h;
h.insert(50);
h.insert(55); 
h.insert(53);
h.insert(52);  
h.insert(54);
h.print(); 
h.deleteFromHeap();
h.print();
int arr[6]={-1,54,53,55,52,50};
int n=5;
for(int i=n/2;i>0;i--){
	heapify(arr,n,i);
}
cout<<"printing the array now"<<endl;
for(int i=1;i<=n;i++){
	cout<<arr[i]<<" ";
}cout<<endl;
//heapsort
heapSort(arr,n);
cout<<"printing the array now"<<endl;
for(int i=1;i<=n;i++){
	cout<<arr[i]<<" ";
}cout<<endl;
//using priority queue here to build heap using stl
priority_queue<int> pq;
pq.push(4);
pq.push(2);
pq.push(5);
pq.push(3);
cout<<"top element"<<pq.top()<<endl;
pq.pop();
cout<<"top element"<<pq.top()<<endl;
cout<<"size is "<<pq.size()<<endl;
if(pq.empty()){
	cout<<"pq is empty"<<endl;
}
else{
	cout<<"pq is  not empty"<<endl;
}
//min heap
priority_queue<int,vector<int>,greater<int>> minheap;
cout<<"min heap operatuon"<<endl;
minheap.push(4);
minheap.push(2);
minheap.push(5);
minheap.push(3);
cout<<"top element"<<minheap.top()<<endl;
minheap.pop();
cout<<"top element"<<minheap.top()<<endl;
cout<<"size is "<<minheap.size()<<endl;
if(minheap.empty()){
	cout<<"minheap is empty"<<endl;
}
else{
	cout<<"minheap is  not empty"<<endl;
}
	return 0;
}