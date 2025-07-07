#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    string name;
    int start;
    int end;
};

class ActivityPlanner {
private:
    vector<Activity> activities;

public:
    void addActivity(string name, int start, int end);
    void scheduleActivities(); // Greedy algorithm
};

#endif
