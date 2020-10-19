#include <stdio.h>

void shellSort(int a[],int size)
{
  int i,j,h,temp,key;
  for (h=size/2;h>0;h=h/2)
  {
    for (i=h;i<size;i+=1)
    {
        a[i]=key;
        j=i;
        while(a[j-h]>key && j>=h)
        {
          a[j]=a[j-h];
          j-=h;
        }
        a[j]=key;
    }
  }
  for(int k=0;k<size;k++)
  printf("%d\t",a[k]);
}


void main()
{
  int a[]={10,9,8,7,6,5,4,3,2,1,11,20,19,18,17,16};
  int n=sizeof(a)/sizeof(a[0]);
  shellSort(a,n);
}
