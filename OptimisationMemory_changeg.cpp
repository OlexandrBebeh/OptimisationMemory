#include <iostream>
#include <stdlib.h> 
#include <thread>


 void main()
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int* a = new int[10, 10];
    int res = 0;


    for (register int i = 0; i < 10; i++)
    {
        for (register int j = 0; j < 10; j++)
        {
            a[i, j]++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start_time;
    std::cout << "The program worked for: " << duration.count() << std::endl;

}