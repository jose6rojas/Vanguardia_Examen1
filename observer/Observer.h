#include "Subject.h"

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
	protected:
		Subject* subject;

	public:
		virtual void update() = 0;

		virtual ~Observer();
};

#endif