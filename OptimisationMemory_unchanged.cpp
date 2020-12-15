#include <iostream>
#include <stdlib.h> 
#include <thread>


 void main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    int* a = new int[10, 10];
    int res = 0;


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[j, i]++;
            
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start_time;
    cout << "The program worked for: " << duration.count() << endl;
}