#include <iostream>
#include "Eigen/Eigen"
#include <iomanip>

using namespace std;
using namespace Eigen;


VectorXd xstar = -1 * VectorXd::Ones(2);
void palu(const Matrix2d &A,const Vector2d &b, unsigned int i){
    Vector2d x_palu = A.fullPivLu().solve(b);
    double relerr_x_palu = ((x_palu - xstar)*(1/xstar.norm())).norm();


    cout << "The relative error for the system " << i << " using PALU is " << setprecision(15) << scientific << relerr_x_palu << endl;

    return;
}

void qr(const Matrix2d &A, const Vector2d &b, unsigned int i){
    Vector2d x_qr = A.fullPivHouseholderQr().solve(b);
    double relerr_qr = ((x_qr-xstar)*1/(xstar).norm()).norm();
    cout << "The relative error for the system " << i << " using QR is "<< scientific << relerr_qr << endl;
    return;
}

int main()
{
    Matrix2d A1;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01, -9.992887623566787e-01;

    Matrix2d A2;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01, -8.324762492991313e-01;

    Matrix2d A3;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01, -8.320502947645361e-01;

    Vector2d b1 = {-5.169911863249772e-01, 1.672384680188350e-01};
    Vector2d b2 = {-6.394645785530173e-04, 4.259549612877223e-04};
    Vector2d b3 = {-6.400391328043042e-10, 4.266924591433963e-10};

    palu(A1,b1, 1);
    palu(A2,b2, 2);
    palu(A3,b3, 3);

    qr(A1,b1, 1);
    qr(A2,b2, 2);
    qr(A3,b3, 3);

  return 0;
}
