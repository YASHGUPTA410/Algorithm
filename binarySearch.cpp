//binary Search implementation only for sorted array
//time complexity is O(logn)
#include<iostream>
using namespace std;

//recursively use divide and conquer strategy as after every recursion
//array is half of the original size
int binarySearch(int a[],int low,int high,int key){
  int mid;
  if(high<low)
    return low-1;
  mid=low+(high-low)/2;
  if(key==a[mid])
    return mid;
  else if (key<a[mid])
    return binarySearch(a,low,mid-1,key);
  else
    return binarySearch(a,mid+1,high,key);
}


int main(){
  int key,size;
  // int a[]={1,2,3,4,7,5,6,10,0,-1};
  // int size=sizeof(a)/sizeof(a[0]);
  cout<<"Enter the size of an array ";
  cin>>size;
  cout<<"\nEnter the array elements :";
  int a[size];
  for(int i=0;i<size;i++){cin>>a[i];}
  cout<<"\nEnter the element to be searched : ";
  cin>>key;
  int result=binarySearch(a,0,size,key);
  if(result==-1){cout<<"No such element";}
  else cout<<"Position of "<<key<<" is "<<result+1;
  return 0;
  return 0;
}
