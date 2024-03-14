

#include <iostream>

using namespace std;

int factoriel(int x)
{
    if (x < 0)
       throw x;
    else
    {
    int fact = 1;
    for(int i = 2; i <= x; i++)
        fact *= i;
    return(fact);

    }
}

int main()
{
    int A;
    cin >> A;

    try{
        int R = factoriel(A);
        cout << A << "! = " << R << endl; 
    }catch(int e){
        cerr << "impossible" << endl;
    }
  
    // if (A < 0)
    // cerr << "impossible" << endl;
    // else 
    cout << factoriel(A) << endl;
    return(0);
}