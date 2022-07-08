#include<iostream>

// 1)
void Schimba(int& a,int& b) 
{
    int aux = a;
    a = b;
    b = aux;
}
void Insert(int A[],int N,int X) 
{
    if (N < 0)
        return;
    if (N == 0) 
    {
        A[N] = X;
        return;
    }
    A[N] = X;
    int fiu = N;
    int parinte = fiu / 2 + fiu % 2 - 1;
    int aux;
    while (true)
    { 
        if (parinte < 0)
            break;
        if (A[parinte] < A[fiu])
        {
            Schimba(A[fiu], A[parinte]);
            fiu = parinte;
            parinte = fiu / 2 + fiu % 2 - 1;
        }
        else
            break;
    }
}
int  Remove(int A[],int& N) 
{
    if (N == 0)
        return -1;
    if (N == 1) 
    {
        int ret_val = A[0];
        N--;
        return ret_val;
    }
    else
    {
        int ret_val = A[0];
        A[0] = A[N-1];
        int nod = 0;
        int aux;
        while (nod * 2 + 2 < N)
        {
            if (A[nod] <= A[nod * 2 + 1]  && A[nod] <= A[nod * 2 + 2])
            {
                if (A[nod * 2 + 2] < A[nod * 2 + 1])
                {
                    Schimba(A[nod * 2 + 1], A[nod]);
                    nod = nod * 2 + 1;
                }
                else 
                {
                    Schimba(A[nod * 2 + 2], A[nod]);
                    nod = nod * 2 + 2;
                }
            }
            else if (A[nod] <= A[nod * 2 + 1]) 
            {
                Schimba(A[nod * 2 + 1], A[nod]);
                nod = nod * 2 + 1;
            }
            else if (A[nod] <= A[nod * 2 + 2]) 
            {
                Schimba(A[nod * 2 + 2], A[nod]);
                nod = nod * 2 + 2;
            }
            else
                break;
        }
        if (nod * 2 + 1 < N && A[nod] < A[nod * 2 + 1])
        {
            Schimba(A[nod * 2 + 1], A[nod]);
        }
        N--;
        return ret_val;
    }

}
void Afisare(int A[], int N)
{
    if (N <= 0)
        return;
    for (int i = 0; i < N; i++) 
    {
        std::cout<< A[i] << " ";
    }
    std::cout << std::endl;
}
void Afisare_Inordine(int A[],int N, int nod) 
{
    if (nod * 2 + 1 < N)
        Afisare_Inordine(A,N, nod * 2 + 1);
    std::cout << A[nod] << " ";
    if (nod * 2 + 2 < N)
        Afisare_Inordine(A, N, nod * 2 + 2);
}

// 2)
void Retro(int A[],int N,int i) 
{
    int parinte = i;
    int fiu = i * 2 + 1;
    int aux;
    while (fiu < N) 
    {
        if (fiu + 1 < N && A[fiu] < A[fiu + 1]) 
        {
            fiu = fiu + 1;
        }
        if (A[fiu] > A[parinte]) 
        {
            Schimba(A[fiu], A[parinte]);
            parinte = fiu;
            fiu = fiu * 2 + 1;
        }
        else
            return;
    }
}
void BuildHeap_v1(int A[], int N) 
{
    for (int i = 1; i < N; i++) 
    {
        Insert(A, i, A[i]);
    }
}
void BuildHeap_v2(int A[], int N) 
{
    for (int i = N / 2 + N % 2 - 1; i >= 0; i--) 
    {
        Retro(A,N,i);
    }
}
void Heapsort(int A[], int N) 
{
    int i = N;
    while (i > 1)
    {
        A[i] = Remove(A, i);
    }
}
