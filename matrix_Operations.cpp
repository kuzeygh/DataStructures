#include<iostream>


/*****************
                 *
   COM267 HW 9   *           
  @author rabia  * 
                 *
******************/

//Here I defined All Operations that can be done with matrix.

#define ROW 5
#define COLUMN 5

using namespace std;

//Function declarations is very clear to get their indexes.
//it it a dynamic program,you should enter dimensions that
// are going to use
// if you want to use only one operation make others comment line.

void printArray( int **,int row,int column );

void matrixAddition( int**,int**,int row1,int col1,int row2,int col2 );
void matrixMultiplication( int**,int**,int row1,int col1,int row2,int col2);
void fillIndex(int**,int row,int column);
void transpose( int**,int row,int column);
void isSymmetric( int**,int row,int column );
void isLowTriangle( int**,int row,int column );
void isUpperTriangle( int**,int row,int column );
void isIdentity( int**,int row,int column );
int** createArray( int row,int column );

int main()
{
  int row,column;
  int row2,column2;
  int** array1;
  int** array2;

  cout<<"Enter for the first ;a number of rows and columns\n";

  cin>>row>>column;

  array1=createArray( row,column );
  fillIndex(array1,row,column);
  
  printArray( array1,row,column );

  cout<<"Enter for the second ;a number of rows and columns\n";

  cin>>row2>>column2;

  array2=createArray( row2,column2 );
  fillIndex(array2,row2,column2);

  printArray( array2,row2,column2 );
 

  cout<<"The addition of the given matrix"<<endl;

  matrixAddition( array1,array2,row,column,row2,column2 );

  cout<<"The multiplication of the given matrix"<<endl;
  
  matrixMultiplication( array1,array2,row,column,row2,column2 );

  cout<<"Matrix transpose"<<endl;

   transpose( array1,row,column );

    isSymmetric( array1,row,column );

    isUpperTriangle( array1,row,column );

   isIdentity(array1,row,column);

}

int** createArray( int row,int column )
{

  
  int **arr;

  arr=new int*[ row ];
  for( int i=0 ; i < row ; i++ )
      arr[ i ]=new int[ column ];

  
  for( int i=0 ; i < row ; i++ )
     for( int j=0 ; j < column ; j++ )
         arr[ i ][ j ]=0;

  return arr;
}  


void printArray( int** arr,int row,int column)
{

   cout<<endl;

   for( int i=0 ; i < row ; i++ )
   {
       for( int j=0 ; j < column ; j++ )
           cout<<arr[ i ][ j ]<<" ";
       cout<<endl;
   }
}

void matrixAddition( int** arr1,int** arr2,int row1,int col1,int row2,int col2 )
{
      
   if(row1==row2 && col1==col2 )
   {

       for( int i=0; i < row1 ; i++ )
       {
          for( int j=0 ; j < col1 ; j++ )
             cout<<arr1[ i ][ j ]+arr2[ i ][ j ]<<" ";
          cout<<endl;
       }
   }else
   
    cout<<"They are not compatible"<<endl;
}

void matrixMultiplication( int** arr1,int** arr2,int row1,int col1,int row2,int col2)
{
   
   int** result=createArray( row1,col2 );
   int i,j;

   if( col1==row2 )
   {

      for( i=0 ; i < row1 ; i++ )
          for( int k=0  ; k < col2 ; k++ )
             for( int c=0 ; c < col1 ; c++ )
                 result[ i ][ k ]+=arr1[ i ][ c ]*arr2[ c ][ k ]; 
    

    printArray( result,row1,col2 );

   }
   else
   cout<<"They are not compatible"<<endl;


   
}


void isIdentity( int** arr,int row,int column )
{
   int check=1;

   if( row==column)
  {
   for( int i=0 ; i < row ; i++ )
      if( arr[ i ][ i ]!=1 )
      {
       cout<<"Not Identity Matrix";
       break;

       check=0;

      }

      if( check==1 ){ cout<<"Identity Matrix"; }
  }else
   cout<<"They are not compatible"<<endl;

} 
  
void fillIndex(int** arr,int row,int column)
{
   

  cout<<"Enter elements\n";


  for( int i=0 ; i < row ; i++ )
      for( int j=0 ; j < column ; j++ )
          cin>>arr[ i ][ j ];
}

void transpose(int** arr,int row,int column)
{

  int** result=createArray( column,row);

  for( int  i=0 ; i < row ; i++ )
      for( int j=0 ; j < column ; j++ )
         result[ j ][ i ]=arr[ i ][ j ];

 


  printArray( result,column,row );
}


void isSymmetric( int** arr,int row,int column )
{

   int check=1;

   for( int i=0 ; i < row ; i++ )
      for( int j=0 ; j < column ; j++ )
          if( arr[ i ][ j ]!=arr[ j ][ i ] )
           {
              cout<<"Not Symmetric Matrix"<<endl;
              break;
              check=0;
           }
  if( check==1 ){ cout<<"Symmetric Matrix"<<endl; }
}

void isLowTriangle( int** arr,int row,int column )
{

     int check=1;

     if( row==column )
     {
        for( int i=0 ; i < row-1 ; i++ )
           for( int j=column ; j >= i+1 ; j-- )
              if( arr[ i ][ j ]!=0 ){ cout<<"Not Low Triangle"; check=0; break; }

    }

   if( check==1 ){ cout<<"Low Triangle"; }
}

void isUpperTriangle( int** arr,int row,int column )
{
   
   int check=1;

     if( row==column )
     {
        for( int i=1 ; i < row ; i++ )
           for( int j=0 ; j < i; j++ )
              if( arr[ i ][ j ]!=0 ){ cout<<"Not Upper Triangle"; check=0; break; } 

    }

    
    if( check==1 ){ cout<<"Upper Triangle"; }
}
    













