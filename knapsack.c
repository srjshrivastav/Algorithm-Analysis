#include<stdio.h>
void knapsack(float w[],float p[],float f[],int objects,float total_wight ){
    float x[10],profit=0;
    int i=0;
    while(1){
        x[i]=0.0;
        if(total_wight<w[i]){
            x[i]=total_wight/w[i];
            profit=profit+(x[i]*p[i]);
            total_wight=total_wight-w[i++];
            break;
        }
        
        else{
            x[i]=1.0;
            total_wight=total_wight-w[i];
            profit=profit+p[i++];
        }

    }
    while(i<objects)
    x[i++]=0.0;
    for(i=0;i<objects;i++)
     printf("O%d = %.1f\n",i,x[i]);   
    printf("Total Profit = %.2f\n",profit);
    
}
int main(){
    int i,j,no_of_objects;
    float w[10],p[10],f[10],Knapsack_weight,temp;
    printf("Enter Kanpsack Size and no of Objects:");
    scanf("%f%d",&Knapsack_weight,&no_of_objects);
    printf("Enter Profit and weight :");
    for(i=0;i<no_of_objects;i++){
        scanf("%f%f",&p[i],&w[i]);
        f[i]=p[i]/w[i];
    }
    //sort profits,weights and fractions in decreasing order of fractions
    for(i=0;i<no_of_objects;i++){
        for(j=i+1;j<no_of_objects;j++){
            if(f[i]<f[j]){
                temp=f[j];
                f[j]=f[i];
                f[i]=temp;

                temp=w[j];
                w[j]=w[i];
                w[i]=temp;

                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
            else if(f[i]==f[j]){
                if(p[i]<p[j]){
                                    temp=f[j];
                f[j]=f[i];
                f[i]=temp;

                temp=w[j];
                w[j]=w[i];
                w[i]=temp;

                temp=p[j];
                p[j]=p[i];
                p[i]=temp;

                }
            }
        }
    }
knapsack(w,p,f,no_of_objects,Knapsack_weight);
}