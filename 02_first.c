#include<stdio.h>
int main(){                                               /*DSA INSERTION SORT*/
    int i,j,n,temp;
    printf("Enter Array Size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter values in array:");
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        for(j=i;j>=1;j--){
            if(a[j-1]>a[j]){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted Result:\n");
    for(i=0;i<n;++i){
        printf("%d",a[i]);
    }
    return 0;
}