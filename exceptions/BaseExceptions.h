#ifndef BASEEXCEPTIONS_H
#define BASEEXCEPTIONS_H

#include <cstring>
#include <exception>

class BaseException : public std::exception
{
  protected:
    static const std::size_t sizebuff = 128;
    char errormsg[sizebuff]{};

  public:
    BaseException() noexcept = default;
    BaseException(const char *msg) noexcept
    {
        std::strncpy(errormsg, msg, sizebuff);
    }
    ~BaseException() override
    {
    }

    const char *what() const noexcept override
    {
        return errormsg;
    }
};

#endif // BASEEXCEPTIONS_H
