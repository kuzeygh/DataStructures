
/*****************
                 *
   COM267 HW 2   *           
  @author rabia  * 
                 *
******************/




#include<stdio.h>
#include <stdlib.h>

//node structure for student

struct nodeStudent
{
  int studentId;
  int midterm;
  nodeStudent *next;
};
 
//node structure for class

struct nodeClass
{
  int classId;
  double classMidtermAverage;
  nodeClass *next;
  nodeStudent *studentPtr;
};

typedef struct nodeClass nodeClass;
typedef struct nodeStudent nodeStudent;

//we use typedef structure to use shorter names

void addStudent( nodeStudent **head,int id,int grade );
//by using this function we are adding new students to classes

void printClassList( nodeClass *head,int classId);
//we use this function to print class list

void printAverages( nodeClass **head );
//when we want to print the averages of the students we use this function

void CalculateAverages( nodeClass *head,int classId);
//this function calculate the average of the given class with id

void printAll( nodeClass **head );
//print all prints all class list with thir averages

int main()
{

   /* Example input:

    99215 75
    66123 45
    -1    -1
  */

   nodeClass *start,*temp;
   nodeClass *p;

   int id,grade;

   start=(nodeClass *)malloc(sizeof( nodeClass ));          //here the numbers begins with
   start->classId=1;                                        // 66 is 1,77 is 2,88 is 3,99 is 4
   start->next=NULL;                                        //class students

   start->studentPtr=NULL;
   temp=start;

   for( int i=1 ; i <= 4 ; i++ )
   {
       temp->next=(nodeClass *)malloc( sizeof( nodeClass ) );
       //first allocate memory then assign it
       temp=temp->next;
       temp->classId=(i+1);
       temp->next=NULL;
       temp->classMidtermAverage=.0;
    
       temp->studentPtr=NULL;
   }
   temp=start;

   scanf("%d%d",&id,&grade);

   while( id!=-1 )
   {
        
               

        int n=(id/10000)%5;
  
        switch( n )
     {
        case 1:
         addStudent( &(start->studentPtr),id,grade);
         break;
       
        case 2:
         addStudent( &(start->next->studentPtr),id,grade);
         break;
        case 3:
         addStudent( &(start->next->next->studentPtr),id,grade);
         break;
        case 4:
         addStudent( &(start->next->next->next->studentPtr),id,grade);
         break;
     } 

   scanf("%d%d",&id,&grade);
   
   }   
  
   printAverages(&start);  
}


void addStudent( nodeStudent **head,int id,int grade )
{
   nodeStudent *temp,*r;
   nodeStudent *p;

   temp=*head;

   if( *head==NULL )
   {
        *head=(nodeStudent *)malloc( sizeof( nodeStudent ) );
        (*head)->studentId=id;
        (*head)->midterm=grade;
  
        (*head)->next=NULL;

  }else{
  //if new grade is greater  than already exist midterm grade put the beginning of the list

          if( (*head)->midterm < grade )
          {
              r=(nodeStudent *)malloc( sizeof( nodeStudent ) );
              r->studentId=id;
              r->midterm=grade;
 
              r->next=(*head);
              (*head)=r;
            


         }else
         {
             while( temp !=NULL && temp->midterm >=grade)
             {
                p=temp;
                temp=temp->next;
             }
        
              r=(nodeStudent *)malloc( sizeof( nodeStudent ) ); 
              r->studentId=id;
              r->midterm=grade;
              r->next=temp;
              p->next=r;
         }
       }
       
}
  
            
void printClassList( nodeClass *head,int classId)
{
     


     nodeClass *temp=head;

     for( int i=1 ; i < classId  ; i++ )

        temp=temp->next;

       

        while( temp->studentPtr !=NULL  )
              {
                  
                  printf("%d ",temp->studentPtr->studentId);
                  printf("%d\n",temp->studentPtr->midterm);
  
                  
                  
                  temp->studentPtr=temp->studentPtr->next;
              }
   

}

void CalculateAverages( nodeClass *head,int classId)
{
     int sum=0;
     int count=0;


     nodeClass *temp=head;

     for( int i=1 ; i < classId  ; i++ )

        temp=temp->next;

       

        while( temp->studentPtr !=NULL  )
              {
                  
                  sum+=temp->studentPtr->midterm;
                  count++;
                  temp->studentPtr=temp->studentPtr->next;
              }
     temp->classMidtermAverage=(double)sum/count;
  
     printf("%d %f\n",temp->classId,temp->classMidtermAverage);
}

            
     
void printAll( nodeClass **head )
{
     nodeClass *temp=*head;
    
     if( temp->studentPtr !=NULL )
       printClassList(temp,1);
 
    printf("\n");

     if( temp->next->studentPtr !=NULL )
       printClassList(temp,2);

     printf("\n");

     if( temp->next->next->studentPtr !=NULL )
       printClassList(temp,3);

     printf("\n");

      if( temp->next->next->next->studentPtr !=NULL )
       printClassList(temp,4);

   
}

void printAverages( nodeClass **head )
{
     nodeClass *temp=*head;
    
     if( temp->studentPtr !=NULL )
      CalculateAverages( temp,1);
       else 
      printf("1  0.0\n");
     
     if( temp->next->studentPtr !=NULL )
      CalculateAverages( temp,2);
       else 
        printf("2  0.0\n");
  

     if( temp->next->next->studentPtr !=NULL )
     CalculateAverages( temp,3);
      else 
        printf("3  0.0\n");
    

      if( temp->next->next->next->studentPtr !=NULL )
       CalculateAverages( temp,4);
      else 
        printf("4  0.0\n");

   
}





 
                  
                      
