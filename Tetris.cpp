#include "Tetris.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////

//Construtor
Tetris::Tetris(int c){
    jogo=new char*[c];
    coluna=c;
    alturas=new int[coluna];
    for(int cont=0;cont<c;cont++){
        alturas[cont]=0;
    }
    for(int cont=0;cont<c;cont++){
        jogo[cont]=new char[alturas[cont]+1];
    }
    ///////////deixando os "Pixels" vazios    
    for(int cont=0;cont<coluna;cont++){
            jogo[cont][0]=' ';
    }
}
//Destrutor
Tetris::~Tetris(){
    delete [] alturas;
    for(int cont=0;cont<coluna;cont++){
       delete [] jogo[cont];
    }
    delete [] jogo;
}
int Tetris::getAltura(int c)const{//Retorna altura da coluna c
    return alturas[c];
}
int Tetris::getAltura()const{//retorna maior altura
    int maior=alturas[0];
    for(int cont=1;cont<coluna;cont++){
        if(alturas[cont]>maior)
            maior=alturas[cont];
    }
    return maior;
}
int Tetris::getNumColunas()const{//Retorna numero de colunas
    return coluna;
}
char Tetris::get(int c, int l)const{//retorna o caractere da posicao jogo[c],[l]
    if(l<alturas[c]){
        return jogo[c][l];
    }else{
        return ' ';
    }
}
void Tetris::removeColuna(int c){//////////////
    for(int cont=c;cont<getNumColunas()-1;cont++){//passa por todas as colunas
        delete [] jogo[cont];//delete a coluna atual
        if(alturas[cont+1]==0){//se a proxima coluna nao possuir altura, adiciona apenas ' '
            jogo[cont]=new char[alturas[cont+1]+1];
            jogo[cont][0]=' ';
            alturas[cont]=alturas[cont+1];
        }
        else{//cria com a altura da proxima coluna e transfere os dados
            jogo[cont]=new char[alturas[cont+1]];
            alturas[cont]=alturas[cont+1];
            for(int cont2=0;cont2<alturas[cont+1];cont2++){
                jogo[cont][cont2]=jogo[cont+1][cont2];
            }
        }
    }
    delete []jogo[getNumColunas()-1];
    coluna--;
    
}
void Tetris::realloclinha(int c,int l){//PRONTA
    char *aux=new char[alturas[c]];//cria auxiliar pra receber os dados antigos
    for(int cont=0;cont<alturas[c];cont++){//passa os dados da linha no aux
        aux[cont]=jogo[c][cont];
    }
    delete [] jogo[c];
    jogo[c]=new char[l+1];//cria com altura nova
    for(int cont=0;cont<l+1;cont++){//tranfere os dados
        if(cont>=alturas[c]){
            jogo[c][cont]=' ';
        }else{
            jogo[c][cont]=aux[cont];
        }
    }
    alturas[c]=l+1;//atualiza a altura da coluna
    delete [] aux;
}
////////////////////Funçoes de Inserçao/////////////////////////////////////////////////////////
//As rotaçoes das figuras sao dadas pela estrutura dos laços de repetiçao
//A inserçao é feita de acordo com os laços de repetiçao


void Tetris::insereFiguraT(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(t[figl][figc]!=' ')
                    jogo[cont][linha]=t[figl][figc];
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(t[figl][figc]!=' ')
                    jogo[cont][linha]=t[figl][figc];
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(t[figl][figc]!=' ')
                    jogo[cont][linha]=t[figl][figc];
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
                if(t[figl][figc]!=' ')
                    jogo[cont][linha]=t[figl][figc];
            }
        }
    }
}
void Tetris::insereFiguraO(int c,int l,char id,int rotacao){
    jogo[c][l]=o[0][0];
    jogo[c+1][l]=o[0][1];
    jogo[c][l-1]=o[1][0];
    jogo[c+1][l-1]=o[1][1];
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
void Tetris::insereFiguraZS(int c,int l,char id,int rotacao){
    if(rotacao==0 || rotacao==180){
        for(int linha=l,figl=0;linha>l-2;linha--,figl++){
            for(int cont=c,figc=0;cont<(3+c);cont++,figc++){
                if(id=='Z'){
                    if(z[figl][figc]!=' ')
                        jogo[cont][linha]=z[figl][figc];
                }
                if(id=='S'){
                    if(s[figl][figc]!=' ')
                        jogo[cont][linha]=s[figl][figc];
                }
            }
        }
    }
    if(rotacao==90 || rotacao==270){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-3+1);linha--,figc++){
               if(id=='Z'){
                    if(z[figl][figc]!=' ')
                        jogo[cont][linha]=z[figl][figc];
                }
                if(id=='S'){
                    if(s[figl][figc]!=' ')
                        jogo[cont][linha]=s[figl][figc];
                }
            }
        }
    }
}

