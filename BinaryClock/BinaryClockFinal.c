/*---Konstantinos Spalas-------@#@#--*/
#include <stdlib.h>
#include <stdio.h>
//#include <time.h>
//#include <pthread.h>
//#include <fcntl.h>
#include <signal.h>
//#include <unistd.h>

//Definitions	
typedef struct node{	    		
	int data;
	struct node *next; }Node;	
int start;	
Node * findLast(Node *);
	
void createClock(int , Node *);
void printList (Node *);
void runClock (int,Node *,int,int,int)	;
void sigHandler(int);
void freeMem(Node *);

//main
	int main(){
		int hour,min,met;
		hour=min=met=-1;
		int N,option;
		printf("What is the accurancy of the clock? : ");
		scanf(	"%d",&N);
		Node *head=malloc(sizeof(Node));
		head->next=NULL;
		head->data=0;
		createClock(N,head);
		//printList(head);			
					
		while(1){	
		printf("\nOptions:\n0.Exit\n1.(Re)Start clock\n2.Set alarm\n3.When pointers met\n");
		scanf("%d",&option);				
		
			switch (option){
			
				
			case 0:
			printf("You exited the program..bb..\n");
			freeMem(head);
			return 1;
			break;
			
			case 1:		
			//run(N,head,option);
			start=1;
			runClock(N,head,-50,-50,-50);							
			break;
			
			case 2:			
			printf("Set alarm hour:\n");
			scanf("%d",&hour);
			printf("Set alarm minute:\n");
			scanf("%d",&min);
			start=1;
			runClock(N,head,hour,min,-50);
			break;
			
			case 3:			
			printf("Press 1 if you want to find when pointers met or ctr+C to go to global menu\n");
			scanf("%d",&met);			
			start=met=1;
			runClock(N,head,-50,-50,met);
			break;
			
			}
		}
		
		
		return 1;		
		
	
}
	
//Functions inplementation.
	
void runClock(int n,Node *h,int getHour,int getMin, int getMet){
	//set the pointers/vars
	//int alarmAid=0;
	Node *sec=malloc(sizeof(Node));
	Node *min=malloc(sizeof(Node));
	Node *hour=malloc(sizeof(Node));
	sec=min=hour=h;	
	int countHour,countMin;
	countHour=countMin=0;
	
	while (start){		
		signal(SIGINT, sigHandler);		
		printf("Hour:%d ",hour->data/(5*n));
		printf("Min.:%d ",min->data/n);
		printf("Sec.:%d",sec->data/n);
		printf("\r");
		
		
		//pointers met??
		if (((hour->data/(5*n))==(min->data/n)) && getMet==1){
				printf("\nPointers met....\n");
			//alarmAid=0;
			}
			//end pointers met
			
		//run the sec pointer								
		sec=sec->next;	
		
		/*in every full cicle,when the sec->data zeros, the min pointer moves one minute but n times the nodes.
		 * The same with the hour pointer.*/
		 
		if(sec->data==0){			
			while(countMin<n){
			min=min->next;
			//countSec=0;
			countMin++;
			}
		countMin=0;
			if(min->data==0){
		
				
			while(countHour<n){
			hour=hour->next;
			//countSec=0;
			countHour++;
			}
		countHour=0;	
			}
			
			//check the alarm
			if ((hour->data/(5*n))==getHour && 	(min->data/n)==getMin){
			printf("\nAlarm rings....\n");
			}
			
	}
			
		
		}
			
	
			
	
	
}


//find last node in order to create the clock
Node *findLast (Node *h){
	Node *last=malloc(sizeof(Node));
	last=h->next;	
	
	while(last->next!=h) {
		last=last->next;		
	}
	return last;
}

void createClock( int n, Node *h){
	Node *new,*last;
	last=malloc(sizeof(Node));
	h->next=last;
	last->next=h;
	last->data=1;
	int i;
	
	for(i=2;i<=60*n-1;i++){
	last=findLast(h);
	new=(Node *)malloc(sizeof(Node));
	new->data=i;
	last->next=new;
	new->next=h;
	}	
	
}

void printList(Node *h){
	Node *temp;
	temp=h;
	
	do{
		printf("%d->",temp->data);
		temp=temp->next;
	}while (temp->next!=h);
	
	printf("%d->",temp->data);
	temp=temp->next;
	printf("%d",temp->data);
}

void freeMem(Node *h){
			Node *temp;
			temp=malloc(sizeof(Node));			
			temp=h;
			temp=temp->next;			
			h->next=NULL;
			
			while(temp->next!=NULL){
				free(temp);								
				temp=temp->next;					
			}				
		

}

//When press ctrl+c, in linux terminal, the clock stalls.
void sigHandler(int sig)
{
   printf("Signal %d, clock stalls...\n", sig);
   start=0;
}