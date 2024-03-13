// question 
/*
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.  

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

 

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []

*/


#include <iostream>
#include <vector>

using namespace std;

pair<int,int> getTimeSlot(vector<pair<int,int>> &slots1 ,vector<pair<int,int>> &slots2 , int &n , int &m  ,int &duration ){
  //edge-case
  if(n == 0 || m == 0 ) return {};
  int i =0 ;
  int j =0 ;

  while( i < n && j < m){
     int startTime = max(slots1[i].first , slots2[j].first);
     int endTime = min(slots1[i].second , slots2[j].second);

      if(endTime - startTime >= duration){
          return {startTime, startTime + duration};
      }

     if(slots1[i].second  < slots2[j].second){
       i++;
     }
      else{
        j++;
      }
  }

  return {};
  
}

int main() {
  vector<pair<int,int>> slots1 = {{10, 50}, {60, 120}, {140, 210}};
  vector<pair<int,int>> slots2 = {{0, 15}, {60, 70}};
  int duration = 8;

  int n = slots1.size();
  int m = slots2.size();

  pair<int,int> timeSlotRes = getTimeSlot(slots1,slots2,n,m,duration);
  
  cout<<timeSlotRes.first<< " "<<timeSlotRes.second<<endl;
  return 0;
}

/**
Important reasoning (why we are comparing with end times of the slots):
Here's why checking the end time is essential in this part of the algorithm, and why using the start time wouldn't yield the correct results:

1. **Finding the Next Potential Overlap:**
    - If `slots1[i].end < slots2[j].end`, it means the slot in `slots1` ended earlier. There's no potential for any further overlap with the current slot in `slots2`. Thus, we advance `i` to move to the next slot in `slots1` and look for overlaps there.
    - Conversely, if `slots1[i].end >= slots2[j].end`, the `slots2` slot ended earlier (or at the same time). We advance `j`. 

2. **Avoiding Missed Opportunities:** 
    - Let's say you compare start times instead. 
Imagine these slots:

* `slots1`: [(5, 15), (20, 30)]
* `slots2`: [(10, 25)]
now dry run for the above example and validate point-2

**In summary:** checking the end time is crucial to correctly determine when a slot effectively ends and to ensure that you don't skip over potential overlap regions when searching for the earliest suitable time slot. 

**/