void Tetris::insereFiguraJ(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(j[figl][figc]!=' ')
                    jogo[cont][linha]=j[figl][figc];
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(j[figl][figc]!=' ')
                    jogo[cont][linha]=j[figl][figc];
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=3;cont<(4+c);cont++,figc--){
                 if(j[figl][figc]!=' ')
                    jogo[cont][linha]=j[figl][figc];
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=3;linha>=(l-4+1);linha--,figc--){
                if(j[figl][figc]!=' ')
                    jogo[cont][linha]=j[figl][figc];
            }
        }

    }
}
void Tetris::insereFiguraL(int c,int l,char id,int rotacao){
    if(rotacao==0){
        for(int linha=l,figl=0;linha>(l-2);linha--,figl++){
            for(int cont=c,figc=0;cont<(4+c);cont++,figc++){
                if(L[figl][figc]!=' ')
                    jogo[cont][linha]=L[figl][figc];
            }
        }
    }
    if(rotacao==90){
        for(int cont=c,figl=1;cont<=(c+1);cont++,figl--){
            for(int linha=l,figc=0;linha>=(l-4+1);linha--,figc++){
                if(L[figl][figc]!=' ')
                    jogo[cont][linha]=L[figl][figc];
            }
        }
    }
    if(rotacao==180){
        for(int linha=l,figl=1;linha>(l-2);linha--,figl--){
            for(int cont=c,figc=3;cont<(4+c);cont++,figc--){
               if(L[figl][figc]!=' ')
                    jogo[cont][linha]=L[figl][figc];
            }
        }
    }
    if(rotacao==270){
        for(int cont=c,figl=0;cont<=(c+1);cont++,figl++){
            for(int linha=l,figc=3;linha>=(l-4+1);linha--,figc--){
                if(L[figl][figc]!=' ')
                    jogo[cont][linha]=L[figl][figc];
            }
        }

    }
}
///////////////////////////////////////////////////////////////////

