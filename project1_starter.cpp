#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void findAvail(std::string busy1, std::string work1, std::string busy2, std::string work2, int duration, 
               std::vector<std::string> unAvail, std::vector<std::string> clockedIn)
{
    std::vector<std::string> allTimeSlots;                          // Holds the total time slots available for the meeting
    char cmp = ':';                                                 // Used in checking time format and inserting time into unAvail vector

    // Traverses the string of the first clocked in input
    // Puts time into total clocked in vector
    for(int i = 0; i < work1.length(); ++i)
    {
        if(isdigit(work1[i]))
        {
            if(work1[i+2] == cmp)
            {
                clockedIn.push_back(work1.substr(i, 5));
                i += 5;
            }
            else if(work1[i+1] == cmp)
            {
                clockedIn.push_back("0" + work1.substr(i, 4));
                i += 4;
            }
        }
    }

    // Traverses the string of the second clocked in input
    // Puts time into total clocked in vector
    for(int i = 0; i < work2.length(); ++i)
    {
        if(isdigit(work2[i]))
        {
            if(work2[i+2] == cmp)
            {
                clockedIn.push_back(work2.substr(i, 5));
                i += 5;
            }
            else if(work2[i+1] == cmp)
            {
                clockedIn.push_back("0" + work2.substr(i, 4));
                i += 4;
            }
        }
    }

    // Traverses the first unavailability string and puts the times
    // into the total unavailability vector
    for(int i = 0; i < busy1.length(); ++i)
    {                                                           
        if(isdigit(busy1[i]))                       
        {
            if(busy1[i+2] == cmp)
            {
                unAvail.push_back(busy1.substr(i, 5));
                i += 5;
            }
            else if(busy1[i+1] == cmp)
            {
                unAvail.push_back("0" + busy1.substr(i, 4));
                i += 4;
            }
        }
    }

    // Traverses the first unavailability string and puts the times
    // into the total unavailability vector
    for(int i = 0; i < busy2.length(); ++i)
    {
        if(isdigit(busy2[i]))                       
        {
            if(busy2[i+2] == cmp)
            {
                unAvail.push_back(busy2.substr(i, 5));
                i += 5;
            }
            else if(busy2[i+1] == cmp)
            {
                unAvail.push_back("0" + busy2.substr(i, 4));
                i += 4;
            }
        }
    }

    // Nested for loops that keep track of hours and minutes
    // starting from 00:00 going up to 23:59 (without constraints)
    for(int hrs = 0; hrs < 24; ++hrs)
    {
        for(int mins = 0; mins < 60; mins += duration)
        {
            // Divides and mods the duration by 60 and adds it to
            // the current hrs and mins to get an accurate end time.
            int endHr = hrs + (duration/60);
            int endMins = mins + (duration%60);

            // If duration >= 60 mins, we subtract 60 minutes from the end time and
            // add 1 hour to the end time. This lets us make sure the minutes don't overlap
            // which ensures accurate time tracking. 
            if(endMins >= 60)
            {
                endHr += 1;
                endMins -= 60;
            }

            // Convert the current time of the two for loops into an hh:mm format
            // with leading zeros for 1 digit numbers. (09:00 or 09:07)
            std::string currTime = (hrs < 10 ? "0" : "") + std::to_string(hrs) + ":" + 
                                      (mins < 10 ? "0" : "") + std::to_string(mins);

            // Convert the end limit into an hh:mm format with leading zeros for
            // 1 digit numbers.
            std::string endTime = (endHr < 10 ? "0" : "") + std::to_string(endHr) + ":" +
                                  (endMins < 10 ? "0" : "") + std::to_string(endMins);
            
            // Checks if the currentTime and endTime are within the limits of the
            // total clocked in times for the whole day.
            if(currTime >= clockedIn[0] && endTime <= clockedIn[1] &&
               currTime >= clockedIn[2] && endTime <= clockedIn[3])
            {
                bool avail = true;

                for(int i = 0; i < unAvail.size(); i+=2)
                {
                    // Checks if the current time OR end time are within the unavailable times
                    // given in the input file
                    if(currTime >= unAvail[i] && currTime < unAvail[i+1] ||
                       endTime > unAvail[i] && endTime <= unAvail[i+1])
                    {
                        avail = false;
                    }
                }
                
                // If the current and end time are not within the times of unavailability
                // then we add the current time and end time into the total available slots.
                if(avail)
                {
                    allTimeSlots.push_back("['" + currTime + "','"+ endTime + "']");
                }
            }
        }
    }

    std::cout << "[";
    for (auto i = allTimeSlots.begin(); i != allTimeSlots.end();)
    {
        std::cout << *i;
        if (++i != allTimeSlots.end())
        {
            std::cout << ",";
        }
    }
    std::cout << "]";

}

int main()
{
    std::ifstream theFile("input.txt");                         //Gets the input file
    std::ofstream output("output.txt");
    std::vector<std::string> unAvail, clockIn;                  //Vector of unavailable times and total clocked in times
    std::string busy1, busy2, work1, work2;
    int duration;

    while(theFile >> busy1 >> work1 >> busy2 >> work2 >> duration)  //Reads the input file and puts information into variables
    {
        findAvail(busy1, work1, busy2, work2, duration, unAvail, clockIn);
        std::cout << std::endl;
    }
    
    
    return 0;
}
