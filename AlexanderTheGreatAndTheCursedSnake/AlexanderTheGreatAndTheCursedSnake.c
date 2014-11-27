/*Konstantinos Spalas,
email:cst08094uop.gr,
//tst2

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


#include <stdio.h>
#include <stdlib.h>
# include <time.h>
//#include "Newalex.h"
/*
The playing table is stored in a 2d, dynamic memory, array called "table".
The 1d dyn. array, called "point" ,stores the coordinates of the table's elements,
starting with M(0,1), S(2,3)...
The story is:
I initialise the table,then check for wells and print the table.
Also,after one "m_move", the "moves_of_m" increases to trigger s_move when is 2.
*/
void init_table(char ** ,int *,  int , int ,int );//Initialise the table at the begining.
int do_rand(int);//Produse random numbers for the elements' (M,G,S...) coordinates on the table.
void m_move(char **,int *,char ,int ,int );//Moves the M.
void s_move(char **,int *);//Moves the S.
void print_table(char **, int ,int);
void is_o(char **,int *,int , int );//Function that checks the M's neighboring boxes for wells(O).

int main(){
char choise;//The choise varies between w/s/a/d/e/h in the fuction m_move.
char **table = NULL;
int  n,k,*point,i,moves_of_m,num_of_o;//n,k the size of table.
moves_of_m=0;
point=NULL;
srand((int) time(NULL));//Inialize rand .
printf("\n%s","Which is the NxK (max  30x30) size of the table you want to play: ");

do{
//printf("\nRAND_MAX=%d",RAND_MAX);
printf("\nN=");
scanf("%d", &n);
printf("K=");
scanf("%d", &k);
}while(n>30 || k>30);

num_of_o=(int)(.05*n*k);//Number of Os(wells),here we can increase the number of wells.
//printf("\nnum_of_o=%d\n",num_of_o);
point = (int *)malloc((2*((int)(.05*n*k)+6)) *  sizeof(int));//"point" table has at least 6 positions + position coming from wells.
//printf("\nsize of p=%ld\n",sizeof(point)/sizeof(int));
table = malloc (n *  sizeof(char *));
//printf("\nsize of t=%ld\n",n*k*sizeof(table));
	for (i = 0; i < n; i++)
		table[i] = (char *) malloc (k *  sizeof(char));	//allocating the 2nd dimension of table.		

printf("Playing Table is:\n\n");
init_table(table,point,n,k,2*num_of_o);
is_o(table,point,n,k);
print_table(table,n,k);

while((choise=getchar()) !='e'){
puts("Key choises are between w/s/a/d (up/down/left/right)\nor e to exit and h for help.");
puts("\nYour choise is:");
choise=getchar();
//putchar(choise=getchar());
m_move(table,point,choise,n,k);
//printf("\n\nPoint of M=(%d,%d\n",(*(point)),(*(point )+1));
//printf("\n\nPoint of G=%d,%d\n",(*(point +5)+1),(*(point + 4)+1));
is_o(table,point,n,k);
print_table(table,n,k);

moves_of_m++;

if(moves_of_m==2){
	s_move(table,point);
	if (*point==*(point+2) && *(point+1)==*(point+3)){//Here the games ends when move of S towards M happens.		
print_table(table,n,k);
printf("\nYou lost,eaten by snake....\n");
				exit (0);
}
else	moves_of_m=0;
	//is_o(table,point,n,k);
	print_table(table,n,k);
}
//is_o(table,point,n,k);
//print_table(table,n,k);


}	

free(table);
free(point);
return 0;

}
void init_table(char **t, int *p, int n, int k,int p2){		
	int m,i,j,add_o;
	add_o=6;		
	double d;
//Create a field of 4 numbers and assign a number for each corner of the table in order to put M.
//Puting M to one of the corners.
	d=(double)rand()/((double)RAND_MAX+1);
	d=d*4;
	m=(int)d;
	if(m == 0 ){t[0][0]='M'; *p=0; *(p+1)=0;} 
	else if (m==1){	t[0][k-1]='M';  *p=0; *(p+1)=k-1;}
	else if (m==2) {t[n-1][0]='M'; *p=n-1; *(p+1)=0;}
	else { t[n-1][k-1]='M';*p=n-1;*(p+1)=k-1;}	
//

//Random for Snake.	
	do{
		(*(p+2))=do_rand(n);
		*(p+3)=do_rand(k);
		}	while(t[*(p+2)][*(p+3)]=='M') ;
		t[*(p+2)][*(p+3)]='S';
//Random for Gold		
	do{
		(*(p+4))=do_rand(n);
		*(p+5)=do_rand(k);
		}	while(t[*(p+4)][*(p+5)]=='M' || t[*(p+4)][*(p+5)]=='S') ;
		t[*(p+4)][*(p+5)]='G';
//	Wells	
		while(add_o<=p2+6){//Adding O positions must not exeed "point" positions.Otherwise stops craeting Os.
	do{
		*(p+add_o)=do_rand(n);
		*(p+add_o+1)=do_rand(k);
		//add_o++;
		}	while((t[*(p+add_o)][*(p+add_o+1)]=='M' ||  t[*(p+add_o)][*(p+add_o+1)]=='S' || t[*(p+add_o)][*(p+add_o+1)]=='G')) ;
		t[*(p+add_o)][*(p+add_o+1)]='O';
		//printf("\n\npofo=%d,%d\n",(*(p+add_o)+1),(*(p+add_o+ 1)+1));
		add_o+=2;
	}
//Putting "#" 		
	for (i=0; i<n;i++){
		for(j=0;j<k;j++){
			if(t[i][j]!='M' &&  t[i][j]!='S' && t[i][j]!='G' && t[i][j]!='O')
			 t[i][j]='#';
		}
	}
}



