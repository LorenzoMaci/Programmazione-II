#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MAX_SIZE 200

template<typename H>
class StaticQueue {
	
	H* array;
	int size = 0;
	int maxSize = MAX_SIZE;
	
	int head = -1;
	int tail = -1;
	
	public:
	
	StaticQueue(int maxSize = MAX_SIZE) :  maxSize(maxSize) {
		this->array = new H[maxSize];
	}
	
	void enqueue(H val) {
		if(size == maxSize){
			return;
		}
		if(head == -1){
			head = 0;
        }
		tail = (++tail % maxSize);
		array[tail] = val;
		size++;
	}

    H dequeue() {
		H val = array[head];
		head = (++head % maxSize);
		size--;
		return val;
	}
	
	void Print_queue(StaticQueue<H>& queue, ostream& out) {
		for(int i=queue.head, count=0; count<queue.size; count++) {
			out << queue.array[i] << " ";
			i = (i+1) % queue.maxSize;
		}
		out << endl;
	}
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string* vett = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        if(tipo == "int"){
            StaticQueue<int> ss(n);
            for(int i = 0; i<n; i++){
                //Enqueue
                if(vett[i][0] == 'i'){
                    int l = vett[i].length();
                    string tmp = "";
                    for(int j = 1; j<l; j++){
                        tmp += vett[i][j];
                    }
                    int key = stoi(tmp);
                    ss.enqueue(key);
                }
                //Dequeue
                else{
                    ss.dequeue();
                }
            }
            ss.Print_queue(ss, out);
        }
        else if(tipo == "double"){
            StaticQueue<double> ss(n);
            for(int i = 0; i<n; i++){
                //Enqueue
                if(vett[i][0] == 'i'){
                    int l = vett[i].length();
                    string tmp = "";
                    for(int j = 1; j<l; j++){
                        tmp += vett[i][j];
                    }
                    double key = stod(tmp);
                    ss.enqueue(key);
                }
                //Dequeue
                else{
                    ss.dequeue();
                }
            }
            ss.Print_queue(ss, out);
        }
        else if(tipo == "bool"){
            StaticQueue<bool> ss(n);
            for(int i = 0; i<n; i++){
                //Enqueue
                if(vett[i][0] == 'i'){
                    string tmp = "";
                    tmp += vett[i][1];
                    int key = stoi(tmp);
                    ss.enqueue(key);
                }
                //Dequeue
                else{
                    ss.dequeue();
                }
            }
            ss.Print_queue(ss, out);
        }
        else if(tipo == "char"){
            StaticQueue<char> ss(n);
            for(int i = 0; i<n; i++){
                //Enqueue
                if(vett[i][0] == 'i'){
                    char key = vett[i][1];                    
                    ss.enqueue(key);
                }
                //Dequeue
                else{
                    ss.dequeue();
                }
            }
            ss.Print_queue(ss, out);
        }
    }
}