#ifndef EXCEPTIONS_ITER_H
#define EXCEPTIONS_ITER_H

#include <exception>
#include <cstring>
#include <iostream>

#include "exceptions_base.h"

class ExceptionIterator: public ExceptionMyMath
{
    private:
        const char *err_index_msg = "Something wrong with iterator...\n";

    public:
        ExceptionIterator() noexcept = default;
        ExceptionIterator(const char *classname, int line, char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
        }

    const char* what() const noexcept override { return errormsg; }
};

class ErrorIteratorChangeIndex : public ExceptionIterator
{
    private:
        const char *err_index_msg = "Error change index iterator!\n";
        int index;
    public:
        ErrorIteratorChangeIndex(const char *classname, int line, char *time, int ind) noexcept : index(ind)
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s: %d", err_index_msg, classname, line, time, index);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorIteratorApplyIndex : public ExceptionIterator
{
    private:
        const char *err_index_msg = "Error apply index iterator!\n";
        int index;
    public:
        ErrorIteratorApplyIndex(const char *classname, int line, char *time, int ind) noexcept : index(ind)
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s: %d", err_index_msg, classname, line, time, index);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorDeleted : public ExceptionIterator
{
    private:
        const char *err_delete_msg = "Error work with deleted object!\n";
    public:
        ErrorDeleted(const char *classname, char *time, int line) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};


#endif