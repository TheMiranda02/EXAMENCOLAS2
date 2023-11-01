#include <iostream>
#include <string>
#include <cstdlib> 
#define MaxTamc 10 //CAPACIDAD DE COLA PARA LA 1

using namespace std;

//COLA2
struct Nodo {
    string Animales;
    Nodo* siguiente;
};

//FUNCIONES PARA LA COLA 1
void menu2();

// FUNCIONES PARA LA COLA 2
void menu();
void Insertarcola(Nodo*&, Nodo*&, string);
bool cola_vacia(Nodo*);
void suprimircola(Nodo*&, Nodo*&, string&);

typedef float TipoDato;

int main() {
    int po;
    cout << "EXAMEN ESTRUCTURA DE DATOS ";

    cout << "\n1.- COLA 1" << endl;
    cout << "\n2.- COLA 2" << endl;
    cout << "\n3.- Salir " << endl;
    cout << endl;
    cout << "Digita una opcion: "; cin >> po;

    switch (po) {
    case 1:
        menu2();
        break;
    case 2:
        menu();
        break;
    }
    return 0;
}

void menu2() {
    int up;
    do {
        cout << "NUMEROS FLOAT " << endl;
        cout << "\n1.- AGREGA FLOAT ";
        cout << "\n2.- Salir";
        cout << "Digita una opcion: "; cin >> up;
        switch (up) {
        case 1:
            int frente = 0, final = 0;
            TipoDato A[MaxTamc];
            int contador = 0;
            char respuesta;
            cout << "¿Desea agregar un elemento float a la cola? (s/n)";
            cin >> respuesta;
            while ((respuesta == 's' || respuesta == 'n') && contador < 10) {
                if ((final + 1) % MaxTamc == frente) {
                    cout << "Desbordamiento de la cola " << endl;
                    return;
                }
                cout << "Ingrese un elemento de la cola tipo float: ";
                TipoDato elementos;
                cin >> elementos;
                final = (final + 1) % MaxTamc;
                A[final] = elementos;
                contador++;
                cout << "Elemento " << contador << " agregado a la cola: " << elementos << endl;
                if (contador < 10) {
                    cout << "¿Desea agregar otro float a la cola? (s/n) ";
                    cin >> respuesta;
                }
            }
            break;
        }
    } while (up != 2);
}

//ESTE LE PERTENECE A COLA 2
void menu() {
    int op, i = 0;
    string Animal;
    Nodo* frente = NULL;
    Nodo* final = NULL;

    do {
        cout << "\t MENU \n ";
        cout << " 1.- Insertar un Animalito" << endl;
        cout << " 2.- Mostrar los Animalitos de la cola" << endl;
        cout << " 3.- Salir" << endl;
        cout << "Digite una opcion: "; cin >> op;

        switch (op) {
        case 1:
            cout << "\nIngrese un Animalito para la cola: (SOLO 10)" << endl;
            cout << "Después de los 10, digita la OPCION 2:" << endl;
            for (i = 0; i < 10; i++) {
                cout << "ANIMAL [" << i + 1 << "]"; cin >> Animal;
                Insertarcola(frente, final, Animal);
            }
            break;
        case 2:
            cout << "Mostrando los elementos de la cola: ";
            Nodo* actual = frente;
            while (actual != NULL) {
                cout << actual->Animales << "\t   " << endl;
                actual = actual->siguiente;
            }
            cout << "\n";
            system("pause");
            break;
        }
        system("cls");
    } while (op != 3);
}

// Función para insertar elementos a la cola
void Insertarcola(Nodo*& frente, Nodo*& final, string n) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->Animales = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)) {
        frente = nuevo_nodo;
    }
    else {
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;
}

// Función para comprobar si la cola está vacía
bool cola_vacia(Nodo* frente) {
    return (frente == NULL);
}

// Función para eliminar elementos de la cola
void suprimircola(Nodo*& frente, Nodo*& final, string& n) {
    n = frente->Animales;
    Nodo* aux = frente;

    if (frente == final) {
        frente = NULL;
        final = NULL;
    }
    else {
        frente = frente->siguiente;
    }
    delete aux;
}
