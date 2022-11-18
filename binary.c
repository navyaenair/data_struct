#include<stdio.h>
int main()
{
 int list[25],max;
 int first,last,middle,i,item,loc=-1;
 printf("how many elemnts: ");
 scanf("%d",&max);
 printf("enter the array elemts in ascending order: ");
 for(i=0;i<max;i++)
 scanf("%d",&list[i]);
 printf("\n enetr the item to be searched : ");
 scanf("%d",&item);
 first=0;
 last=max-1;
 while(first<=last)
 {
  middle=(first+last)/2;
  if(item==list[middle])
 {
  loc=middle;
  break;
  }
  if(item<list[middle])
  {
  last=middle-1;
  }
  else
  {
  first=middle+1;
  }
  }
  if(loc!=-1)
  {
  printf("the item is found at the position:%d ",loc+1);
  }
  else
  {
   printf("ot found");
   }
   return 0;
   }
