#include<stdio.h>
void Sort(int arr[],int low1,int high1,int low2,int high2){
    int temp[20],i=low1,j=low2;
    int k=0;
    while(i<=high1&&j<=high2){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i];
            i++;
        }
        else{
            temp[k++]=arr[j];
            j++;
        }
    }
    if(j<=high2){
        while(j<=high2)
            temp[k++]=arr[j++];
    }
    else{
        while(i<=high1)
            temp[k++]=arr[i++];
    }
    for(i=0;i<k&&low1<=high2;i++)
        arr[low1++]=temp[i];

}
void mergeSort(int arr[],int low,int high){
    int mid;
    mid=(low+high)/2;
    if(low<high){
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        Sort(arr,low,mid,mid+1,high);
    }
}
int main(){
    int num[20],n,i;
    printf("Enter Total Elements(Max 20):");
    scanf("%d",&n);
    printf("Now Enter %d Elements :",n);
    for(i=0;i<n;i++)
    scanf("%d",&num[i]);
    mergeSort(num,0,n-1);
    printf("Sorted array :\t");
    for(i=0;i<n;i++)
    printf("%d\t",num[i]);
    printf("\n");
    return 0;
}