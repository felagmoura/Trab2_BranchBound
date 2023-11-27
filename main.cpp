#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "JOBS.h"
#include "GERADOR.h"
#include "GREEDY.h"

using namespace std;

#define NUM_JOBS 20
#define FILE_NAME "JobsTeste_"
#define RANGE 20

int main (int argc, char* argv[]) {
    if (argc == 1) {
        gerarTestes(FILE_NAME, NUM_JOBS, RANGE);
        exit(1);
    }

    Jobs jobs = Jobs (argv[1]);
    
    greedy(jobs);

    return 0;
}
