#include <iostream>
#include <typeinfo>
#include <exception>
#include <codecvt>
#include <string>

#include <Poco/Dynamic/Var.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Data/ODBC/Connector.h>

using namespace std;
using namespace Poco::Dynamic;
class NException : public std::exception
{
public:
  NException(const char *msg) : message(msg) {}
  const char *what() const noexcept override
  {
    return message;
  }

private:
  const char *message;
};

class _variant_t: public Var
{
public:
  _variant_t() throw() : Var() {};
  template <typename T>
  _variant_t(const T &val) : Var(val) {}
  // _variant_t(const _variant_t &varSrc);
  // _variant_t(const _bstr_t &bstrSrc);
  _variant_t(const wchar_t *pSrc) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cvt2;
    auto utf8 = cvt2.to_bytes((wchar_t *) pSrc);
    Var::operator=(utf8);
  }
  // _variant_t(const char *pSrc); // This already implemented in Var
  // ~_variant_t() throw() {  };
  template <typename T>
  operator T() const { return Var::operator T(); }
  // operator _bstr_t() const;
  // _variant_t &operator=(const _variant_t &varSrc);
  // _variant_t &operator=(const _bstr_t &bstrSrc);
  // _variant_t &operator=(const wchar_t *pSrc);
  // _variant_t &operator=(const char *pSrc);
  
  // void ChangeType(VARTYPE vartype, const _variant_t *pSrc = NULL);
  // void SetString(const char *pSrc);
};

void use_variant()
{
  Var strv1("hello");
  // Var strv2(L"wide char string: 한글"); // error!
  _variant_t v1(10);
  _variant_t v2(10.01);
  _variant_t v3("Hello");
  _variant_t v4(L"wide char string: 한글");
  cout << "v1: " << v1.toString() << endl;
  cout << "v1: " << static_cast<int>(v1) << endl;
  cout << "v1: " << static_cast<unsigned int>(v1) << endl;
  cout << "v2: " << v2.toString() << endl;
  cout << "v2: " << static_cast<double>(v2) << endl;
  cout << "v2: " << static_cast<float>(v2) << endl;
  cout << "v3: " << v3.toString() << endl;
  cout << "v4: " << v4.toString() << endl;
}