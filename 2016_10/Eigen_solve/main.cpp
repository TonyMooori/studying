#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

// g++ -o main main.cpp -I E:\dev\Eigen-3.2.8\

using namespace std;
using namespace Eigen;

int main(void){
    Matrix3f A;
    Vector3f b;
    
    A << 1,2,3, 4,5,6, 7,8,10;
    b << 3,3,4;
    
    // https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html
    //Vector3f x = A.colPivHouseholderQr().solve(b);
    //Vector3f x = A.fullPivLu().solve(b);
    //Vector3f x = A.partialPivLu().solve(b);
    //Vector3f x = A.colPivHouseholderQr().solve(b);
    Vector3f x = A.fullPivHouseholderQr().solve(b);
    cout << "-----------------------------" << endl;
    cout << b << endl;
    cout << "-----------------------------" << endl;
    cout << A * x<< endl;
    cout << "-----------------------------" << endl;
    cout << "Accuracy:\t" << (A*x - b).norm() / b.norm() << endl;
    
    return 0;
}
