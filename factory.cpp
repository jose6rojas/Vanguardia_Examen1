// Desarrollo de Aplicaciones de Vanguardia - Sección 914
// José Carlos Rojas Herrera - 11541234
// CRUD que implementa el patrón de diseño FACTORY para la creación de armas 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon {
	protected:
		string name;
		int magSize;
		// string rarity;

	public:
		// name
		void setName(string name) { this -> name = name; }
		string getName() { return name; }

		// magSize
		void setMagSize(int magSize) { this -> magSize = magSize; }
		int getMagSize() { return magSize; }

		/* rarity
		void setRarity(string rarity) { this -> rarity = rarity; }
		string getRarity() { return rarity; } */

		virtual int getDamage() = 0;

		virtual ~Weapon() {}
};

class SMG : public Weapon {
	public:
		int getDamage() { return 12; } // R-99 base damage 
		~SMG() {}
};

class Sniper : public Weapon {
	public:
		int getDamage() { return 55; } // Longbow DMR base damage
		~Sniper() {}
};

class AssaultRifle : public Weapon {
	public:
		int getDamage() { return 14; } // R-301 Carbine base damage
		~AssaultRifle() {}
};

class Shotgun : public Weapon {
	public:
		int getDamage() { return 10; } // Peacekeeper base damage
		~Shotgun() {}
};

class WeaponFactory {
	public:
		static Weapon *getWeapon(int type) {
			if (type == 1) {
				SMG *smg = new SMG;
				return smg;
			} else if (type == 2) {
				Sniper *sniper = new Sniper;
				return sniper;
			} else if (type == 3) {
				AssaultRifle *assaultRifle = new AssaultRifle;
				return assaultRifle;
			} else if (type == 4) {
				Shotgun *shotgun = new Shotgun;
				return shotgun;
			} else {
				return NULL; 
			}
		} 
};

int main() {
	WeaponFactory *weaponFactory = new WeaponFactory;

	vector<Weapon*> armamento;

	string menuPrincipal = "MENÚ\n"
		"1. Agregar arma\n"
		"2. Modificar arma\n"
		"3. Listar armas\n"
		"4. Eliminar arma\n"
		"5. Mostrar daño\n"
		"6. Salir\n"
		"Escoja una opción: ";

	int opPrincipal = 0;
	while (opPrincipal != 6) {
		cout << menuPrincipal;

		cin >> opPrincipal;
		while (opPrincipal < 1 || opPrincipal > 7) {
			// cout << menuPrincipal;
			cout << "Por favor ingrese una opción válida: ";
			cin >> opPrincipal;
		}

		if (opPrincipal == 1) {
			cout << endl;
			string name;
			cout << "Ingrese el nombre de su arma: ";
			cin >> name;

			int magSize;
			cout << "Ingrese la cantidad de municiones en un cartucho: ";
			cin >> magSize;
			while (magSize <= 0 || magSize > 40) {
				cout << "Ingrese una cantidad válida [> 0 y <= 40]: ";
				cin >> magSize;
			}

			string menuOp1 = "TIPO\n"
				"1. Submachine Gun (SMG)\n"
				"2. Sniper\n"
				"3. Assault Rifle\n"
				"4. Shotgun\n"
				"5. Regresar al menú principal\n"
				"Escoja una opción: ";
			cout << menuOp1;

			int op1;
			cin >> op1;
			while (op1 < 1 || op1 > 6) {
				cout << "Por favor ingrese una opción válida: ";
				cin >> op1;
			}

			// SMG
			if (op1 == 1) {
				Weapon *weapon = weaponFactory -> getWeapon(1);

				weapon -> setName(name);
				weapon -> setMagSize(magSize);

				armamento.push_back(weapon);
				cout << "La SMG fue agregada correctamente." << endl << endl;
			// Sniper
			} else if (op1 == 2) {
				Weapon *weapon = weaponFactory -> getWeapon(2);

				weapon -> setName(name);
				weapon -> setMagSize(magSize);

				armamento.push_back(weapon);
				cout << "La Sniper fue agregada correctamente." << endl << endl;
			// Assault Rifle
			} else if (op1 == 3) {
				Weapon *weapon = weaponFactory -> getWeapon(3);

				weapon -> setName(name);
				weapon -> setMagSize(magSize);

				armamento.push_back(weapon);
				cout << "La Assault Rifle fue agregada correctamente." << endl << endl;
			// Shotgun
			} else if (op1 == 4) {
				Weapon *weapon = weaponFactory -> getWeapon(4);

				weapon -> setName(name);
				weapon -> setMagSize(magSize);

				armamento.push_back(weapon);
				cout << "La Shotgun fue agregada correctamente." << endl << endl;
			} else if (op1 == 5) {
				// Regresar al menú principal
			} else { /* do nothing */ }
		} else if (opPrincipal == 2) {
			cout << endl << "Me dio pereza hacerlo ingeniero. :(" << endl << endl;
		} else if (opPrincipal == 3) {
			cout << endl << "ARMAMENTO" << endl;
			for (int i = 0; i < armamento.size(); ++i)
			{
				cout << "(" << i << ")" << endl;
				cout << "Nombre: " << armamento[i] -> getName() << endl;
				cout << "Municiones por cartucho: " << armamento[i] -> getMagSize() << endl;
			}
			cout << endl;
		} else if (opPrincipal == 4) {
			cout << endl;
			if (!armamento.empty()) {
				int op4;
				cout << "Ingrese el índice de la arma: ";
				cin >> op4;
				while (op4 < 0 || op4 >= armamento.size()) {
					cout << "Ingrese un índice válido: ";
					cin >> op4;
				}
				armamento.erase(armamento.begin() + (op4 - 1));
				cout << "El arma fue eliminada correctamente." << endl;
			} else {
				cout << "El armamento está vacío." << endl;
			}
			cout << endl;
		} else if (opPrincipal == 5) {
			cout << endl;
			if (!armamento.empty()) {
				int op5;
				cout << "Ingrese el índice de la arma: ";
				cin >> op5;
				while (op5 < 0 || op5 >= armamento.size()) {
					cout << "Ingrese un índice válido: ";
					cin >> op5;
				}
				cout << "Nombre: " << armamento[op5] -> getName() << ", Daño: " << armamento[op5] -> getDamage() << endl;
			} else {
				cout << "El armamento está vacío." << endl;
			}
			cout << endl;
		} else if (opPrincipal == 6) {
			// Salir
		} else { /* do nothing */ }

	}

	// Limpia el vector de Weapons
	for(int i = 0; i < armamento.size(); i++)
		delete armamento[i];
	armamento.clear();

	// Weapon *weapon = weaponFactory -> getWeapon(2);

	// cout << weapon -> getDamage() << endl;

	return 0;
}