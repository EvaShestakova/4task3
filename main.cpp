
//#include "CVector.h"
//#include "Temp.h"
//#include "CVectorHori.h"
//#include "CVectorVert.h"
#include "Fabric.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

//void AutoTest();

class Fabric;
class FabricHori;
class FabricVert;

int main() {
    try {
        const int n = 5000000;   
        vector<double> a;
        vector<double> b;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
           // a.push_back((200) * (double)rand() / RAND_MAX - 100); 
           // b.push_back((200) * (double)rand() / RAND_MAX - 100);
            a.push_back(1);
            b.push_back(1);
        }
        CVectorHori A(a, n);
        CVectorHori B(b, n);
        CVectorHori C = A + B;
       // cout << C[2000];
        //double d = A * B;
        cout << A * B;


        /*CVectorHori a;
        CVectorVert c,b;
        a[1] = 3;
        b[1] = 2;
        c = a + b;
        c.print();
        AutoTest();
        ifstream fin("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        string str;
        string s;
        int m;
        double d;
        int n = 0;
        while (!fin.eof())
        {
            getline(fin,str);
            n++;
        }
        fin.seekg(0, ios_base::beg);
        fin.close();
        fin.open("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        vector <CVector*> arr(n);
        map<string, Fabric*> factory;
        factory["Hori"] = new FabricHori;
        factory["Vert"] = new FabricVert;
        for (auto i = arr.begin(); i !=arr.end(); ++i) {
            fin >> s;
            *i = create(s, factory);
            fin >> s;
            (*i)->SetFileName(s);
            fin >> m;
            (*i)->Setn(m);
            for (int j = 0; j < m; ++j) {
                fin >> d;
                (*(*i))[j] = d;
            }
        }
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            (*i)->output((*i)->GetFileName());
        }
        fin.close();
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            delete (*i);
        }*/
        return 0;
    }
    catch (int err) { printf("error=%d\n", err); }
}
