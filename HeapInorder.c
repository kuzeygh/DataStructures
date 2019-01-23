# include <stdio.h>
#include<stdlib.h>



/*****************
                 *
   COM267 HW 7   *           
  @author rabia  * 
                 *
******************/

//This program creates heap according to the given input
//and then outputs them in-Order walk. 

struct node{

 int data;
 struct  node *left;
 struct  node *right;

};

int heap_arr[100],size;

//first we build max-heap by using the function insert

void insert(int element,int position )
{

    int parent;

    while( position > 0 )
    {     //we find the index of parent node
          parent= (position -1 )/2;
          //if the parent node's element is lower than our new element
          if( element <= heap_arr[parent] )
	  {
            //insert it into given location,and return nothing
	    heap_arr[position]=element;
	    return;
	  }
            // if it doesn't return at the previous section 
            // we continue with assigning our parent to this new position

	    heap_arr[ position ]=heap_arr[ parent ];
            position=parent;
            //and our new position is our parent's position
   }
        //if function comes this point this means that our new element
        //is greater than all of the elements 
	heap_arr[0]=element; 

}

void inOrder(struct node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\n", root->data );
        inOrder(root->right);
    }
}
 

struct node* insert_tree( int heap_arr[], struct node* root,int i, int size)
{
    
    if (i < size)
    {
        struct node* new_node = (struct node*)malloc( sizeof( struct node ) );
        new_node->data=heap_arr[ i ];

        root = new_node;
        //after we build max-heap put them in a tree in level order 
        
        root->left =insert_tree(heap_arr,root->left, 2*i+1, size);
 
        
        root->right =insert_tree(heap_arr,root->right, 2*i+2, size);
    }
    return root;
}

int main()
{
        struct node *root=NULL;
	int element;
	size=0;

	scanf("%d",&element);

                while( element !=-1 )
                {
			
                   insert(element,size);
		   size++;
                   scanf("%d",&element);
                }

         
        root=insert_tree(heap_arr,root,0,size);
        inOrder(root);	
}
