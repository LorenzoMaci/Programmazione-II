#include<iostream>
#include<fstream>
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
			//cout << "Queue is full" << endl;
			return;
		}
		if(head == -1){
			head = 0;
        }
		tail = (++tail % maxSize);
		array[tail] = val;
		size++;
	}
	
	void Print_queue(StaticQueue<H>& queue, ostream& out) {
		if(queue.size == 0){
			//out << "Queue is empty" << endl;
        }
		
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
        string s;
        in >> s;

        int n;
        in >> n;

        if(s == "int"){
            StaticQueue<int> sq(n);

            for(int i = 0; i<n; i++){
                int tmp;
                in >> tmp;
                sq.enqueue(tmp);
            }

            sq.Print_queue(sq, out);
        }
        else if(s == "double"){
            StaticQueue<double> sq(n);
            
            for(int i = 0; i<n; i++){
                double tmp;
                in >> tmp;
                sq.enqueue(tmp);
            }

            sq.Print_queue(sq, out);
        }
        else if(s == "bool"){
            StaticQueue<bool> sq(n);
            
            for(int i = 0; i<n; i++){
                bool tmp;
                in >> tmp;
                sq.enqueue(tmp);
            }

            sq.Print_queue(sq, out);
        }
        else if(s == "char"){
            StaticQueue<char> sq(n);
            
            for(int i = 0; i<n; i++){
                char tmp;
                in >> tmp;
                sq.enqueue(tmp);
            }

            sq.Print_queue(sq, out);
        }
    }    
}