bool Tetris::adicionaForma(int c,int l,char id,int rotacao){//Funçao para adicionar peças e verificar se são inseriveis
    //////PEÇAS/////////////////////////////////////////////////////////////////////
    if(id=='T'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                if(rotacao==0){
                    for(int cont=c;cont<(c+3);cont++){
                        if(l>=alturas[cont]){//testa se todas as colunas possuem altura necessaria
                            inserivel=false;
                            realloclinha(cont,l);
                        }
                        else{
                            if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                                return false;
                            }
                        }
                    }
                    if(jogo[c+1][l-1]!=' '){
                        return false;
                    }
                }
                else{//rotacao 180
                    if(l-1>=alturas[c]){
                        realloclinha(c,l-1);
                    }else{
                        if(jogo[c][l-1]!=' ')
                            return false;
                    }
                    if(l>=alturas[c+1]){
                        realloclinha(c+1,l);
                    }else{
                        if(jogo[c+1][l]!=' ')
                            return false;
                    }
                    if(l-1>=alturas[c+2]){
                        realloclinha(c+2,l-1);
                    }else{
                        if(jogo[c+2][l-1]!=' ')
                            return false;
                    }
                    if(jogo[c+1][l-1]!=' '){
                        return false;
                    }
                }
            }else{
                return false;
            }
            insereFiguraT(c,l,id,rotacao);// Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                if(rotacao==90){
                    if(l-1>=alturas[c]){
                        realloclinha(c,l-1);
                    }else{
                        if(jogo[c][l-1]!=' ')
                            return false;
                    }
                    if(l>=alturas[c+1]){
                        realloclinha(c+1,l);
                    }else{
                         if(jogo[c+1][l]!=' ')
                                return false;
                    }
                    for(int linha=l-1;linha>=l-2;linha--){
                        if(jogo[c+1][linha]!=' ')
                            return false;
                    }
                }
                else{
                     if(l-1>=alturas[c+1]){
                        realloclinha(c+1,l-1);
                    }else{
                        if(jogo[c+1][l-1]!=' ')
                            return false;
                    }
                    if(l>=alturas[c]){
                        realloclinha(c,l);
                    }else{
                         for(int linha=l;linha>=l-2;linha--){
                             if(jogo[c][linha]!=' ')
                                return false;
                         }
                    }
                }            
            }else{
                return false;
            }
            insereFiguraT(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='O'){
        bool inserivel=true;
            if(l-2+1>=0 && c+2<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<c+2;cont++){
                    if(l>=alturas[cont]){//testa se todas as colunas possuem altura necessaria
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
                return false;
            }
            insereFiguraO(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='I'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l>=alturas[c]){
                realloclinha(c,l);
            }
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
            insereFiguraI(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 || rotacao==270){
            bool inserivel=true;
            if((c+3)<getNumColunas()){
                for(int cont=c;cont<=(c+3);cont++){
                    if(l>=alturas[cont]/*getAltura(cont)*/){
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
            insereFiguraI(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='Z'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c;cont<(c+2);cont++){
                    if(l>=alturas[cont]/*getAltura(cont)*/){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            return false;
                        }
                    }
                }
                if(l-1>=alturas[c+2]){
                    realloclinha(c+2,l-1);
                }else{
                    if(jogo[c+1][l-1]!=' ' || jogo[c+2][l-1]!=' ')
                        return false;
                }
            }else{
                return false;
            }
            insereFiguraZS(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                if(l-1>=alturas[c]){//testa se todas as colunas possuem altura necessaria
                    realloclinha(c,l-1);
                }
                else{
                    if(jogo[c][l-1]!=' '){//caso a posiçao exista e estiver ocupada == false
                        return false;
                    }
                }
                if(l>=alturas[c+1]){
                    realloclinha(c+1,l);
                }
                else{
                    if(jogo[c+1][l]!=' ')
                        return false;
                }
                if(jogo[c][l-2]!=' ' || jogo[c][l-1]!=' ' || jogo[c+1][l-1]!=' '){
                    return false;
                }
            }else{
                return false;
            }
            insereFiguraZS(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }

    }
//////////////////////////////////////////////////////////////////////////////////////////////
    if(id=='S'){
           if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(l-2+1>=0 && c+3<=coluna){//caso va para posicoes negativas ou o numero de colunas ultrapasse
                for(int cont=c+1;cont<(c+3);cont++){
                    if(l>=alturas[cont]){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(cont,l);
                    }
                    else{
                        if(jogo[cont][l]!=' '){//caso a posicao exista e estiver ocupada == false
                            return false;
                        }
                    }
                }
                if(l-1>=alturas[c]){
                    realloclinha(c,l-1);
                }else{
                    if(jogo[c][l-1]!=' ')
                        return false;
                }
                if(jogo[c+1][l]!=' ' || jogo[c+2][l]!=' '|| jogo[c][l-1]!=' ' || jogo[c+1][l-1]!=' '){
                    return false;
                }
            }else{
                return false;
            }
            insereFiguraZS(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3+1>=0 && c+1<coluna){
                if(l>=alturas[c])
                    realloclinha(c,l);
                else{
                    if(jogo[c][l]!=' ')
                        return false;
                }
                if(l-1>=alturas[c+1]){//testa se todas as colunas possuem altura necessaria
                    realloclinha(c+1,l-1);
                }
                else{
                    if(jogo[c+1][l-1]!=' '){//caso a posiçao exista e estiver ocupada == false
                        return false;
                    }
                }
                if(jogo[c+1][l-2]!=' ' || jogo[c][l-1]!=' '|| jogo[c+1][l-1]!=' '){
                    return false;
                }
            }else{
                return false;
            }
            insereFiguraZS(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }

    }
///////////////////////////////////////////////////////////////////////
    if(id=='J'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(c+4<=coluna && l-2+1>=0){
                if(rotacao==0){
                    for(int cont=c;cont<(c+4);cont++){
                        if(l>=alturas[cont]){
                            inserivel=false;
                            realloclinha(cont,l);
                        }
                        else{
                            if(jogo[cont][l]!=' '){
                                return false;
                            }
                        }
                    }
                    if(jogo[c+3][l-1]!=' '){
                        return false;
                    }
                }
                else{
                    for(int cont=c+1;cont<(c+4);cont++){
                        if(l-1>=alturas[cont]){
                            realloclinha(cont,l-1);
                        }
                    }
                    if(l>=alturas[c]){
                        realloclinha(c,l);
                        if(jogo[c][l]!=' ')
                            return false;
                    }
                    for(int cont2=c;cont2<(c+4);cont2++){//testa linha de baixo
                        if(jogo[cont2][l-1]!=' '){
                            return false;
                        }
                    }
                }
            }else{
                return false;
            }
            insereFiguraJ(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 || rotacao==270){
            bool inserivel=true;
            if(l-3>=0 && c+1<coluna){

                if(rotacao==90){
                    if(l>=alturas[c+1]){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(c+1,l);
                    }
                    else{
                        if(jogo[c+1][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            return false;
                        }
                    }
                    if(l-3>=alturas[c]){
                        realloclinha(c,(l-3));
                    }else{    
                        if(jogo[c][l-3]!=' '){
                            return false;
                        }
                    }
                    for(int linha=l-1;linha>=l-3;linha--){
                        if(jogo[c+1][linha]!=' ')
                            return false;
                    }
                }
                else{
                     if(l>=alturas[c]){//testa se todas as colunas possuem altura necessaria
                        inserivel=false;
                        realloclinha(c,l);
                    }
                    else{
                        if(jogo[c][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                            return false;
                        }
                    }
                    if(l>=alturas[c+1]){
                        realloclinha(c+1,l);
                    }
                    else{
                        if(jogo[c+1][l]!=' '){
                            return false;
                        }
                    }
                    for(int linha=l-1;linha>=l-3;linha--){
                        if(jogo[c][linha]!=' ')
                            return false;
                    }
                }
            }else{
                return false;
            }
            insereFiguraJ(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
    }
////////////////////////////////////////////////////////////////////////////////
    if(id=='L'){
        if(rotacao==0 || rotacao==180){
            bool inserivel=true;
            if(c+4<=coluna && l-2+1>=0){
                if(rotacao==0){
                    for(int cont=c;cont<(c+4);cont++){
                        if(l>=alturas[cont]/*getAltura(cont)*/){
                            inserivel=false;
                            realloclinha(cont,l);
                        }
                        else{
                            if(jogo[cont][l]!=' '){
                                return false;
                            }
                        }
                    }
                     if(jogo[c][l-1]!=' '){//testa o pixel da linha debaixo
                        return false;
                    }
                }
                else{
                    for(int cont=c;cont<(c+3);cont++){
                        if(l-1>=alturas[cont]){
                            realloclinha(cont,l-1);
                        }
                    }
                    if(l>=alturas[c+3]){
                        realloclinha(c+3,l);
                    }
                    if(jogo[c+3][l]!=' '){
                        return false;
                    }
                    for(int cont2=c;cont2<(c+4);cont2++){//testa linha de baixo
                        if(jogo[cont2][l-1]!=' '){
                            return false;
                        }
                    }
                }
            }else{
                return true;
            }
            insereFiguraL(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }
        if(rotacao==90 ||rotacao==270){
            bool inserivel=true;
            if(l-3>=0 && c+1<coluna){
                if(rotacao==90){
                    for(int cont=c;cont<c+2;cont++){
                        if(l>=alturas[cont]){//testa se todas as colunas possuem altura necessaria
                            inserivel=false;
                            realloclinha(cont,l);
                        }
                        else{
                            if(jogo[cont][l]!=' '){//caso a posiçao exista e estiver ocupada == false
                                return false;
                            }
                        }
                    }
                    for(int linha=l-1;linha>=l-3;linha--){
                        if(jogo[c+1][linha]!=' ')
                            return false;
                   }
                }
                else{
                    if(l>=alturas[c]){
                        realloclinha(c,l);
                    }
                    if(l-3>=alturas[c+1]){
                        realloclinha(c+1,l-3);
                    }
                    for(int linha=l;linha>=l-3;linha--){
                        if(jogo[c][linha]!=' ')
                            return false;
                    }
                    if(jogo[c+1][l-3]!=' ')
                        return false;
                }
               
            }else{
                return false;
            }
            insereFiguraL(c,l,id,rotacao); // Caso a funçao nao encontre nenhum problema, insere e retorna true
            return true;
        }

    }  
}
void Tetris::removeLinha(int l){ //Funçao auxiliar para remover linha cheia
    for(int cont=0;cont<getNumColunas();cont++){//passa por todas as colunas
        char *aux=new char[alturas[cont]-1];//cria um auxiliar que comporta um elemento a menos
        for(int linha=0,cont2=0;linha<alturas[cont];linha++){///////passando os dados para um aux sem o elemento da linha a ser retirado
            if(linha!=l){//testando se é o elemento da linha a ser REMOVIDA
                aux[cont2]=jogo[cont][linha];      
                cont2++;
            }
        }
        delete [] jogo [cont];//deleta coluna atual
        alturas[cont]--;
        jogo[cont]=new char[alturas[cont]];//recria coluna com um elemento a menos
        for(int linha=0;linha<alturas[cont];linha++){//Passa os valores de aux pra coluna
            jogo[cont][linha]=aux[linha];
        }
        delete []aux;
    }
}
void Tetris::removeLinhasCompletas(){
    bool eligible=true;
    int linhapreenchida=0,diferentes=0;
    
    for(int linha=0;linha<getAltura();linha++){///////////teste pra saber quantas linhas podem ser testadas
        eligible=true;
        for(int cont=0;cont<getNumColunas();cont++){
            if(alturas[cont]<=linha){
                eligible=false;
            }
        }
        if(eligible){
            linhapreenchida++;//Significa que a linha está toda alocada, conta quantas linhas podem ser avaliadas
        }
    }

    for(int linha=0;linha<linhapreenchida;linha++){//percorre todas as linhas que podem ser avaliadas para ver se estao preenchidas
        diferentes=0;
        for(int coluna=0;coluna<getNumColunas();coluna++){//Conta quantos elementos da linha sao diferentes de ' '
            if(jogo[coluna][linha]!=' '){
                diferentes++;
            }
        }
        if(diferentes==getNumColunas()){//se esse valor for igual ao numero de colunas a coluna esta preenchida
            removeLinha(linha);
            linha--;//atualiza valor para a repetiçao nao dar erro
            linhapreenchida--;//diminuiu o numero de linhas preenchidas
        }
    }
     for(int cont=0;cont<coluna;cont++){//Verificando os "pixels" que ficaram vazios
        if(alturas[cont]==1 && jogo[cont][0]==' ')
            alturas[cont]--;
    }
}
Tetris::Tetris(const Tetris &game){//cria com os dados do argumento
    jogo=new char*[game.coluna];
    coluna=game.getNumColunas();
    alturas=new int[coluna];
    for(int cont=0;cont<coluna;cont++){
        alturas[cont]=game.alturas[cont];
    }    
    for(int cont=0;cont<getNumColunas();cont++){//Passa os dados pro novo
        jogo[cont]=new char[alturas[cont]];
        for(int linha=0;linha<alturas[cont];linha++){
            jogo[cont][linha]=game.jogo[cont][linha];
        }
    }
}
Tetris & Tetris::operator=(const Tetris &game){
    if(this==&game){
        return *this;
    }
    delete [] alturas;//deleta o vetor alturas
    alturas=new int[game.coluna];//cria com o numero de colunas novo
    for(int cont=0;cont<game.coluna;cont++){//atualiza as alturas do novo jogo
        alturas[cont]=game.alturas[cont];
    }
    for(int cont=0;cont<getNumColunas();cont++){//deleta as colunas antigas
        delete [] jogo[cont];
    }
    delete [] jogo;


    ////////////////////////Transerindo os dados do jogo
    this->coluna=game.coluna;//cria novo jogo com as novo numero de colunas e transfere o conteudo
    jogo=new char*[coluna];
    for(int cont=0;cont<getNumColunas();cont++){
        jogo[cont]=new char[alturas[cont]];
        for(int linha=0;linha<alturas[cont];linha++){
            jogo[cont][linha]=game.jogo[cont][linha];
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    return *this;
}

