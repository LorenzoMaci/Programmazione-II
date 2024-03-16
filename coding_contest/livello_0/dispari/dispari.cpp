/*In matematica, ogni numero intero è pari oppure dispari: un numero è pari se è multiplo di 2, altrimenti è dispari. 
La caratterizzazione di un intero relativa all'essere pari o dispari si dice parità . Essa equivale all'appartenenza ad una delle due classe di 
resti modulo 2: dato un intero x, x mod(2)=0 per gli interi pari, x mod(2)=1 per i dispari.

Specifiche
Si realizzi un programma che, presa in input una sequenza di N numeri interi, sia in grado di individuare tutti gli elementi dispari della sequenza .

Dati in input
Il file di input contiene 100 task, uno per ogni riga. Ogni riga del file di input è formata da N+1 elementi. Il primo elemento rappresenta il numero N. 
Seguono gli N elementi della sequenza.

Dati in output
L'output dovrà essere formato da 100 righe, una per ogni task. Ogni riga contiene solo i numeri dispari appartenenti alla sequenza di input, nell'ordine in cui 
appaiono in input.

Note
Il valore di N è sempre compreso tra 1 e 1000.
I numeri contenuti all'interno dell'array sono sempre interi compresi tra 1 e 1000.
Un determinato valore può essere presente più volte all'interno della sequenza.*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void dispari(int arr[], int n, ostream& out){
    for(int i=0; i<n; i++){
        if(arr[i] % 2 == 1){
            out << arr[i] << " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        int* arr = new int[n];
        for(int j=0; j<n; j++){
            in >> arr[j];
        }
        dispari(arr, n, out);
        delete [] arr;
    }

}