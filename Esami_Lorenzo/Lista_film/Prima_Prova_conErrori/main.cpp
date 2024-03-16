#include <iostream>
#include <fstream>
#include "List.h"
#define DIM 9

using namespace std;

int main(){
    ifstream in("film.txt");

    List lista;

    for(int i=0; i<DIM; i++){
        string temp;
        getline(in, temp);
        string nome = "";
        for(int j=0; j<temp.length()- 2; j++){
            nome += temp[j];
        }


        getline(in, temp);
        string genere = "";
        for(int j=0; j<temp.length() - 2; j++){
            genere += temp[j];
        }

        getline(in, temp);
        string data = "";
        for(int j=0; j<temp.length()-2; j++){
            data += temp;
        }
        lista.insertInOrder(data, nome, genere);
    }

    cout << lista << endl;

    lista.film_piu_nuovo();

    lista.film_piu_vecchio();

    cout << endl;

    lista.film_dato_un_genere("FANTASY");
    lista.film_dato_un_genere("COMMEDIA");
    lista.film_dato_un_genere("MUSICAL");
    lista.film_dato_un_genere("HORROR");
    lista.film_dato_un_genere("DRAMATIC");
    lista.film_dato_un_genere("ANIME");
    lista.film_dato_un_genere("THRILLER");
    lista.film_dato_un_genere("ACTION");   
}