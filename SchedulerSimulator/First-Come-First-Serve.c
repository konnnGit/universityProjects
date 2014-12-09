/*--Konstantinos Spalas, AM: 2025200800094,cst08094@uop.gr---*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
# include <time.h>
//#include "clcg4.c"
#include <signal.h>
typedef struct job{		
	int id;
	//The id set to aid the queue acknowledge but not used
	int executed;    		
	float timeIn;
	float timeOut;
	//struct job *prev;
	struct job *next; }job;
	
	//--------functions declare---------
	int gen(int,float);
	//void RoundRobin(job *  ,float);
	int isEmpty(job *);
	void pushJob(job *,float,int,float,int );
	job *popJop(job *,float );
	void sigHandler(int);
	job *newAdd(job *);
	
	
	
	
	//---------------------------main------------------------------------------
	int main(){	
		//InitDefault();
		srand((float) time(NULL));//Initalize rand .	
			
		int timeStart,timeStop,timeSlice,countSlices,nOfQ,i,countQ;	
		countSlices=countQ=0;
		int j;	
		//nOfQ is number of queues and countQ counts them		
		float p;//p is the load	
		int totalExecutions=0;	
		float totalTimeWait=0;	
			
		printf("Select the time start:");
		scanf("%d",&timeStart);
		int globalTimeStart=timeStart;
		printf("Select the time stop:");
		scanf("%d",&timeStop);
		printf("Select the time slices:");
		scanf("%d",&timeSlice);
		
		printf("Select the number of queues:");
		scanf("%d",&nOfQ);
		printf("Select the float p (0<p<1):");
		scanf("%f",&p);
		
/*---This is an array which stores the head address of each queue---*/
		timeStart++;//add a time not to evoke negative results
		job *queuesH[nOfQ];
		//create queues		
		for(i=0;i<nOfQ;i++){
			queuesH[i]=malloc(sizeof(job));	
			queuesH[i]->id=i;
			queuesH[i]->timeIn=timeStart;
			queuesH[i]->timeOut=0;			
			queuesH[i]->next=NULL;				
			
		}
		
				
			
		double	qExec[nOfQ];//stores for each queue the num of jobs executed
		float 	timeWait[nOfQ];
		//Initialiazing 
		for(i=0;i<nOfQ;i++){
			qExec[i]=timeWait[nOfQ]=0;//Until now 0 executions 			
		}
		
		
		//--------------------Start-----------------------
		printf("\nThis is an   First-Come-First-Serve implementation:\n");
		job *temp;
		temp=malloc(sizeof(job));
		timeStart++;
		
		for (i=0;i<nOfQ;i++){//create new jobs, this happens once in order to sort to imply First-Come-First-Serve
					pushJob(queuesH[i],timeStart+(countSlices/timeSlice),i,p,nOfQ);
					//queues[i]->id=i;
				}
				
				//Sort accordind the min timeIn when the first job created to make it First-Come-First-Serve
				for (i = 0; i < (nOfQ - 1); ++i){
          for (j = 0; j < nOfQ - 1 - i; ++j ){
               if (queuesH[j]->timeIn > queuesH[j+1]->timeIn)
               {
                    temp = queuesH[j+1];
                    queuesH[j+1] = queuesH[j];
                    queuesH[j] = temp;
               }
          }
     }
		
		
		timeStart++;
		//loop the time scheduler operates( Start-Stop)
		while(timeStart<timeStop){					
			signal(SIGINT, sigHandler);
			countSlices=0;
			countQ=0;
			//-----------------time slices start --------------------
			while(countSlices<timeSlice && countQ<nOfQ ){
				
				for (i=0;i<nOfQ;i++){//create new jobs
					pushJob(queuesH[i],timeStart+(countSlices/timeSlice),i,p,nOfQ);//i is for id,p is for load
					//queues[i]->id=i;
				}				
				
				
									
				temp=popJop(queuesH[countQ],timeStart+(countSlices/timeSlice));
				
				
				/*if(temp==NULL&&countQ+1<nOfQ){//Check not to overcome time slices 
					countQ++; 
					continue;
				}**Inerleaved module*****/		
				
				if (temp!=NULL){
					timeWait[countQ]=timeWait[countQ]+temp->timeOut-temp->timeIn;//Queue's i time wait
					qExec[countQ]++;
					queuesH[countQ]=queuesH[countQ]->next;//One job came out and the head moves a node after.
					temp->next=NULL;
					if	(countQ+1<nOfQ)				
					countQ++;
					//else break;
				}								
				/*else if (temp==NULL && countQ+1<nOfQ){								
					countQ++;	
					temp=popJop(queuesH[countQ],timeStart+(countSlices/timeSlice));				
					//countQ++;
					timeWait[countQ]=timeWait[countQ]+temp->timeOut-temp->timeIn;
					qExec[countQ]++;
					queuesH[countQ]=queuesH[countQ]->next;
					temp->next=NULL;
					//if	(countQ<nOfQ)				
					countQ++;
					//else break;
				
				
					//countQ++;
					}	*/
				else break;	
					//break;								
											
				countSlices++;	
				
				
			}
			//----time slices stop  and restart-----
			
			timeStart++;
				
		}
		printf("\nStatistics ");
		printf("for p=%f , %d slices and time %d : \n",p,timeSlice,timeStop-globalTimeStart);
			
		for(i=0;i<nOfQ;i++){		
			totalExecutions=totalExecutions+qExec[i];	
			totalTimeWait=totalTimeWait+timeWait[i];
		}			
			
			for(i=0;i<nOfQ;i++){
			printf("\nFor queue %d: ,",i+1);	
			printf("Num of jobs serviced: %f ,",qExec[i]);	
			printf("Serve rate: %f ,",(qExec[i]/timeStop-globalTimeStart));
			printf("Justice: %f percent,",(qExec[i]/totalExecutions)*100);
			//printf("%");
			printf("Time wait: %f \n",timeWait[i]/totalExecutions);		
		}		
		printf("\n");
	    printf("\nTotal avg time wait %f",totalTimeWait/totalExecutions);		
		printf("\nTotal jobs serviced: %d :", totalExecutions);
		printf("\nTotal serve rate: %d",totalExecutions/timeStop-globalTimeStart);
		
		return 1;
	}
	
	//The generator function
