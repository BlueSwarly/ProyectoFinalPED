#include <iostream>
#include <string>
using namespace std;

struct Jugador
{
    string Nombre;
    string Carnet;
    int jugada;
    bool eliminar;
    Jugador *sig;
};

void insertarJugador( Jugador*&tail, string carnet, string nombre)
{
    Jugador *nuevo = new Jugador();
    nuevo->Nombre = nombre;
    nuevo->Carnet = carnet;
    if (tail == nullptr)
    {
        tail = nuevo;
        nuevo->sig = nuevo;
    }
    else
    {
        nuevo->sig = tail->sig;
        tail->sig = nuevo;
        tail = nuevo; // nuevo se vuelve el último
    }
}

void mostrar(Jugador *tail)
{
    if (tail == nullptr)
    {
        cout << endl;
        cout << "No hay jugadores en la partida" << endl;
        return;
    }

    Jugador *head = tail->sig;
    Jugador *aux = head;
    
        cout << endl;
        cout << "--LISTA DE JUGADORES--" << endl;
    do
    {
        cout << "Nombre: " << aux->Nombre << endl;
        cout << "Carnet: " << aux->Carnet << endl;
        cout << "-----------------------" << endl;
        aux = aux->sig;
    } while (aux != head);
    cout << endl;
}


void Creditos(Jugador *tail)
{
    cout << endl;
    cout << "ADRIAN EMANUEL ESCOBAR AVILES. "
        << "RODRIGO JOSE VILLEDA RODEZNO. "
        << "MANUEL TOBAR GARCIA. " << endl;
}

void tutorial(Jugador *tail)
{
    cout << endl;
    cout << " Este es un juego super intuitivo a la hora de juegar"
    <<" Despues de haber ingresado a los jugadores seleccionamos la opcion 1"
   << "para darle inicio al juego de pierda, papel o tijera y durante la partida"
   << "puede haber dos 'un empate entre todos los juegadores' o la victoria de un jugador" 
   << " al ganar un jugador recibe +3 puntos y si empatan o pierden no reciben puntos "
   << " puedes ver quienes son los que mas han puntuado en el menu principal." << endl;
}
