// Desarrollo de Aplicaciones de Vanguardia - Sección 914
// José Carlos Rojas Herrera - 11541234

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Packing {
	public:
		virtual string pack() = 0;

		virtual ~Packing() {}
};

class Item {
	public:
		// Item() {};

		virtual string name() = 0;
		virtual Packing* packing() = 0;
		virtual float price() = 0;

		virtual ~Item() = default;
};

class Wrapper : public Packing {
	public:
		string pack() { return "Wrapper"; }

		~Wrapper() {}
};

class Bottle : public Packing {
	public:
		string pack() { return "Bottle"; }

		~Bottle() {}
};

class Burger : public Item {
	public:
		// Burger() {};

		Packing* packing() { return new Wrapper; }

		virtual float price();

		// virtual string name();

		virtual ~Burger() {};
};

class ColdDrink : public Item {
	public:
		// ColdDrink() {};

		Packing* packing() { return new Bottle; }

		virtual float price();

		// virtual string name();

		virtual ~ColdDrink() {};
};

class VegBurger : public Burger {
	public:
		// VegBurger() {};

		float price() { return 25.0; }
		string name() { return "Veg Burger"; }

		~VegBurger() {}
};

class ChickenBurger : public Burger {
	public:
		// ChickenBurger() {};

		float price() { return 50.5; }
		string name() { return "Chicken Burger"; }

		~ChickenBurger() {}
};

class Coke : public ColdDrink {
	public:
		// Coke() {};

		float price() { return 30.0; }
		string name() { return "Coke"; }

		~Coke() {}
};

class Pepsi : public ColdDrink {
	public:
		// Pepsi() {};

		float price() { return 35.0; }
		string name() { return "Pepsi"; }

		~Pepsi() {}
};

class Meal {
	private:
		vector<Item*> items;

	public:
		// Meal() {};

		void addItem(Item* item) { items.push_back(item); }

		float getCost() {
			float cost = 0.0;
			for (int i = 0; i < items.size(); i++)
				cost += items[i] -> price();
			return cost;
		}

		void showItems() {
			for (int i = 0; i < items.size(); i++)
				cout << "Item: " << items[i] -> name() << ", Packing: " << items[i] -> packing() -> pack() << ", Price: " << items[i] -> price();
		}
};

class MealBuilder {
	public:
		Meal* prepareVegMeal() {
			Meal* meal = new Meal;
			meal -> addItem(new VegBurger());
			meal -> addItem(new Coke());
			return meal;
		}

		Meal* prepareNonVegMeal() {
			Meal* meal = new Meal;
			meal -> addItem(new ChickenBurger());
			meal -> addItem(new Pepsi());
			return meal;
		}
};

int main() {
	MealBuilder* mealBuilder = new MealBuilder;

	Meal* vegMeal = mealBuilder -> prepareVegMeal();
	/* cout << "Veg Meal" << endl;
	vegMeal -> showItems();
	cout << "Total cost: " << vegMeal -> getCost() << endl; */

	/* Limpia el vector de Items de VegMeal
	for(int i = 0; i < vegMeal -> items.size(); i++)
		delete vegMeal -> items[i];
	vegMeal -> items.clear(); */

	return 0;
}