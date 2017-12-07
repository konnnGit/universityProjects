
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//# include <time.h>

//#define STACKSIZE 100





typedef struct  
	{
	int y;
	int x;
	bool king;
	//int white;
		
}piece;

typedef struct  {
	int board[8][8]; 
	piece x_piece[12];
	piece o_piece[12];	   
    //struct game *next;
} GAME;

typedef struct gamestack {
	GAME the_game;
	struct gamestack *next;
}GAMESTACK;



void print_board(int [8][8]);
//int getx();
//int gety();
int move_x(int [8][8],  piece *,int ,int ,int ,int );/*returns 0 if the move is wrong */
int move_o(int [8][8], piece *,int ,int ,int ,int );/*returns 0 if the move is wrong */
void push_game(GAMESTACK ** , GAME );
GAME pop_game(GAMESTACK **);
void newgame();
void restoregame(GAME );



  
int main(int argc  ,char **argv){
	GAME inGAME;	
	FILE *inFILE;
		 
			if (strcmp(*(argv+1),"-l")==0 ){
			 inFILE=fopen(*(argv+2),"rb");
				fread(&inGAME,1,sizeof(GAME),inFILE);
				restoregame(inGAME);
				
			}
						
			else	if (strcmp(*(argv+1),"-n")==0) newgame();
			
			else puts("Wrong arguments.\n");		
				
				
	return 1;
}


