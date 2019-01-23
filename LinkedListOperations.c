#include<iostream>
#include<stdlib.h>

struct node{

 int data;
 struct node *next;

};

void insert_beg( struct node **start,int num )
{

  struct node* ptr=*start;
  struct node* new_node;

  new_node=(struct node* )malloc( sizeof( struct node ));
  new_node->data=num;
  new_node->next=*start;

  *start=new_node;

 
}

void insert_end( struct node **start,int num )
{
   struct node *ptr=*start;
   struct node *new_node;

   new_node=(struct node* )malloc( sizeof( struct node ));
   new_node->data=num;
   new_node->next=NULL;

   if( *start==NULL )
   {
       *start=new_node;
   }
   else
   {
     while( ptr->next!=NULL  )
       ptr=ptr->next;
   
       ptr->next=new_node;
   }
}

void search( struct node **start,int num )
{

   struct node *ptr=*start;
   
   int i=0;
 
   while( ptr->next !=NULL )
   {
       if( ptr->data==num )
         {
            printf("\nElement found !");
            i=1;
            break;
         }
   
         ptr=ptr->next;
    }
  
    if( i==0 )
    printf("\nELement Not Found");
           
}

void insert_before( struct node **start,int num ,int element)
{
  struct node *ptr=*start;
  struct node *new_node,*prev;

  while( ptr->data !=num )
  {
     prev=ptr;
     ptr=ptr->next;
  }
 
  new_node=(struct node* )malloc( sizeof( node ));
  new_node->data=element;
  prev->next=new_node;
  new_node->next=ptr;

}

void insert_after( struct node **start,int num,int element )
{
  struct node *ptr=*start;
  struct node *new_node,*forward;

  forward=ptr;

  while( forward->data !=num )
  {
    forward=ptr;
    ptr=ptr->next;
  }

  new_node=(struct node* )malloc( sizeof( node ));
  new_node->data=element;

  forward->next=new_node;
  new_node->next=ptr;
}
  
void delete_beg( struct node** start )
{
   struct node *ptr=*start;
   *start=(*start)->next;
   
   free( ptr );
}

void delete_end( struct node* start )
{
   struct node *ptr,*prev;

   ptr=start;

   while( ptr->next !=NULL )
   {
      prev=ptr;
      ptr=ptr->next;
   }

   prev->next=NULL;

   free(ptr);
}

void delete_node( struct node** start,int val )
{
   struct node *ptr,*prev;
   
   ptr=*start;

   if( ptr->data==val )
   {
      delete_beg( start );
   }else{
           while( ptr->data !=val )
           {
               prev=ptr;
               ptr=ptr->next;
           }

           prev->next=ptr->next;
          
           free( ptr );
        }
}

void deleteAfter( struct node* start,int val )
{
   struct node *ptr,*prev;  
   
   ptr=start;
   prev=ptr;

   if( ptr->data ==val )
   {
     prev=ptr;
     ptr=ptr->next;
 
     prev->next=ptr->next;
     free( ptr );
   }else
   {
  
   while( prev->data !=val )
  {
     prev=ptr;
     ptr=ptr->next;
  }
  prev->next=ptr->next;
  free( ptr );
}   
}
      
void sort( struct node **start )
{
      
   struct node *ptr1,*ptr2;
   int tmp;

   ptr1=*start;

   while( ptr1->next !=NULL )
   {
      ptr2=ptr1->next;
   
      while( ptr2 !=NULL )
      {
         if( ptr1->data > ptr2->data )
         {
            tmp=ptr1->data;
            ptr1->data=ptr2->data;
            ptr2->data=tmp;
         }

         ptr2=ptr2->next;
     }
     ptr1=ptr1->next;
  }

}

void display( struct node *start)
{

  struct node *ptr=start;

  while( ptr !=NULL )
  {
    printf("%d",ptr->data);
    ptr=ptr->next;
  }
}
     
int main()
{

  struct node* st=NULL;

  insert_end( &st,2);

  insert_end( &st,1);

  insert_end( &st,3);

  display( st );

  sort( &st );

  display( st );   

}
 
   
  
            
