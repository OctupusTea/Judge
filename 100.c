#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m)
{
   int *temp;
   for(int i=0;i<m*m;i++)
   {
      for (int j =i+1; j < m*m; ++j)
      {
        if( **(ptr_array+i) > **(ptr_array+j))
        {
            temp=*(ptr_array+i);
            *(ptr_array+i)=*(ptr_array+j);
            *(ptr_array+j)=temp;


        }
      }
      
   }



}
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}