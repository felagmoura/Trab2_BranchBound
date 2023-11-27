#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "JOBS.h"

using namespace std;

#ifndef GREEDY_H
#define GREEDY_H


void greedy (Jobs jobs) {
    //jobs.sortJobsDeadline();
    //jobs.printJobs();

    jobs.sortJobsPenalty();
    //jobs.printJobs();

    int result[jobs.numJobs];
    bool slot[jobs.numJobs];

    for (int i = 0; i < jobs.numJobs; i++)
        slot[i] = false;

    for (int i = 0; i < jobs.numJobs; i++) {
        for (int j = min(jobs.numJobs, jobs.jobList[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                j = 0;
            }
        }
    }

    for (int i = 0; i < jobs.numJobs; i++)
        if (slot[i])
            cout << jobs.jobList[result[i]].id << " ";
    cout << endl;
}

#endif