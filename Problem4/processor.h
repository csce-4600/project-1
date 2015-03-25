#ifndef PROCESSOR_H
#define PROCESSOR_H

class processor {

	bool processing;

	public:
		bool is_busy();
		void assign_process(std::vector<process>::iterator &p);

};

#endif 