void print_table(char **t, int n, int k ){
	int i,j,count;
	count=1;
	printf(" ");
	printf(" ");
	for (i=0; i<n;i++){
		//printf(" ");
		printf(" ");
		printf("%d" ,count);
		printf(" ");
		printf(" ");
		count++;
	}	
		printf("\n");
		count=1;
		printf(" ");
	printf(" ");
		for (i=0; i<n;i++){
		//printf(" ");
		printf("--" );
		printf(" ");
		printf(" ");		
	}
		printf("\n");
		
	 for (i=0; i<n;i++){
		printf("%d" ,count);
		 printf("|");
		for(j=0;j<k;j++){
			printf(" ");
			if (t[i][j]=='O')//Put  commends in order to appear wells.
			printf("#");	//Put  commends in order to appear wells.
			else		//Put  commends in order to appear wells.
				printf("%c" ,t[i][j]);
				printf(" ");
				printf(" ");						
				}
					printf("\n\n");
				count++;	
				}		
	}

int  do_rand(int a){
	int i1;
	double d1;
	d1=(double)rand()/((double)RAND_MAX+1);	
	d1=d1*a;	
	i1=(int)d1;	
	return i1;
}

void m_move(char **t,int *p, char ch, int n, int k){
	
	switch(ch){
		case 'w': case 'W':
			if ((*p)>0){//Checks for not  be out of borders.Segmetation fault may happen.
			t[(*p)][(*(p+1))]='.';
			  
			  if (t[(*p)-1][(*(p+1))]=='S' || t[(*p)-1][(*(p+1))]=='O'){ 
				//(*p)--;			
				//t[(*p)][(*(p+1))]='X';				
				printf("\nYou lost....");
				exit (0);
			}
					
			//else {
			(*p)--;
						
			t[(*p)][(*(p+1))]='M';	
		}
		else  printf("\nMove out of border,retry another choise....\n");
		break;	

		case 's': case 'S':
		if((*p)<n-1){//Checks for not  be out of borders.Segmetation fault may happen.
			t[(*p)][(*(p+1))]='.'; 			  
			  	
			if (t[(*p)+1][(*(p+1))]=='S' || t[(*p)+1][(*(p+1))]=='O'){
				//(*p)++;			
				//t[(*p)][(*(p+1))]='X';
				printf("\nYou lost....");
				exit (0);
			}		  						
			(*p)++; 			
			t[(*p)][(*(p+1))]='M';	
		}	
		else printf("\nMove out of border,retry another choise....\n");
		break;

		case 'a': case 'A':
		if((*(p+1))>0){//Checks for not  be out of borders.Segmetation fault may happen.
			t[(*p)][(*(p+1))]='.';	
			  
			  if (t[(*p)][(*(p+1))-1]=='S' || t[(*p)][(*(p+1)-1)]=='O'){
				 // (*(p+1))--;			
				//t[(*p)][(*(p+1))]='X';
				printf("\nYou lost....");
				exit (0);
			}
								
			(*(p+1))--; 				
			t[(*p)][(*(p+1))]='M';
		}
		else  printf("\nMove out of border,retry another choise....\n");
		break;

		case 'd': case 'D':
		if((*(p+1))<k-1){//Checks for not  be out of borders.Segmetation fault may happen.
			t[*p][*(p+1)]='.';
			
			  if (t[(*p)][(*(p+1)+1)]=='S' || t[(*p)][(*(p+1)+1)]=='O'){
				//  (*(p+1))++;			
				//t[(*p)][(*(p+1))]='X';
				printf("\nYou lost....");
				exit (0);
			}
						
			(*(p+1))++; 				
			t[*p][*(p+1)]='M';
		}
		
		//else printf("\nMove is out of range, try in range.\n");
		else  printf("\nMove out of border,retry another choise....\n");
		break;

		case 'e': case 'E':
			printf("\nYou prefered exit the game....");
			exit(0);

		case 'h': case 'H':
		printf("\nHelp:\nThere is a well in (%d,%d) and gold is in (%d,%d).\n",*(p+7)+1,*(p+6)+1,*(p+5)+1,*(p+4)+1);
		
	 
 }
 
		
 //printf("hbcbasdhbas");
}

