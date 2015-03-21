#include <iostream>
#include <vector>
#include <algorithm>  
#include "const.h"
#include "process.h"
#include "generator.h"

using namespace std;

// Initialize the process list with values
void init_process_list(vector<process> &p_list) {

    cout << "\n>> Generating process list...";

    generator generate; // Random number generator class
    process p;

    for(int i = 0; i < process_count; i++) {
        p.process_id = i;
        p.cpu_cycles = generate.rand_num_between(cycle_lbound, cycle_ubound);
        p.mem_footprint = generate.rand_num_between(mem_lbound, mem_ubound);
        p_list.push_back(p);
    }

    cout << "Done" << endl;

}

// Initialize processor array
void init_processor_list(int *processor_list) {

    for(int i = 0; i < processor_count; i++)
        processor_list[i] = 0;

}

void print_process_list(vector<process> &p_list) {

    vector<process>::iterator it;

    cout << "\n" << "PID" << "\tBurst Time" << "\tMemory Footprint" << "\n" << endl;

    for(it = p_list.begin(); it != p_list.end(); it++)
        cout << it->process_id << "\t" << it->cpu_cycles << "\t\t" << it->mem_footprint << endl;

}

bool compare_cycles(const process &lhs, const process &rhs) { 
    return lhs.cpu_cycles < rhs.cpu_cycles;  
}

void schedule_processes(vector<process> &p_list, int *processor) {

    // Sort process list by cpu cycles in the ascending order (SJF)
    sort(p_list.begin(), p_list.end(), compare_cycles);

    do{
        cout << "\nScheduling PID: " << p_list.begin()->process_id << endl;
        // Assign process here
        p_list.erase(p_list.begin());
    } while(p_list.size() != 0);

}

int main() {

    vector<process> process_list;
    int cpu[processor_count];

    init_process_list(process_list);
    init_processor_list(cpu);

    // print_process_list(process_list);
    
    schedule_processes(process_list, cpu);

}