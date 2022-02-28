#include<stdio.h>
#include<stdlib.h>

int main(){

    int size, max=0, min=0, sum=0;
    printf("Enter the Size of the Array: ");
    scanf("%d", &size);
    int arr[size];


    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%10;
    }
    for(int i=0;i<size;i++)
    {
        printf("%dth Element: %d\n",i,arr[i]);
    }

    max=arr[0];
    min=arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
        sum+=arr[i];
    }

    printf("Maximum No is %d\n",max);
    printf("Maximum No is %d\n",min);
    printf("Sum of all numbers is: %d\n",sum);
    printf("Average of all numbers is: %f\n",sum/(float)size);
    
}