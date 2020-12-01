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


int main()
{
    struct ar arr={{0,1,2,3,4},10,5};
//    append(&arr,10);
//    insert(&arr,3,10);
    del(&arr,3);
    display(arr);
    return 0;
}
