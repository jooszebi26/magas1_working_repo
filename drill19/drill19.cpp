#include "std_lib_facilities.h"

template<typename T>
struct S
{
    
    S() {}
    S(T t): val(t){}

    S& operator=(T tt) {val = tt; return *this;}
    
    void set(T t) { val = t;}
    const T& get() const {return val;}

    T& get_non_const() {return val;}

    private:
        T val;
};

template<typename T>
const T& get(S<T>& s)
{
    return s.get();
}

template<typename T>
void read_val(T& v)
{
    cin >> v;
}


int main()
{
    S<int> var1;
    cout << "Int: "; 
    read_val(var1.get_non_const());
    cout << get(var1) << endl;

    S<char> var2;
    cout << "Char: "; 
    read_val(var2.get_non_const());
    cout << get(var2) << endl;
    
    S<double> var3;
    cout << "Double: "; 
    read_val(var3.get_non_const());
    cout << var3.get() << endl;

    S<string> var4;
    cout << "String: "; 
    read_val(var4.get_non_const());
    cout << var4.get() << endl;

    S<vector<int>> my_vector(vector<int>(5,15));
    for(int i: get(my_vector)){cout << i << endl;}

    return 0;
}
