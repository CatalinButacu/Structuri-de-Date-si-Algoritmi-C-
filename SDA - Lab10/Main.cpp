#include <iostream>
#include <fstream>
#include "Functii.h"
#include "Nod.h"

int main() 
{
    //1)
#if 0
    Nod* Hash[M];
    for (int i = 0; i < M; i++)
        Hash[i] = new Nod();
    std::string line;
    std::ifstream myfile("Dictionar.txt");

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            Inserare(Hash, line, M);
        }
        myfile.close();
    }
    else 
        std::cout << "Unable to open file";

    Afisare(Hash);

    std::cout << std::endl << "cuvantul de verificat = ";
    std::cin >> line;
    while (line != "0")
    {
        std::cout<<"Este corect? "<< Corect(Hash, line) <<std::endl; 
        std::cout << "cuvantul de verificat = ";
        std::cin >> line;
    }

    std::cout << "cuvantul de sters = ";
    std::cin >> line;
    std::cout << std::endl;
    Stergere(Hash, line);
    Afisare(Hash);
#endif

    //2)
#if 0
    Nod* H11[M1],*H12[M1],*H13[M1],*H21[M2],*H22[M2],*H23[M2],*H31[M3],*H32[M3],*H33[M3];
    for (int i = 0; i < M1; i++)
    {
        H11[i] = new Nod();
        H12[i] = new Nod();
        H13[i] = new Nod();
    }
    for (int i = 0; i < M2; i++)
    {
        H21[i] = new Nod();
        H22[i] = new Nod();
        H23[i] = new Nod();
    }
    for (int i = 0; i < M3; i++)
    {
        H31[i] = new Nod();
        H32[i] = new Nod();
        H33[i] = new Nod();
    }

    std::string line;
    std::ifstream myfile("Dictionar.txt");

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            Inserare (H11, line, M1);
            Inserare2(H12, line, M1);
            Inserare3(H13, line, M1);

            Inserare (H21, line, M2);
            Inserare2(H22, line, M2);
            Inserare3(H23, line, M2);

            Inserare (H31, line, M3);
            Inserare2(H32, line, M3);
            Inserare3(H33, line, M3);
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    std::cout << "   " << "f1      " << "f2      " << "f3      " << std::endl;
    std::cout << "M1 " << Clusterizare(H11,M1) << " " << Clusterizare(H12,M1) << " " << Clusterizare(H13, M1) << std::endl;
    std::cout << "M2 " << Clusterizare(H21, M2) << " " << Clusterizare(H22, M2) << " " << Clusterizare(H23, M2) << std::endl;
    std::cout << "M3 " << Clusterizare(H31, M3) << " " << Clusterizare(H32, M3) << " " << Clusterizare(H33, M3) << std::endl;
#endif

    //3)
#if 0
    Nod2* Hash[26];
    for (int i = 0; i < 26; i++)
    {
        Hash[i] = new Nod2();
        Hash[i]->cheie = i + 65;
    }

    std::string text;
    std::cout << "Introdu text:"<<std::endl;
    std::getline(std::cin, text);

    for (int i = 0; i < (int)text.length(); i++) 
    {
        Inserare(Hash,text[i],26);
    }
    Afisare(Hash,26);
#endif
    //4)
#if 0
    Nod3* Hash[100];
    for (int i = 0; i < 100; i++)
    {
        Hash[i] = new Nod3();
    }

    std::string text;
    std::cout << "Introdu textul cuvant cu cuvant:" << std::endl;
    std::cin >> text;
    while (text != "0")
    {
        Inserare(Hash,text,100);
        std::cin >> text;
    } 
    Afisare(Hash,100);
#endif
	return 0;
}