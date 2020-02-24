// #include "Observer.h"
#include <vector>

using namespace std;

#ifndef SUBJECT_H
#define SUBJECT_H

class Subject
{
	private:
		vector<Observer*> observers;
		int state;

	public:
		// state
		void setState(int);
		int getState();

		void attach(Observer*);

		void notifyAllObservers();
};

#endif