void newgame(){
			int i,coo_int[5],right_x_move,right_o_move;	
			i=0;	
			char coo[5];
	
			GAME mygame = { 
			.board={
				{1,0,1,0,1,0,1,0},
			{0,1,0,1,0,1,0,1},
			{1,0,1,0,1,0,1,0},
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0},
			{0,2,0,2,0,2,0,2},
			{2,0,2,0,2,0,2,0},
			{0,2,0,2,0,2,0,2} 
			},
			.x_piece={
				{0,0,0},{0,2,0},{0,4,0},{0,6,0},{1,1,0},{1,3,0},{1,5,0},{1,7,0},{2,0,0},{2,2,0},{2,4,0},{2,6,0}
				},
			.o_piece={
				{7,1,0},{7,3,0},{7,5,0},{7,7,0},{6,0,0},{6,2,0},{6,4,0},{6,6,0},{5,1,0},{5,3,0},{5,5,0},{5,7,0}
				}	
			
			};	
	
	 
			GAME *pmygame;
			pmygame=&mygame;
			
			GAMESTACK	mygamestack;
			mygamestack.the_game=mygame;
			mygamestack.next=NULL;
			
			GAMESTACK	*pmygamestack;
			pmygamestack=&mygamestack;			
	
			print_board(pmygame->board);/* Initial print */
			
			do{		/* A loop to Repeat the game */		
			
/*--------------------The O's player turn starts------------------------*/
				
				do{ 
					puts("X player select move :");/* Repeat the X player if the play is wrong*/
					
					/* Read the X's input*/					
					do{ 		
						coo[i++]=getchar();	//i++;	
					}while(i<=5);
					
		

	if(strncmp(coo,"z9-z9",5)==0) {
		char store;		
		puts("You end the game, do you want to store the game?y,n:\n");		
		if((store=getchar())=='y'){
			int file_letter_buffer=0;
			char filename[5],file_end[]=".chk";
			FILE *f;
			//char ch;
			puts("Which is the name (until 5 letters) of file?\n");
			while(file_letter_buffer<6 || filename[file_letter_buffer]=='\n' ){
			filename[file_letter_buffer++]=getchar();
		}
			strcat(filename,file_end);
			f=fopen(filename,"wb");
			fwrite(&mygame ,sizeof( GAME),1,f);
			fclose(f);
}
			
		
		
		 exit(0);}
	else if (strncmp(coo,"u9-u9",5)==0){
			puts("You redid the game\n");
			*pmygame=pop_game(&pmygamestack);		
			i=0;	
			break;
	}
	else{
			push_game(&pmygamestack,*pmygame );
			for(i=0;i<5;i++){ /*----Convert the char coordinates to integers---*/
				switch (coo[i]){
				case 'a' : coo_int[i]=0;
				break;
				case 'b' : coo_int[i]=1;		
				break;
				case 'c' : coo_int[i]=2;
				break;		
				case 'd' : coo_int[i]=3;
				break;
				case 'e' : coo_int[i]=4;
				break;
				case 'f' : coo_int[i]=5;
				break;
				case 'g' : coo_int[i]=6;
				break;
				case 'h' : coo_int[i]=7;
				break;
				case '1' : coo_int[i]=0;
				break;
				case '2' : coo_int[i]=1;
				break;
				case '3' : coo_int[i]=2;
				break;
				case '4' : coo_int[i]=3;
				break;
				case '5' : coo_int[i]=4;
				break;
				case '6' : coo_int[i]=5;
				break;
				case '7' : coo_int[i]=6;
				break;
				case '8' : coo_int[i]=7;
				break;
				//default : printf("No propiate coordinates..\n");
				//break;
				
			}
}		
		//}while(board[coo_int[1]][coo_int[0]]!=1);						
					for(i=0;i<12;i++){/*---Seek for the selected piece--- */			
						if (pmygame->board[coo_int[1]][coo_int[0]]==1 && pmygame->x_piece[i].x==coo_int[0] && pmygame->x_piece[i].y==coo_int[1] ){
							//printf("(%d,%d)\n",x_piece[i].x,x_piece[i].y)	;	
							right_x_move=move_x(pmygame->board,&pmygame->x_piece[i],coo_int[0],coo_int[1],coo_int[3],coo_int[4]);							
							break;	/*--If the piece found stop seeking----*/
				}			
		}
		
		i=0;
	}
		}while(right_x_move==0 ); 
		
/*------------------------The O's player turn stops--------------------------------*/
	
		print_board(pmygame->board);
		
		
/*------------------------The O's player turn starts--------------------------------*/
		
		do{		
			puts("O player select move :");
			do{
			coo[i++]=getchar();
				//i++;	
			}while(i<=5);
			
	if(strncmp(coo,"z9-z9",5)==0) {
		char store;		
		puts("You end the game, do you want to store the game?y,n:\n");		
		if((store=getchar())=='y'){
			int file_letter_buffer=0;
			char filename[14],file_end[]=".chk";
			FILE *f;
			//char ch;
			puts("Which is the name (until 10 letters) of file?\n");
			while(file_letter_buffer<10 || filename[file_letter_buffer]=='\n'){
			filename[file_letter_buffer++]=getchar();
		}
			strcat(filename,file_end);
			f=fopen(filename,"w+");
			fwrite(pmygame ,sizeof(GAME),1,f);
			fclose(f);
}
			
		
		
		 exit(0);}
	
	 else if (strncmp(coo,"u9-u9",5)==0){
		puts("You redid the game\n"); 
		*pmygame=pop_game(&pmygamestack);	
		i=0;
		break;
	}
	else{
		push_game(&pmygamestack,*pmygame );

	for(i=0;i<5;i++){/*---Convert the char coordinates to integers----*/
	switch (coo[i]){
		case 'a' : coo_int[i]=0;
		break;
		case 'b' : coo_int[i]=1;		
		break;
		case 'c' : coo_int[i]=2;
		break;		
		case 'd' : coo_int[i]=3;
		break;
		case 'e' : coo_int[i]=4;
		break;
		case 'f' : coo_int[i]=5;
		break;
		case 'g' : coo_int[i]=6;
		break;
		case 'h' : coo_int[i]=7;
		break;
		case '1' : coo_int[i]=0;
		break;
		case '2' : coo_int[i]=1;
		break;
		case '3' : coo_int[i]=2;
		break;
		case '4' : coo_int[i]=3;
		break;
		case '5' : coo_int[i]=4;
		break;
		case '6' : coo_int[i]=5;
		break;
		case '7' : coo_int[i]=6;
		break;
		case '8' : coo_int[i]=7;
		break;
		//default : printf("No propiate coordinates..\n"); 
		//break;
		
	}
}

		//}while(board[coo_int[3]][coo_int[2]])!=2);		
			
			for(i=0;i<12;i++){
				
				if (pmygame->board[coo_int[1]][coo_int[0]]==2 && pmygame->o_piece[i].x==coo_int[0] && pmygame->o_piece[i].y==coo_int[1] )	{
					//printf("(%d,%d)\n",o_piece[i].x,o_piece[i].y)	;		
					right_o_move=move_o(pmygame->board,&pmygame->o_piece[i],coo_int[0],coo_int[1],coo_int[3],coo_int[4]);					
					//printf("(%d,%d)\n",o_piece[i].x,o_piece[i].y)	;
					break;
				}
								
		}		
		i=0;
	}
	}while(right_o_move==0 );
	
/*-------------------------The O's player turn stop--------------------------------------*/
	
		print_board(pmygame->board);
		
		
	}while(strncmp(coo,"z9-z9",5)!=0);/*--- A fake compare to stop the game.The real check happens inside the code--- */
	
	puts("You ended the game\n");	
