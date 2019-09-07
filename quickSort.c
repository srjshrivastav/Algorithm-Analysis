#include<stdio.h>
int partitioning(int num[],int low,int high,int pivot){
    int i=low+1,j=high,temp;
    while(1){
    while(num[i]<num[pivot]&&i<=high){i++;}
    while(num[j]>num[pivot]&&j>=low){j--;}
    if(i>=j)
        break;
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
    }
    temp=num[j];
    num[j]=num[pivot];
    num[pivot]=temp;
    return j;

}
void quickSort(int num[],int low,int high){
    int pi;
    pi=low;
    if(low<high){
        pi=partitioning(num,low,high,pi);
        quickSort(num,low,pi-1);
        quickSort(num,pi+1,high);

    }

}
int main(){
    int num[20],n,i;
    printf("Enter Total Elements :");
    scanf("%d",&n);
    printf("Now Enter %d Elements :",n);
    for(i=0;i<n;i++)
    scanf("%d",&num[i]);
    quickSort(num,0,n-1);
    printf("Sorted array :\t");
    for(i=0;i<n;i++)
    printf("%d\t",num[i]);
    printf("\n");
    return 0;
}