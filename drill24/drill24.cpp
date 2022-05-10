#include <complex>
#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

template<typename T>
void print_1D(Matrix<T>& a)
{
    for(int i=0; i<a.dim1(); ++i)
    {
        cout << a(i) << "\t";
    }
    cout << "\n";
}

int main()
{
    cout << "---------------------1---------------------" << "\n";

    cout << "Char size: " << sizeof(char) << "\n";
    cout << "Short size: " << sizeof(short) << "\n";
    cout << "Int size: " << sizeof(int) << "\n";
    cout << "Long size: " << sizeof(long) << "\n";
    cout << "Float size: " << sizeof(float) << "\n";
    cout << "Double size: " << sizeof(double) << "\n";
    cout << "Int* size: " << sizeof(int*) << "\n";
    cout << "Double* size: " << sizeof(double*) << "\n";

    cout << "---------------------2 & 3---------------------" << "\n";

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "Matrix size 'a': " << sizeof(a) << " Number of elements: " << a.size() << "\n";
    cout << "Matrix size 'b': " << sizeof(b) << " Number of elements: " << b.size() << "\n";
    cout << "Matrix size 'c': " << sizeof(c) << " Number of elements: " << c.size() << "\n";
    cout << "Matrix size 'd': " << sizeof(d) << " Number of elements: " << d.size() << "\n";
    cout << "Matrix size 'e': " << sizeof(e) << " Number of elements: " << e.size() << "\n";

    print_1D(a);
    print_1D(b);
    print_1D(c);

    cout << "---------------------4---------------------" << "\n";

    cout << "Enter ints." << "\n";

    for(int i = 0; i < 5; i++)
    {
        int x = 0;
        cin >> x;
        if(x < 0)
            cout << "no square root" << "\n";
        else
            cout << "Square root: " << sqrt(x) << "\n";     

    }

    cout << "---------------------5---------------------" << "\n";

    Matrix<double,1> ten_doubles(10);
    ifstream ist {"doubles.txt"};

    double dv;
    for (int i = 0; i < 10; ++i)
    	ist >> ten_doubles[i];

    print_1D(ten_doubles);
        
    cout << "---------------------6---------------------" << "\n";

    int n; int m;
    cout << "n value: "; cin >> n;
    cout << "m value: "; cin >> m;
    Matrix<int,2> m_table(n,m);

    for(int i = 0; i < m_table.dim1(); i++)
    {
        for(int j = 0; j < m_table.dim2(); j++)
        {
            m_table(i,j) = (i+1)*(j+1);
        }
    }
    cout << m_table << "\n";

    cout << "---------------------7---------------------" << "\n";

    Matrix<complex<double>> ten_complex(10);
    cout << "Enter 10 complex number." << "\n";
    for (int i=0; i<ten_complex.size(); ++i) 
    {
        cin >> ten_complex[i];
    }

    complex<double> sum;
     for (int i = 0; i<ten_complex.size(); ++i)
        sum += ten_complex[i];
    cout << "Sum: " << sum << "\n";

    cout << "---------------------7---------------------" << "\n";

    Matrix<int,2> six_ints(2,3);
    cout << "Enter six ints." << "\n";

    for(int i=0; i<six_ints.dim1(); i++)
        for(int j=0; j<six_ints.dim2(); j++)
        {
            cin >> six_ints(i, j);
        }
    cout << six_ints << "\n";

    return 0;
}