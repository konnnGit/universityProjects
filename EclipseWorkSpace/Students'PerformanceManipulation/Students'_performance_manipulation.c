/*Students' performance manipulation*/

/*Konstantinos Spalas, cst08094
 * Only me in group */


#include <stdio.h>
#define N 3//Here we change the amount of students allowed to store.Now is until three.

//All the functions take as parameter the array of students
//Presume that the values(ID,age,sex and degree) stored in a 2d array

//The program pains whether you need to add less students than those allowed

void insert_student(int [N][4]);
void print_students(int [N][4]);
int max_degree(int [N][4]);
int min_degree(int [N][4]);
int average(int [N][4]);

int main(void){
	int student[N][4],max,min,choise,j;
	max=min=j=choise=0;
	
	while(choise!=6){
	printf("\nThe progmam allows you to insert the degrees and the age of some students and count their performance.You can choose from the menu as follow:\n\n");
	printf("\nChoises to select:\n1.Insert students, 2.Print students, 3.High scored student, 4.Low scored student, 5.Degrees Average, 6.Exit\nYou select :");
	scanf("%d",&choise);
	
	switch(choise){			
		case 1 :
		insert_student(student);
		//break;
		continue;
		case 2:
		print_students(student);
		continue;
		case 3:		
		max=max_degree(student);
		printf("\nHigh scored student=");	
		printf(" ID:%d, Age:%d, Sex:%d, Degree:%d\n ",student[max][j],student[max][j+1],student[max][j+2],student[max][j+3]);
		continue;
		case 4:
		min=min_degree(student);
		printf("\nLow scored student=");	
		printf(" ID:%d, Age:%d, Sex:%d, Degree:%d\n ",student[min][j],student[min][j+1],student[min][j+2],student[min][j+3]);
		continue;
		case 5:
		printf("\nThe degrees average is =%d\n",average(student));
		
		
	}	  
		
	}	
printf("\nBye Bye..");
return 0;	
}

void insert_student(int a[N][4]){
	    int i,k,j;
	   // p=a[0][0];
	    i=j=k=0;
		while(i<N && j<4){//Check to stay whithin array
		printf("\nGive the ID, between 0 to 500 ,of the %d student:\n",i+1);
		scanf("%d",&a[i][j]);
		k=0;
			while(k<i){//Here we ran a check of the ID's given to see for dublicates
			if (a[i][j]==a[k][j]) { //We use the k to ran until the already i.
				printf("\nAlready given.Give another ID, between 0 to 500 ,of the %d student:\n",i+1);
				scanf("%d",&a[i][j]);
			}
			else  k++;//if check ok , move forward the array to check.
		}
		j++;//If the whole check ok, move for the next insertion
		printf("\nGive the age ,between 18 and 35, of the %d student:\n",i+1);
		scanf("%d",&a[i][j]);
			while (a[i][j]<18 || a[i][j]>35) { 
				printf("\nAge out of range, between 18 and 35, of the %d student:\n",i+1);
				scanf("%d",&a[i][j]);
			}
			
		j++;//move for the next insertion
		printf("\nGive the sex  ,1 for male and 2 for female,of the %d student:\n",i+1);
		scanf("%d",&a[i][j]);
		while (a[i][j]<1 || a[i][j]>2) { 
			printf("\nWrong,1 for male and 2 for female:\n");
			scanf("%d",&a[i][j]);
		}
		j++;
		printf("\nGive the degree , between 1 to 10,of the %d student:\n",i+1);
		scanf("%d",&a[i][j]);
		while (a[i][j]<1 || a[k][j]>10) { 
			printf("\nWrong degree,1 to N:\n");
			scanf("%d",&a[i][j]);
		}
		j=0;//send value pointer to the start in order to add a new student
		i++;//next student
	}		
	
}

void print_students(int a[N][4]){
	int i,j;
	j=0;
	for(i=0;i<N;i++){//Ran through the array in order to print
		printf("\nStudent %d:\n",i+1);		
			printf( "ID:%d, Age:%d , Sex:%d , Dedree:%d",a[i][j],a[i][j+1],a[i][j+2],a[i][j+3]);
		}
		printf("\n");
}
	
int max_degree(int a[N][4]){
	int i,max,max_point;
	i=0;
	max=a[0][3];//max stores the maximum degree which always stored in the a place like [a value][3].max initialized in the the first point of the array.
	max_point=i;//max_point stores the point where the student is(1st,2nd,3rd)
	for (i=0;i<N-1;i++){
		if( max<a[i+1][3]){
		 max=a[i+1][3];
		 max_point=i+1;
		}
		
	}
		return max_point;//We return that point.
				
}

int min_degree(int a[N][4]){//As the previous function
	int i,min,min_point;
	i=0;
	min=a[0][3];
	min_point=i;
	for (i=0;i<N-1;i++){
		if( min>a[i+1][3]){
		 min=a[i+1][3];
		 min_point=i+1;
		}
		
	}
		return min_point;
				
}

int average(int a[N][4]){
	int i;
	int j=0;	
	for (i=0;i<N;i++)
		j=j+a[i][3];//add the degrees
return j/N;	//devide whith the population
}
	
	
	
	
	
	



