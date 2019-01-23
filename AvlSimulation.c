#include <stdio.h>
#include<stdlib.h>



/*****************
                 *
   COM267 HW 8   *           
  @author rabia  * 
                 *
******************/

//This is an AVL-tree simulation.
//As an input you enter some ids and grades
//this prgram makes required rotations and print the 
// image of a created AVL tree.

struct node
{

  int val;
  int balance;
  char character;
  struct node *left_child;
  struct node *right_child;
  struct node *father;

};

//FUNCTIONS TO PRINT TREE IMAGE

int getHeight( struct node *root )
{
   if( root==NULL )
     return 0;
   else
   {
     int leftMax=1+getHeight(root->left_child);
     int rightMax=1+getHeight(root->right_child);
 

     if( leftMax > rightMax )
        return leftMax;
     else
        return rightMax;
  }
}

void printLevel( struct node *root,int level )
{
   if( root !=NULL && level==0 )
   {
      printf("%d ",root->val);
      if( root->father !=NULL )
      printf("(%d%c) ",root->father->val,root->character);
      printf("(%d B) ",root->balance);
   }
   else if( root !=NULL )
   {
       printLevel( root->left_child,level-1);
       printLevel( root->right_child,level-1);
   }
}     
void printTreeImage( struct node *root )
{
   int i;
  
   int totalLevel=getHeight( root );

   for( i=0 ; i < totalLevel ; i++ )
   {
       printf("\n");
       printLevel(root,i);
   }
} 

//INSERT FUNCTION

struct node *insert (int data, struct node *ptr,int *check)
{
   struct node *Lptr;
   struct node *Rptr;

   if(ptr==NULL)
  {
		
    ptr = (struct node *) malloc(sizeof(struct node));
		
    ptr -> val = data;
		
    ptr -> left_child = NULL;
		
    ptr -> right_child = NULL;
    
    ptr->character=' ';

    ptr->father=NULL;
		
    ptr -> balance = 0;
		
   *check = 1;
		
   return (ptr);
 }
 if(data < ptr -> val)
 {
		
    ptr -> left_child = insert(data, ptr -> left_child, check);
    ptr->left_child->father=(struct node *)malloc( sizeof( node ));
    ptr->left_child->father=ptr;
    ptr->left_child->character='L';
		
    if(*check==1)
   {
	switch(ptr -> balance)
			 
   {
				
       case -1: /* Right heavy */
				
       ptr -> balance = 0;
				
       *check = 0;
				
       break;
				
       case 0: /* Balanced */
					
       ptr -> balance = 1;
					
       break;
				
       case 1: /* Left heavy */
					
       Lptr = ptr -> left_child;
       Lptr->father=(struct node *)malloc( sizeof( node ));
       if( ptr->father !=NULL )
       Lptr->father=ptr->father;

       
					
       if(Lptr -> balance == 1)
					
  {
						
   //Left to Left Rotation
   Lptr->father=NULL;
   Lptr->character=' ';	
						
   ptr -> left_child= Lptr -> right_child;
  
   ptr->character='R';					
   Lptr -> right_child = ptr;
  

   ptr->father=Lptr;
						
   ptr -> balance = 0;
						
   Lptr -> balance=0;
						
   ptr = Lptr;
					
 }
					
 else
					
{
						
  //Left to right rotation
						
  Rptr = Lptr -> right_child;
 					
  Lptr -> right_child = Rptr -> left_child;
  Lptr->character='L';						
  Rptr -> left_child = Lptr;
  Lptr->father=Rptr;
						
  ptr -> left_child = Rptr -> right_child;
  ptr->character='R';						
  Rptr -> right_child = ptr;
  ptr->father=Rptr;

  Rptr->father=NULL;
  Rptr->character=' ';
						
  if(Rptr -> balance == 1 )
							
     ptr -> balance = -1;
						
  else
							
     ptr -> balance = 0;
						
  if(Rptr -> balance == -1)
							
     Lptr -> balance = 1;
						
  else
							
    Lptr -> balance = 0;
						
    Rptr -> balance=0;
						
    ptr = Rptr;
					
}
					
 *check = 0;
			 
}
		}
}
if(data > ptr -> val)
{
		
    ptr -> right_child = insert(data, ptr -> right_child, check);
    ptr->right_child->father=(struct node *)malloc( sizeof( node ));
    ptr->right_child->father=ptr;
    ptr->right_child->character='R';
		
   if(*check==1)
  {
			
    switch(ptr -> balance)
			
   {
				
    case 1: /* Left heavy */
					
    ptr -> balance = 0;
					
    *check= 0;
					
    break;
				
    case 0: /* Balanced */
					
    ptr -> balance = -1;
					
    break;
				
    case -1: /* Right heavy */
					
    Lptr = ptr -> right_child;
    Lptr->father=(struct node *)malloc( sizeof( node ));
    if( ptr->father !=NULL )
        Lptr->father=ptr->father;
					
    if(Lptr -> balance == -1)
					
    {
						
      //"Right to Right Rotation\n"
      Lptr->father=NULL;
      Lptr->character=' ';						
      ptr -> right_child= Lptr -> left_child;
      
      ptr->character='L';					
      Lptr -> left_child = ptr;
     

      ptr->father=Lptr;				
      ptr -> balance = 0;
						
      Lptr -> balance=0;
						
      ptr = Lptr;
					
  }
					
  else
					
 {
						
    //"Right to Left Rotation\n"
						
    Rptr = Lptr -> left_child;
						
    Lptr -> left_child = Rptr -> right_child;
    
    Lptr->character='R';						
    Rptr -> right_child = Lptr;
    Lptr->father=Rptr;
						
    ptr -> right_child = Rptr -> left_child;

    ptr->character='L';						
    Rptr -> left_child = ptr;
    ptr->father=Rptr;


    Rptr->father=NULL;
    Rptr->character=' ';
						
    if(Rptr -> balance == -1)
							
    ptr -> balance = 1;
						
    else
							
    ptr -> balance = 0;
						
    if(Rptr -> balance == 1)
							
    Lptr -> balance = -1;
						
    else
							
    Lptr -> balance = 0;
						
    Rptr -> balance=0;
						
    ptr = Rptr;
					
}/*End of else*/
					
 *check=0;
			
}
		}
}
return(ptr);
}


void display(struct node *ptr, int level)
{
int i;
if ( ptr!=NULL )
{
		
display(ptr -> right_child, level+1);
		
printf("\n");
		
for (i = 0; i < level; i++)
			
printf(" ");
		
printf("%d ", ptr -> val);
		
display(ptr -> left_child, level+1);
}
}


void inorder(struct node *ptr)
{
   if(ptr!=NULL)
  {
		
     inorder(ptr -> left_child);
     printf("%d\n",ptr -> val);	
     inorder(ptr -> right_child);
  }
}

int main()
{

   int ht_inc;
   int data ;
 
   struct node *root = (struct node *)malloc(sizeof(struct node));
   root = NULL;
  
    
	   			
           scanf("%d", &data);

           while( data !=-1 )
          {
					    						
              root = insert(data, root, &ht_inc);					
              scanf("%d", &data);
	  }
          
          printf("\n");
 	  inorder(root);
         		
          printTreeImage(root);
			
		
}
