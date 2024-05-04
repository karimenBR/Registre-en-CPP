//
// Created by karimen on 5/2/24.
//
#include<iostream>
#include<string>
#define MAX 100
using namespace std;
class Registre{
protected:
    int taille;
    int *tab;
public:
    Registre(){
        taille=0;
        int *tab;
        tab=new int[taille];
        for(int i=0;i<taille;i++){
            tab[i]=0;
        }
    }
    Registre(int t = MAX){
        taille=t;
        tab=new(int[t]);
        for(int i=0;i<taille;i++){
            tab[i]=0;
        }
    }
   // Registre copy(const Registre &r){
    //    Registre *nouv;
   //     nouv=new Registre(r.taille);
    //    for(int i=0;i<r.taille;i++){
    //        nouv->tab[i]=r.tab[i];
    //    }
    //    return *nouv;
    //}
    virtual ~Registre(){
        delete[] tab;
    }
    virtual void affiiche(){
        cout<<"la taille de registre est : "<<taille<<endl;
        for(int i=0;i<taille;i++){
            cout<<tab[i];
        }
        cout<<endl;
    }
    virtual void saisir(){
        cout<<"saisir la taille du registre : ";
        cin>>taille;
        string s;
        cout<<"<------noté bien une mot mémoire contient que des 1 et des 0------>"<<endl;
        cout<<"saisir le mot mémoire : ";
        cin>>s;
        for(int i=0;i<taille;i++){
            tab[i]=s[i]-'0';
        }
    }
    Registre operator +(const Registre& r) {
        int n = max(taille, r.taille);
        Registre *nouv=new Registre(n);
        for(int i=0;i<n;i++) {
            if (tab[i] == 0 && r.tab[i] == 0) {
                nouv->tab[i] = 0;
            } else {
                if (tab[i] == 0 && r.tab[i] == 1) {
                    nouv->tab[i] = 1;
                }
                if (tab[i] == 1 && r.tab[i] == 0) {
                    nouv->tab[i] = 1;
                }
                if (tab[i] == 1 && r.tab[i] == 1) {
                    nouv->tab[i] = 0;
                    nouv->tab[i + 1] = 1;
                }
            }
        }
        return *nouv;
    }
    Registre * operator *(const Registre& r) {
        int max_size = max(taille, r.taille);
        Registre result(max_size);
        for (int i = 0; i < max_size; i++) {
            result.tab[i] = (i < taille && i < r.taille) ? (tab[i] & r.tab[i]) : 0;
        }
        return &result;
    }
    Registre& operator =(Registre& r){
        for(int i=0;i<taille;i++){
            tab[i]=r.tab[i];
        }
        return *this;
    }
    Registre operator <(int n){
        Registre *nouv;
        nouv=new Registre(taille);
        string s="";
        for(int i=0;i<taille;i++){
            s = s + (char(tab[i]+'0'));
        }
        int j = n ;
        while(j!=0){
            s="0"+s;
            j--;
        }
        nouv->taille=taille+n;
        for(int i=0;i<taille+n;i++){
            nouv->tab[i]=s[i]-'0';
        }
        return *nouv;
    }
    Registre operator >(int n){
        Registre *nouv;
        nouv=new Registre(taille);
        string s="";
        for(int i=0;i<taille;i++){
            s = s + char(tab[i]+'0');
        }
        int j = n ;
        while(j!=0){
            s=s+"0";
            j--;
        }
        nouv->taille=taille+n;
        for(int i=0;i<taille+n;i++){
            nouv->tab[i]=s[i]-'0';
        }
        return *nouv;
    }
};
int main(){
    Registre r=Registre(8);
    r.saisir();
    r.affiiche();
    Registre r2=Registre(16);
    r2.saisir();
    r2.affiiche();
    cout<<"les operations : ";
    Registre r3=r+r2;
    r3.affiiche();
    //Registre *r4;
    //8r4=r*r2;
    cout<<"les opeations < et > : ";
    Registre r5=r<3;
    cout<<"l'opération < est : "<<endl;
    r5.affiiche();
    Registre r6=r2>3;
    cout<<"l'opération > est : "<<endl;
    r6.affiiche();
    return 0;
}
