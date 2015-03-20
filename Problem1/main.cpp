#include <iostream>
#include <list>
#include "const.h"
#include "process.h"
#include "generator.h"

using namespace std;

// Initialize the process list with values
void init_process_list(list<process> &p_list) {

    generator generate; // Random number generator class
    process p;

    for(int i = 0; i < process_count; i++) {
        p.process_id = i;
        p.cpu_cycles = generate.rand_num_between(cycle_lbound, cycle_ubound);
        p.mem_footprint = generate.rand_num_between(mem_lbound, mem_ubound);
        p_list.push_back(p);
    }

}

// Initialize processor array
void init_processor_list(int *processor_list) {

    for(int i = 0; i < processor_count; i++)
        processor_list[i] = 0;

}

void print_process_list(list<process> &p_list) {

    list<process>::iterator it;

    cout << "\n" << "PID" << "\tBurst Time" << "\tMemory Footprint" << "\n" << endl;

    for(it = p_list.begin(); it != p_list.end(); it++)
        cout << it->process_id << "\t" << it->cpu_cycles << "\t\t" << it->mem_footprint << endl;

}

int main() {

    list<process> process_list;
    int cpu[processor_count];

    init_process_list(process_list);
    init_processor_list(cpu);
    print_process_list(process_list);

}