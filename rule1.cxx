// template<typename T>     //
// void f(ParamType param)  //
// f(expr)                  //
//
// there are three kinds of induction of param and T type

#include <utility> 
#include <iostream>
#include <string>


using namespace std;

// situation 1, ParamType is reference or pointer, but not universal reference
template<typename T>
void f1(T& param, string prefix = "")
{
    bool is_int = std::is_same<T, int>::value;
    bool is_const_int = std::is_same<T, const int>::value;
    cout << prefix << ", " << "is_int: " << is_int << ", is_const_int: " << is_const_int << endl;
}

// situation 2, ParamType add reference
template<typename T>
void f2(const T& param, string prefix = "")
{
    bool is_int = std::is_same<T, int>::value;
    bool is_const_int = std::is_same<T, const int>::value;
    cout << prefix << ", " << "is_int: " << is_int << ", is_const_int: " << is_const_int << endl;
}

// situation 3, ParamType is Universal reference
template<typename T>
void f3(T&& param, string prefix = "")
{
    bool is_int = std::is_same<T, int>::value;
    bool is_int_ref = std::is_same<T, int&>::value;
    bool is_const_int_ref = std::is_same<T, const int&>::value;
    bool is_rvalue_int_ref = std::is_same<T, int&&>::value;
    cout << prefix << ", " << "is_int: " << is_int << ", is_int_ref: " << is_int_ref << ", is_const_int_ref: " << is_const_int_ref << endl;
}

int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = x;
    cout << "void f2(T& param)" << endl;
    f1(x, "x");  // T is int, ParamType is int&
    f1(cx, "cx"); // T is const int, ParamType is const int&
    f1(rx, "rx"); // T is const int, ParamType is const int&, T will ignore ref of rx
    cout << "void f2(const T& param)" << endl;
    f2(x, "x");  // T is int, ParamType is int&
    f2(cx, "cx"); // T is int, ParamType is const int&, remove const in cx
    f2(rx, "rx"); // T is int, ParamType is const int&, remove const and ref in rx
    cout << "void f3(T&& param)" << endl;
    f3(x, "x");  // T is int&, ParamType is int&
    f3(cx, "cx"); // T is const int&, ParamType is const int&
    f3(rx, "rx"); // T is const int&, ParamType is const int&
    f3(27, "27"); // T is int, ParamType is int&&
}
