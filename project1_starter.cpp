#include <iostream>
#include <vector>
#include <string>
#include <fstream>



int main()
{
    std::ifstream theFile("input.txt");
    std::string busy1, busy2, work1, work2;
    int duration = 0;

    while(theFile >> busy1 >> work1 >> busy2 >> work2 >> duration)
    {
        std::cout << "Person 1 is busy during " << busy1 << "\nAnd is clocked in during " << work1 << "\n";
                  
        std::cout << "Person 2 is busy during " << busy2 << "\nAnd is clocked in during " << work2 << "\n"
                  << "The meeting will last " << duration << " minutes\n";
    }

    
    return 0;
}
