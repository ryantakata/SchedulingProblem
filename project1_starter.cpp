#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



int main()
{
    std::ifstream theFile("input.txt");
    std::vector<std::string> totalSched;
    std::string busy1, busy2, work1, work2;
    int duration = 0;

    while(theFile >> busy1 >> work1 >> busy2 >> work2 >> duration)
    {
        

        std::cout << "Person 1 is busy during " << busy1 << "\nAnd is clocked in during " << work1 << "\n";
                  
        std::cout << "Person 2 is busy during " << busy2 << "\nAnd is clocked in during " << work2 << "\n"
                  << "The meeting will last " << duration << " minutes\n";
    }

    for(int i = 0; i < busy1.length(); ++i)         //Gets the digits from the string, but need to figure out how to use those
    {                                               //digits to subtract from an overall clock
        if(isdigit(busy1[i]))
        {
            std::cout << busy1[i] << ", ";
        }
    }
    
    return 0;
}
