#include<iostream>
#include <string>
#include "Functii.h"

// 1)
int f(std::string key)
{
    int suma;
    suma = 0;
    for (int i = 0; i < (int)key.length(); i++)
    {
        if (key[i] != ' ')
        {
            suma = suma + key[i];
        }
    }
    return suma % M;
}
void Inserare(Nod* Hash[],std::string cheie) 
{
    int index = f(cheie);
    Nod* p = Hash[index];
    if (p->cheie == "")
    {
        p->cheie = cheie;
        return;
    }
    while (p->urm != nullptr)
        p = p->urm;
    p->urm = new Nod;
    p->urm->cheie = cheie;
}
bool Corect(Nod* Hash[], std::string cheie) 
{
    int index = f(cheie);
    Nod* p = Hash[index];

    while (p->urm != nullptr) 
    {
        if (p->cheie == cheie)
            return true;
        p = p->urm;
    }
    if (p->cheie == cheie)
        return true;
    return false;
}
void Afisare(Nod* Hash[]) 
{
    Nod* p = nullptr;
    for (int i = 0; i < M; i++) 
    {
        p = Hash[i];
        while (p->urm != nullptr)
        {
            std::cout << p->cheie << " ";
            p = p->urm;
        }
        std::cout << p->cheie << " ";
        std::cout << std::endl;
    }
}
void Stergere(Nod* Hash[], std::string cheie)
{
    if (Hash == nullptr) 
    {
        std::cout << "Elementul nu exista" << std::endl;
        return;
    }
    int index = f(cheie);
    Nod* q = Hash[index];
    Nod* p = q->urm;

    if (q->cheie == cheie) 
    {
        if (p == nullptr)
            p = new Nod();
        Hash[index] = p;
        delete q;
        return;
    }

    if (p != nullptr)
    {
        while (p->urm != nullptr)
        {
            if (p->cheie == cheie)
            {
                q->urm = p->urm;
                delete p;
                return;
            }
            p = p->urm;
            q = q->urm;
        }
        if (p->cheie == cheie)
        {
            q->urm = nullptr;
            delete p;
            return;
        }
    }

    std::cout << "Elementul nu exista" << std::endl;
    return;
}

// 2)
int f(std::string key, int m)
{
    int suma;
    suma = 0;
    for (int i = 0; i < (int)key.length(); i++)
    {
        if (key[i] != ' ')
        {
            suma = suma + key[i];
        }
    }
    return suma % m;
}
int f2(std::string key,int m) 
{
    double suma = 0;
    for (int i = 0; i < (int)key.length(); i++)
    {
        if (key[i] != ' ')
        {
            suma = suma + key[i];
        }
    }
    return (int)(m * ((A * suma) - (int)(A * suma)));
}
int f3(std::string key, int m)
{
    int h = 0, highorder;
    int len = key.length();
    for (int i = 0; i < len; i++) {
        //shiftare circulara la stanga cu 5 pozitii
        highorder = h & 0xf8000000;
        h << 5;
        h = h ^ (highorder >> 27);
        //---> end shiftare
        h = h ^ key[i];
    }
    return h % M;
}

void Inserare(Nod* Hash[], std::string cheie, int m)
{
    int index = f(cheie, m);
    Nod* p = Hash[index];
    if (p->cheie == "")
    {
        p->cheie = cheie;
        return;
    }
    while (p->urm != nullptr)
        p = p->urm;
    p->urm = new Nod;
    p->urm->cheie = cheie;
}
void Inserare2(Nod* Hash[], std::string cheie, int m)
{
    int index = f2(cheie,m);
    Nod* p = Hash[index];
    if (p->cheie == "")
    {
        p->cheie = cheie;
        return;
    }
    while (p->urm != nullptr)
        p = p->urm;
    p->urm = new Nod;
    p->urm->cheie = cheie;
}
void Inserare3(Nod* Hash[], std::string cheie, int m)
{
    int index = f3(cheie,m);
    Nod* p = Hash[index];
    if (p->cheie == "")
    {
        p->cheie = cheie;
        return;
    }
    while (p->urm != nullptr)
        p = p->urm;
    p->urm = new Nod;
    p->urm->cheie = cheie;
}

int Numarare(Nod* Hash[], int pos)
{
    Nod* p = Hash[pos];
    int count=0;
    while (p != nullptr && p->cheie != "") 
    {
        count++;
        p = p->urm;
    }
    return count;
}
double Clusterizare(Nod* Hash[],int m) 
{
    int n;
    double C=0;
    for (int i = 0; i < m; i++) 
    {
        n = Numarare(Hash, i);
        C = C + ((double)n * n) / N;
    }
    return C - N / m;
}

 // 3)
void Inserare(Nod2* Hash[], char cheie, int m)
{
    if (std::toupper(cheie) >= 65 && std::toupper(cheie) <= 90)
    {
        int index = std::toupper(cheie) - 65;
        Nod2* p = Hash[index];
        if (p->cheie == ' ')
        {
            p->cheie = std::toupper(cheie);
            return;
        }
        while (p->urm != nullptr)
        {
            if (p->cheie == std::toupper(cheie))
            {
                p->nr++;
                return;
            }
            p = p->urm;
        }
        if (p->cheie == std::toupper(cheie))
        {
            p->nr++;
            return;
        }
        p->urm = new Nod2;
        p->urm->cheie = std::toupper(cheie);
    }
}
void Afisare(Nod2* Hash[], int m)
{
    Nod2* p = nullptr;
    for (int i = 0; i < m; i++)
    {
        p = Hash[i];
        if (p->cheie != ' ')
        {
            while (p->urm != nullptr)
            {
                std::cout << p->cheie << " " << p->nr << std::endl;
                p = p->urm;
            }
            std::cout << p->cheie << " " << p->nr << std::endl;
        }
    }
}

 // 4)
void Inserare(Nod3* Hash[], std::string cheie, int m)
{
    int index = f(cheie,m);
    Nod3* p = Hash[index];
    if (p->cheie == "")
    {
        p->cheie = cheie;
        return;
    }
    while (p->urm != nullptr)
    {
        if (p->cheie == cheie)
        {
            p->nr++;
            return;
        }
        p = p->urm;
    }
    if (p->cheie == cheie)
    {
        p->nr++;
        return;
    }
    p->urm = new Nod3;
    p->urm->cheie = cheie;
    
}
void Afisare(Nod3* Hash[], int m)
{
    Nod3* p = nullptr;
    for (int i = 0; i < m; i++)
    {
        p = Hash[i];
        if (p->cheie != "")
        {
            while (p->urm != nullptr)
            {
                std::cout << p->cheie << " " << p->nr << std::endl;
                p = p->urm;
            }
            std::cout << p->cheie << " " << p->nr << std::endl;
        }
    }
}