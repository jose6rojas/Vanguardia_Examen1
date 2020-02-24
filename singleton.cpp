// Desarrollo de Aplicaciones de Vanguardia - Sección 914
// José Carlos Rojas Herrera - 11541234
// Juego de XO que implementa el patrón de diseño SINGLETON para el tablero

#include <iostream>

using namespace std;

void imprimirTablero(char**); // Imprime el tablero

void liberarTablero(char**); // Libera el espacio de memoria que ocupa el tablero

int seguirJugando(char**, int, int, char); // Lógica del juego de XO

class Singleton {
   static Singleton *instance;
   public:
      char** tablero = NULL;
 
   // Constructor privado para que ningún otro objeto pueda ser creado
   Singleton() {
      tablero = inicializarTablero();
      llenarTablero();
   }

   public:
      static Singleton *getInstance() {
         if (!instance)
            instance = new Singleton;
         return instance;
      }

   public:
      char** inicializarTablero() {
         char** retval = new char*[3];
         for (int i = 0; i < 3; ++i)
         {
            retval[i] = new char[3];
         }
         return retval;
      }

   public:
      void llenarTablero() {
         for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
               tablero[i][j] = ' ';
            }
         }
      }
};

// Se inicializa el puntero en cero para que pueda ser inicializado en la primera llamada a getInstance
Singleton *Singleton::instance = 0;

int main() {
   Singleton *s = NULL;
   s = s -> getInstance();

   char** tablero = s -> tablero;

   int cont = 0;
   int keepPlaying = 0;
   while (keepPlaying == 0) {
      if (cont % 2 == 0) {
         cout << "Turno de X" << endl;
      } else {
         cout << "Turno de O" << endl;
      }

      cout << "Ingrese la coordenada i: ";
      int i;
      cin >> i;
      while (i < 0 || i > 2) {
         cout << "Por favor ingrese una coordenada válida para i: ";
         cin >> i;
      }

      cout << "Ingrese la coordenada j: ";
      int j;
      cin >> j;
      while (j < 0 || j > 2) {
         cout << "Por favor ingrese una coordenada válida para j: ";
         cin >> j;
      }

      if (tablero[i][j] == ' ') {
         if (cont % 2 == 0) {
            // Es el turno de X
            tablero[i][j] = 'X';
            keepPlaying = seguirJugando(tablero, i, j, 'X');
         } else {
            // Es el turno de O
            tablero[i][j] = 'O';
            keepPlaying = seguirJugando(tablero, i, j, 'O');
         }
      } else if (tablero[i][j] == 'X') {
         // do nothing
      } else {
         // do nothing
      }

      imprimirTablero(tablero);

      cont++;
   }

   cont--;
   if (keepPlaying == 1) {
      if (cont % 2 == 0) {
         cout << "¡Ganó X!" << endl;
      } else {
         cout << "¡Ganó O!" << endl;
      }
   }

   liberarTablero(tablero);

   return 0;
}

void imprimirTablero(char** tablero) {
   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
         cout << "[" << tablero[i][j] << "]";
      }
      cout << endl;
   }
}

void liberarTablero(char** tablero) {
   for(int i = 0; i < 3; i++) {
      delete[] tablero[i];
      tablero[i] = NULL;
   }
   delete[] tablero;
}

int seguirJugando(char** tablero, int i, int j, char player) {
   // arriba
   if (i - 1 >= 0) {
      // puedo moverme 1 posición arriba
      if (tablero[i - 1][j] == player) {
         // encontré al jugador una segunda vez
         if (i - 2 >= 0) {
            // puedo moverme 2 posiciones arriba
            if (tablero[i - 2][j] == player) {
               // encontré al jugador una tercera vez, el jugador gana
               return 1;
            }
         }
      }
   }
        
   // abajo
   if (i + 1 <= 2) {
      // puedo moverme 1 posición abajo
      if (tablero[i + 1][j] == player) {
         // encontré al jugador una segunda vez
         if (i + 2 <= 2) {
            // puedo moverme 2 posiciones abajo
            if (tablero[i + 2][j] == player) {
               // encontré al jugador una tercera vez, el jugador gana
               return 1;
            }
         }
      }
   }
   
   // izquierda
   if (j - 1 >= 0) {
      // puedo moverme 1 posición hacia la izquierda
      if (tablero[i][j - 1] == player) {
         // encontré al jugador una segunda vez
         if (j - 2 >= 0) {
            // puedo moverme 2 posiciones hacia la izquierda
            if (tablero[i][j - 2] == player) {
               // encontré al jugador una tercea vez, el jugador gana
               return 1;
            }
         }
      }
   }

   // derecha
   if (j + 1 <= 2) {
      // puedo moverme 1 posición hacia la derecha
      if (tablero[i][j + 1] == player) {
         // encontré al jugador una segunda vez
         if (j + 2 <= 2) {
            // puedo moverme 2 posiciones hacia la derecha
            if (tablero[i][j + 2] == player) {
               // encontré al jugador una tercea vez, el jugador gana
               return 1;
            }
         }
      }
   }

   return 0;
}