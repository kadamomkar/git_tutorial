//
//  main.cpp
//  Array
//
//  Created by Omkar Kadam on 01/12/20.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace::std;

struct ar
{
    int A[10];
    int size;
    int length;
};

void display(struct ar arr)
{
    for (int i=0;i<arr.length;i++)
    cout<<arr.A[i];
}

void append(struct ar *arr,int x)
{
    if(arr->length<arr->size)
    {arr->A[arr->length]=x;
        arr->length++;
    }
}

void insert(struct ar *arr,int p,int x)
{
    if(p>=0&&p<=arr->length)
    {
        for(int i=arr->length;i>=p;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[p-1]=x;
        arr->length++;
    }
}

void del(struct ar *arr,int p)
{
    if(p>=0&&p<arr->length)
    {int i;
        for(i=p;i<arr->length;i++)
        {
            arr->A[i-1]=arr->A[i];
        }
        arr->A[i-1]=0;
        arr->length--;
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int lin_search_mod1(struct ar *arr,int x)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==x)
        {
            swap(&(arr->A[i]),&(arr->A[i-1]));
            return i-1;
         break;
        }
    }
    return -1;
}

int lin_search_mod2(struct ar *arr,int x)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==x)
        {
            swap(&(arr->A[i]),&(arr->A[0]));
            return 0;
         break;
        }
    }
    return -1;
}
int bin_search(struct ar *arr,int x)
{
    int low=0,high=(arr->length)-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr->A[mid]==x)
        {return mid;
            break;
        }
        if(arr->A[mid]<x)
            low=mid+1;
        if(arr->A[mid]>x)
            high=mid-1;
        
    }
    return -1;
}

int bin_search_rec(struct ar arr,int x,int high ,int low)
{ if(low<=high)
  { int mid=(low+high)/2;
    
     if(arr.A[mid]==x)
        return mid;
   
     else if(arr.A[mid]<x)
      {
         low=mid+1;
         return bin_search_rec(arr,x,high,low);
      }
     else 
      {
        high=mid-1;
        return bin_search_rec(arr,x,high,low);
      }
     
  }
    else return -1;
}

int main()
{
    struct ar arr={{5,10,15,30,40},10,5};
    cout<<bin_search_rec(arr,40,(arr.length)-1,0);
//    cout<<bin_search(&arr,40);
//    cout<<lin_search_mod2(&arr,3);
//    cout<<lin_search_mod1(&arr,3);
//    append(&arr,10);
//    insert(&arr,3,10);
//    del(&arr,3);
//    display(arr);
    return 0;
}