//	print_board(board);
	}
	
	
		
	



void print_board(int b[8][8]){
	int i,j;
	int count,endx,endy;
	endx=endy=0;
	count=1;
	printf(" ");
	printf(" ");
	for (i=0; i<8;i++){
		//printf(" ");
		printf(" ");
		if (count==1) printf("A");
		else if (count==2) printf("B");
		else if (count==3) printf("C");
		else if (count==4) printf("D");
		else if (count==5) printf("E");
		else if (count==6) printf("F");
		else if (count==7) printf("G");
		else if (count==8) printf("H");
		//printf("%d" ,count);
		printf(" ");
		printf(" ");
		count++;
	}
	count=1;
	printf("\n");
	for (i=0;i<8;i++){
		printf("%d" ,count++);
		printf(" ");
		printf(" ");
			for(j=0;j<8;j++){
				if (b[i][j]==1) {
					endx++;//Counts the number of X
					printf("X"); printf(" "); printf(" "); printf(" ");
				}
				/*else {
					printf("You lost...\n");
					exit(0);
				}*/
				else if (b[i][j]==2){
					endy++;//Counts the number of O
						printf("O"); printf(" "); printf(" "); printf(" ");
					}
				else  	{
							printf(".");	printf(" ");	printf(" "); printf(" ");
						}
		}
		printf("\n\n");
	}
	/*for (i=0;i<8;i++)
		for(j=0;j<8;j++)
		 */
		 if(endx==0 || endy==0){//if num of X or O extinguished the game FINISH
			printf("You lost, end of game....\n");
			exit(0);
		}
	
}

int move_x(int b[8][8], piece *p, int x1, int y1,int x2,int y2){
//	int tempx,ptempy;	
	int eat=1;
	
	if (x1==x2 || y1==y2 || y1>y2+1 || x1>x2+1 || y1<y1-1 || x1<x2-1 || b[y2][x2]==1 || (y2<y1 && p->king==0)){ puts("No CORRECT move..\n"); return 0;}
	
	if (y1<y2){
	//if ( || ( y2<y1 && p->king==0)) { puts("No CORRECT move..\n"); return 0;}
	
	
	 if ( b[y2][x2]==0){
		b[y1][x1]=0;
		b[y2][x2]=1;		
		p->x=x2;
		p->y=y2;	
		if (y2==7) p->king=1;
		//printf("(%d,%d)",p.x,p.y)	;
	}
	
	else if (x2<x1){
		if (b[y2][x2]==2 && (b[y2+1][x2-1]==0 || b[y2+1][x2-1]==2)) {
			//if (x2<x1 && b[y2+1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2+1][x2-1]==2 ) 
				move_x(b,p,x2,y2,x2-1,y2+1);
			//else if (b[y2+1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2+1);
		}
		
		
		
		
		
		
		
		
		
		else puts("Cannot eat..\n");
	}
	
	else if (x2>x1){
		if (b[y2][x2]==2 && ( b[y2+1][x2+1]==0 || b[y2+1][x2+1]==2)) {
			//if (x2<x1 && b[y2+1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2+1][x2+1]==2 ) 
				move_x(b,p,x2,y2,x2+1,y2+1);
			//else if (b[y2+1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2+1);
		}
		else puts("Cannot eat..\n");
	}
}
	if(y2<y1 && p->king==1){
		if (b[y2][x2]==1){ puts("No CORRECT move..\n"); return 0;}
	
	else if ( b[y2][x2]==0){
		b[y1][x1]=0;
		b[y2][x2]=1;		
		p->x=x2;
		p->y=y2;	
		if (y2==7) p->king=1;
		//printf("(%d,%d)",p.x,p.y)	;
	}
	
	else if (x2<x1){
		if (b[y2][x2]==2 && (b[y2-1][x2-1]==0 || b[y2-1][x2-1]==2)) {
			//if (x2<x1 && b[y2-1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2-1][x2-1]==2 ) 
				move_x(b,p,x2,y2,x2-1,y2-1);
			//else if (b[y2-1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2-1);
		}
		else puts("Cannot eat..\n");
	}
	
	else if (x2>x1){
		if (b[y2][x2]==2 && ( b[y2-1][x2+1]==0 || b[y2-1][x2+1]==2)) {
			//if (x2<x1 && b[y2-1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2-1][x2+1]==2 ) 
				move_x(b,p,x2,y2,x2+1,y2-1);
			//else if (b[y2-1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2-1);
		}
		else puts("Cannot eat..\n");
	}
}

	return 1;
	
}

