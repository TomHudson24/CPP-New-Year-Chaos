#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits.h>
#include <limits>
#include <minmax.h>


/*
Given a list of 8 integers in a queue (1,2,3,5,4,6,7,8). With the input (2,1,5,3,4,6,7,8), how did they list get into this position?
Integers can only move a maximum of 2 steps forward, never backwards. If the given input cannot be reconstructed, deem it to be too
chaotic.


-------------------------------------------------------------------------------------------------------------------------------------------

The logic of the algorithm is, that the question only asks for the number of steps to make the model, so no need to sort or restructure the list.


The algorithm works like so, 2 loops, the top level checking if the current integer (starting from the end of the list) can be in that position, 
if not finish up, the list is too chaotic. If it can be in that position another loop starts comparing the current integer can overtake the integer
near it. If so then record that.

*/


void minimumBribes(std::vector<int> q) {

    for (int i = 0; i < q.size(); i++) {
        std::cout << q[i];
    }
    std::cout << "\n";
    int count = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            std::cout << "Too chaotic" << std::endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
        {
            if (q[j] > q[i]) count++;
            std::cout << "Comparing this: "<< q[j] << "\twith the current integer:" << q[i] << "   Current step count: " << count << "\n";
        }
            
    }
    std::cout << count << std::endl;
    
}

int main()
{
    std::vector<int> q;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        std::cin >> t;
        q.push_back(t);
    }
        minimumBribes(q);

    return 0;
}
