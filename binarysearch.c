#include<stdio.h>
int* sort(int* arr,int n){
    int i,j,inst;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                inst = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=inst;
            }
        }
    }
    return arr;
}

int binsearch(int arr[],int fr,int re,int n,int srh){
    int i;
    printf("Sorted array: ");
    int* samp = sort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ", samp[i]);
    while(fr <= re)
    {
      int mid = (fr + re)/2;
      printf("mid = %d\n",mid);

      if(samp[mid]==srh)
        return mid;
      if(arr[mid]<srh)
          fr = mid + 1;
      else
          re = mid - 1;
    }
    return -1;
}


void main()
{
    int array[25],n,i,temp;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    int srh;
    printf("Enter element to be searched:");
    scanf("%d",&srh);
    int fr = 0, re = n - 1, res;
    res = binsearch(array,fr,re,n,srh);

    if(res == -1)
      printf("\nElement is absent");
    else
      printf("\nElement found at position %d", res+1);
}               
