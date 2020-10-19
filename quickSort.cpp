#include<iostream>
#include<stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Use auto keyword to avoid typing long
//now function is used to get the time now
auto start = high_resolution_clock::now();

void swap(int & a,int & b){
  int temp=a;
  a=b;
  b=temp;
}

int partition(int a[],int low,int high){
  int pivot_value=a[low],left=low,right=high;
  while(left<right){
    while(a[left]<=pivot_value) left++;
    while(a[right]>pivot_value) right--;
    if(left<right)  swap(a[left],a[right]);
  }
  a[low]=a[right];
  a[right]=pivot_value;
  return right;
}

void quickSort(int a[],int left,int right){
  int pivot;
  if(right>left){
    pivot=partition(a,left,right);
    quickSort(a,left,pivot-1);
    quickSort(a,pivot+1,right);
  }
}

int main(){
  int size;
  cout<<"Enter the size of an array ";
  cin>>size;
  int a[size];
  for (int i = 0; i < size; ++i){
    a[i]=rand()%100;//Using random function to generate random variables in range 1 to 100
  }
	quickSort(a, 0, size - 1);
  for (int i = 0; i < size; ++i){cout<<a[i]<<" ";}
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout <<"Time taken by function: "
        << duration.count() << " microseconds" << endl;
	return 0;
}
