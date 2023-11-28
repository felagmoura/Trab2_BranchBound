#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue>
#include <bits/stdc++.h>
#include "JOBS.h"

using namespace std; 

#ifndef BB_H
#define BB_H


    static int maxPenalty;
    static int UpperBound;
    static Jobs bestJobSet;
    
    struct Node {
        Node* parent;
        list<Node*> filhos;
        Jobs jobSet;
        int upperBoundSet;
        int costSet;

        Node () {
            parent = NULL;
            filhos = {};
            jobSet = {};
            upperBoundSet = maxPenalty;
            costSet = 0;
        }
    };

    int calcPenalty (Jobs jobSet) {
        int sumPenalty = 0;

        for (int i = 0; i < jobSet.numJobs; i++) {
            sumPenalty += jobSet.jobList[i].penalty;
        }

        return sumPenalty;
    }

    int calccostSet (Jobs jobs, Jobs jobSet, Job job) {
        int cost = 0;
        vector<Job> temp = jobs.jobList;

        for (int i = 0; i < jobSet.numJobs; i++) 
            temp.erase (temp.begin() + jobSet.jobList[i].id);

        for (int i = 0; i < job.id; i++) 
                cost += temp[i].penalty;

        return cost;
    }

    Node* newNode (Node* parent, Jobs jobs, Job job) {
        Node* node = new Node;
 
        node->parent = parent;
        node->filhos = {};

        node->jobSet = parent->jobSet;

        node->jobSet.jobList.push_back(job);
        node->jobSet.numJobs++;

        node->costSet = calccostSet (jobs, node->jobSet, job);
        node->upperBoundSet -= job.penalty;
        
        return node;
    }

    bool prune (int costSet) {
        return costSet > UpperBound;
    }

    

    void scheduler (Jobs jobs, Node* parent, int index) {
        Node* node;

        while (index < jobs.numJobs) {
            node = newNode (parent, jobs, jobs.jobList[index++]);
            parent->filhos.push_back(node);
            if (node->upperBoundSet < UpperBound) {
                UpperBound = node->upperBoundSet;
                bestJobSet = node->jobSet;
            }
        }


        while (!parent->filhos.empty()) {
            node = parent->filhos.front();
            parent->filhos.pop_front();

            if (!prune (node->costSet))
                scheduler (jobs, node, 0);
        }
    }

    void bb (Jobs jobs) {
        maxPenalty = calcPenalty(jobs);
        UpperBound = maxPenalty;

        Node* root = newNode (NULL, jobs, {});

        scheduler (jobs, root, 0);

        bestJobSet.printJobs();
    }


#endif