/*-----Konstantinos Spalas , AM: 2025200800094---------*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


typedef struct TreeNode{
	int key;
	struct TreeNode *left;
	struct TreeNode *right;
}*TreeNode;
	
void insert(TreeNode *,int);

int main(int argc, char *argv[]){
	int key;
	TreeNode *root;
	while(1){
	if(strcmp(argv[0],"insert")==0){
		key=atoi(argv[1]);
		insert(root,key);
	}
		
}
	
	
	
	
	return 1;
}

void insert(TreeNode *root, int x) {
TreeNode *v = root; // v τρέχων κόμβος
TreeNode *pv = NULL; // pv γονέας v
while (v != NULL) { // επαναληπτική εκδοχή
pv = v;
if (x < v->key) v=v->left;
else if (x > v->key) v=v->right;
else { // υπάρχει ήδη
printf(”error: duplicate”);
exit(1);}
}
TreeNode *tmp = malloc(sizeof(TreeNode));
tmp->key=x; tmp->left=tmp->right=NULL;
if (root != NULL) {
if (x < pv->key) pv->left=tmp;
else pv->right=tmp;
} else root=tmp;
//return root; // επιστροφή ρίζας δέντρου
}
