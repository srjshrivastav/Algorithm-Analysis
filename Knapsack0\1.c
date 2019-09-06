#include<stdio.h>
int max(int x,int y){
    if(x>y){

        return x;
    }
    else
    {
        return y;
    }
    
}
int main(){
    int data[10][30],w[10],p[10],x[10],i=0,j=0,k,Knapsack_wight,no_of_objects,temp;
    printf("Enter the Weight of the Knapsack and no of objects :");
    scanf("%d%d",&Knapsack_wight,&no_of_objects);
    while(j<=Knapsack_wight)
    data[0][j++]=0;
    while(i<=no_of_objects)
    data[i++][0]=0;
    printf("Enter Profit and Weight :");
    for(i=0;i<no_of_objects;i++){
    scanf("%d%d",&p[i],&w[i]);
    x[i]=0;
    }
    for(i=1;i<=no_of_objects;i++){
        for(j=1;j<=Knapsack_wight;j++){
            if(j>=w[i-1])
            data[i][j]=max(data[i-1][j],data[i-1][j-w[i-1]]+p[i-1]);
            else
            {
                data[i][j]=data[i-1][j];
            }
            
        }
    }    
    temp=data[no_of_objects][Knapsack_wight];
    for (i =no_of_objects ; i >=0 ; i--)
    {  j=0;
        while(temp!=data[i][j++]){}
        while(temp==data[i--][j-1]){}
        x[i+1]=1;
        temp=data[i+2][j-1]-p[i+1];
        i=i+2;
        if(temp==0)
            break;
        
    }
for ( i = 0; i < no_of_objects; i++)
{
    printf("Object-%d : %d\n",i+1,x[i]);
}
printf("Maximum Profit is : %d\n",data[no_of_objects][Knapsack_wight]);
}