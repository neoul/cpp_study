#include <string>
#include <iostream>
using namespace std;
using namespace std::string_literals;
int use_string_literals()
{
  cout << "it requires c++14" << endl;
  // Character literals
  auto c0 = 'A'; // char
  // auto c1 = u8'A'; // char
  auto c2 = L'A'; // wchar_t
  auto c3 = u'A'; // char16_t
  auto c4 = U'A'; // char32_t

  // Multicharacter literals
  auto m0 = '한'; // int, value 0x61626364

  // String literals
  auto s0 = "hello";   // const char*
  auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                       // const char8_t* in C++20
  auto s2 = L"hello";  // const wchar_t*
  auto s3 = u"hello";  // const char16_t*, encoded as UTF-16
  auto s4 = U"hello";  // const char32_t*, encoded as UTF-32

  // Raw string literals containing unescaped \ and "
  auto R0 = R"("Hello \ world")";   // const char*
  auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                    // const char8_t* in C++20
  auto R2 = LR"("Hello \ world")";  // const wchar_t*
  auto R3 = uR"("Hello \ world")";  // const char16_t*, encoded as UTF-16
  auto R4 = UR"("Hello \ world")";  // const char32_t*, encoded as UTF-32

  // not supported in c++14
  // // Combining string literals with standard s-suffix
  // auto S0 = "hello"s;   // std::string
  // // auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
  // auto S2 = L"hello"s;  // std::wstring
  // auto S3 = u"hello"s;  // std::u16string
  // auto S4 = U"hello"s;  // std::u32string

  // // Combining raw string literals with standard s-suffix
  // auto S5 = R"("Hello \ world")"s;   // std::string from a raw const char*
  // auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
  //                                    // std::u8string in C++20
  // auto S7 = LR"("Hello \ world")"s;  // std::wstring from a raw const wchar_t*
  // auto S8 = uR"("Hello \ world")"s;  // std::u16string from a raw const char16_t*, encoded as UTF-16
  // auto S9 = UR"("Hello \ world")"s;  // std::u32string from a raw const char32_t*, encoded as UTF-32
  cout << "c0: " << c0 << endl;
  cout << "c2: " << c2 << endl;
  cout << "c3: " << c3 << endl;
  cout << "c4: " << c4 << endl;
  cout << "m0: " << m0 << endl;
  cout << "s0: " << s0 << endl;
  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;
  cout << "s3: " << s3 << endl;
  cout << "s4: " << s4 << endl;
  cout << "R0: " << R0 << endl;
  cout << "R1: " << R1 << endl;
  cout << "R2: " << R2 << endl;
  cout << "R3: " << R3 << endl;
  cout << "R4: " << R4 << endl;
  // cout << "S0: " << S0 << endl;
  // cout << "S1: " << S1 << endl;
  // cout << "S2: " << S2 << endl;
  // cout << "S3: " << S3 << endl;
  // cout << "S4: " << S4 << endl;
  // cout << "S5: " << S5 << endl;
  // cout << "S6: " << S6 << endl;
  // cout << "S7: " << S7 << endl;
  // cout << "S8: " << S8 << endl;
  // cout << "S9: " << S9 << endl;
  return 0;
}