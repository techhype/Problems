 #include<stdio.h>
void sort(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int swapArray(int a[],int c){
    int temp,i,j;
    for(i=c-1,j=i-1;i>1;){
        if(a[j]<a[i]){
            temp = a[j];
            a[j]=a[i];
            a[i]=temp;
            break;
        }
        else{
            j--;
        }
        if(j==0){
            i--;
            j=i-1;
        }    
    }
    // returns index of sub array to be swapped
    return j+1;
}
void reverse(int a[],int st,int c){
    c--;
    while (st < c) 
    { 
        int temp = a[st];  
        a[st] = a[c]; 
        a[c] = temp; 
        st++; 
        c--; 
    }  
}
int main(){
    int n=78999,a[5],c=0,temp;
    // scanf("%d",&n);
    while(n){
        a[c]=n%10;
        n=n/10;
        c++;
    }
    
    sort(a,c);
    int st= swapArray(a,c);
    // printf("%d %d\n",st,c);
    reverse(a,st,c);
    for(int i=0;i<c;i++)
        printf("%d ",a[i]);
    return 0;
}
