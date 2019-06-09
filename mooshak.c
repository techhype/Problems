#include<stdio.h>
#include<stdlib.h>
int n,a[100][100],s[100][100];
int isSafe(int x,int y){
    if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1)
        return 1;
    return 0;
}
int findDest(int x,int y){
    // printf("%d %d\n",x,y);
    if(x>=0 && x<n && y>=0 && y<n &&s[x][y]==0){
        s[x][y]=1;
        if(a[x][y]==9)
            return 1;
        else if(isSafe(x,y)==1){
            if(findDest(x+1,y)==1)
                return 1;
            if (findDest(x - 1, y) == 1)
                return 1;
            if(findDest(x,y+1)==1)
                return 1;
            if(findDest(x,y-1)==1)
                return 1;
            return 0;
        }
        return 0;
    }
    return 0;
}
int main(){
    // int n;
    scanf("%d",&n);
    // int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            s[i][j]=0;
        }
    }
    int res = findDest(0,0);
    printf("%d",res);
    return 0;
}
