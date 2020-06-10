#include <iostream>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <time.h>

using namespace std;

class Pole{
    public:
    int x,y;
    int zajete;
    int gora,dol,lewo,prawo;
    char znak;
};

    const int X=70; const int Y=20;
    Pole lab[Y][X];
    int x=1; int y=1;
    Pole* tak_nie[4];
    int ile;
    int wybor;
    list <Pole> stos;
    list <Pole>::iterator it;

void wyswietl()
{

    for(int i=0;i<Y;i++)
        for(int j=0;j<X;j++){
            if(lab[i][j].gora==1&&lab[i][j].prawo==1&&lab[i][j].dol==1&&lab[i][j].lewo==1)
                lab[i][j].znak=206;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==1&&lab[i][j].dol==1&&lab[i][j].lewo==0)
                lab[i][j].znak=204;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==1&&lab[i][j].dol==0&&lab[i][j].lewo==1)
                lab[i][j].znak=202;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==0&&lab[i][j].dol==1&&lab[i][j].lewo==1)
                lab[i][j].znak=185;
            else if(lab[i][j].gora==0&&lab[i][j].prawo==1&&lab[i][j].dol==1&&lab[i][j].lewo==1)
                lab[i][j].znak=203;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==1&&lab[i][j].dol==1&&lab[i][j].lewo==1)
                lab[i][j].znak=203;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==1&&lab[i][j].dol==0&&lab[i][j].lewo==0)
                lab[i][j].znak=200;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==0&&lab[i][j].dol==1&&lab[i][j].lewo==0)
                lab[i][j].znak=186;
            else if(lab[i][j].gora==0&&lab[i][j].prawo==1&&lab[i][j].dol==1&&lab[i][j].lewo==0)
                lab[i][j].znak=201;
            else if(lab[i][j].gora==1&&lab[i][j].prawo==0&&lab[i][j].dol==0&&lab[i][j].lewo==1)
                lab[i][j].znak=188;
            else if(lab[i][j].gora==0&&lab[i][j].prawo==1&&lab[i][j].dol==0&&lab[i][j].lewo==1)
                lab[i][j].znak=205;
            else if(lab[i][j].gora==0&&lab[i][j].prawo==0&&lab[i][j].dol==1&&lab[i][j].lewo==1)
                lab[i][j].znak=187;
            else
                lab[i][j].znak=' ';
        }

    system("cls");
    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            cout<<lab[i][j].znak;
        }
        cout<<endl;
    }
}

void ustal()
{
    ///NIE JEST W UZYCIU
    if(lab[y][x].gora==1&&lab[y][x].prawo==1&&lab[y][x].dol==1&&lab[y][x].lewo==1)
        lab[y][x].znak=206;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==1&&lab[y][x].dol==1&&lab[y][x].lewo==0)
        lab[y][x].znak=204;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==1&&lab[y][x].dol==0&&lab[y][x].lewo==1)
        lab[y][x].znak=202;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==0&&lab[y][x].dol==1&&lab[y][x].lewo==1)
        lab[y][x].znak=185;
    else if(lab[y][x].gora==0&&lab[y][x].prawo==1&&lab[y][x].dol==1&&lab[y][x].lewo==1)
        lab[y][x].znak=203;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==1&&lab[y][x].dol==1&&lab[y][x].lewo==1)
        lab[y][x].znak=203;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==1&&lab[y][x].dol==0&&lab[y][x].lewo==0)
        lab[y][x].znak=200;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==0&&lab[y][x].dol==1&&lab[y][x].lewo==0)
        lab[y][x].znak=186;
    else if(lab[y][x].gora==0&&lab[y][x].prawo==1&&lab[y][x].dol==1&&lab[y][x].lewo==0)
        lab[y][x].znak=201;
    else if(lab[y][x].gora==1&&lab[y][x].prawo==0&&lab[y][x].dol==0&&lab[y][x].lewo==1)
        lab[y][x].znak=188;
    else if(lab[y][x].gora==0&&lab[y][x].prawo==1&&lab[y][x].dol==0&&lab[y][x].lewo==1)
        lab[y][x].znak=205;
    else if(lab[y][x].gora==0&&lab[y][x].prawo==0&&lab[y][x].dol==1&&lab[y][x].lewo==1)
        lab[y][x].znak=187;
    else
        lab[y][x].znak=' ';
}

void wypelnij()
{
    for(int i=0;i<Y;i++)
        for(int j=0;j<X;j++){
            lab[i][j].gora=0;
            lab[i][j].prawo=0;
            lab[i][j].dol=0;
            lab[i][j].lewo=0;
            lab[i][j].zajete=0;
            lab[i][j].x=j;
            lab[i][j].y=i;
        }
    for(int i=0;i<Y;i++){
        lab[i][0].zajete=2;
        lab[i][X-1].zajete=2;
    }
    for(int i=0;i<X;i++){
        lab[0][i].zajete=2;
        lab[Y-1][i].zajete=2;
    }
}

void sprawdz()
{
    if(lab[y-1][x].zajete==0){
        tak_nie[ile]=&(lab[y-1][x]);
        ile++;
    }
    if(lab[y][x+1].zajete==0){
        tak_nie[ile]=&(lab[y][x+1]);
        ile++;
    }
    if(lab[y+1][x].zajete==0){
        tak_nie[ile]=&(lab[y+1][x]);
        ile++;
    }
    if(lab[y][x-1].zajete==0){
        tak_nie[ile]=&(lab[y][x-1]);
        ile++;
    }
}

void cofnij()
{
    lab[y][x].zajete='1';
    it=stos.end();
    --it;
    x=(*it).x;
    y=(*it).y;
    stos.pop_back();
}

void przejdz()
{
    if((*tak_nie[wybor]).y==y-1){
        lab[y][x].gora=1;
        lab[y][x].zajete=1;
        lab[y-1][x].dol=1;
        stos.push_back(lab[y][x]);
        y--;
    }
    else if((*tak_nie[wybor]).x==x+1){
        lab[y][x].prawo=1;
        lab[y][x].zajete=1;
        lab[y][x+1].lewo=1;
        stos.push_back(lab[y][x]);
        x++;
    }
    else if((*tak_nie[wybor]).y==y+1){
        lab[y][x].dol=1;
        lab[y][x].zajete=1;
        lab[y+1][x].gora=1;
        stos.push_back(lab[y][x]);
        y++;
    }
    else if((*tak_nie[wybor]).x==x-1){
        lab[y][x].lewo=1;
        lab[y][x].zajete=1;
        lab[y][x-1].prawo=1;
        stos.push_back(lab[y][x]);
        x--;
    }
}

int main()
{
    srand(time(NULL));
    wypelnij();
    ///PETLA GLOWNA
    while(lab[1][2].zajete==0||lab[2][1].zajete==0||x!=1||y!=1){
        ///WYZEROWANIE
        tak_nie[0]=tak_nie[1]=tak_nie[2]=tak_nie[3]=NULL;
        ile=0;
        ///SPRAWDZENIE MOZLIWOSCI
        sprawdz();
        ///COFNIECIE JESLI BRAK MOZLIWOSCI
        if(tak_nie[0]==NULL){
                cofnij();
        }
        ///WYBOR JESLI JEST MOZLIWOSC
        else{
            //wyswietl();
            ///LOSOWANIE MOZLIWOSCI
            wybor=rand()%ile;
            ///PRZEJSCIE DALEJ
            przejdz();
        }
    }
    wyswietl();
    return 0;
}
