#include<stdio.h>

int main(){
    int m,n,p,q;
    
    printf("Enter the Number of Rows and Columns for 1st Matrix: ");
    scanf("%d %d",&m,&n);

    printf("Enter the Number of Rows and Columns for 2nd Matrix: ");
    scanf("%d %d",&p,&q);
    
    int matrix1[m][n], matrix2[p][q], matrix3[m][n], matrix4[n][p];

    printf("Enter the elements of 1st Matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the Element for %dth Row and %dth Column: ",i+1,j+1);
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\nEnter the elements of 2nd Matrix: \n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("Enter the Element for %dth Row and %dth Column: ",i+1,j+1);
            scanf("%d",&matrix2[i][j]);
        }
    }

    //Multiplication of matrices
    if(n==p)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                matrix3[i][j]=0;
                for (int k = 0; k < n; k++)
                {
                    matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
    }
    else
    {
        printf("\nThe Matrices cannot be multiplied.\n\n");
    }

    //Additon of matrices
    if(m==p && n==q)
    {   
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%d %d\n",i,j);
                matrix4[i][j]=matrix1[i][j]+matrix2[i][j];
            }
        }
    }
    else
    {
        printf("Addition of Matrix is not possible.\n");
    }

    //printing the matrices
    printf("Matrix 1 is: \n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d\t",matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2 is: \n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d\t",matrix2[i][j]);
        }
        printf("\n");
    }

    if(n==p)
    {
        printf("\nThe Multiplication of the Matrices is: \n");

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%d\t",matrix3[i][j]);
            }
            printf("\n");
        }
    }
    
    if(m==p && n==q)
    {
        printf("\n\nThe Addition of the Matrices is: \n");
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%d\t",matrix4[i][j]);
            }
            printf("\n");
        }
    }
}