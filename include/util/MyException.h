#ifndef MYEXPRESSION_H
#define MYEXPRESSION_H

#include <exception>
#include <string>
namespace Util
{
/**
 * @brief The MyException class класс обертка исключений
 */
class MyException : public std::exception
{
public:

    /**
     * @brief MyException конструктор
     * @param str исключение
     */
    MyException( std::string str);
    /**
     * @brief what узначть что за исключение
     * @return
     */
    const char* what() const noexcept;
private:
    std::string str;
};
};
#endif // MYEXPRESSION_H
