//implementing linear search in an unsorted array
//It is an example of subtractive recursive/iterative algorithm
//as after every iteration size of an array decreases by 1
#include<iostream>
#include<stdlib.h>
using namespace std;

//time complexity O(n)
//searches recursively
int linearSearch(int a[], int low, int high, int key){
  if (high<low){return -1;}
  if(a[low]==key){return low;}
  return linearSearch(a,low+1,high,key);
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
  int result=linearSearch(a,0,9,key);
  if(result==-1){cout<<"No such element";}
  else cout<<"Position of "<<key<<" is "<<result+1;
  return 0;
}