int  gen(int nOfQ,float p){	
	float f;	
	f=(float)rand()/((float)RAND_MAX+1);
	//f=	f*p/nOfQ;
	if(f>=0 && f<p/nOfQ) 
		return 1;
	else return 0;
	
}
	
int isEmpty(job *h){
	if(h->next==NULL)	return 1;
	else 		return 0;
}

//-----FIFO queues-------------
void pushJob(job *h,float timeIn,int id,float p,int nOfQ){
	//printf("%d//",gen());
	if(gen(nOfQ,p)==1){
		if(h->next==NULL){//If it is the 1st job (This step can be eliminated because each queue has been already initiated)
			job *temp;
			temp=malloc(sizeof(job));
			temp->timeIn=timeIn;
			temp->timeOut=0;
			temp->id=id;
			h->next=temp;
			temp->next=NULL;						
				
		}	
		else {	//if it is not the 1st job
		job *temp;
		temp=malloc(sizeof(job));		
		temp->timeIn=timeIn;
		temp->timeOut=0;
		temp->id=id;
		//temp->next=h;	
		while(h->next!=NULL){
			h=h->next;
		}
		
		h->next=temp;
		temp->next=NULL;
		
				 
		}
		//printf("q id :%d",temp->id);
		
	}
	else return;
	
	 }
	//	printf("q id :%d",temp->id);
	//printf("\r");


job *popJop(job *h,float timeOut){
	if(isEmpty(h)) return NULL;	
	else{
		 h->timeOut=timeOut;
		return h;
	}
	
	
 }	
//This gives new global address to a job(Not used)
job *newAdd(job *h){
	if(h->next!=NULL){
	 h=h->next;
	 return h;
	}
	else return NULL;
	}
	
	

//Utility function (Not used)
void sigHandler(int sig){
   //printf("Signal %d, clock stalls...\n", sig);
   printf("printscreen");
   //start=0;
}
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



