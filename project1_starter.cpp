#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



int main()
{
    std::ifstream theFile("input.txt");                             //Gets the input file
    std::vector<std::string> unAvail;                               //Vector of unavailable times
    std::string busy1, busy2, work1, work2;
    int duration = 0;

    while(theFile >> busy1 >> work1 >> busy2 >> work2 >> duration)  //Reads the input file and puts information into variables
    {
        
        for(int i = 0; i < busy1.length(); ++i)                     //Gets times from the busy list and puts it into 
        {                                                           //the total schedule vector.
            
            if(isdigit(busy1[i]))                       
            {
                unAvail.push_back(busy1.substr(i, 5));   
                i+=4;
            }
        }
        

        //std::cout << work1 << std::endl;
        /*std::cout << "Person 1 is busy during " << busy1 << "\nAnd is clocked in during " << work1 << "\n";
                  
        std::cout << "Person 2 is busy during " << busy2 << "\nAnd is clocked in during " << work2 << "\n"
                  << "The meeting will last " << duration << " minutes\n";*/
    }
    for(int i = 0; i < unAvail.size(); ++i)                      //Prints out the unavailable times
    {
        std::cout << unAvail[i] << " ";
    }
    
    return 0;
}
