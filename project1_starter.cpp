#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void findAvail(std::string busy1, std::string work1, std::string busy2, std::string work2, int duration, std::vector<std::string> unAvail, std::vector<std::string> clockedIn)
{
    char cmp = ':';
    for(int i = 0; i < busy1.length(); ++i)                     //Gets the unavailable time slots from first person's schedule and 
    {                                                           //puts it into the unavailability vector
        if(isdigit(busy1[i]))                       
        {
            if(busy1[i+2] == cmp)
            {
                unAvail.push_back(busy1.substr(i, 5));
                i += 5;
            }
            else if(busy1[i+1] == cmp)
            {
                unAvail.push_back(busy1.substr(i, 4));
                i += 4;
            }
        }
    }

    for(int i = 0; i < busy2.length(); ++i)                     // Gets the unavailable time slots from second person's schedule and 
    {                                                           // puts it into the unavailability vector
        if(isdigit(busy2[i]))                       
        {
            if(busy2[i+2] == cmp)
            {
                unAvail.push_back(busy2.substr(i, 5));
                i += 5;
            }
            else if(busy2[i+1] == cmp)
            {
                unAvail.push_back(busy2.substr(i, 4));
                i += 4;
            }
        }
    }
    
    for(int i = 0; i < work1.length(); ++i)                     // Gets the clock in time from the first person and puts it into a clocked
    {                                                           // in vector
        if(isdigit(work1[i]))
        {
            if(work1[i+2] == cmp)
            {
                clockedIn.push_back(work1.substr(i, 5));
                i += 5;
            }
            else if(work1[i+1] == cmp)
            {
                clockedIn.push_back(work1.substr(i, 4));
                i += 4;
            }
        }
    }

    for(int i = 0; i < work2.length(); ++i)                     // Gets the clock in time from the second person and puts it into a clocked
    {                                                           // in vector
        if(isdigit(work2[i]))
        {
            if(work2[i+2] == cmp)
            {
                clockedIn.push_back(work2.substr(i, 5));
                i += 5;
            }
            else if(work2[i+1] == cmp)
            {
                clockedIn.push_back(work2.substr(i, 4));
                i += 4;
            }
        }
    }



    for(int i = 0; i < unAvail.size(); ++i)                      // Prints out the unavailable times
    {
        std::cout << unAvail[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < clockedIn.size(); ++i)                   // Prints out clocked in times
    {
        std::cout << clockedIn[i] << " ";
    }
    std::cout << "\n";

}

int main()
{
    std::ifstream theFile("input.txt");                         //Gets the input file
    std::vector<std::string> unAvail, clockIn;                  //Vector of unavailable times
    std::string busy1, busy2, work1, work2;
    int duration = 0;

    while(theFile >> busy1 >> work1 >> busy2 >> work2 >> duration)  //Reads the input file and puts information into variables
    {
        findAvail(busy1, work1, busy2, work2, duration, unAvail, clockIn);
    }

    // for(int i = 0; i < work1.length(); ++i)
    // {
    //     if(isdigit(work1[i]))
    //     {
    //         if(work1[i+2] == cmp)
    //         {
    //             std::cout << work1.substr(i, 5) << " ";
    //             i += 5;
    //         }
    //         else if(work1[i+1] == cmp)
    //         {
    //             std::cout << work1.substr(i, 4)<< " ";
    //             i += 4;
    //         }
    //     }
    // }

    
    // for(int i = 0; i < busy1.length(); ++i)                     //Gets times from the busy list and puts it into 
    // {                                                           //the total schedule vector.
    //     if(isdigit(busy1[i]))                       
    //     {
    //         if(busy1[i+2] == cmp)
    //         {
    //             unAvail.push_back(busy1.substr(i, 5));
    //             i += 5;
    //         }
    //         else if(busy1[i+1] == cmp)
    //         {
    //             unAvail.push_back(busy1.substr(i, 4));
    //             i += 4;
    //         }
    //     }
    // }

    // for(int i = 0; i < busy2.length(); ++i)                     //Gets times from the busy list and puts it into 
    // {                                                           //the total schedule vector.
    //     if(isdigit(busy2[i]))                       
    //     {
    //         if(busy2[i+2] == cmp)
    //         {
    //             unAvail.push_back(busy2.substr(i, 5));
    //             i += 5;
    //         }
    //         else if(busy2[i+1] == cmp)
    //         {
    //             unAvail.push_back(busy2.substr(i, 4));
    //             i += 4;
    //         }
    //     }
    // }

    // for(int i = 0; i < unAvail.size(); ++i)                      //Prints out the unavailable times
    // {
    //     std::cout << unAvail[i] << " ";
    // }
    
    return 0;
}
