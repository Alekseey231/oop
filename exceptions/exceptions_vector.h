#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <cstring>
#include <iostream>
#include "exceptions_base.h"

class ExceptionVector: public ExceptionMyMath
{
    private:
        const char *err_index_msg = "Something wrong with vector...\n";

    public:
        ExceptionVector() noexcept = default;
        ExceptionVector(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
        }

    const char* what() const noexcept override { return errormsg; }
};

class ErrorVectorIndex : public ExceptionVector
{
    private:
        const char *err_index_msg = "Error index vector!\n";
        int index;
    public:
        ErrorVectorIndex(const char *classname, int line, const char *time, int ind) noexcept : index(ind)
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s: %d", err_index_msg, classname, line, time, index);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorMemory : public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error allocate memory for vector!\n";
    public:
        ErrorMemory(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorEmpty : public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error can't use this operation with vector size zero!\n";
    public:
        ErrorEmpty(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorZeroDiv: public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error devided zero!\n";
    public:
        ErrorZeroDiv(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorInvalidDimension : public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error ivalid dimension for vector mul!\n";
    public:
        ErrorInvalidDimension(const char *classname, int line, int size, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s: %d", err_delete_msg, classname, line, time, size);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorNotEqualDimension : public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error applying the operation to vectors with different dimensions!\n";
    public:
        ErrorNotEqualDimension(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};

class ErrorZeroLength : public ExceptionVector
{
    private:
        const char *err_delete_msg = "Error applying normalize zero vector!\n";
    public:
        ErrorZeroLength(const char *classname, int line, const char *time) noexcept
        {
            std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_delete_msg, classname, line, time);
        }
    const char* what() const noexcept override { return errormsg; }
};

#endif