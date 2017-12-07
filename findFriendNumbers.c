/* This programme counts the numbers that are friends.*/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

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
  printf ("Give the lower  field's number, except number 0 , and press enter :\n");
  scanf ("%d",&low);
  printf ("Give the upper  field's number and press enter  :\n");
  scanf ("%d",&high);
 
  if (high<low){
    printf ("Msg:Give the upper field's number to  be  greater than the  lower and press enter :\n");   
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
Created by konnn (Konstantinos Spalas).Email:konnn.sp@gmail.com*/
