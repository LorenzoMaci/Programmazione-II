#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
/*void bubbleSort(T*arr, int n) {
    bool scambio = true;
    int appoggio;
    while (scambio) {
        scambio = false;
        for (int i=0; i<n; i++) {
        if (arr[i] > arr[i + 1]) {
            appoggio = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = appoggio;
            scambio = true;
        }
      }
    }
}*/

void selectionSort(T array[], int n) {
	int indexMin;
	
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		
		swap(array[i], array[indexMin]);
	}
}

template <typename T>
void selectionSort(T array[], T arrayDue[], int n) {
	int indexMin;
    
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		swap(array[i], array[indexMin]);
        swap(arrayDue[i], arrayDue[indexMin]);
	}
}

template <typename T>
struct Nodo {
    T valore;
    Nodo<T> *succ;
};

template <typename T>
class Lista {
    private :
    Nodo<T> *testa;

    public :
    Lista() : testa(nullptr) {}

     Nodo<T>* search(T indice) {
	 Nodo<T>* p;
	 for (p=this->testa; p!=NULL; p=p->succ)
		if (p->valore==indice)
			return p;
	 return NULL;
    }

    void insert(T val) {
        /*Nodo<T> *nuovo = new Nodo<T>;
        nuovo -> valore = val;
        nuovo -> succ = this -> testa;
        this -> testa = nuovo;*/

        Nodo<T> *nuovo = new Nodo<T>;
    nuovo -> valore = val;
    nuovo -> succ = nullptr;

    Nodo<T> *iter = this -> testa;
    if (iter == nullptr) {
        this -> testa = nuovo;
    }
    else {
        while (iter -> succ != nullptr) {
            iter = iter -> succ;
        }
        iter -> succ = nuovo;
    }
    }

    Nodo<T> *getTesta() {return testa;}

    void print() {
        Nodo<T> *iter = getTesta();
        while (iter != nullptr) {
            cout << iter -> valore << "-->";
            iter = iter -> succ;
        }
        cout << "NULL" << endl;
    }
};

template <typename T>
class LGraph {
    int len;
    int n; 
    int m;

    T **Lpunta;
    Lista<int> **Adj;

    int findIndex(T x) {
        for (int i=0; i<n; i++) 
            if (*Lpunta[i] == x) return i;
            return - 1;
    } 

    public :
    LGraph(int len) {
        this -> len = len;
        n = m = 0;
        Lpunta = new T*[len];
        for (int i=0; i<len; i++) {
            Lpunta[i] = NULL;
        }
        Adj = new Lista<int>*[len];
        for (int i=0; i<len; i++) {
            Adj[i] = new Lista<int>();
        }
    }

    LGraph<T>* addNode(T k) {
        if (n == len) return this;
        if (findIndex(k) >= 0) return this;
        Lpunta[n] = new T(k);
        n++;
        return this;
    }

    LGraph<T>* addEdge(T x, T y) {
        int i = findIndex(x);
        int j = findIndex(y);
        if (i < 0 || j < 0) return this;
        if (!Adj[i] -> search(j)) {
            Adj[i] -> insert(j);
            m++;
        }
        return this;
    }

