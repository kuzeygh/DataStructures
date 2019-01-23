/*****************
                 *
 Turtle-Graphics *           
  @author rabia  * 
                 *
******************/


#include<stdio.h>
#include<stdlib.h>

//structures           //This program combines two linked lists in one linked list
                       // one of them is called FB,
                       //and other one is called GS
struct nodeGS{         //User enters FB supporters with their ages. 

 int id;                 //Example Input:
                         //  456756 45
 struct nodeGS *next;    //  561232 41
};                       // -1    -1 (end of FB supporters)  
                         //  872456
struct nodeFB{           //  272456
                         //  -1

 int id;
 int age;
 struct nodeFB *next;     //Output is:
};                        //  456756  45
                          //  872456
struct mixedFBnode{       //  561232 41
    int id;               //  272456
    int age;
    struct mixedGSnode *mixGSnodeN;
};

struct mixedGSnode{
    int id;
    struct mixedFBnode *mixFBnodeN;
};
//abbreviations-------------------------------------------------------------------

typedef struct nodeFB nodeFB; 
typedef struct nodeGS nodeGS;
typedef struct mixedFBnode mixedFBnode;
typedef struct mixedGSnode mixedGSnode;
//needed functions----------------------------------------------------------------

void addSupportersGS( nodeGS **head,int id );
void printGS( nodeGS *head);
void addSupportersFB( nodeFB **head,int id,int age );
void printFB( nodeFB *head);
void makeItMixed( mixedFBnode **tmp,nodeFB *listFB,nodeGS *listGS );
void printAll( mixedFBnode **tmp );
//main function-------------------------------------------------------------------
int main()
{

  nodeGS *listGS=NULL;
  
  nodeFB *listFB=NULL;

  mixedFBnode *result=NULL;


  int id,age;

   scanf("%d%d",&id,&age);

  while( id !=-1 )
  {

    addSupportersFB( &listFB,id,age);
    
    scanf("%d%d",&id,&age);
  }
  scanf("%d",&id);

  while( id !=-1 )
 {

   addSupportersGS( &listGS,id);

   scanf("%d",&id);
 }


/*
 printFB( listFB );  
 printf("\n");
 printGS( listGS );
 printf("\n");
*/

 makeItMixed(&result,listFB,listGS);
 printAll( &result );
 


}

// function declerations-----------------------------------------------------------
void addSupportersGS( nodeGS **head,int id)
{
   nodeGS *temp,*r,*p;

   temp=*head;

   
   if( *head==NULL )
   {
        *head=(nodeGS *)malloc(sizeof( nodeGS ) );
        (*head)->id=id;
        
  
        (*head)->next=NULL;

  }else
  {

     
          if( (*head)->id < id )
          {
              r=new nodeGS[ sizeof( nodeGS ) ];
              r->id=id;
             
 
              r->next=(*head);
              (*head)=r;
            


         }else
         {
             while( temp !=NULL && temp->id >=id )
             {
                p=temp;
                temp=temp->next;
             }
        
              r=(nodeGS *)malloc(sizeof( nodeGS ) ); 
              r->id=id;
             
              r->next=temp;
              p->next=r;
         }
       }
   
       
}
  
void printGS( nodeGS *head)
{

  nodeGS *temp=head;

  while( temp!=NULL )
  {
 
     printf("Id: %d\n",temp->id);
     temp=temp->next;
  }

}

void addSupportersFB( nodeFB **head,int id,int age )
{

 nodeFB *temp,*r,*p;

   temp=*head;

   
   if( *head==NULL )
   {
        (*head)=(nodeFB *)malloc(sizeof( nodeFB ) );
        (*head)->id=id;
        (*head)->age=age;
  
        (*head)->next=NULL;

  }else
  {

     
          if( (*head)->id > id )
          {
              r=(nodeFB *)malloc( sizeof( nodeFB ) );
              r->id=id;
              r->age=age;           
  
              r->next=(*head);
              (*head)=r;
            


         }else
         {
             while( temp !=NULL && temp->id <= id )
             {
                p=temp;
                temp=temp->next;
             }
        
              r=(nodeFB *)malloc( sizeof( nodeFB ) ); 
              r->id=id;
              r->age=age;

              r->next=temp;
              p->next=r;
         }
       }

 }  

void printFB( nodeFB *head)
{

  nodeFB *temp=head;

  while( temp!=NULL )
  {
 
     printf("Id: %d ",temp->id);
     printf("Age: %d\n",temp->age);
     temp=temp->next;
  }

}

void makeItMixed(mixedFBnode **tmp,nodeFB *listFB,nodeGS *listGS)
{
  mixedFBnode *head;

  if( listFB ==NULL )
     return;

  *tmp=(mixedFBnode *)malloc(sizeof( mixedFBnode) );
  (*tmp)->id=listFB->id;
  (*tmp)->age=listFB->age;
  
  (*tmp)->mixGSnodeN=(mixedGSnode *)malloc( sizeof( mixedGSnode ) );
  (*tmp)->mixGSnodeN->id=listGS->id;

  listFB=listFB->next;
  listGS=listGS->next;

  head=*tmp;

  while( listFB !=NULL )
  {
      head->mixGSnodeN->mixFBnodeN=(mixedFBnode *)malloc(sizeof( mixedFBnode) );
      head->mixGSnodeN->mixFBnodeN->id=listFB->id;
      head->mixGSnodeN->mixFBnodeN->age=listFB->age; 
      
      head->mixGSnodeN->mixFBnodeN->mixGSnodeN=(mixedGSnode *)malloc( sizeof( mixedGSnode ) );
      head->mixGSnodeN->mixFBnodeN->mixGSnodeN->id=listGS->id;
      head=head->mixGSnodeN->mixFBnodeN;

       listFB=listFB->next;
       listGS=listGS->next;

  }

   head->mixGSnodeN->mixFBnodeN=NULL;
      
}

void printAll( mixedFBnode **tmpFB )
{
   mixedGSnode *tmpGS;
   int turn=0;

   if( tmpFB ==NULL )
       return;

   while( tmpFB !=NULL )
   {
        
      if( turn==0 )
      {
         printf("Id: %d Age: %d\n",(*tmpFB)->id,(*tmpFB)->age);
         turn=turn+1;
         if( (*tmpFB)->mixGSnodeN!=NULL )
         tmpGS=(*tmpFB)->mixGSnodeN;
         else
         break;

      }else
      {
        printf("Id: %d\n",tmpGS->id);
         turn=turn-1;
         if( tmpGS->mixFBnodeN !=NULL )
         *tmpFB=tmpGS->mixFBnodeN;
         else
         break;
      }
  }

}




