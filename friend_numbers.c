/* This programme counts the numbers that are friends.*/
#include<stdio.h>

int func_sum(int num){
int  div=0,sum=0;

for(div=1;div<=num/2;div++){
   if((num%div)==0){         
      sum=sum+div;}       
      }       
   return sum;
}

int main(){

  int *p;
  int i,j,k,size,n=0;   
  int low=0,high=0,num=0,sum=0;
  printf ("Give the lower search field number, except number 0 , and press enter :\n");
  scanf ("%d",&low);
  printf ("Give the upper search field number and press enter  :\n");
  scanf ("%d",&high);
 
  if (high<low){
    printf ("Give the upper search field number be  greater than lower and press enter :\n");   
    scanf ("%d",&high); }
   
  int arr[high-low];
 
  for(num=low;num<high;num++){   
    sum=func_sum(num);
   
    /*1.-------Place the numbers in an array----------*/   
    if(func_sum(sum)==num && sum!=num){      
      arr[n]=num;
      arr[n+1]=sum;
      n=n+2;}
      }
     
    /*a.-------Remove douplicates-----------*/
      size=n;
      p=arr;
      for(i=0;i<size;i++){
   for(j=0;j<size;j++){
       if(i==j){
      continue;
       }
       else if(*(p+i)==*(p+j)){
      k=j;
      size--;
      while(k < size){
          *(p+k)=*(p+k+1);
          k++;
        }
        j=0;
         }
     }
      }
      printf("\nThe couples of friend numbers are %d,the: \n",size/2);
      for(i=0;i < size;i=i+2){
   printf(" %d and %d\n",arr[i],arr[i+1]);
    }
    return 0;
}

/*---------------------------------Under GPL-------------------------------------------
Created by konnn (Konstantinos Spalas).Email:konnn@live.com*/
