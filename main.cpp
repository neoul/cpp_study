#include <iostream>

using namespace std;

int use_string_literals();
void use_convert();
void use_typeinfo();
void use_variant();

int main() {
    cout << "Hello, World!" << endl;
    use_string_literals();
    use_convert();
    use_typeinfo();
    use_variant();
    return 0;
}