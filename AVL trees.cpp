// ---------------------------------------------------------------------------------------------
//  			Code by (c 2021 )  Shahab Ghouri(shahabghouri726@gmail.com)
// ---------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;


class Node{
	public:
		int key,height;
		Node *left;
		Node *right;
		
};

class AVL{
	public:
		
		Node *newnode(int data){
			Node *temp = new Node();
			temp->key = data;
			temp->left = temp->right =NULL;
			temp->height = 1;
			return temp;
		}
		
		// insertion will be same as BST
		Node *insertion(Node *node,int data){
		
			// base case
			if(node == NULL){
				return(newnode(data));
			}
			else if(data < node->key){
				node->left = insertion(node->left,data);
			}
			else if(data > node->key){
//				cout<<"HELLO";
				node->right = insertion(node->right,data);
			}
			// equal values are not allowed in BST
			else{
				cout<<" SORRY EQUAL VALUE cannot be inserted. Please try another value.";
				return node;
			}
			
			// update the height of the root
			node->height = 1 + max(height(node->left),height(node->right));
			
			// check if the tree is balanced or not
			
			int balance = getBalance(node);
			
//			LEFT LEFT  CASE			
// 			RR rotation
/*						10		balance  = 2
					   /
					  9
					 /
					8					*/
			
			if(balance > 1  &&  data < node->left->key){
				return RR_rotation(node);
			}
			
			
			
//			RIGHT RIGHT CASE
//			LL Rotation
/*						10		balance  = -2
					   	   \
					  		11
					 		  \
							   12					*/
							   
			if(balance < -1 && data > node->right->key){
				return LL_rotation(node);
			}
			
//			LEFT	RIGHT CASE
// 			LR Rotation
				
/*					11			balance = 2
				  /
				 9
				  \
				   10		*/
				   
			if(balance > 1 && data > node->left->key){
				node->left = LL_rotation(node->left);						/*						10		balance  = 2
					 																	  /
					  																	9
					 																   /
																					  8					*/					
				return RR_rotation(node);
			}
//			RIGHT LEFT CASE
//			RL Rotation
/*				13
				   \
				    12
				   /
				  11	*/
				  
			if(balance < -1 && data < node->right->key){
				node->right = RR_rotation(node->right);
				return LL_rotation(node);
			}
			 
			return node;
			
		}
		
		Node *RR_rotation(Node *temp){
			Node *ptr = temp->left;
			Node *ptr2 = ptr->right;	
			
			// performing rotation
			
			ptr->right = temp;
			temp->left = ptr2;
			
			// update heights
			
			temp->height = max(height(temp->left),height(temp->right))+1;
			ptr->height = max(height(ptr->left),height(ptr->right))+1;
			
			return ptr; 
		}
		
		Node *LL_rotation(Node *temp){
			Node *ptr = temp->right;
			Node *ptr2 = ptr->left;
			
			// performing rotation
			ptr->left = temp;
			temp->right = ptr2;
			
			// update heights
			temp->height = max(height(temp->left),height(temp->right)) + 1 ;
			ptr->height = max(height(ptr->left),height(ptr->right)) + 1;
			return ptr;
		}
		
		
		int max(int a,int b){
			return (a > b)? a : b;
		}
		
		int height(Node *temp){
			if(temp == NULL){
				return 0;
			}
			return temp->height;
		}
		void display(Node *root){

			if(root!=NULL){
				cout<<root->key<<" ";
				display(root->left);
				display(root->right);
			}
		}
		
		int getBalance(Node *temp){
			if(temp == NULL){
				return 0;
			}
			return height(temp->left)-height(temp->right);
		}
		
		
		
};		// end of AVL class

main(){
	AVL obj;
	Node *root = NULL;
	root =  obj.insertion(root,5);
	root = obj.insertion(root,6);
	root = obj.insertion(root,4);
	obj.display(root);
	cout<<endl<<" Height of The Tree is : "<<obj.height(root);
	
	cout<<endl<<"Right Right Rotation"<<endl;
	Node *root2 = NULL;
	root2 = obj.insertion(root2,3);
	root2 = obj.insertion(root2,2);
	root2 = obj.insertion(root2,1);
	obj.display(root2);
	
	cout<<endl<<"LEFT LEFT Rotation"<<endl;
	Node *root3 = NULL;
	root3 = obj.insertion(root3,10);
	root3 = obj.insertion(root3,11);
	root3 = obj.insertion(root3,12);
	obj.display(root3);
	
	cout<<endl<<endl<<"RIGHT LEFT Rotation"<<endl;
	Node *root4 = NULL;
	root4 = obj.insertion(root4,30);
	root4 = obj.insertion(root4,40);
	root4 = obj.insertion(root4,35);
	obj.display(root4);
	
	cout<<endl<<endl<<"LEFT RIGHT Rotation"<<endl;
	Node *root5 = NULL;
	root5 = obj.insertion(root5,100);
	root5 = obj.insertion(root5,80);
	root5 = obj.insertion(root5,90);
	obj.display(root5);
	
}
