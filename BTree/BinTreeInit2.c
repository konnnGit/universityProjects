/*-----Konstantinos Spalas , AM: 2025200800094---------*/

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

int main(int argc, char **argv){
	int x;
	TreeNode *root=malloc(sizeof(TreeNode));
	//root=NULL;
	char word[31];  // mia symboloseira me to poly 30 characters;

    printf("Give orders:\n");

    while (1) {
        
	scanf("%s",word);
	
	if (strcmp(word, "print")==0) {
		printf("Choosed to  print.");
		print(root);
	}	
		
	else if (strcmp(word, "insert")==0) {
		
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
