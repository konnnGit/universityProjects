
#include <stdio.h>
#include <stdlib.h>

int petra_psalidi_xarti (int );

int main (void){
	int choise=4;
	while (choise!=0){
	printf("Stone=1\n");
	printf("Scissors=2\n");
	printf("Paper=3\n");
	printf("Exit=0\n\n");	
	printf("Give your choise :");
	scanf("%d",&choise);
	petra_psalidi_xarti(choise);
}
    return 0;
}

int petra_psalidi_xarti(int c){
	int value;
	value=rand() % 3+1;
	if (value<c){
		printf("Result %d :",value ); 
		printf("Winner\n") ;
		}
	else if (value==c) {
		printf("Result %d :",value ); 
		printf("Equal\n") ;
		}
	else if (value==1&&c==2){
		printf("Result %d :",value ); 
		printf("Winner\n");
		} else {
			printf("Result %d :",value ); 
			printf("Lost\n ");
			}
	return 0;
}
