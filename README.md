# SchedulingProblem

Ryan Takata
ryan.takata@csu.fullerton.edu

How to Run the Program:
I used g++ to compile and run the code.
Have an "input.txt" file in the same directory
(g++ .\project1_starter.cpp -o main) or (c++ .\project1_starter.cpp -o main) to compile
(./main) to run


Pseudocode

Create a void function that takes in 7 parameters. The unavailability of both people,
the clock in schedule of both people, the duration of the meeting, an unavailability string vector
containing the total unavailable times, and a string vector that takes in the time that the 
group is clocked in for the day.

Create a string vector to keep track of the total available time slots.

Create a char = ':' to compare to the input strings in order to extract the times.

Use a for loop to traverse the unavailability and the clock in schedule of both people.
The for loop should run the whole length of the string we are traversing.
In the for loop, we check if the current index is a digit.

If it is a digit, we check if the current index + 2 is equal to the ':' char.
If it does equal the ':' char, we push a substring of the current index that is a length of 5
into the clocked in vector or the unavailability vector.

We also check if the current index + 1 is equal to the ':' char, then we push a substring of the current index that
is a length of 4 into the clocked in vector or the unavailability vector.

Checking if the current index + 2 or + 1 is equal to the ':' char ensures that we
find single and double digit times.

Once we traverse all of the strings from the input file, we will have two vectors, one with unavailability and one with
a total clocked in schedule. 

Now we have to compare the indicies of those two vectors with a whole clock to find available meeting times.

(In the nested for loop)
We can use a nested for loop where the first for loop keeps track of the hours where
for (hrs = 0; hrs < 24; ++hrs) 
and the nested for loop will contain the minutes
for (mins = 0; mins < 60; mins += durationOfMeeting)
This will ensure that 60 minutes will pass before incrementing the hour loop.
Adding the duration of the meeting to the minutes will be there to prevent overlaps
of available times (9:00 - 9:30 and 9:01 - 9:31)

Within the nested for loop we can start by keeping track of the meeting's end time by creating 
two variables that will take the current loop's hrs and add the meetingDuration/60 and the current loop's
mins and add meetingDuration%60. Dividing the duration by 60 will ensure there are no overflowing minutes
like 7:75.

Next in the nested loop, we check if the ending minutes will be greater than 60. If it is, 
we have to add an hour to the end time's hour, and subtract 60 minutes from the end time minutes.

After an accurate end time, we need to convert the current time and ending time into strings to compare 
to the unavailability vector and the clocked in vector's indicies

(Inside of an if statement)
Next, we check if the current time and the end time of the meeting is within the
clock in schedules of the group members

If the meeting time is within the member's clock in schedules, we then have to take into account the
unavailability of both group members.

(Inside a for loop)
We can do this by creating another for loop to traverse the vector of unavailability. 
for(i = 0; i < unavailability.size(); i+=2)
We increment by two spaces since the times in the vector are paired as (start of unavail, end of unavail).

We need to create an available bool and set it to true

In this for loop, we use an if statement to check if the current time is >= the current index and < current index + 1
OR
the end time is > then current index and <= current index + 1
The if statement will check if the current time or end time is within the pair of unavailability.
If either statements are true, we change the available boolean to false.

Next in this loop, we check if avail is still true.
If it is, we push back the current time and end time into the available meeting time slots vector.
(exits for loop)
(exit if statement)
(exit nested for loop)

After we have the available meeting time slots vector filled, we print every element of the vector
to show the available slots.