# OptimisationMemory


## Task

**Tasks for work:**
1) Analyze the program, measure its execution time, determine where there is room for improvement.
2) Based on the mechanisms described in the theory of memory organization to make the necessary changes in the code structure.
3) Measure the new execution time, if there are obvious improvements, go to paragraph 4, if not - to paragraph 1
4) Record new indicators and explain why the acceleration was achieved.

Code

```
        static void Main(string[] args)
        {
            int[,,] a = new int[10,10];
            int res = 0;

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                        a[j,i]++;
                }
            }

        }
```

## Rewrite


I rewrite this code to C++ and I have:
```
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
```

## Unoptimazet program

After few tries I see that time isn't constant but keep around this result:

![example 1](/images/1.png)

As you can see code and program is very small, loop too, so it took not many time.

## Optimization

I optimazed this code and as I say higher, code and actions in it too small, so changes not many:

- I replace i and j in `a[j, i]++;` for maximizing of space location.
- Optimize loop with using `register int i = 0` and `register int j = 0` as it should suggest the compiler to store this value in the registers.
- Delete unused variable `int res = 0;` what help minimize memory costs.

## Optimized code

```
#include <iostream>
#include <stdlib.h> 
#include <thread>

 void main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    int* a = new int[10, 10];


    for (register  int i = 0; i < 10; i++)
    {
        for (register  int j = 0; j < 10; j++)
        {
            a[i,j]++;
            
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start_time;
    cout << "The program worked for: " << duration.count() << endl;
}
```
### Output of optimazed program

![example 2](/images/2.png)

As you can see it minimazed time but a little bit, because program also small.











