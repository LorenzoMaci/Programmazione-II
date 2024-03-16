
#include<iostream>
#include<fstream>
using namespace std;

bool Check(string s, char key){
    if(s[0] == key){
        return true;
    }
    return false;
}

void Solve(string s1, string s2, string s3, char key, ostream& out){
    if(Check(s1, key)){
        out << s1 << " ";
    }

    if(Check(s2, key)){
        out << s2 << " ";
    }

    if(Check(s3, key)){
        out << s3 << " ";
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        char key;
        in >> key;

        int l1;
        in >> l1;

        string s1;
        in >> s1;

        int l2;
        in >> l2;

        string s2;
        in >> s2;

        int l3;
        in >> l3;

        string s3;
        in >> s3;

        Solve(s1, s2, s3, key, out);
    }
}


//PROGRAMMA MIGLIORE MA CHE NON VA

// void Solve(string* vett, int n, char key, ostream& out){
//     for(int i = 1; i<n; i+=2){
//         if(vett[i][0] == key){
//             out << vett[i];
//         }
//     }
//     out << endl;
// }

// int main(){
//     ifstream in("input.txt");
//     ofstream out("output.txt");

//     for(int i = 0; i<100; i++){
//         char key;
//         in >> key;

//         string* vett = new string[6];
//         for(int j = 0; j<6; j++){
//             in >> vett[i];
//         }

//         Solve(vett, 6, key, out);
//         delete [] vett;
//      }
// }

