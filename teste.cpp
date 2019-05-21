#include <iostream>
using namespace std;
#include "Tetris.h"

int main(){
    Tetris a(4);
    Tetris b(5);
    //a.removeColuna(0);
    //cout<<a.getAltura(0)<<endl;
    bool vrau=a.adicionaForma(0,3,'I',0);
    if(!vrau)
        cout<<"Nao inseri"<<endl;
    else
        cout<<"Inseri"<<endl;
    vrau=a.adicionaForma(1,2,'T',90);
    if(!vrau)
        cout<<"Nao inseri"<<endl;
    else
        cout<<"Inseri"<<endl;
    vrau=b.adicionaForma(3,3,'I',180);
    if(!vrau)
        cout<<"Nao inseri"<<endl;
    else
        cout<<"Inseri"<<endl;
    cout<<a.get(1,2)<<a.get(2,2)<<endl;
    cout<<a.get(1,1)<<a.get(2,1)<<endl;
    cout<<a.get(1,0)<<a.get(2,0)<<endl;

    //cout<<a.get(1,1);
    a.removeLinhasCompletas();
    a=b;
    
    cout<<a.get(3,3)<<endl;
    cout<<a.get(3,2)<<endl;
    cout<<a.get(3,1)<<endl;
    cout<<a.get(3,0)<<endl;
    Tetris c=a;
    //cout<<a.get(1,1);
    //cout<<a.get(0,4)<<a.get(1,4)<<a.get(2,4)<<endl;
    //cout<<a.get(0,3)<<a.get(1,3)<<a.get(2,3)<<endl;
    /*cout<<a.get(2,4)<<a.get(0,3)<<endl;
    cout<<a.get(3,4)<<a.get(0,2)<<endl;
    cout<<a.get(4,4)<<a.get(0,1)<<endl;*/
    //a.removeColuna(2);
    //cout<<a.getNumColunas()<<endl;  

    
}