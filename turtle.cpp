/*****************
                 *
 Turtle-Graphics *           
  @author rabia  * 
                 *
******************/

// 4 Thursday July 2018 || 18:41



#include<iostream>

using namespace std;

//defining macros for readability.

#define PenUp 1
#define PenDown 2
#define TurnRight 3
#define TurnLeft 4
#define Print 6
#define EndOfData 9
#define MoveForward 5

char Room[ 50 ][ 50 ]={0};

int movX=0 ,movY=0;
int posX=0 ,posY=0;


//functions needed to validate direction and move forward in true direction

int correctDirection( int );
void moveForward( int,int,int );

int main()
{
  //needed variables--------------------------------------------------------
  int PenSituation=PenUp;
 
  int TempCommand;
  int Commands[ 50 ]={0};
  int indexX=0,indexY=0;
  int index=0;
  int direction=0;
  //------------------------------------------------------------------------
  

//initial point of turtle is [0][0]

 cin>>TempCommand;

 while( TempCommand !=EndOfData )
 {
   //buffering commands from user
   
   Commands[ index ]=TempCommand;
   cin>>TempCommand;
   index++;
 }

 for( int i=0; i < index ; i++ )
 {
     switch( Commands[ i ] )
     {

       case PenUp://command 1

       PenSituation=PenUp;
       break;

       case PenDown://command 2

       PenSituation=PenDown;
       Room[ 0 ][ 0 ]='*';

       break;

       case TurnRight://command 3
       
       direction-=90;
       direction=correctDirection( direction );

       break;

       case TurnLeft://command 4

       direction+=90;
       direction=correctDirection( direction );

       break;

       case MoveForward://command 5
  
       moveForward( direction , Commands[ ++i ]-1 ,PenSituation );
       break;

       case Print://command 6
       
       for( int i=0 ; i < 50 ; i++ )
       {
         for( int j=0 ; j < 50 ; j++)
         {
            if ( Room[ i ][ j ]=='*' )
            cout<<"*";
            else
            cout<<" ";
         }
         
         cout<<endl;
       }
     
       break;


     }//end switch

 }//end for

}//end main

//function definitions-------------------------------------------------------
void moveForward( int dirVal , int amount ,int penVal )
{
   if( dirVal==0 )
   {
      movX=0;
      movY=1;      

   }
   if( dirVal==90 )
   {
      movX=-1;
      movY=0;

   }
   if( dirVal==180 )
   {
      movX=0;
      movY=-1;

   }
   if( dirVal==270 )
   {
      movX=1;
      movY=0;

   }

   for( int i=0 ; i < amount ; i++ )
   {
        posX+=movX;
        
        if( posX < 0 ) posX=0;
  
        else if( posX > 49 ) posX=49;


        posY+=movY;

        if( posY < 0 ) posY=0;

        else if( posY > 49 ) posY=49;

        if( penVal==PenDown )
        {
            Room[ posX ][ posY ]='*';
        }
       
  }

}

  
int correctDirection( int value )
{
   if( value < 0 )
   
   return (value+360);

   else
 
   return (value%360);
}
