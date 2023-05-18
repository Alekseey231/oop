#ifndef BASE_EXCEPTIONS_H
#define BASE_EXCEPTIONS_H

class ExceptionMyMath : public std::exception
{
protected:
    static const std::size_t sizebuff = 128;
    char errormsg[sizebuff]{};

public:
    ExceptionMyMath() noexcept = default;
    ExceptionMyMath(const char* msg) noexcept
    {
    std::strncpy(errormsg, msg, sizebuff);
    }
    ~ExceptionMyMath() override {}

    const char* what() const noexcept override { return errormsg; }
};


#endif