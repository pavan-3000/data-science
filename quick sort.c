#include<stdio.h>

#include<time.h>

int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int temp;
    int i = low +1;
    int j = high;
    do
    {
    while(a[i]<=pivot)
    {
        i++;
    }
    while(a[j] > pivot)
    {
        j--;
    }
    
    if(i<j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
        } while(i<j);
    temp = a[low];
    a[low] = a[j];
    a[j]  = temp;
    return j;
}


void quicksort(int a[],int low,int high)
{
    int par;
    if(low<high)
    {
    par = partition(a,low,high);
    quicksort(a,low,par-1);
    quicksort(a,par+1,high);

    }
}


int main()
{
    int n,a[10],i,low=0,high;
    clock_t start,end;
    double time_taken;
    printf("size");
    scanf("%d", &n);
   high = n-1;
    printf("ele");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
    printf("%d" ,a[i]);
    }
    start = clock();
    quicksort(a,low,high);
    end = clock();
    for(i=0;i<n;i++)
    printf("\t%d" ,a[i]);
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n%f",time_taken);
    return 0;
    
}
