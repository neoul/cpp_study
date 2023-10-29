#include <iostream>

struct A
{
    double d;
};

int main()
{
    int num = 0;
    int &ref_num = num;
    int &&rref_num = 1;
    rref_num = 3;
    
    std::cout << "num: " << num << ", ref_num: " << ref_num << ", rref_num: " << rref_num << "\n";
    int a = 3;
    decltype(a) b = 2; // int

    int &r_a = a;
    decltype(r_a) r_b = b; // int&

    int &&x = 3;
    decltype(x) y = 2; // int&&

    A *aa;
    decltype(aa->d) dd = 0.1; // double
}