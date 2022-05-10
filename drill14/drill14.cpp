##include "std_lib_facilities.h"

class B1 
{
public:
    virtual void vf() { cout << "B1::vf " << "\n"; }
    void f() { cout << "B1::f" << "\n"; }
    virtual void pvf() = 0;
};

class D1 : public B1
{
public:
    void vf() override { cout << "D1::vf" << "\n"; }
    void f() { cout << "D1::f" << "\n"; }
    void pvf() override { cout << "D1::pvf" << "\n"; }
};

class D2 : public D1
{
public:
    void pvf() override { cout << "D2::pvf" << "\n"; }
};

class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    string s;    
    void pvf() override { cout << s << "\n"; }
};

class D22 : public B2
{
public:
    int i;    
    void pvf() override { cout << i << "\n"; }
    void f(B2& b2r) { b2r.pvf(); }
};

int main()
{
    D1 d1;
    d1.vf();
    d1.f();
    d1.pvf();

    B1& b1r = d1;       //a B1 referencia nem latja D1 f()-et
    b1r.vf();           // -->B1 f()-et hivja
    b1r.f();

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    D21 d21;
    d21.s = "String data.";

    D22 d22;
    d22.i = 15;

    d22.f(d21);
    d22.f(d22);

    return 0;
}