int move_o(int b[8][8], piece *p, int x1, int y1,int x2,int y2){
//	int tempx,ptempy;
		int eat=1;
		
	if (x1==x2 || y1==y2 || y1>y2+1 || x1>x2+1 || y1<y1-1 || x1<x2-1 || b[y2][x2]==2 || (y2>y1 && p->king==0)){ puts("No CORRECT move..\n"); return 0;}
	 
	if (y1>y2){//--------------------y1>y2
	//if (b[y2][x2]==2 || ( y2>y1 && p->king==0)){ puts("No CORRECT move..\n"); return 0;}
	
	 if ( b[y2][x2]==0){
		b[y1][x1]=0;
		b[y2][x2]=2;		
		p->x=x2;
		p->y=y2;	
		if (y2==7) p->king=1;
		//printf("(%d,%d)",p.x,p.y)	;
	}
	
	else if (x2<x1){
		if (b[y2][x2]==1 && (b[y2-1][x2-1]==0 || b[y2-1][x2-1]==1)) {
			//if (x2<x1 && b[y2+1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=2;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2-1][x2-1]==1 ) 
				move_o(b,p,x2,y2,x2-1,y2-1);
			//else if (b[y2+1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2+1);
		}
		else puts("Cannot eat..\n");
	}
	
	else if (x2>x1){
		if (b[y2][x2]==1 && ( b[y2-1][x2+1]==0 || b[y2-1][x2+1]==1)) {
			//if (x2<x1 && b[y2+1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=2;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2-1][x2+1]==2 ) 
				move_o(b,p,x2,y2,x2+1,y2-1);
			//else if (b[y2+1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2+1);
		}
		else puts("Cannot eat..\n");
	}
}
	if(y2>y1 && p->king==1){//------------y1<y2
		if (b[y2][x2]==2){ puts("No CORRECT move..\n"); return 0;}
	
	else if ( b[y2][x2]==0){
		b[y1][x1]=0;
		b[y2][x2]=2;		
		p->x=x2;
		p->y=y2;	
		if (y2==7) p->king=1;
		//printf("(%d,%d)",p.x,p.y)	;
	}
	
	else if (x2<x1){
		if (b[y2][x2]==1 && (b[y2+1][x2-1]==0 || b[y2+1][x2-1]==1)) {
			//if (x2<x1 && b[y2-1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2+1][x2-1]==1 ) {
				move_o(b,p,x2,y2,x2-1,y2-1);
				eat++;	
			}
			//else if (b[y2-1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2-1);
		}
		else puts("Cannot eat..\n");
	}
	
	else if (x2>x1){
		if (b[y2][x2]==2 && ( b[y2+1][x2+1]==0 || b[y2+1][x2+1]==2)) {
			//if (x2<x1 && b[y2-1][x2-1]==0){
			b[y1][x1]=0;
			b[y2][x2]=1;		
			p->x=x2;
			p->y=y2;
			if (y2==7) p->king=1;
			printf("You ate %d foe piece..\n",eat);
			eat++;		
			if (b[y2+1][x2+1]==1 ) 
				move_o(b,p,x2,y2,x2+1,y2+1);
			//else if (b[y2-1][x2-1]==2) move_x(b,p,x2,y2,x2-1,y2-1);
		}
		else puts("Cannot eat..\n");
	}
}

	
	return 1;
	
}

