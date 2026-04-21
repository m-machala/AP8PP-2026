#include <iostream>
#include <omp.h>
#include <cmath>

int main()
{
    int threadCount = omp_get_max_threads();

    std::cout << "System thread count: " << threadCount << std::endl;

    #pragma omp parallel num_threads(4)
    {
        int threadId = omp_get_thread_num();

        #pragma omp critical
        {
            std::cout << "Hello from thread " << threadId << "!" << std::endl;
        }
    }

    std::cout << "For loop:" << std::endl;

    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        int threadId = omp_get_thread_num();

        #pragma omp critical
        {
            std::cout << "Hello from thread " << threadId << "!" << std::endl;
            std::cout << "Task number: " << i << std::endl;
        }
    }


    std::cout << "Reduction:" << std::endl;

    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100000; i++) {
        int temp = sum;
        temp++;
        sum = temp;
    }

    std::cout << "Final sum: " << sum << std::endl;


    std::cout << "Timing:" << std::endl;

    int iterationCount = 1000000;

    double startTime = omp_get_wtime();

    double timingSum = 0;

    for (int i = 0; i < iterationCount; i++) {
        double temp = timingSum;
        temp = temp + std::sin(i) + std::cos(i);
        timingSum = temp;
    }

    std::cout << "Sequential result: " << timingSum << std::endl;

    double endTime = omp_get_wtime();
    double sequentialTime = endTime - startTime;


    startTime = omp_get_wtime();

    timingSum = 0;

    #pragma omp parallel for
    for (int i = 0; i < iterationCount; i++) {
        #pragma omp critical
        {
            double temp = timingSum;
            temp = temp + std::sin(i) + std::cos(i);
            timingSum = temp;
        }
    }
    std::cout << "Critical result: " << timingSum << std::endl;
    endTime = omp_get_wtime();
    double criticalTime = endTime - startTime;


    startTime = omp_get_wtime();

    timingSum = 0;

    #pragma omp parallel for reduction(+:timingSum)
    for (int i = 0; i < iterationCount; i++) {
        double temp = timingSum;
        temp = temp + std::sin(i) + std::cos(i);
        timingSum = temp;
    }
    std::cout << "Reduction result: " << timingSum << std::endl;
    endTime = omp_get_wtime();
    double reductionTime = endTime - startTime;


    std::cout << "Sequential runtime: " << sequentialTime << " seconds" << std::endl;
    std::cout << "Critical runtime: " << criticalTime << " seconds" << std::endl;
    std::cout << "Reduction runtime: " << reductionTime << " seconds" << std::endl;

    return 0;
}
