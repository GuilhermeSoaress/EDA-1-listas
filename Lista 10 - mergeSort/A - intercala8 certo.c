void merge(int A[ ] , int start, int mid, int end) {
 //stores the starting position of both parts in temporary variables.
int p = start ,q = mid+1;

int Arr[end-start+1] , k=0;

for(int i = start ;i <= end ;i++) {
    if(p > mid)      //checks if first part comes to an end or not .
       Arr[ k++ ] = A[ q++] ;

   else if ( q > end)   //checks if second part comes to an end or not
       Arr[ k++ ] = A[ p++ ];

   else if( A[ p ] < A[ q ])     //checks which part has smaller element.
      Arr[ k++ ] = A[ p++ ];

   else
      Arr[ k++ ] = A[ q++];
 }
  for (int p=0 ; p< k ;p ++) {
   /* Now the real array has elements in sorted manner including both 
        parts.*/
     A[ start++ ] = Arr[ p ] ;
  }
}

int main(){
    int vetor1[10] = {1, 3, 5, 7, 9, 1, 2, 4, 6, 8};
    for(int i=0; i<10; i++)
        printf("%d ", vetor1[i]);
    
    printf("\n");

    merge(vetor1, 0, 5, 10);

    for(int i=0; i<10; i++){
        printf("%d ", vetor1[i]);
    }
}