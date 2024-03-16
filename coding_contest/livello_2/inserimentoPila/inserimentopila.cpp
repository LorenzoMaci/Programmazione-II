#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class StatickStack{
    int size = 0;
    int top = -1;
    T* arr;
    int maxSize = -1;
    public:
    StatickStack(int maxSize) : maxSize(maxSize){
        arr = new T[maxSize];
    }

    bool isEmpty(){
        return top == -1;
    }

    T getTop(){
        if(this->isEmpty()){
            return -1;
        }
        return arr[top];
    }

    void push(T val){
        if(top == maxSize -1){
            return;
        }

        arr[++top] = val; 
    }

    void Print_Stack(StatickStack<T>& s, ostream& out){
        for(int i = s.top; i >= 0; i--){
            out << s.arr[i] << " ";
        }
        out << endl;
    }
};

int main(){
    ifstream in ("input.txt");
    ofstream out("output.txt");
    
    for(int i=0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;
        string* vett = new string[n];
        if(tipo == "int"){
            StatickStack<int> ss(n);
            for(int j=0; j<n; j++){
                int key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "double"){
            StatickStack<double> ss(n);
            for(int j=0; j<n; j++){
                double key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "bool"){
            StatickStack<bool> ss(n);
            for(int j=0; j<n; j++){
                bool key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "char"){
            StatickStack<char> ss(n);
            for(int j=0; j<n; j++){
                char key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
    }
}