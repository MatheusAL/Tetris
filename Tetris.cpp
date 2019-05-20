#include "Tetris.h"
#include <iostream>
using namespace std;


//Figuras
/*char Tetris:: i[4][1]={{'I'},
                        {'I'},
                        {'I'},
                        {'I'},
};

char Tetris::j[2][4]={{'J','J','J','J'},
                        {' ',' ',' ','J'}
};

char Tetris::l[2][4]={{'L','L','L','L'},
                        {'L',' ',' ',' '}
};
char Tetris::o[2][2]={{'O','O'},
                        {'O','O'}
};
char Tetris::s[2][3]={{' ','S','S'},
                        {'S','S',' '}
};
char Tetris::t[2][3]={{'T','T','T'},
                        {' ','T',' '}
};
char Tetris::z[2][3]={{'Z','Z',' '},
                        {' ','Z','Z'}
};*/
///////////////////////////////////////////////////////////////////
Tetris::Tetris(int c){
    jogo=new char*[c];
    coluna=c;
    alturas=new int[coluna];
    for(int cont=0;cont<c;cont++){
        alturas[cont]=0;
    }
    for(int cont=0;cont<c;cont++){
        jogo[cont]=new char[alturas[cont]+1];//alturas[cont];
    }
    ///////////deixando os "Pixels" vazios    
    for(int cont=0;cont<coluna;cont++){
            jogo[cont][0]=' ';
    }
    cout<<jogo[0][0]<<" "<<endl;
}
Tetris::~Tetris(){
    delete [] alturas;
    for(int cont=0;cont<coluna;cont++){
       delete [] jogo[cont];
    }
    delete [] jogo;
}
int Tetris::getAltura(int c)const{
    return alturas[c];
}
int Tetris::getAltura()const{
    int maior=alturas[0];
    for(int cont=1;cont<coluna;cont++){
        if(alturas[cont]>maior)
            maior=alturas[cont];
    }
    return maior;
}
int Tetris::getNumColunas()const{
    return coluna;
}
char Tetris::get(int c, int l)const{
    return jogo[c][l];
}
void Tetris::removeColuna(int c){//////////////
    //////////////////////////////////////////////////////
    for(int cont=c;cont<getNumColunas()-1;cont++){
        delete [] jogo[c];
        jogo[c]=new char[alturas[c+1]];
        //cout<<"ALTURA DE "<<cont<<alturas[cont]<<endl;
        //cout<<"ALTURA DE "<<cont+1<<alturas[cont+1]<<endl;
        for(int cont=0;cont<alturas[c+1];cont++){
            jogo[c][cont]=jogo[c+1][cont];
        }
    }
    delete []jogo[getNumColunas()-1];
    coluna--;
    
}
void Tetris::realloclinha(int c,int l){//PRONTA
    //cout<<"altura de "<<c<<" "<<alturas[c];
    char *aux=new char[alturas[c]/*+1*/];//cria auxiliar pra receber os dados antigos
    for(int cont=0;cont<alturas[c];cont++){//passa os dados da linha no aux
        aux[cont]=jogo[c][cont];
    }
    //cout<<"aux=="<<aux[0]<<"aaa"<<endl;
    delete [] jogo[c];
    jogo[c]=new char[l+1];//cria com altura nova
    for(int cont=0;cont<l+1;cont++){
        if(cont>=alturas[c]){
            jogo[c][cont]=' ';
        }else{
            jogo[c][cont]=aux[cont];
        }
    }
    alturas[c]=l+1;
    delete [] aux;
    //cout<<"Realocado"<<jogo[c][l]<<c<<endl;
}
void Tetris::insereFiguraT(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=t[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=t[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=t[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=t[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }

    }

}
void Tetris::insereFiguraO(int c,int l,char id,int rotacao){
    for(int cont=c,figl=0;cont<=c+1;cont++,figl++){//simplify it
        for(int linha=l,figc=0;linha>=(l-2+1);linha--,figc++){
            if(getAltura(cont)<l){
                realloclinha(cont,l);
            }
            jogo[cont][linha]=o[figl][figc];
        }
    }
}
void Tetris::insereFiguraI(int c,int l,char id,int rotacao){
    if(rotacao==0 || rotacao==180){
        for(int linha=l,figl=3;linha>(l-4);linha--,figl--){
            jogo[c][linha]=i[figl][0];
        }
    }
    if(rotacao==90 || rotacao==270){
        for(int cont=c,figl=3;cont<(c+4);cont++,figl--){
            jogo[cont][l]=i[figl][0];
        }
    }
}
void Tetris::insereFiguraZ(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>l-2;linha--,figl++){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=z[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=z[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=z[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=z[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }

    }
}

void Tetris::insereFiguraS(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=s[figl][figc];
                //cout<<"coluna "<<cont<<"linha "<<linha<<" INDICES DA FIGURA "<<figl<<" "<<figc<<endl;/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=s[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=s[figl][figc];/////INVERTIDO????
                //cout<<"coluna "<<cont<<"linha "<<linha<<" INDICES DA FIGURA "<<figl<<" "<<figc<<endl;
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=s[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }

    }
}
void Tetris::insereFiguraJ(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=j[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=j[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=j[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=j[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }

    }
}
void Tetris::insereFiguraL(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=L[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=L[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=L[figl][figc];/////INVERTIDO????
                //alturas[cont]++;
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(getAltura(cont)<l){
                    realloclinha(cont,l);
                }
                jogo[cont][linha]=L[figl][figc];
                //cout<<cont<<" "<<linha<<"     "<<"FIGURA: "<<figl<<" "<<figc<<" "<<t[figl][figc]<<endl;
            }
        }

    }
}
bool Tetris::adicionaForma(int c,int l,char id,int rotacao){
    //cout<<"TAMANHO DA COLUNA QUE A GNT TA TENTANDO INSERIR "<<getAltura(c)<<" LINHA "<<l<<endl<<endl;
    if(l>=getAltura(c)){//if(2>0)
        //cout<<getAltura(c);
        realloclinha(c,l);
    }

    //////PEÇAS/////////////////////////////////////////////////////////////////////
    if(id=='T'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<(c+3);cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            //cout<<"vish parça"<<" "<<cont<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+3);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                //cout<<"aqui";
                return false;
            }
            insereFiguraT(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){
                    for(int a=l-1;a>=l-2;a--){
                        //cout<<"linha: "<<a<<endl;
                        if(jogo[cont2][a]!=' '){
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
            }else{
                //cout<<"aqui"<<endl;
                return false;
            }
            insereFiguraT(c,l,id,rotacao);
            return true;
        }

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='O'){
        bool inserivel=true;
            if(l-2+1>=0 && c+2<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            //cout<<"vish parça"<<" "<<cont<<endl;
                            return false;//
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                //cout<<"aqui";
                return false;
            }
            insereFiguraO(c,l,id,rotacao);
            return true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='I'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-3>=0 && c<getNumColunas()){//nao precisa testar colunas
                if(jogo[c][l]!=' '){
                    return false;
                }
                for(int linha=l;linha>(l-4);linha--){
                    if(jogo[c][linha]!=' '){
                        return false;
                    }
                }
            }
            else{
                return false;
            }
            insereFiguraI(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 || rotacao==270){
            bool inserivel=true;
            if((c+3)<getNumColunas()){
                for(int cont=c;cont<=(c+3);cont++){
                    if(l>=getAltura(cont)){
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){
                            return false;
                        }
                    }
                }
            }else{
                
                return false;
            }
            insereFiguraI(c,l,id,rotacao);
            return true;
        }
        
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='Z'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<(c+3);cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            //cout<<"vish parça"<<" "<<cont<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+3);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                //cout<<"aqui";
                return false;
            }
            insereFiguraZ(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){
                    for(int a=l-1;a>=l-2;a--){
                        //cout<<"linha: "<<a<<endl;
                        if(jogo[cont2][a]!=' '){
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
            }else{
                //cout<<"aqui"<<endl;
                return false;
            }
            insereFiguraZ(c,l,id,rotacao);
            return true;
        }

    }
//////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='S'){
           if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<(c+3);cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            //cout<<"vish parça"<<" "<<cont<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+3);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                //cout<<"aqui";
                return false;
            }
            insereFiguraS(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){
                    for(int a=l-1;a>=l-2;a--){
                        //cout<<"linha: "<<a<<endl;
                        if(jogo[cont2][a]!=' '){
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
            }else{
                //cout<<"aqui"<<endl;
                return false;
            }
            insereFiguraS(c,l,id,rotacao);
            return true;
        }

    }
    if(id=='J'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(c+4<=coluna && l-2+1>=0){
                for(int cont=c;cont<(c+4);cont++){
                    if(l>=getAltura(cont)){
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+4);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                return false;
            }
            insereFiguraJ(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 || rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){
                    for(int a=l-1;a>=l-2;a--){
                        //cout<<"linha: "<<a<<endl;
                        if(jogo[cont2][a]!=' '){
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
            }else{
                //cout<<"aqui"<<endl;
                return false;
            }
            insereFiguraJ(c,l,id,rotacao);
            return true;
        }
    }
    if(id=='L'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(c+4<=coluna && l-2+1>=0){
                for(int cont=c;cont<(c+4);cont++){
                    if(l>=getAltura(cont)){
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+4);cont2++){//testa linha de baixo
                    if(jogo[cont2][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                return true;
            }
            insereFiguraL(c,l,id,rotacao);
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                for(int cont=c;cont<c+2;cont++){
                    if(l>=getAltura(cont)){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
                for(int cont2=c;cont2<(c+2);cont2++){
                    for(int a=l-1;a>=l-2;a--){
                        //cout<<"linha: "<<a<<endl;
                        if(jogo[cont2][a]!=' '){
                            //cout<<"vish parça"<<endl;
                            return false;
                        }
                    }
                }
            }else{
                //cout<<"aqui"<<endl;
                return false;
            }
            insereFiguraL(c,l,id,rotacao);
            return true;
        }

    }  
}
void Tetris::removeLinha(int l){
    //cout<<"fui chamado"<<endl;
    for(int cont=0;cont<getNumColunas();cont++){
        char *aux=new char[alturas[cont]-1];
        //cout<<"tamanho do bloc auxiliar "<<cont<<" "<<alturas[cont]-1<<endl;
        for(int linha=0,cont2=0;linha<alturas[cont];linha++){///////passando os dados para um aux sem o elemento da linha a ser retirado
            if(linha!=l){
                aux[cont2]=jogo[cont][linha];
                //cout<<l<<endl;
                cont2++;
            }
        }
        delete [] jogo [cont];
        alturas[cont]--;
        jogo[cont]=new char[alturas[cont]];
        for(int linha=0;linha<alturas[cont];linha++){
            jogo[cont][linha]=aux[linha];
        }
        delete []aux;
    }
    //cout<<"eu removi"<<endl;
}
void Tetris::removeLinhasCompletas(){
    bool eligible=true;
    int linhapreenchida=0,diferentes=0;
    
    //cout<<"ALTURA MAXIMA "<<getAltura()<<endl;
    for(int linha=0;linha<getAltura();linha++){///////////teste pra saber quantas linhas podem ser testadas
        eligible=true;
        for(int cont=0;cont<getNumColunas();cont++){
            if(alturas[cont]<=linha){
                eligible=false;
            }
        }
        if(eligible){
            //cout<<linha<<endl;
            linhapreenchida++;
        }
    }
    //cout<<linhapreenchida<<endl;//usa esse valor no for
    //cout<<"esse e o numero de colunas"<<getNumColunas()<<endl;
    for(int linha=0;linha<linhapreenchida;linha++){
        diferentes=0;
        for(int coluna=0;coluna<getNumColunas();coluna++){
            if(jogo[coluna][linha]!=' '){
                diferentes++;
            }
        }
        if(diferentes==getNumColunas()){
            //cout<<diferentes<<" "<<linha<<endl;
            removeLinha(linha);
            linha--;
            linhapreenchida--;
        }
    }
}

 Tetris & Tetris::operator=(const Tetris game){
    if(this==&game){
        return *this;
    }
    this->coluna=game.coluna;
    delete [] alturas;
    alturas=new int[coluna];
    for(int cont=0;cont<coluna;cont++){
        alturas[cont]=game.alturas[cont];
    }
    jogo=game.jogo;
    return *this;
 }

