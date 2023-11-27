#include <vector>
#include <algorithm>

using namespace std;

#ifndef JOBS_H
#define JOBS_H

struct Job {
    int id;
    int deadline;
    int penalty;
};

struct Jobs {
    int numJobs;
    vector<Job> jobList;

    Jobs () : numJobs(0), jobList() {}

    Jobs (string fileName) {
        ifstream inputFile (fileName);
        int id;
        int d;
        int p;


        if (!inputFile.is_open()) {
            cerr << "Error opening file." << endl;
            exit(1);
        }

        inputFile >> numJobs;

        for (int i = 0; i < numJobs; i++) {
            inputFile >> id >> d >> p;
            jobList.push_back({id, d, p});
        }

        inputFile.close();
    }

    static bool compareWeight (Job job1, Job job2) {
        double w1 = (double) job1.penalty / job1.deadline;
        double w2 = (double) job2.penalty / job2.deadline;
        return w1 > w2;
    }

    static bool comparePenalty (Job job1, Job job2) {
        return job1.penalty > job2.penalty;
    }

    static bool compareDeadline (Job job1, Job job2) {
        return job1.deadline < job2.deadline;
    }

    void sortJobsWeight () {
        sort(jobList.begin(), jobList.end(), compareWeight);
    }

    void sortJobsPenalty () {
        sort(jobList.begin(), jobList.end(), comparePenalty);
    }

    void sortJobsDeadline () {
        sort(jobList.begin(), jobList.end(), compareDeadline);
    }

    void printJobs () {
        for (const auto& job : jobList) {
            cout << job.id << ": " << "Deadline: " << job.deadline << ", Penalty: " << job.penalty << endl;
        }

        cout << endl;
    }
};

#endif