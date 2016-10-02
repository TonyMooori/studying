#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

// g++ -o main main.cpp -I E:\dev\Eigen-3.2.8\

using namespace std;
using namespace Eigen;

int main(void){
    Vector2f v1;
    Vector2f v2( 1.0, 0.0);
    Vector3f v3( 0.0, 1.0, -1.0);
    Matrix3d mat_33;
    MatrixXd mat_22(2,2);   // サイズを指定できる
    string line = "----------------------------------------";
    
    v1 << 0.0, 0.0;
    mat_33 << 
        1.0, 1.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0;
    
    mat_22 << 
        0.0 , -1.0,
        1.0 , 0.0;
    
    cout << v1 << endl;
    cout << line << endl;
    cout << v2 << endl;
    cout << line << endl;
    cout << v3 << endl;
    cout << line << endl;
    cout << mat_33 << endl;
    cout << line << endl;
    cout << mat_33 * mat_33<< endl;
    cout << line << endl;
    cout << mat_33 * mat_33 * mat_33 << endl;
    cout << line << endl;
    cout << mat_22 << endl;
    cout << line << endl;
    cout << mat_22 * mat_22<< endl;
    cout << line << endl;
    cout << mat_22 * mat_22 * mat_22 << endl;
    cout << line << endl;
    
    return 0;
}
