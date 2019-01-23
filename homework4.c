
/*****************
                 *
   COM267 HW 4   *           
  @author rabia  * 
                 *
******************/

//Customers-Employees Banking System Using Stacks and Queues
 
#include<stdio.h>                    //This is a simulation system for banks,for input you give
                                     // id ,customer's coming time,customer's processing time.
#define SIZE 100                     // And output will be consist of customer number,employee number, 
                                     //time the transaction started,
                                     // time the transaction finished, customer waiting time in queue.
                                     //Additionally each employee's total serving time

//Needed structures related to employees and customers 

struct employee
{
   int total_serving=0;
   int id;

};

struct stack_of_employees
{
   employee arr[ 6 ];
   int top;
};

struct customer
{
  int id;
  int start,finish;

};

//renaming the structures

typedef struct employee employee;
typedef struct stack_of_employees stack_of_employees;
typedef struct customer customer;

//needed function prototypes
void init_stack( stack_of_employees* );
void push( stack_of_employees* ,employee item );
employee pop( stack_of_employees* );

void insertqueue( customer* arr,int id,int st,int fn,int *pfront,int *prear);
customer deletequeue( customer *arr,int *pfront ,int *prear);

//needed global variables that are used by all program functions 
int count=0;
int p=0;
int wait_queue=0;
int caution=0;

int main()
{
/////////////////////////////////////////
// variables
  stack_of_employees s;
  customer c[ SIZE ];
  int front=-1,prear=-1;
  customer i;
  employee e;
  int minute=0,minute2=0,a=1;
  int number_of_customer;
  int f[ 6 ]={0};
  employee emp[ 6 ];
  
  int cus_num,start,finish;
//////////////////////////////////////////

  init_stack( &s );
//creating the employees and pushing them inyto the stack   

  employee e1;
  e1.id=1;
  emp[ 0 ]=e1;
  push(&s,e1);

  employee e2;
  e2.id=2;
  emp[ 1 ]=e2;
  push(&s,e2);
  
  employee e3;
  e3.id=3;
  emp[ 2 ]=e3;
  push(&s,e3);

  employee e4;
  e4.id=4;
  emp[ 3 ]=e4;
  push(&s,e4);

  employee e5;
  e5.id=5;
  emp[ 4 ]=e5;
  push(&s,e5);

  employee e6;
  e6.id=6;
  emp[ 5 ]=e6;
  push(&s,e6);

//taking the customers into queue
 scanf("%d%d%d",&cus_num,&start,&finish);

 while( cus_num != -1 )
 {

  count++;
  insertqueue(c,cus_num,start,finish,&front,&prear);

  scanf("%d%d%d",&cus_num,&start,&finish);

 }
//start to take customers from queue in order

 i=deletequeue(c,&front,&prear);
 e=pop(&s);
 
  
 f[ e.id-1 ]=i.start+i.finish;
 emp[ e.id-1 ].total_serving+=i.finish;
 printf("%d %d %d %d  %d\n",i.id,e.id,i.start,i.start+i.finish,wait_queue);
 minute=i.start;
 count--;

 while( count > 0 )
 {
   
   
   i=deletequeue(c,&front,&prear);
   minute2=i.start;
   
   if( minute!=minute2 )
     {
        a++;
     }

   int j=0;

   while( j < 6 )
   {
        if( f[ j ]==a )
        {
          
          push(&s,emp[ j ]);
          f[ j ]=0;
        }
        j++;
   }
//poping the employee at the top of the stack

  e=pop(&s);
//if there is no employee at the stack increment minute by one 
//push the employees that completes their work and try again
 
  while( e.id==0 )
  {
    int j=0;
    wait_queue++;
    a++;
    i.start++;

   while( j < 6 )
   {
        if( f[ j ]==a )
        {
          
          push(&s,emp[ j ]);
          f[ j ]=0;
        }
        j++;
   }
 e=pop(&s);//pop  a new employee again
   }
 

  
  f[ e.id-1 ]=i.start+i.finish;
  emp[ e.id-1 ].total_serving+=i.finish;

  printf("%d %d %d %d  %d\n",i.id,e.id,i.start,i.start+i.finish,wait_queue);
  if( wait_queue !=0 )
    wait_queue--;

  count--;

 if( count > 0)
{

  i=deletequeue(c,&front,&prear);
  minute=i.start;

   if( minute!=minute2 )
     {
        a++;
     }

   int j=0;

   while( j <6  )
   {
        if( f[ j ]==a )
        {
          
          push(&s,emp[ j ]);
          f[ j ]=0;
        }
        j++;
   }

//making the same process again to asign minute2 variable 
 e=pop(&s);

 while( e.id==0 )
  {
    int j=0;
     wait_queue++;
    a++;
    i.start++;

   while( j < 6 )
   {
        if( f[ j ]==a )
        {
          
          push(&s,emp[ j ]);
          f[ j ]=0;
        }
        j++;
   }

 e=pop(&s);
}

 f[ e.id-1 ]=i.start+i.finish;
 emp[ e.id-1 ].total_serving+=i.finish;

 printf("%d %d %d %d  %d\n",i.id,e.id,i.start,i.start+i.finish,wait_queue);
 
 count--;

 }//if there is someone at the queue 
  if( wait_queue !=0 )
    wait_queue--;
}   
 
 for( int i=5 ; i >= 0  ; i--)
    printf("\n%d %d",i+1,emp[ i ].total_serving);

     
}
void init_stack( stack_of_employees* s )
{
  s->top=-1;
}

void push( stack_of_employees* s,employee item )
{

  if( s->top ==SIZE-1 )
  {
    printf("Stack full");

    return;

  }
  s->top++;
  s->arr[ s->top ].id=item.id;


}

employee pop( stack_of_employees* s)
{
   employee data;
   employee nul;
   nul.id=0;

   if( s->top==-1  )
   {
     
     return nul;
   }
  else
 {
   data=s->arr[ s->top ];
   s->top--;
   return data;
 } 
  
}
  
void insertqueue( customer* arr,int id,int st,int fn,int *pfront,int *prear)
{
  
  if( *prear==SIZE-1)
  {
     printf("Queue is full");

     return;
  }
  (*prear)++;
  arr[ *prear ].id=id;
  arr[ *prear ].start=st;
  arr[ *prear ].finish=fn;
  if( *pfront ==-1)
     *pfront=0;

}
customer deletequeue( customer *a,int *pfront,int *prear)
{
  customer data;

  data=a[ *pfront ];

  if( *pfront==*prear )
     *pfront=*prear=-1;
  else
    (*pfront)++;
   
     return data;
}


  
 
  
