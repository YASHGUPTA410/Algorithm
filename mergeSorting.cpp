//Author : Yash Jain | Roll Number : 11911029 | Branch : CSE
//Merge Sorting ALgorithm
#include<iostream>
#include <stdlib.h>
#include<iomanip>//For setw() function
#include <chrono>

using namespace std;
using namespace std::chrono;
// Use auto keyword to avoid typing long
//now function is used to get the time now
auto start = high_resolution_clock::now();

void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}//swap the content of a and b

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;//breaks array into two part
      // Sort first and second arrays
      mergeSort(array, l, m);//recursively deconstructs the array
      mergeSort(array, m+1, r);
      merge(array, l, m, r);//after getting the smallest sub-array its starts sorting
   }
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   for(int i = 0; i<n; i++) {
      arr[i]=rand()%100;//Using random function to generate random variables in range 1 to 100
   }
   //cout << setw(25)<<"Array before Sorting : ";
  // display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout <<setw(25)<< "Array after Sorting : ";
   display(arr, n);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << setw(25  )<<"Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
