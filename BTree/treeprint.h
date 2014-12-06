/* 
 * File: treeprint.h
 *
 * Periexei th dhlwsi tou kombou enos dyadikou dentrou kai
 * th leitourgia printTree gia thn ektypwsi tou dentrou
 * kata epipeda
 *
 */

#include <stdlib.h>
#include <stdio.h> // gia eisodo/exodo
#include <assert.h>  // gia tin synartisi assert
#include <stdbool.h> // typos boolean

typedef struct treeNode TreeNode;

// struct gia ton kombo enos dyadikou dentrou
typedef struct treeNode {
  int item;
  TreeNode *left;
  TreeNode *right;

  // to epomeno melos xrhsimopoieitai apokleistika gia thn ektypwsi tou dentrou
  int rank;  // h seira tou item (1o, 2o, 3o klp), ypologizetai me th synartisi inorder 
} TreeNode;


// Epektasi tis inorder diasxisis pou apothikeyei gia kathe kombo ti seira tou
void inorder(TreeNode *t, int *pr) {
    if (t==NULL) return;

    inorder(t->left, pr);   // episkepsi aristerou ypodentrou tou t

    t->rank = ++(*pr);  // episkepsi komvou t, anathesi timis rank
     
    inorder(t->right, pr);  // episkepsi deksiou ypodentrou tou t
}


typedef TreeNode *T; // o typos T orizetai ws deikths se kombo dentrou

// megisto megethos stoixeiwn ouras 50
#define MaxQSize 50 


// Oura ylopoihmenh me aplo pinaka
typedef struct queue {
   T q[MaxQSize];
   int front, rear;
} Queue;

void init(Queue *q) {
  q->front=q->rear=0;
}

void destroy(Queue *q) {
  q->front=q->rear=0;
}

bool isEmpty(Queue *q) {
    return (q->front==q->rear);
}

bool isFull(Queue *q) {
    return (q->rear==MaxQSize);
}

T dequeue(Queue *queue) {
  assert(!isEmpty(queue));  // elegxos an i oura periexei stoixeia
  return queue->q[queue->front++];
}

void enqueue(Queue *queue, T newitem) {
     assert(!isFull(queue));  // elegxos an i oura exei gemisei
     queue->q[queue->rear++]=newitem;
}

// synarthsh ektypwsis dentrou
void printTree(TreeNode *t) {

   if (t==NULL) return;

   int rank=0; // metabliti pou apothikeyei to trexon plhthos kombwn pou exei episkeftei i inorder
   inorder(t, &rank); // ypologismos rank kathe kombou tou dentrou

   // levelorder: episkepsi kombwn dentrou ana epipedo 0, 1, 2, klp kai apo aristera pros deksia
   Queue q[2];  // dyo oures mia gia kombous se zygo kai mia se mono epipedo dentrou

   init(&q[0]);
   init(&q[1]);

   const int ItemWidth=3; // orismos platos tou kathe stoixeiou (3 xarakthres)
   int level=0; // trexon epipedo zygo=0, mono=1
   int column=0; // trexousa stili, dhladh posoi xaraktires (kena i arithmoi) exoun typothei stin trexousa grammi mexri stigmis

   enqueue(&q[level],t);

   while (!isEmpty(&q[level])) 
   {

      t=dequeue(&q[level]); // trexon kombos

      int width= ItemWidth * t->rank - column;  // ypologismos apaitoumenou platous se xarakthres
      printf("%*d", width, t->item);  // ektypwsh kleidiou tou kombou t se platos width
      column = ItemWidth * t->rank;

      // eisagwgi stin oura tou epomenou epipedou twn paidiwn tou
      if (t->left!=NULL) 
		enqueue(&q[1-level], t->left);
      if (t->right!=NULL) 
		enqueue(&q[1-level], t->right);

      if (isEmpty(&q[level])) {
		// trexousa oura einai i oura tou epomenou epipedou
		level=1-level;
		printf("\n"); // nea grammi
		column=0;  
      }
   }
   printf("\n");
} // telos tis synartisis printTree

