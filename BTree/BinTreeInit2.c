/*-----Konstantinos Spalas , AM: 2025200800094---------*/

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
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
	
void insert(TreeNode *,int);
int search(TreeNode *,int);
void print(TreeNode *);
int max(TreeNode *);

int main(int argc, char **argv){
	int x;
	TreeNode *root=malloc(sizeof(TreeNode));
	//root=NULL;
	char word[31];  // mia symboloseira me to poly 30 characters;

    printf("Give orders (print,insert,max,search):\n");

    while (1) {
        
	scanf("%s",word);
	
	if (strcmp(word, "print")==0) {
		printf("Choosed to  print.");
		print(root);
	}
	
	else if (strcmp(word, "exit")==0){
		if(root==NULL) printf("exited");
		else {
			while(root
		}
	}	
	
	else if (strcmp(word, "max")==0){
		if (max(root)==-1) printf("The tree is emty.");
		else printf("The max is %d ",max(root)); 
		
	}
		
	else if (strcmp(word, "insert")==0)   {
		
		scanf("%d", &x);
	 	printf("Choosed to insert %d.", x);	
	 	insert(root,x);	
	} else if (strcmp(word, "search")==0){
		scanf("%d", &x);
		if(	search(root,x)) printf("The key %d already exists.\n", x);
		else printf("The key %d doesn't exists.\n", x);
	}
	else printf("Uknown command...retry:");
	
	printf("\n");
}
	
	
	
	return 1;
}

int search(TreeNode *root, int x) {
	TreeNode *v = root;  // v trexon kombos
	if(v==NULL){ printf("The tree is emty."); return 0;}
	
	while (v != NULL) {  
      //pv = v; 
      if (x < v->key) v=v->left;
      else if (x > v->key) v=v->right;
      else   return 1;
           
              
   }
  // printf("The key %d did not found.\n",x);
   return 0;
}





void insert(TreeNode *root, int x) {  
	   TreeNode *v = root; 
	   TreeNode *pv =NULL;
	   TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
	   tmp->key=x; tmp->left=tmp->right=NULL;    
	   if(v==NULL){ v=tmp; return;}
	   else if(search(v,x)){ printf("The key %d already exists.\n", x); return;}
	   else{   
			while (v != NULL) { 
				pv=v;
				if (x < v->key) v=v->left;
				else v=v->right;
	   } 
	   if(x<pv->key) pv->left=tmp;
	   else pv->right=tmp;
	}   
}

int max(TreeNode * root){
	TreeNode *v = root;  
	if (v==NULL) return -1;
	while(v->right!=NULL)v=v->right;
	return v->key;
		
}


void print(TreeNode * root) {
	int i;
	TreeNode *v = root;  
	if (v!=NULL) {
	for(i=0;i<v->key-1;i++) printf(" ");
	printf("%d",v->key);
	printf("\n");
	print(v->left);
	print(v->right);
 }
 }
