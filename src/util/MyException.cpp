#include "include/util/MyException.h"
namespace Util
{
MyException::MyException(std::string _str): std::exception(), str ( _str )
{
}


const char* MyException::what() const noexcept
{
    return str.c_str();
};


};
