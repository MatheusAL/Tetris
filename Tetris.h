#ifndef __TETRIS_H
#define __TETRIS_H

#include <iostream>
class Tetris{
    private:
            char **jogo;
            int coluna;
            int *alturas;
            char i[4][1]={{'I'},
                        {'I'},
                        {'I'},
                        {'I'}
            };
            char j[2][4]={{'J','J','J','J'},
                        {' ',' ',' ','J'}
            };
            char L[2][4]{{'L','L','L','L'},
                        {'L',' ',' ',' '}
            };
            char o[2][2]={{'O','O'},
                        {'O','O'}
            };
            char s[2][3]={{' ','S','S'},
                        {'S','S',' '}
            };
            char t[2][3]={{'T','T','T'},
                        {' ','T',' '}
            };
            char z[2][3]={{'Z','Z',' '},
                        {' ','Z','Z'}
            };
            
    public:
    Tetris(int c);
    int getAltura() const;
    char get(int c,int l)const;
    void removeColuna(int c);
    void removeLinhasCompletas();
    void removeLinha(int l);
    int getNumColunas()const;
    int getAltura(int c)const;
    bool adicionaForma(int c,int l,char id,int rotacao);
    void insereFiguraT(int c,int l,char id,int rotacao);
    void insereFiguraO(int c,int l,char id,int rotacao);
    void insereFiguraI(int c,int l,char id,int rotacao);
    void insereFiguraZ(int c,int l,char id,int rotacao);
    void insereFiguraS(int c,int l,char id,int rotacao);
    void insereFiguraJ(int c,int l,char id,int rotacao);
    void insereFiguraL(int c,int l,char id,int rotacao);
    Tetris & operator=(const Tetris teste);
    void realloclinha(int c,int l);
    ~Tetris();
    void preenche(); 

};



#endif