#include <codecvt>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

void use_convert()
{
    std::setlocale(LC_ALL, "");
    std::ios_base::sync_with_stdio(true);

    // std::locale utf8( std::locale(), new std::codecvt_utf8_utf16<wchar_t> );
    // std::locale utf8( std::locale(), new std::codecvt_utf8<wchar_t> );
    // std::wcout.imbue(utf8);

    std::wstring w(L"한글");
    std::wcout << w << '\n';

    int x, y;
    wchar_t str[20];
	// wcout << L"Enter 2 integers:";
	// wcin >> x >> y;
	// wcout << L"Sum = " << (x+y) << endl;
	
	// wcout << L"Enter a string:" << endl;
	// wcout << L"You entered " << wstring(L"한글") << endl;
    // std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt3;
    // std::wstring wss2 = cvt3.from_bytes("한글");
    // // std::wcout << "wstring size: " << wss2 << '\n';
    // // std::wcout.write(wss2.c_str(), wss2.size());
    // // std::cout << "converted() == " << cvt3.converted() << '\n';
    // std::wcout << wss2 << '\n';

    // std::string utf8 = "z\u00df\u6c34\U0001d10b"; // or u8"zß水𝄋"
    //                // or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
    // std::cout << "original UTF-8 string size: " << utf8.size() << '\n';
 
    // // the UTF-8 - UTF-32 standard conversion facet
    // std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> cvt1;
 
    // // UTF-8 to UTF-32
    // std::u32string utf32 = cvt1.from_bytes("한글");
    // std::cout << "UTF-32 string size: " << utf32.size() << '\n';
    // std::cout << "converted() == " << cvt1.converted() << '\n';

    // // UTF-32 to UTF-8
    // utf8 = cvt1.to_bytes(utf32);
    // std::cout << "converted() == " << cvt1.converted() << '\n';

    // std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> cvt2;
    // // UTF-8 to UTF-16
    // // UTF-16은 locale에 따라 다르게 동작...
    // std::u16string utf16 = cvt2.from_bytes("한글");
    // std::cout << "UTF-16 string size: " << utf16.size() << '\n';
    // std::cout << "converted() == " << cvt2.converted() << '\n';
    // // UTF-16 to UTF-8
    // utf8 = cvt2.to_bytes(utf16);
    // std::cout << "new UTF-8 string size: " << utf8.size() << '\n';
    // std::cout << "converted() == " << cvt2.converted() << '\n';
    // std::cout << utf16.c_str() << '\n';

    // std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt3;
    // // UTF-8 to UTF-16
    // // UTF-16은 locale에 따라 다르게 동작...
    // std::wstring wss = cvt3.from_bytes("한글");
    // std::cout << "wstring size: " << wss.size() << '\n';
    // std::cout << "converted() == " << cvt3.converted() << '\n';
    // // UTF-16 to UTF-8
    // utf8 = cvt3.to_bytes(wss);
    // std::cout << "new UTF-8 string size: " << utf8.size() << '\n';
    // std::cout << "converted() == " << cvt3.converted() << '\n';
    // std::cout << wss.c_str() << '\n';

}