#include<stdio.h>

void merge(int a[],int mid,int low,int high)
{
    int i ,j,k,b[10];
    i = low;
    j=mid +1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k] = a[i];
            i++,k++;
        }
        else
        {
            b[k] = a[j];
            j++,k++;
        }
        
    }
    
            while(i<=mid)
            {
                b[k] = a[i];
                k++,i++;
            }
            while(j<=high)
            {
                b[k] = a[j];
                k++,j++;
            }
            for( int i = 0 ; i<=high;i++)
            {
        a[i] = b[i];
            }
}


void mergesort(int a[],int low ,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}

int main()
{
    int a[10],n,i,low =0 ,high;
    printf("size");
    scanf("%d",&n);
    high = n-1;
    printf("ele");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    mergesort(a,low,high);

    printf("sorted");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
    
    
    
}