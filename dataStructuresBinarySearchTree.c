#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/* Abdurrahman Derda Karaaslan - 191180048 */


typedef struct treeNode {
    int value;
    struct treeNode  *left;
    struct treeNode  *right;
}TreeNode ;



void preorder ( TreeNode *treePtr );
void inorder ( TreeNode *treePtr );
void postorder ( TreeNode *treePtr );


int main(int argc, char *argv[]) {
    int i;
	int newValue;
    TreeNode *root = NULL;
    TreeNode *current = root;
    
    srand(time(NULL));
    printf("The numbers being placed in the tree are: ");
    for(i = 0; i<10;i++){
        newValue = 1+rand()%25;// we create random number
        printf("%d ", newValue);
        if(i ==0){// for first number
            root = (TreeNode *)malloc(sizeof (TreeNode));// we create root
            root->value = newValue; // for first number we dont have to control so we added new value
            root->left =NULL; // we declare left and right null because we will control later
            root->right = NULL;
        }else{
            current = root;
        while(1){
            if(current == NULL){ // if current is null (its mean there is not value to control (we are in leaf))
                current = (TreeNode *)malloc(sizeof (TreeNode));// we create new leaf
                current->left = NULL;// we declare left and right null because we will control later
                current->right = NULL;
                current->value = newValue;// there is not value to control so we added new value
                break;
            }
            else{
                if(newValue < current->value ){ // if new value smaller than current value
                    if(current->left == NULL){ // if current is null (its mean there is not value to control (we are in leaf))
                        current->left = (TreeNode *)malloc(sizeof (TreeNode));
                        current->left->left = NULL;// we declare left and right null because we will control later
                        current->left->left = NULL;
                        current->left->value = newValue;//  there is not value to control so we added new value
                        break;
                    }else{ // if current is not null (its mean there is an element to control)
                    	current = current->left; // go to left side
					}
                    
                    
                }
                else{ // if new value bigger than current value (or equal)
                    if(current->right == NULL){// if current is null (its mean there is not value to control (we are in leaf))
                        current->right = (TreeNode *)malloc(sizeof (TreeNode));
                        current->right->left = NULL;// we declare left and right null because we will control later
                        current->right->left = NULL;
                        current->right->value = newValue;//  there is not value to control so we added new value
                        break;
                    }
                    else{// if current is not null (its mean there is an element to control)
                    	current = current->right; // go to left side
					}
                    
                }
            }
        }    
        }
    }
    
    printf("\nThe preorder traversal is: ");
    preorder(root);
    
    printf("\nThe inorder traversal is: ");
    inorder(root);

    printf("\nThe postorder traversal is: ");
    postorder(root);
    
    return 0;
}



void inorder(TreeNode *treePtr){
    if(treePtr == NULL){
        return;
    }
    inorder(treePtr->left); // recursive
    printf("%d ", treePtr->value); // print value
    inorder(treePtr->right); // recursive
    }

void preorder(TreeNode *treePtr){
    
    if(treePtr != NULL){
        printf("%d ",treePtr->value);// print value
        preorder(treePtr->left);// recursive
        preorder(treePtr->right);// recursive
    }
}

void postorder(TreeNode *treePtr){
    
    if(treePtr != NULL){
        postorder(treePtr->left);;// recursive
        postorder(treePtr->right);;// recursive
        printf("%d ", treePtr->value);// print value
    }
}
