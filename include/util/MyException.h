#ifndef MYEXPRESSION_H
#define MYEXPRESSION_H

#include <exception>
#include <string>
namespace Util
{
class MyException : public std::exception
{
public:

    MyException( std::string str);
    const char* what() const noexcept;
private:
    std::string str;
};
};
#endif // MYEXPRESSION_H
