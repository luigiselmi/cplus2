#include <stdio.h>

/* Computes the maximum, minimun and mean values
   of an array
*/
int main() {

   int N; // number of data points to be inserted
   int min, max;
   double mean = 0.0;

   printf("Insert the number of data points: \n");
   scanf("%d", &N);

   int data[N];

   for (int i = 0; i < N; ++i) {
      printf("Data point %d): ", i);
      scanf("%d", &data[i]);
   }

   min = max = data[0];

   for (int i = 0; i < N; ++i) {
      if (min > data[i])
         min = data[i];
      else if (max < data[i])
         max = data[i];
      mean += data[i];
   }
   mean /= N;
   printf("Array's min value = %d\n", min);
   printf("Array's max value = %d\n", max);
   printf("Array's mean value = %.2f\n", mean);
}
