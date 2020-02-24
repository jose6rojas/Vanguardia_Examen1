#include "Subject.h"

// state
void Subject::setState(int state) { this->state = state; }
int Subject::getState() { return state; }

void Subject::attach(Observer* observer) { observers.push_back(observer); }

void Subject::notifyAllObservers()
{
	for (int i = 0; i < observers.size(); i++)
		observers[0]->update();
}