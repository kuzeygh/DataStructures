#include<stdio.h>


/*****************
                 *
   COM267 HW 6   *           
  @author rabia  * 
                 *
******************/



//In this project we are implementing a simple puzzle.
//User inputs one keyword and this program outputs the word where it was placed.

int findLength( char word[] );

void checkLines( char line[],char word[] ,int row,int size);
void checkColumns( char puzzle[],char word[],int,int);
void transpose( char puzzle[][15] );
void printArray2(char puzzle[][15],int pos,int row,int size,char w[]);

int  check=0;
void printArray(char puzzle[][15],int pos,int row,int size,char w[]);

 char puzzle[15][15]={
                         {'G','S','L','N','F','R','N','P','R','E','N','D','P','O','R'},
                         {'N','A','N','F','D','K','U','O','L','M','K','I','A','C','N'},
                         {'I','F','V','A','C','S','F','P','T','A','A','S','R','O','H'},
                         {'L','E','P','I','I','S','I','N','R','S','T','N','T','A','A'},
                         {'I','S','R','L','I','R','L','N','M','I','Y','I','D','Y','D'},
                         {'A','B','T','L','A','I','D','G','S','O','S','R','T','E','R'},
                         {'W','U','E','N','G','T','N','A','F','I','S','I','D','G','R'},
                         {'G','N','A','H','E','I','N','S','H','S','V','S','M','O','O'},
                         {'C','H','T','O','N','V','I','E','C','A','P','S','S','T','B'},
                         {'L','O','A','I','U','B','R','A','C','K','E','T','E','O','R'},
                         {'W','I','A','D','E','T','N','U','O','M','R','R','L','T','O'},
                         {'R','T','G','E','R','M','S','E','U','E','I','E','I','H','W'},
                         {'E','F','S','H','A','D','R','I','E','F','E','P','T','E','N'},
                         {'A','S','W','I','T','C','H','T','D','P','L','A','Q','U','E'},
                         {'D','N','E','R','G','S','H','E','L','E','S','P','A','C','N'},
                      };   
char result[15][15];

int main()
{

  char word[10];
  int size,row;
  int index=0;
  int i,j,k;
  int hold,holdk;

 

 printf("Enter your word:\n");

 scanf("%s",word);

 size=findLength( word );

  
  for( k=0 ; k < 15 ; k++ )
     if( check==0 )
     checkLines(puzzle[k],word,k,size);

  if( check==0 )
{ 
  transpose( puzzle );        
   
  
  for( k=0 ; k < 15 ; k++ )
     if( check==0 )
     checkColumns(result[k],word,k,size);
}  
}

//end main

int findLength( char word[] )
{
   
   int i;

   for(i=0 ; word[ i ] !='\0' ; i++ )
      ;

   return i;
}

void checkLines( char str[],char substr[],int row,int size )
{
   int i,j,temp;

   for(i=0; i < 15 ;i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
 
            if(substr[j]=='\0')
            {
                check=1;
                printArray(puzzle,temp,row,size,substr);
                break;
            }
            else
            {
                i=temp;
                temp=0;

            }
        }
    }
 
 if( temp==0)
   check=0;

  
} 

void printArray(char puzzle[][15],int pos,int row,int size,char w[])
{
    
  char res[ 15 ][ 15 ];
  int i,j,index=0;

  
   pos--;
    
 
    for( i=0 ; i < 15 ;i++ )
       for( j=0 ; j < 15 ; j++ )
           res[ i ][ j ]='*';

   
    for( i=pos ; index < size ; i++ )
    {
       res[ row ][ i ]=w[ index ];
       index++;
    }

     for( i=0 ; i < 15 ; i++ )
    {
         for( j=0 ; j < 15 ; j++ )
         {
              printf("%c",res[i][j]);
         }
         printf("\n");
   }
   
}


void transpose( char puzzle[][15] )
{
   int i,j;
   
    
  for( i=0 ; i < 15 ; i++ )
   {
      for( j=0 ; j < 15 ; j++ )
      {
          result[ i ][ j ]=puzzle[ j ][ i ];
      }
   }
}


void checkColumns( char str[],char substr[],int row,int size )
{
   int i,j,temp;

   for(i=0; i < 15 ;i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
 
            if(substr[j]=='\0')
            {
                check=1;
                printArray2(puzzle,row,temp,size,substr);
                break;
            }
            else
            {
                i=temp;
                temp=0;

            }
        }
    }
 
 if( temp==0)
   check=0;

  
} 


void printArray2(char puzzle[][15],int pos,int row,int size,char w[])
{
    char res[ 15 ][ 15 ];
    int i,j,index=0;

  
    row--;
    
 
    for( i=0 ; i < 15 ;i++ )
       for( j=0 ; j < 15 ; j++ )
           res[ i ][ j ]='*';

    for( i=row ; index < size ; i++ )
    {
       res[ i ][ pos ]=w[ index ];
       index++;
    }

    for( i=0 ; i < 15 ; i++ )
    {
         for( j=0 ; j < 15 ; j++ )
         {
              printf("%c",res[i][j]);
         }
         printf("\n");
   }
         
}




