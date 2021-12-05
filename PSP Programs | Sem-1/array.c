#include<stdio.h>
 int main(){

     int i,j,arr[10],min=0,index=0,temp=0;

     printf("Enter 10 Numbers:\n");

     for(i=0;i<10;i++){
         scanf("%d",&arr[i]);
     }

     for(i=0;i<9;i++){
         min=arr[i];
         for(j=i+1;j<10;j++){
             if(min>arr[j]){
                 temp=arr[i];
                 arr[i]=arr[j];
                 arr[j]=temp;
                 
             }
         }
         
     }
     printf("\nSorted array is:\n");

     for(i=0;i<10;i++){
         printf("%d\n",arr[i]);
     }

     for(i=0;i<9;i++){
         for(j=i+1;j<10;j++){
             if(arr[i]==arr[j]){
                 printf("Repeated Number is: %d\n",arr[i]);
                 printf("Corrected Number is: %d\n",arr[0]+j);
                 
             }
         }
     }
     
     for(i=0;i<9;i++){
         for(j=i+1;j<10;j++){
             if(arr[i]==arr[j]){
                 arr[j]=arr[0]+j;
             }
         }
     }

     printf("\nCorrected array is:\n");

     for(i=0;i<10;i++){
         printf("%d\n",arr[i]);
     }
 }
