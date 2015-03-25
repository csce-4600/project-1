#include <iostream>
#include <vector>
#include <algorithm> 
#include <future> 
#include "const.h"
#include "process.h"
#include "processor.h"
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

bool compare_cycles(const process &lhs, const process &rhs) { 
    return lhs.cpu_cycles < rhs.cpu_cycles;  
}

void schedule_processes(vector<process> &p_list, processor *p_core) {

    vector<process>::iterator current_process;

    do{

        for (int i = 0; i < processor_count; i++) {

            current_process = p_list.begin();

            // Check which processors are available
            if (!p_core[i].is_busy()) {

                cout << "\nScheduling PID: " << current_process->process_id << " with " << current_process->cpu_cycles << " cycles on processor " << i << endl;
                std::async(std::launch::async, &processor::assign_process, p_core[i], current_process);
                p_list.erase(current_process);   

            }

            if (i == 5) i = 0;

        }

    } while(p_list.size() != 0);

}

int main() {

    vector<process> process_list;
    processor processor_core[processor_count];

    init_process_list(process_list);
    schedule_processes(process_list, processor_core);

}