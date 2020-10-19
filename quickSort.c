#include <stdio.h>

int partition(int *arr,int start, int end){
	int temp;
	int pivot = arr[end];
	int pindex = start;
	int i = 0;
	for(i = start;i<end;i++){
		if(arr[i] <= pivot){
			temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex = pindex + 1;
		}
	}
	
	temp = arr[pindex];
	arr[pindex] = arr[end];
	arr[end] = temp;
	
	return pindex;
}

void quicksort(int *arr,int start,int end){
	
	if(start < end){
		int pindex = partition(arr,start,end);
		quicksort(arr,start,pindex-1);
		quicksort(arr,pindex+1,end);
	}
}


void main(){
	int arr[50];
	int n = 0;
	printf("Enter length of array: ");
	scanf("%d", &n);
	int i = 0;
	printf("Enter elements :- \n");
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
}
