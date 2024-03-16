#include <iostream>
#include <fstream>
#define MAX_SIZE 200

using namespace std;

template<typename T>
class StatickQueue{
    T* arr;
    int head = -1;
    int tail = -1;
    int size = 0;
    int maxSize = MAX_SIZE;
    public:
    StatickQueue(int maxSize = MAX_SIZE) : maxSize(maxSize){
        arr = new T[maxSize];
    }

    void enqueue(T val){
        if(size == maxSize){
            return;
        }
        if(head == -1){
            head = 0;
        }
        tail = (++tail % maxSize);
        arr[tail] = val;
        size++;
    }

    T dequeue(){
        T val = arr[head];
        head = (++head % maxSize);
        size--;
        return val;
    }

    void Print_Queue( StatickQueue<T>& queue, ostream& out){
        for(int i=queue.head, count=0; count<queue.size; count++) {
			out << queue.arr[i] << " ";
			i = (i+1) % queue.maxSize;
		}
		out << endl;
    }
};


template<typename T>
class StatickStack : public StatickQueue<T>{
    T* arr;
    int top = -1;
    int size = 0;
    int maxSize = -1;
    public:
    StatickStack(int maxSize = MAX_SIZE) : maxSize(maxSize){
        arr = new T[maxSize];
    }

    void push(T val){
        if(top == maxSize -1){
            return;
        }
        arr[++top] = val;
    }

    T pop(){
        return arr[top--];
    }

    void Travasa( StatickStack<T>& ss, StatickQueue<T>& queue, int n){
        for(int i=ss.top; i >= 0; i--){
            queue.enqueue(arr[i]);
            ss.pop();
        }
    }

    void Print_Stack(StatickStack<T>& ss, ostream& out){
        for(int i = ss.top; i >= 0; i--){
            out << ss.arr[i] <<  " ";
        }
        out << endl;
    }

};


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string tipo;
        in >> tipo;
        
        int n;
        in >> n;

        string* vett = new string[n];
        for(int j=0; j<n; j++){
            in >> vett[j];
        }
        if(tipo == "int"){
            StatickQueue<int> sq(n);
            StatickStack<int> ss(n);

            for(int j=0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    for(int x = 2; x<l; x++){
                        temp += vett[j][x];
                    }
                    int key = stoi(temp);
                    sq.enqueue(key);
                }else if(vett[j].find("p:")!= string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    for(int x=2; x<l; x++){
                        temp += vett[j][x];
                    }
                    int key = stoi(temp);
                    ss.push(key);
                }else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }else if(vett[j] == "pop"){
                    ss.pop();
                }else if(vett[j] == "travasa"){
                    ss.Travasa(ss, sq, n);
                }
            }
            sq.Print_Queue(sq, out);
        }
        else if(tipo == "double"){
            StatickQueue<double> sq(n);
            StatickStack<double> ss(n);

            for(int j=0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    for(int x = 2; x<l; x++){
                        temp += vett[j][x];
                    }
                    double key = stod(temp);
                    sq.enqueue(key);
                }else if(vett[j].find("p:")!= string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    for(int x=2; x<l; x++){
                        temp += vett[j][x];
                    }
                    double key = stod(temp);
                    ss.push(key);
                }else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }else if(vett[j] == "pop"){
                    ss.pop();
                }else if(vett[j] == "travasa"){
                    ss.Travasa(ss, sq, n);
                }
            }
            sq.Print_Queue(sq, out);
        }
        else if(tipo == "bool"){
            StatickQueue<bool> sq(n);
            StatickStack<bool> ss(n);

            for(int j=0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    temp += vett[j][2];
                    int key = stoi(temp);
                    sq.enqueue(key);
                }
                else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    string temp = "";
                    temp += vett[j][2];
                    int key = stoi(temp);
                    ss.push(key);
                }else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.Travasa(ss, sq, n);
                }
            }
            sq.Print_Queue(sq, out);
        }
        else if(tipo == "char"){
        StatickQueue<char> sq(n);
        StatickStack<char> ss(n);

        for(int j = 0; j<n; j++){
            if(vett[j].find("e:") != string::npos){
                int l = vett[j].length();
                char key = vett[j][2];
                sq.enqueue(key);
            }
            else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    char key = vett[j][2];
                    ss.push(key);
                }   
                else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.Travasa(ss, sq, n);
                }
            }   
            sq.Print_Queue(sq, out);
        }
    }
}