void s_move(char **t,int *p){
	int xdiff,ydiff;
	/*Counts the coordinates diffs relating M to move S as required.	 
	 */
	//xdiff=ydiff=0;
		
	xdiff=(*(p+2))-*p;
	ydiff=(*(p+3))-(*(p+1));
	
	if(ydiff<0){ 
		t[(*(p+2))][(*(p+3))]='#'; 
		(*(p+3))++; 
		t[(*(p+2))][(*(p+3))]='S';
		}
	else if (ydiff>0) {  
		t[(*(p+2))][(*(p+3))]='#';
		(*(p+3))--; 
		t[(*(p+2))][(*(p+3))]='S';
	}
	else if (ydiff==0){
		if(xdiff<0){
			t[(*(p+2))][(*(p+3))]='#';
			 (*(p+2))++;
			 t[(*(p+2))][(*(p+3))]='S';
		 }
		else {
			t[(*(p+2))][(*(p+3))]='#';
			(*(p+2))--;
			t[(*(p+2))][(*(p+3))]='S';
		}
	}	
	
} 

/*Searches the boxes near the M for O in order to switch the appropriate boxes to ~.
 * External ifs prevents for out-of-allocated memory searching.
 * */
void is_o(char **t,int *p,int n,int k){	
	
	if(*(p)-2>=0 ){
		if (t[(*p)-2][(*(p+1))]=='O' ){ // in the 2nd upper box
			t[(*p)-1][(*(p+1))]='~';
			//t[(*p)-2][(*(p+1)+1)]='~';
			//t[(*p)-2][(*(p+1)-1)]='~';
			//t[(*p)-3][(*(p+1))]='~';
		}			
	}
	if(*(p)-1>=0 && *(p+1)+1<k){
		 if (t[(*p)-1][(*(p+1)+1)]=='O'){//in the  1st right upper diagonal
			t[(*p)][(*(p+1)+1)]='~';
			t[(*p)-1][(*(p+1))]='~';
	}
}
	if(*(p)-1>=0 && *(p+1)-1>=0){
	     if (t[(*p)-1][(*(p+1)-1)]=='O'){ //in the  1st left upper diagonal
			t[(*p)][(*(p+1)-1)]='~';
			t[(*p)-1][(*(p+1))]='~';
	}	
}	

	
	if(*(p)+2<n ){
		 if( t[*(p)+2][(*(p+1))]=='O'){	//in the 2nd lower box
			t[*(p)+1][(*(p+1))]='~';
			//t[(*p)+2][(*(p+1)+1)]='~';
			//t[(*p)+2][(*(p+1)-1)]='~';
			//t[(*p)+3][(*(p+1))]='~';		
	}
}
		
	if(*(p)+1<n && *(p+1)+1<k){		
		 if (t[(*p)+1][(*(p+1)-1)]=='O'){ //in the  1st left lower diagonal
			t[*(p)][(*(p+1)-1)]='~';
			t[*(p)+1][(*(p+1))]='~';
	}
}
	if(*(p)+1<n && *(p+1)+1<k){
		 if (t[*(p)+1][(*(p+1)+1)]=='O'){//in the  1st right lower diagonal
			t[(*p)][(*(p+1)+1)]='~';
			t[(*p)+1][(*(p+1))]='~';
		}
	}
	
	if(*(p+1)-2>=0 ){			
	  if( t[(*p)][(*(p+1)-2)]=='O' ){//in next two left box
		//if ( t[(*p)][(*(p+1)-2)]=='O'){
			t[(*p)][(*(p+1)-1)]='~';
			//t[(*p)-1][(*(p+1)-2)]='~';
			//t[(*p)+1][(*(p+1)-2)]='~';
			//t[(*p)][(*(p+1)-3)]='~';		
	}
}
if(*(p+1)+2<k ){
     if ( t[(*p)][(*(p+1)+2)]=='O' ){//in next two right box	
			t[(*p)][(*(p+1)+1)]='~';
			//t[(*p)-1][(*(p+1)+2)]='~';
			//t[(*p)+1][(*(p+1)+2)]='~';
			//t[(*p)][(*(p+1)+3)]='~';
			
		}
	}
}	







