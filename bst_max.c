#include<stdio.h> 
#include<stdlib.h> 
struct node *min(struct node* root);
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 
struct node *new(int value) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = value; 
	temp->left = NULL;
    temp->right = NULL; 
	printf("\nNODE CREATED SUCCESSFULLY %d\n",temp->key);
	return temp; 
} 
struct node* insert(struct node* node, int key) 
{ 
	
	if (node == NULL) {
            return new(key); 
    }
	
	if (key < node->key) {
		node->left = insert(node->left, key); 
    }
	else if (key > node->key) {
		node->right = insert(node->right, key); 
    }
	return node;
} 
int main() 
{ 
	struct node *root =NULL,*y= NULL; 
	
	printf("ENTER TOTAL NODES");
	int n;
	scanf("%d",&n);
	int key;
	for(int i=0;i<n;i++){
			if(root==NULL) {
					printf("Hello ! Enter ROOT Node\n");
					scanf("%d",&key);
					root=insert(root,key);
	}
	
			else{		
					scanf("%d",&key);
					insert(root,key);
			}
	}
	y=min(root);
	return 0; 
} 

struct node *min(struct node* root){
    
            if(root->left==NULL){
				    printf("\nMAX ELEMENT->%d\n",root->key);
                   
            }
            else {
                return min(root->right);
            }
         
}