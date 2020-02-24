#include <iostream>
#include <vector>
#include <bitset>
#include "Observer.h"
#include "Subject.h"

using namespace std;

/* class Subject
{
	private:
		vector<Observer*> observers;
		int state;

	public:
		// state
		void setState(int state) { this->state = state; }
		int getState() { return state; }

		void attach(Observer* observer) { observers.push_back(observer); }

		void notifyAllObservers()
		{
			for (int i = 0; i < observers.size(); i++)
				observers[0]->update();
		}
};

class Observer
{
	protected:
		Subject* subject;

	public:
		virtual void update() = 0;

		virtual ~Observer() {}
}; */

class BinaryObserver : public Observer
{
	public:
		BinaryObserver(Subject* subject)
		{
			this->subject = subject;
			this->subject->attach(this);
		}

		void update()
		{
			cout << "Binary string: " << bitset<64>(subject->getState()).to_string() << endl;
		}

		~BinaryObserver() {}
};

class OctalObserver : public Observer
{
	public:
		OctalObserver(Subject* subject)
		{
			this->subject = subject;
			this->subject->attach(this);
		}

		void update()
		{
			cout << "Octal string: " << oct << subject->getState() << endl;
		}

		~OctalObserver() {}
};

class HexaObserver : public Observer
{
	public:
		HexaObserver(Subject* subject)
		{
			this->subject = subject;
			this->subject->attach(this);
		}

		void update()
		{
			cout << "Hexa string: " << hex << subject->getState() << endl;
		}

		~HexaObserver() {}
};

int main()
{
	cout << "hola" << endl;

	return 0;
}