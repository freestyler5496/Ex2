#include <cstdlib>
#include <fstream>     // file operations
#include <iostream>
#include <ctime>
using namespace std;

#include "solutions.h"
int main()
{
    const int k = 1000;

    // FOR THE PLOTS, THE VECTORS OF THE MATLAB CODE WILL BE SAVED INTO 3 DIFFERENT FILES
    ofstream sol1, sol2, sol3;
    sol1.open("sol1.txt");
    sol2.open("sol2.txt");
    sol3.open("sol3.txt");
    sol1 << "---------------------THE RESULTS OF FIRST ALGORITHM----------------------------\n\n";
    sol2<< "---------------------THE RESULTS OF SECOND ALGORITHM----------------------------\n\n";
    sol3<< "---------------------THE RESULTS OF THIRD ALGORITHM----------------------------\n\n";
    int m=0;
    // OUTER FOR LOOP TO TRY DIFFERENT SIZES ONE BY ONE
    for(int n = 1000; n < 350000; n+=20000)
    {
        // input and output arrays: k largest integers out of n integers
        int inArr[n];
        int outArr[k];
        cout << "RANDOM ARRAY " <<  ++m << ":\tSIZE: " << n << "\n";

        //FILL THE ARRAY RANDOMLY with random numbers in range [0-100]
        srand((unsigned)time(0));
        for(int i = 0; i < n; i++)
        {
            inArr[i] = (rand()%100)+1;
        }

        // ***** GIVE THE SAME ARRAY TO ALL 3 ALGORITHMS **********
        //  MEASURE THE DURATIONS OF THREE ALGORITHMS USING THE SAME ARRAY
        // WRITE THEM INTO THEIR CORRESPONDING FILES
        // THE RESULTS IN THE TXT FILES sol1, sol2, and sol3 WILL BE COPIED TO A MATLAB CODE AND PLOTTED
        // VERSUS SIZE N=1000:500:100000 being the x-axis
        double duration;

        clock_t startTime = clock();
        solution1(inArr, n, k, outArr);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sol1 << duration << ", ";

        startTime = clock();
        solution2(inArr, n, k, outArr);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sol2 << duration << ", ";

        startTime = clock();
        solution3(inArr, n, k, outArr);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        sol3 << duration << ", ";

    }
    // close the file streams
    sol1.close();
    sol2.close();
    sol3.close();

} // end of main
