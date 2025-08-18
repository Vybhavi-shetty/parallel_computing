#include <stdio.h>
#include <omp.h>

int main() {
    int A1[6] = {1, 2, 3, 4, 5, 6}; 
    int A2[6] = {1, 2, 3, 4, 5, 6}; 

    
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A1[i] = 3 * A1[i] + 2;
        printf("Dynamic: Thread %d processed A1[%d] = %d\n",
               omp_get_thread_num(), i, A1[i]);
    }

    printf("\n");

    
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
        printf("Static: Thread %d processed A2[%d] = %d\n",
               omp_get_thread_num(), i, A2[i]);
    }

    return 0;
}