#include "activity.h"

void ActivityPlanner::addActivity(string name, int start, int end) {
    activities.push_back({name, start, end});
}

void ActivityPlanner::scheduleActivities() {
    sort(activities.begin(), activities.end(), [](Activity a, Activity b) {
        return a.end < b.end;
    });

    cout << "\n🎯 Scheduled Activities (Max Non-Overlapping):\n";
    int lastEnd = -1;
    for (auto& act : activities) {
        if (act.start >= lastEnd) {
            cout << "- " << act.name << " (" << act.start << ":00 to " << act.end << ":00)\n";
            lastEnd = act.end;
        }
    }
}
