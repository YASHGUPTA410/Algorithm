#include <stdio.h>

int merge(int a[0],int b[0])
{
  int i=0,j=1;
  while (i<n/2)
  {
  if (a[i]<a[j])
  {
    swap(a[i],a[j]);
    i++;j++;
  }
  else
  i++;j++;
  }
  int i=0,j=1;
  while (i<n/2)
  {
  if (b[i]<b[j])
  {
    swap(b[i],b[j]);
    i++;j++;
  }
  else
  i++;j++;
  }
  int c[i+j],x=0,y=0;
  for(int k=0;k<n;k++)
  {
    if (a[x]<b[y])
    {
      c[k]=a[x];
      x++;
    }
    else
    {
      c[k]=b[y];
      y++;
    }
  }
  return c;
}


void main()
{
  int n;
  printf("Enter array length : ");
  scanf("%d",&n);
  int a[n];
  if (n%2==0)
  {
    int b[n/2],c[n/2],i=0,j=0;
    while (i<n)
    {
    if (i<n/2)
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    else
    {
      scanf("%d",&a[i]);
      c[j]=a[i];
      j++;
    }
    i++;
    }
  }
  else
  {
    int b[(n-1)/2],c[(n+1)/2],i=0,j=0;
    while (i<n)
    {
    if (i<((n-1)/2))
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    else
    {
      scanf("%d",&a[i]);
      c[j]=a[i];
      j++;
    }
    i++;
    }
  }
  int r[n],x;
  r=merge(b,c);
  while(x<n)
  {
    printf("%d\t",r[x]);
    x++;
  }
}
