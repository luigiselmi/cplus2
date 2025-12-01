#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int niter=10000; //Specify the number of samples.
  srand((unsigned)time(NULL)); //Set the seed of random number generator.
  int n_in=0; //Initialize the counter.
  /*************/
  /* Main loop */
  /*************/
  for(int iter=1;iter<niter+1;iter++){
    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    //Generate random numbers x,y in [0,1].
    if(x*x+y*y < 1e0) { //If xˆ2+yˆ2<1....
      n_in=n_in+1; //Add 1 to n_in.
    }
    printf("\"%d %.10f\n",iter,(double)n_in/iter);
  }
}
