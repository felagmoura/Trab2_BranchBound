#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;


#ifndef GERADOR_H
#define GERADOR_H

void gerarTestes (string fileName, int numJobs, int range) {
    srand((unsigned) time(NULL));
    
    ofstream ArqJobs (fileName + to_string(numJobs) + ".txt");
    int deadline, penalty;

    ArqJobs << numJobs << endl;

    for (int i = 0; i < numJobs; i++) {
        deadline = rand() % range + 1;
        penalty = rand() % range + 1;
        ArqJobs << i << " " << deadline << " " << penalty << endl;
    }
    
    ArqJobs.close();
}


#endif