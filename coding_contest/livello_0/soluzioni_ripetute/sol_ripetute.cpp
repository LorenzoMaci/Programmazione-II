#include<iostream>
#include<fstream>
using namespace std;

void Sol_ripetute(string s1, ostream& out){
    string s = s1;
    string r = "";
    int n = s1.length()/2;
    for(int i = 0; i<n; i++){
        r += s1[i];
    }
    out << r << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string s1;
        in >> s1;

        Sol_ripetute(s1, out);
    }
}