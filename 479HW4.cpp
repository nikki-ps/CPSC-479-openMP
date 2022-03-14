#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char *argv[] ) 
{
    int a[32];
    int totalEven = 0;
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        int t_id = omp_get_thread_num();
        for (int i = t_id; i < 32; i += omp_get_num_threads()) {
            a[i] = 0;
            printf("i am thread %d: i put %d into array index %d \n", t_id, a[i], i);
        }
    }
    #pragma omp parallel
    {
        int t_id = omp_get_thread_num();
        for (int i = t_id; i < 32; i += omp_get_num_threads()) {
            a[i] += i;
            printf("i am thread %d: i have index %d and number value %d \n", t_id, i, a[i]);
        }
    }
    #pragma omp parallel reduction(+ : totalEven)
     {
        int t_id = omp_get_thread_num();
        for (int i = t_id; i < 32; i += omp_get_num_threads()) {
            if(a[i] % 2 == 0) {
                totalEven++;
            }
        }
     }
    printf("total number of even values: %d \n", totalEven);
}