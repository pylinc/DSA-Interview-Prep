/*
Problem: 2402. Meeting Room III
Platform: LeetCode
Difficulty: Hard

Approach:1
1.Sort the meetings based on their start times.
2. Maintain two arrays: one to track when each room will be available next and another to count how many times each room has been used.
3. Iterate thorugh each meeting and decclare six variables: start time, end time, a boolean found to check if a room is found,duration of the meeting, earlyEndRoomTime, and earlyEndRoom(to store the room with earliest end time).
     - Iterate through each to room to check if the lastAvailableAt time is less than or equal to the start time of the meeting.
        - If found, update the lastAvailableAt time for that room to the end time of the meeting and increment the roomUsedCount for that room mark found as true and break.
        - check if the lastAvailableAt time for that room is less than earlyEndRoomTime, if yes update earlyEndRoomTime and earlyEndRoom.
    - If no room is found, update the lastAvailableAt time for the earlyEndRoom by adding the duration of the meeting and increment the roomUsedCount for that room.
4. After processing all meetings, find the room with the maximum usage count and return its index.
Time Complexity: O(m * n), where m is the number of meetings and n is the number of rooms.
Space Complexity: O(n) for the two arrays used to track room availability and usage counts.
*/

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings),end(meetings));

        vector<long long> lastAvailableAt(n,0);
        vector<int> roomUsedCount(n,0);

        for(vector<int>& meeting: meetings){

            int start = meeting[0];
            int end = meeting[1];
            bool found = false;
            int duration = end - start;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;
            for(int room =0;room<n;room++){

                if(lastAvailableAt[room] <= start){
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earlyEndRoomTime){
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom = room;
                }
            }

            if(!found){
                lastAvailableAt[earlyEndRoom] += duration;
                roomUsedCount[earlyEndRoom]++;

            }
        }

        int resultRoom = -1;
        int maxUse = 0;

        for(int room = 0;room < n;room++){
            if(roomUsedCount[room] > maxUse){
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

/*
The Problem with approach 1 is that is for every meeting we are iterating through all rooms to find an available room or the room with the earliest end time. This results in a time complexity of O(m * n), where m is the number of meetings and n is the number of rooms. This can be inefficient when both m and n are large.
So to optimize this we can use priority queues to efficiently manage room availability and quickly find the next available room.

Approach:2
1. Sort the meetings based on their start times.
2. Declare an array roomUsedCount to keep track of how many times each room has been used.
3. Use two priority queues: one (roomUsed) to keep track of available rooms sorted by their indices this priroity queue will store the data in pairs where first is endTime and the second is room number and another (availableRoom) to keep track of occupied rooms sorted by their end times.
3. Iterate through every room and push all rooms into the availableRoom priority queue.
4. Iterate through each meeting:
   -Declare start time, end time and duration of the meeting.
   -While there are rooms in the roomUsed priority queue and the top room's end time is less than or equal to the start time of the meeting, pop the room from roomUsed and push it into availableRoom.
    -If there are available rooms, pop the top room from availableRoom, push it into roomUsed with the current meeting's end time, and increment the roomUsedCount for that room.
    -If no rooms are available, pop the room with the earliest end time from roomUsed, calculate the new end time by adding the meeting duration to the room's end time, push it back into roomUsed, and increment the roomUsedCount for that room.
5. After processing all meetings, find the room with the maximum usage count and return its index.

Time Complexity: O(m log n), where m is the number of meetings and n is the number of rooms. This is because each meeting involves operations on the priority queues which take O(log n) time.
Space Complexity: O(n) for the roomUsedCount array and the priority queues.
*/
class Solution {
public:
    typedef pair<long long , int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings),end(meetings));

        vector<int> roomUsedCount(n,0);

        priority_queue<P,vector<P>, greater<P>> roomUsed;
        priority_queue<int,vector<int>,greater<int>> availableRoom;

        for(int room = 0;room<n;room++){
            availableRoom.push(room);
        }

        for(vector<int>&meet: meetings){
            int start = meet[0];
            int end = meet[1];

            int duration = end - start;

            while(!roomUsed.empty() && roomUsed.top().first <= start){
                int room  = roomUsed.top().second;
                roomUsed.pop();
                availableRoom.push(room);
            }

            if(!availableRoom.empty()){
                int room = availableRoom.top();
                availableRoom.pop();
                roomUsed.push({end,room});
                roomUsedCount[room]++;
            }
            else{
                int room = roomUsed.top().second;
                long long endTime = roomUsed.top().first;

                roomUsed.pop();
                roomUsed.push({endTime+duration,room});
                roomUsedCount[room]++; 
            }

        }

        int resultRoom = -1;
        int maxUse = 0;

        for(int room = 0;room < n;room++){
            if(roomUsedCount[room] > maxUse){
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