    void print (ostream& out) {
        for (int i=0; i<n; i++) {
            out << "(" << *Lpunta[i];
            Nodo<int>* iter =&(*Adj[i]->getTesta());
            //Nodo<T> *iter = Adj[i] -> getTesta();
            for(int c=0; iter!=NULL; iter=iter->succ, c++){
            //for (; iter != NULL; iter = iter -> succ) {
                out << " " << *Lpunta[iter -> valore];
            }
            out << ") ";
        }
        out << endl;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

int nodo;
int arco;
string tipo;
    for (int i=0; i<100; i++) {
        in >> nodo;
        cout << "N Nodi : " << nodo << endl;
        in >> arco;
        cout << "N Archi : " << arco << endl;
        in >> tipo;
        cout << "Tipo : " << tipo << endl;
      if (tipo == "int") {
        Lista<int> l;
        LGraph<int> G(nodo);
        int *nodi = new int [nodo];
        for (int j=0; j<nodo; j++) {
            in >> nodi[j];
        }
        selectionSort(nodi, nodo);
        for (int h = 0; h<nodo; h++) {
            l.insert(nodi[h]);
            G.addNode(nodi[h]);
            cout << nodi[h] << " ";
        }
        cout << endl;
        l.print();
        string *valori = new string[arco *2];
        for (int z=0; z<arco * 2; z++) {
            in >> valori[z];
            cout << valori[z] << " ";
        }
        int *archiUno = new int [arco];
        int *archiDue = new int [arco];
        cout << endl;
        int r = 0;
        int c = 0;
        for (int x=0; x<arco*2; x++) {
            string tmp;
            string tmpUno;
            if (x % 2 == 0) {
            for (int m=1; m!=valori[x].size(); m++) {
                tmp += valori[x][m];
            }archiUno[r] = stod(tmp);
            cout << archiUno[r] << " ";
            r++;
            }
            else {
                for (int m=0; m != valori[x].size(); m++) {
                    tmpUno += valori[x][m];
                }
            archiDue[c] = stod(tmpUno);
            cout << archiDue[c] << " ";
            c++;
            }
            tmp = " ";
            tmpUno = " ";
        }
        cout << endl;
        selectionSort(archiDue, archiUno, arco);
        for (int s=0; s<arco; s++) {
            cout << archiUno[s] << " " << archiDue[s] << endl;
                G.addEdge(archiUno[s], archiDue[s]);
            }
         G.print(out);
      }
      else if (tipo == "char") {
        Lista<char> l;
        LGraph<char> G(nodo);
        char *nodi = new char [nodo];
        for (int j=0; j<nodo; j++) {
            in >> nodi[j];
            cout << nodi[j] << " ";
        }
        cout << endl;
        selectionSort(nodi, nodo);
        for (int h = 0; h<nodo; h++) {
            l.insert(nodi[h]);
            G.addNode(nodi[h]);
            cout << nodi[h] << " ";
        }
        cout << endl;
        l.print();
        string *valori = new string[arco*2];
        for (int z=0; z<arco*2; z++) {
            in >> valori[z];
            cout << valori[z] << " ";
        }
        char *archiUno = new char [arco];
        char *archiDue = new char [arco];
        cout << endl;
        int r = 0;
        int c = 0;
        for (int x=0; x<arco*2; x++) {
            if (x % 2 == 0) {
            archiUno[r] = valori[x][1];
            cout << archiUno[r] << " ";
            r++;
            }
            else {
                archiDue[c] = valori[x][0];
                cout << archiDue[c] << " ";
                c++;
            }
        }
        cout << endl;
        selectionSort(archiDue, archiUno, arco);
        for (int s=0; s<arco; s++) {
            cout << archiUno[s] << " " << archiDue[s] << endl;
                G.addEdge(archiUno[s], archiDue[s]);
            }
         G.print(out);
      }
      else {
        Lista<double> l;
        LGraph<double> G(nodo);
        double *nodi = new double [nodo];
        for (int j=0; j<nodo; j++) {
            in >> nodi[j];
        }
        selectionSort(nodi, nodo);
        for (int h = 0; h<nodo; h++) {
            l.insert(nodi[h]);
            G.addNode(nodi[h]);
            cout << nodi[h] << " ";
        }
        cout << endl;
        l.print();
        string *valori = new string[arco *2];
        for (int z=0; z<arco * 2; z++) {
            in >> valori[z];
            cout << valori[z] << " ";
        }
        double *archiUno = new double [arco];
        double *archiDue = new double [arco];
        cout << endl;
        int r = 0;
        int c = 0;
        for (int x=0; x<arco*2; x++) {
            string tmp;
            string tmpUno;
            if (x % 2 == 0) {
            for (int m=1; m!=valori[x].size(); m++) {
                tmp += valori[x][m];
            }archiUno[r] = stod(tmp);
            cout << archiUno[r] << " ";
            r++;
            }
            else {
                for (int m=0; m != valori[x].size(); m++) {
                    tmpUno += valori[x][m];
                }
            archiDue[c] = stod(tmpUno);
            cout << archiDue[c] << " ";
            c++;
            }
            tmp = " ";
            tmpUno = " ";
        }
        cout << endl;
        selectionSort(archiDue, archiUno, arco);
        for (int s=0; s<arco; s++) {
            cout << archiUno[s] << " " << archiDue[s] << endl;
                G.addEdge(archiUno[s], archiDue[s]);
            }
         G.print(out);
      }
    }
}