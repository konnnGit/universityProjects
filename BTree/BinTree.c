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
void print_preorder(TreeNode *);

int main(int argc, char **argv){
	int x;
	TreeNode *root=malloc(sizeof(TreeNode));
	root=NULL;
	char word[31];  // mia symboloseira me to poly 30 characters;

    printf("Dwste entoles:\n");

    while (1) {
        
	scanf("%s",word);
	
	if (strcmp(word, "print")==0) {
		printf("Epileksate thn entolh print.");
		print_preorder(root);
	}	
		
	else if (strcmp(word, "insert")==0) {
		
		scanf("%d", &x);
	 	printf("Epileksate th entolh insert me orisma %d.", x);	
	 	insert(root,x);	
	} else if (strcmp(word, "search")==0){
		scanf("%d", &x);
		if(	search(root,x)) printf(" Yes exists..");
	}
	else printf("Agnwsti entolh. Xanaprospathiste.");
	
	printf("\n");
}
	
	
	
	return 1;
}

int search(TreeNode *root, int x) {
	TreeNode *v = root;  // v trexon kombos
 while (v != NULL) {  
      //pv = v; 
      if (x < v->key) v=v->left;
      else if (x > v->key) v=v->right;
           else { // yparxei idi, ektypwsi mhnymatos
                  printf("The key %d allredy exists.\n", x);
		  return 1;
           }
              
   }
   return 0;
}




// eisagwgi neou kleidiou sto dentro
void insert(TreeNode *root, int x) {  
   TreeNode *v = root;  // v trexon kombos
   TreeNode *pv = NULL; // pv goneas tou v 
   while (v != NULL) {  
      pv = v; 
      if (x < v->key) v=v->left;
      else if (x > v->key) v=v->right;
           else { // yparxei idi, ektypwsi mhnymatos
                  printf("The key %d allredy exists.\n", x);
		  return ;
           }   
   }
   TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
   tmp->key=x; tmp->left=tmp->right=NULL;    
   if (root != NULL) { 
      if (x < pv->key) pv->left=tmp;
         else pv->right=tmp;
   } else root=tmp;
   return ; // epistrofi rizas dentrou
}


void print_preorder(TreeNode * v) {
	int i;
 if (v!=NULL) {
	for(i=0;i<v->key-1;i++) printf("\n ");
	printf("%d",v->key);
	print_preorder(v->left);
	print_preorder(v->right);
 }
 }
