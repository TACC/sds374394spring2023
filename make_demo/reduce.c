/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%
   %%%% This program file is part of the book and course
   %%%% "Parallel Computing"
   %%%% by Victor Eijkhout, copyright 2013-6
   %%%%
   %%%% reduce.c : reduction
   %%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mpi.h"
#include "myrandom.h"

int main(int argc,char **argv) {

#include "globalinit.c"

  //codesnippet reduce
  float myrandom = myrandomf(2.),
    result;
  int target_proc = nprocs-1;
  // add all the random variables together
  MPI_Reduce(&myrandom,&result,1,MPI_FLOAT,MPI_SUM,
             target_proc,comm);
  // the result should be approx nprocs/2:
  if (procno==target_proc)
    printf("Result %6.3f compared to nprocs/2=%5.2f\n",
           result,nprocs/2.);
  //codesnippet end

  MPI_Finalize();
  return 0;
}
