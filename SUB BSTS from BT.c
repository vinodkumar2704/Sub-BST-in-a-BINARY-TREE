//SUBTREE BST's IN BINARY TREE HAVING A SUM FROM PARENTHESIS REPRESENTATION

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* p;
	struct node* left;
	struct node* right;
	int data;
};


struct node* NewNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->p = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
	
}

struct node* BST(){
	int d;
	char c;
	scanf("%c",&c);
	scanf("%c",&c);
	if(scanf("%d",&d)==1){
		struct node* head = NewNode(d);
		head->left = BST();
		if(head->left !=NULL)head->left->p = head;
		head->right = BST();
		if(head->right!= NULL)head->right->p = head;
		scanf("%c",&c);
		scanf("%c",&c);
		return head;
	}
	else{
		scanf("%c",&c);
		scanf("%c",&c);
		return NULL;
	}

}


int FINDBST(struct node* head,int k,int *count){
	if(head==NULL)return 0;
	int sum = 0;
	int left = FINDBST(head->left,k,count);
	int right = FINDBST(head->right,k,count);
	if((head->left != NULL && head->left->data <= head->data)||(head->left == NULL)){
		if((head->right != NULL && head->right->data >= head->data)||(head->right == NULL)){
			
			
			sum = head->data + left + right;
			if(sum == k){
			*count = *count+1;}
			
			
			return sum;
			
		
	}
}

}

void main(){
	struct node* head = BST();
	int k;
	scanf("%d",&k);
	int count = 0;
	FINDBST(head,k,&count);
	if(count==0)printf("-1");
	else printf("%d",count);

}
 
