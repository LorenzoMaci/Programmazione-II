#include<iostream>
#include<fstream>
using namespace std;

void Ripetute(string s1, ostream& out){
    string s = s1;
    s += s;
    out << s << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string s;
        in >> s;

        Ripetute(s, out);
    }
}