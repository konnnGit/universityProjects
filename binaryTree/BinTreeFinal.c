/*--------Konstantinos Spalas , cst08094@uop.gr , AM: 2025200800094---------*/

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
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//#include <treeprint.h>


typedef struct TreeNode{
	int key;
	int level;//used to determine the level of the node in the tree
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

//Declarations	
void insert(TreeNode *,int);
int search(TreeNode *,int);
void print(TreeNode *);
int max(TreeNode *);
void succ(TreeNode *,int);
TreeNode *returnPreXNode(TreeNode *,int);
TreeNode *returnXNode(TreeNode *,int);
int size(TreeNode *,int);
int countOrder(TreeNode * );
void delete(TreeNode *);

//Main
int main(int argc, char **argv){
	int x;
	TreeNode *root=malloc(sizeof(TreeNode));
	//root=NULL;
	char word[31];  // max 30 characters;

    printf("Give orders (print,insert x,max,search x,size x,succ x,exit):\n");

    while (1) {
        
	scanf("%s",word);
	
	if (strcmp(word, "print")==0) {
		printf("Choosed to  print.");
		print(root);
	}
	
	else if (strcmp(word, "exit")==0){
		printf("Deleting tree...exiting....\n"); 
		delete(root);
		return 0;
	}	
	
	else if (strcmp(word, "max")==0){
		if (max(root)==-1) printf("The tree is emty.\n");
		else printf("The max is %d ",max(root)); 
		
	}
	
	else if (strcmp(word, "size")==0){
		scanf("%d", &x);
	 	printf("Choosed to find the size from node %d which is %d . \n", x,size(root,x));
		
		
	}
	
	else if (strcmp(word, "succ")==0){
		scanf("%d", &x);
	 	printf("Choosed to succ %d.", x);	 
	 	succ(root,x);	
		
	}
		
	else if (strcmp(word, "insert")==0)   {		
		scanf("%d", &x);
	 	printf("Choosed to insert %d.", x);	
	 	insert(root,x);	
	} 
	
	else if (strcmp(word, "search")==0){
		scanf("%d", &x);
		if(	search(root,x)) printf("The key %d already exist.\n", x);
		else printf("The key %d doesn't exist.\n", x);
	}
	
	else printf("Uknown command...retry:\n");
	
	printf("\n");
}
	
	
	
	return 1;
}

//Functions

void delete(TreeNode *root){
	if(root==NULL) return;
	delete(root->left);
	delete(root->right);
	free(root);
}
		 

int search(TreeNode *root, int x) {
	TreeNode *v = root;  
	if(v==NULL){ printf("The tree is empty."); return 0;}
	
	while (v != NULL) {         
      	if (x < v->key) v=v->left;
     	else if (x > v->key) v=v->right;
      	else   return 1;
           
              
   }
  // printf("The key %d did not found.\n",x);
   return 0;
} 

TreeNode * returnPreXNode(TreeNode *root,int x){//This function returns the node before the key x
	TreeNode *v = root;
	TreeNode *pv =NULL;
	while (v != NULL) {  
      //pv = v; 
      	if (x < v->key) v=v->left;
      	else if (x > v->key) v=v->right;
      	else   return pv;           
              
   }
	
	return NULL;
}

TreeNode * returnXNode(TreeNode *root,int x){//This function returns the node of the key x
	TreeNode *v = root;	
	while (v != NULL) {        
     	 if (x < v->key) v=v->left;
     	 else if (x > v->key) v=v->right;
     	 else   return v;           
              
   }
	return NULL;
	
}





void insert(TreeNode *root, int x) {  
		int level=0;
	   TreeNode *v = root; 
	   TreeNode *pv =NULL;
	   TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));//Due to the existance check happens later the memory is occupied in case of existanse.Have to go lower.
	   tmp->key=x; tmp->left=tmp->right=NULL; tmp->level=0;   
	   if(v==NULL){ v=tmp; v->level=level; return;}
	   else if(search(v,x)){ printf("The key %d already exists.\n", x); return;}
	   else{   
			while (v != NULL) { 
				pv=v;
			//	level++;
				if (x < v->key){ level=(v->level)+1; v=v->left; }
				else {  level=(v->level)+1;v=v->right;}
	   } 
	   tmp->level=level;
	   if(x<pv->key) pv->left=tmp;//connect the new node to the tree
	   else pv->right=tmp;//connect the new node to the tree
	}   
}

int max(TreeNode * root){
	TreeNode *v = root;  
	if (v==NULL) return -1;
	while(v->right!=NULL)v=v->right;
	return v->key;
		
}

void succ(TreeNode * root,int x) {
	if (root==NULL){  printf(" Emty tree.\n"); return;}
	
	else if(search(root,x)){
		 printf("The key %d  exists ",x);
			//check if there is a greater child
		 if(returnXNode(root,x)->right!=NULL) printf(" and the  greater is %d . ",returnXNode(root,x)->right->key);
			//if there is not a greater childe return the previous node 
		 else printf(" and the  greater is %d . ",returnPreXNode(root,x)->key);
	//printf(" there is not any greater key\n");
		 
	 } 
	 else  printf(" The key does not exist\n"); 
	
	
}

int countOrder(TreeNode * root){//a utility function which counts the nodes from a given node
	TreeNode *v =root;
	if(v==NULL) return 0;
	else return countOrder(v->left)+1+countOrder(v->right);
}
	
int size(TreeNode * root,int x) {
//	int s=0;	
	TreeNode *v = returnXNode(root,x); //count from the node of key x
	return countOrder(v);
}


void print(TreeNode * root) {//print function is a preOrder traversal
	if (root==NULL) return;
	int i,j;
	TreeNode *v = root;  
	if (v!=NULL) {			
	for(j=0;j<v->level;j++) printf("\n");
	for(i=0;i<v->key-1;i++)
		printf(" ");
	printf("%d",v->key);
	print(v->left);	
	print(v->right);
	
 }
 }
