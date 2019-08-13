#include<stdio.h>
#include<string.h>


int main(){
    char key[100],pt[100];
    int a[26],v=0,s1i,s2i,s1j,s2j;
    char res[strlen(key)];
    char mat[5][5];
    char search1='\0',search2='\0';
    int c,i,j,ro,col;
    scanf("%[^\n]s",key);
    getchar();
    scanf("%[^\n]s",pt);
//     printf("%s\n%s",key,pt);
    
    for(i=0;i<26;i++)
        a[i]=0;
    for(i=0;key[i] ;i++){
        int value = key[i]-'a';
//         printf("value : %d a[val] : %d ",value,a[value]);
        if(a[value]==0){
            res[v++]=key[i];
            a[value]=1;
        }
    }
//      printf("After filtering %d %s\n",v,res);
    
    for(j=0,i=0,c=0;i<5&&c<v;j++){
            if(j==5){
                i++;
                j=0;
            }
    mat[i][j]=res[c++];
    }
    ro=i;
    col=j--;
   
   printf("j:%d\n",j); 
   for(int va=0;va<26;va++){
    if(a[va]==0 && va != 16){
        mat[ro][col] = va + 'a';
        col++;
    if(col==5) {col=0;ro++;}
   }
}

     printf("Key matrix\n");    
     for(i=0;i<5;i++,printf("\n")){
     for(j=0;j<5;j++){
         printf("%c",mat[i][j]);
     }
     }
     
    //forming plain text into cipher
    int va=0;
while(va<strlen(pt)){
         search1=pt[va++];
         search2=pt[va++];
         printf("\n%c %c",search1,search2);
     for(i=0;i<5;i++){
         for(j=0;j<5;j++){
         
             if(search1==mat[i][j]){
                 s1i=i;llll
                 s1j=j;
             }
             if(search2==mat[i][j]){
                 s2i=i;
                 s2j=j;
             }
             
         }
     }
        printf("\n%d %d\n%d %d",s1i,s1j,s2i,s2j);
     if(s1i==s2i){
//          if(++s1j==5) s1j=0;
//          if(++s2j==5) s2j=0;
         pt[va-2]=mat[s1i][(++s1j)%5];
         pt[va-1]=mat[s2i][(++s2j)%5];
        }
     else if(s1j==s2j){
//          if(++s1i==5) s1i=0;
//          if(++s2i==5) s2i=0;
         pt[va-2]=mat[(++s1i)%5][s1j];
         pt[va-1]=mat[(++s2i)%5][s2j];
        }
      else{
         pt[va-2]=mat[s1i][s2j];
         pt[va-1]=mat[s2i][s1j];
        }
    }
     
     printf("cipher text : %s",pt);
    return 0;
}
