#include "RoundRobin.h"
#include <iostream>
#include <vector>
#include <fstream>  // Include to handle file operations

int main() {
    std::vector<Process> processes;
    std::ifstream file("dylantest.txt");  // Open the test.txt file
    int id, arrival, burst;

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Read the process data from the file
    while (file >> id >> arrival >> burst) {
        processes.push_back(Process(id, burst, arrival));
    }

    file.close();  // Close the file after reading

    int quantum = 2;  // Quantum time slice

    // Instantiate the RoundRobin scheduler with the processes and quantum
    RoundRobin scheduler(processes, quantum);

    // Run the round-robin scheduling
    scheduler.runRoundRobin();

    return 0;
}
