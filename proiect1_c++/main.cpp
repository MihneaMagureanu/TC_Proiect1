#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct { int s; int d; char l; int inStack; int outStack; char output;} muchie;
bool accept(int position, int currentNode,int nrmuchii, muchie muchii[100], int nrnods, int nodiesire, char* cuv, stack<int> stiva, queue<char> output) {
    int lungime=strlen(cuv);
    int gasit=0;
    if (position>=lungime) {
        return false;
    }
    if (position==lungime) {
        if (currentNode==nodiesire) {
            return true;
        }
        else {
            return false;
        }
    }


    for (int i=1; i<nrmuchii; i++) {
        if ((muchii[i].s==currentNode) && (muchii[i].l==cuv[position]) && (muchii[i].inStack==stiva.top())) {
            stiva.pop();
            stiva.push(muchii[i].outStack);
            output.push(muchii[i].output);
            if (accept(position+1,muchii[i].d,nrmuchii,muchii,nrnods,nodiesire,cuv,stiva,output)) {
                gasit=1;
            }
            //return accept(position+1,muchii[i].d,nrmuchii,muchii,nrnods,nodiesire,cuv,stiva);
        }
    }
    if (gasit==1) {
        return true;
    }
    else {
        return false;
    }

}

int main()
{
    int n,i,in,fin,m,poz;
    muchie v[100];
    ifstream f("citire.txt");
    //f>>w; //cuvant
    f>>n; //nr noduri
    f>>in; //nod intrare
    f>>fin; //nod iesire
    f>>m; //muchii
    stack<int> nfa_stack;
    nfa_stack.push(0); //vom folosi 0 pe post de lambda
    for (i=1;i<=m; i++)
        f>>v[i].s>>v[i].d>>v[i].l>>v[i].inStack>>v[i].outStack>>v[i].output;
    poz=in;
    char cuv[10];
    int indice=0;
    queue<char> output;
    while (!f.eof()) {
        f>>cuv[indice];
        indice++;
    }
    if (accept(0,poz,m,v,n,fin,cuv,nfa_stack,output)) {
        cout<<"Accepted"<<endl;
        while (output.empty()==false) {
            cout<<output.front();
            output.pop();
        }
    }
    else
        cout<<"Not accepted";
}


/*
fisier text:

4
1
3
4
1 2 b 0 1 d
2 3 b 0 1 d
4 3 a 1 0 a
1 4 a 0 1 d
aa
*/
