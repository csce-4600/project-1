#include <iostream>
#include "const.h"
#include "process.h"
#include "generator.h"

using namespace std;

// Initialize the process list with values
void init_process_list(PROCESS *process_list) {

    generator generate;

    for(int i = 0; i < process_count; i++) {
        process_list[i].process_id = i;
        process_list[i].cpu_cycles = generate.rand_num_between(cycle_lbound, cycle_ubound);
        process_list[i].mem_footprint = generate.rand_num_between(mem_lbound, mem_ubound);
    }

}

void init_processor_list(int *processor_list) {

    for(int i = 0; i < processor_count; i++)
        processor_list[i] = 0;

}

void print_process_list(PROCESS *process_list) {

    cout << "\n" << "PID" << "\tBurst Time" << "\tMemory Footprint" << "\n" << endl;

    for(int i = 0; i < process_count; i++) {
        cout << process_list[i].process_id << "\t" << process_list[i].cpu_cycles << "\t\t" << process_list[i].mem_footprint << endl;
    }

}

int main() {

    PROCESS processes[process_count];
    int cpu[processor_count];

    init_process_list(processes);
    init_processor_list(cpu);
    print_process_list(processes);

}