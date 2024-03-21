#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


// void foo(const int &c, int &d) //non uso memoria e non permetto di cambiare il valore
// {
// //    c++;
// }
int main()
{
    // int a = 0;
    // int c = a; //copy

    // a++;
    // cout << "c: " << c << endl;

    // const int i = 0; //Obbligatorio assegnare un valore

    // int &ref = a;

    // a++;

    // cout << "ref: " << ref << endl;

    // double d = 5.5;
    // const int ii = d;

    // const int &ref2 = ii; //Se oggetto è const anche la ref deve essere const, ma un oggetto non costante può avere una referenza costante
    // const int &ref = 5; //posso
    // const int &ref = d;
    // //equivalente a
    // double d = 5.5;
    // int temp = d; //copia non referenza
    // const int &ref = temp;
    //  //una referenza non può esere inizializzata con un literal, una const reference si
    //  //una referenza deve avere lo stesso tipo dell'oggetto con cui la inizializzo

    // int jj = 0;
    // int ii = 0;
    // foo(5, ii);

    // cout << jj << endl;
    // //step 1: int &c = jj;
    // //step 2: esegue il corpo della funzione; ora cambiamenti di c cambiano anche jj;
    // //step 3: return -> int b = valueReturn;
    // cout << "ii: " << ii << endl;

    //posso usare void, usare referenze e togliere return

    // srand(5); //settare il seme???
    // RowVector2d v = Vector2d::Ones();
    // cout << v.transpose() << endl;

    // Matrix4d A = Matrix4d::Zero();
    // MatrixXd B = MatrixXd::Zero(3, 4);

    //Resize mette utti i valori a 0
    //Conservative resize


    srand(5);
    unsigned int n = 5;
    MatrixXd A = MatrixXd::Zero(n,n);
    VectorXd v = VectorXd::LinSpaced(n*n, 1, n*n);

    // cout << v<< endl;

    // for (unsigned int =0; i<n; i++)
    // {
    //     A.row(i) = v.segment ( i*n, ,n);
    // }

    A = v.reshaped<RowMajor>(n,n);
    cout << A << endl;
    return 0;
}