void push_game(GAMESTACK **head ,GAME new_game_data ){	
	
    GAMESTACK *newnode = malloc(sizeof(GAMESTACK));  /* create a new node */
 
    if (head == NULL){
        fputs("Error: no space available for node\n", stderr);
        abort();
    } 
    else { 
		newnode->the_game=new_game_data;
		newnode->next=NULL;		
		*head=newnode;
		
    }
}



GAME pop_game(GAMESTACK **head){
	
    if (head==NULL) {                          /* stack is empty */
       fputs("Error: BOARD stack underflow\n", stderr);
       abort();
     // return 0;
    } 
    else {                                     /* pop a node */
        GAMESTACK *top;
        top=*head; 
        //top=head;    
        GAME lastgame=top->the_game;           
        *head = top->next;
        free(top);        
        return lastgame;    		
        
    }
    
}

void restoregame(GAME restored_game){
		int i,coo_int[5],right_x_move,right_o_move;	
			i=0;	
			char coo[5];		 			
			GAME *prestored_game=&restored_game;
			GAMESTACK	restored_gamestack;
			restored_gamestack.the_game=restored_game;
			restored_gamestack.next=NULL;
			
			GAMESTACK	*prestored_gamestack;
			prestored_gamestack=&restored_gamestack;			
	
			print_board(prestored_game->board);/* Initial print */
			
			do{		/* A loop to Repeat the game */		
			
			/*-----The O's player turn starrt------*/
				
				do{ 
					puts("X player select move :");/* Repeat the X player if the play is wrong*/
					
					/* Read the X's input*/					
					do{ 		
						coo[i++]=getchar();	//i++;	
					}while(i<=5);

	if(strncmp(coo,"z9-z9",5)==0) {
		char store;		
		puts("You end the game, do you want to store the game?y,n:\n");		
		if((store=getchar())=='y'){
			int file_letter_buffer=0;
			char filename[14],file_end[]=".chk";
			FILE *f;
			//char ch;
			puts("Which is the name (until 10 letters) of file?\n");
			while(file_letter_buffer<10 || filename[file_letter_buffer]=='\n'){
			filename[file_letter_buffer++]=getchar();
		}
			strcat(filename,file_end);
			f=fopen(filename,"w+");
			fwrite(prestored_game ,sizeof(GAME),1,f);
			fclose(f);
}
			
		
		
		 exit(0);}
	else if (strncmp(coo,"u9-u9",5)==0){
			puts("You redid the game\n");
			*prestored_game=pop_game(&prestored_gamestack);		
			i=0;	
			break;
	}
	else{
			push_game(&prestored_gamestack,*prestored_game );
			for(i=0;i<5;i++){ /*----Convert the char coordinates to integers---*/
				switch (coo[i]){
				case 'a' : coo_int[i]=0;
				break;
				case 'b' : coo_int[i]=1;		
				break;
				case 'c' : coo_int[i]=2;
				break;		
				case 'd' : coo_int[i]=3;
				break;
				case 'e' : coo_int[i]=4;
				break;
				case 'f' : coo_int[i]=5;
				break;
				case 'g' : coo_int[i]=6;
				break;
				case 'h' : coo_int[i]=7;
				break;
				case '1' : coo_int[i]=0;
				break;
				case '2' : coo_int[i]=1;
				break;
				case '3' : coo_int[i]=2;
				break;
				case '4' : coo_int[i]=3;
				break;
				case '5' : coo_int[i]=4;
				break;
				case '6' : coo_int[i]=5;
				break;
				case '7' : coo_int[i]=6;
				break;
				case '8' : coo_int[i]=7;
				break;
				//default : printf("No propiate coordinates..\n");
				//break;
				
			}
}		
		//}while(board[coo_int[1]][coo_int[0]]!=1);						
					for(i=0;i<12;i++){/*---Seek for the selected piece--- */			
						if (prestored_game->board[coo_int[1]][coo_int[0]]==1 && prestored_game->x_piece[i].x==coo_int[0] && prestored_game->x_piece[i].y==coo_int[1] ){
							//printf("(%d,%d)\n",x_piece[i].x,x_piece[i].y)	;	
							right_x_move=move_x(prestored_game->board,&prestored_game->x_piece[i],coo_int[0],coo_int[1],coo_int[3],coo_int[4]);							
							break;	/*--If the piece found stop seeking----*/
				}			
		}
		
		i=0;
	}
		}while(right_x_move==0 ); 
	
		print_board(prestored_game->board);
		
		
/*------------The O's player turn starrt------------*/
		
		do{		
			puts("O player select move :");
			do{
			coo[i++]=getchar();
				//i++;	
			}while(i<=5);

	if(strncmp(coo,"z9-z9",5)==0) {
		char store;		
		puts("You end the game, do you want to store the game?y,n:\n");		
		if((store=getchar())=='y'){
			int file_letter_buffer=0;
			char filename[14],file_end[]=".chk";
			FILE *f;
			//char ch;
			puts("Which is the name (until 10 letters) of file?\n");
			while(file_letter_buffer<10 || filename[file_letter_buffer]=='\n'){
			filename[file_letter_buffer++]=getchar();
		}
			strcat(filename,file_end);
			f=fopen(filename,"w+");
			fwrite(prestored_game ,sizeof(GAME),1,f);
			fclose(f);
}
			
		
		
		 exit(0);}
	
	 else if (strncmp(coo,"u9-u9",5)==0){
		puts("You redid the game\n"); 
		*prestored_game=pop_game(&prestored_gamestack);	
		i=0;
		break;
	}
	else{
		push_game(&prestored_gamestack,*prestored_game );

	for(i=0;i<5;i++){/*---Convert the char coordinates to integers----*/
	switch (coo[i]){
		case 'a' : coo_int[i]=0;
		break;
		case 'b' : coo_int[i]=1;		
		break;
		case 'c' : coo_int[i]=2;
		break;		
		case 'd' : coo_int[i]=3;
		break;
		case 'e' : coo_int[i]=4;
		break;
		case 'f' : coo_int[i]=5;
		break;
		case 'g' : coo_int[i]=6;
		break;
		case 'h' : coo_int[i]=7;
		break;
		case '1' : coo_int[i]=0;
		break;
		case '2' : coo_int[i]=1;
		break;
		case '3' : coo_int[i]=2;
		break;
		case '4' : coo_int[i]=3;
		break;
		case '5' : coo_int[i]=4;
		break;
		case '6' : coo_int[i]=5;
		break;
		case '7' : coo_int[i]=6;
		break;
		case '8' : coo_int[i]=7;
		break;
		//default : printf("No propiate coordinates..\n"); 
		//break;
		
	}
}

		//}while(board[coo_int[3]][coo_int[2]])!=2);		
			
			for(i=0;i<12;i++){
				
				if (prestored_game->board[coo_int[1]][coo_int[0]]==2 && prestored_game->o_piece[i].x==coo_int[0] && prestored_game->o_piece[i].y==coo_int[1] )	{
					//printf("(%d,%d)\n",o_piece[i].x,o_piece[i].y)	;		
					right_o_move=move_o(prestored_game->board,&prestored_game->o_piece[i],coo_int[0],coo_int[1],coo_int[3],coo_int[4]);					
					//printf("(%d,%d)\n",o_piece[i].x,o_piece[i].y)	;
					break;
				}
								
		}		
		i=0;
	}
	}while(right_o_move==0 );
	
	/*-----The O's player turn stop------*/
	
		print_board(prestored_game->board);
		
		
	}while(strncmp(coo,"z9-z9",5)!=0);/*--- A fake compare to stop the game.The real check happens inside the code--- */
	
	puts("You ended the game\n");	
//	print_board(board);
	}
