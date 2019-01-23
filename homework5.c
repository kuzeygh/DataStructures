#include<stdio.h>
#include<stdlib.h>


/*****************
                 *
   COM267 HW 5   *           
  @author rabia  * 
                 *
******************/

//||||----<<<<<-Binary search tree with in-order->>>>>>------|||||||||\\

/*
             70
           /     \
          50      90
         /  \    /  \
       40   60  80  120      */

/*that sorts the grades of students registered in a data structure course. 
Let’s assume that grades are given out of 100. The number of students registered 
to the course is not known in advance.Student IDs and grades are given in input.Our program 
will output the sorted list of the student grades with student ids*/
//Example Input:
/*123 70
 546 90
 456 50
 445 60
 677 80
 121 40
 -1 -1
*/

//required structures--------------------------------------------------------
struct node
{
    int key;
    int id;
    char left_or_right;
    struct node *left, *right,*father;
};

struct node *newNode(int id,int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->father=(struct node *)malloc( sizeof( struct node ));
    temp->key = item;
    temp->id=id;
    temp->left = temp->right = NULL;
    return temp;
}
//----------------------------------------------------------------------------

typedef struct node node;

/////////////////////////////////////-----Function-Prototypes-----////////////
 
void inorder( node *root);
int getLevelCount(node *node);
void printLevel(node *node, int level);
void printElements(node *node);
node* insert( node* node, int id,int key);

//-----------Main Function------------------------------/////////////////////

int main()
{
   

    int id,grade;

   node *root = NULL;

    scanf("%d%d",&id,&grade);

    
    root = insert(root,123, 70);

    scanf("%d%d",&id,&grade);
    
    while( id !=-1 && grade !=-1 )
   {
    
    insert(root,id,grade);
    scanf("%d%d",&id,&grade);
   }
 
  
    
                                                                                                                                                                                                                                                                                                                                                                       
    inorder( root );

    printf("\n");

    printElements(root);

   
    return 0;
}

/////////////////////------------------------Required Function Definitions--///////////
 
void inorder( node *root)
{
    if (root != NULL)
    {
         
        inorder(root->left);
        printf("%d %d\n", root->id,root->key);
        inorder(root->right);
    }
}
////////////////////------------------Following three functions to print elements-///////
int getLevelCount(node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    if (leftMaxLevel > rightMaxLevel)
    {
        return leftMaxLevel;
    }
    else
    {
        return rightMaxLevel;
    }
}

void printLevel(node *node, int level)
{
    
    if (node != NULL && level == 0)
    {
        printf("%d %d ", node->id,node->key);
        if( node->father->key != 0)
           printf("(%d %c) ",node->father->key,node->left_or_right);
    }   
    else if (node != NULL)
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void printElements(node *node)
{
    int i;
    int levelCount = getLevelCount(node);
   
    for (i = 0; i < levelCount; i++)
    {
        printf("\n");
        printLevel(node, i);
    }
}
///////////////////////////////////////////////////////////////////////////////////////  
//insert function

 node* insert( node* node, int id,int key)
{
    
    if (node == NULL) return newNode(id,key);
 
    if (key < node->key)
       {
       //if the value is less than the already exist one put it into left side      
      
        node->left  = insert(node->left,id,key);
       
      //allocating memory for the father node

        node->left->father=(struct node *)malloc( sizeof( node ));
      //setting the father node

        node->left->father=node;
      //if it is at left hand side, assign 'L'
        node->left->left_or_right='L';

      
       }
    else if (key > node->key)
      {
       //if the value is more than the already exist one put it into right side
        node->right = insert(node->right, id,key); 
 
       //allocating memory for the father node
        node->right->father=(struct node *)malloc( sizeof( node ));
        //setting the father node
        node->right->father=node;
        //if it is at left hand side, assign 'R'
        node->right->left_or_right='R';
       }

    return node;
}
  



 
