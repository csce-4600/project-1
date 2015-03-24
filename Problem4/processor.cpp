#include <iostream>
#include <thread>
#include <vector>
#include "process.h"
#include "processor.h"

using namespace std;

bool processor::is_busy() { 

	return processing; 

}

void processor::assign_process(const std::vector<process>::iterator &p) {

	processing = true;
	this_thread::sleep_for(chrono::microseconds(p->cpu_cycles));
	processing= false;

}