#ifndef LOADER_EXCEPTIONS_H
#define LOADER_EXCEPTIONS_H

#include <cstring>
#include <exception>
#include <iostream>

#include "BaseExceptions.h"

class ExceptionLoader : public BaseException
{
  private:
    const char *err_index_msg = "Something wrong with loader...\n";

  public:
    ExceptionLoader() noexcept = default;
    ExceptionLoader(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }

    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFile : public ExceptionLoader
{
  private:
    const char *err_index_msg = "Something wrong with read file...!\n";

  public:
    ErrorLoaderFile() = default;
    ErrorLoaderFile(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileReadPoint : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error read point from file!\n";

  public:
    ErrorLoaderFileReadPoint(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileReadEdge : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error read edge from file!\n";

  public:
    ErrorLoaderFileReadEdge(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileOpen : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error open file!\n";

  public:
    ErrorLoaderFileOpen(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileClose : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error close file!\n";

  public:
    ErrorLoaderFileClose(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderIndexPoints : public ExceptionLoader
{
  private:
    const char *err_index_msg = "Error incorrcet index in edge!\n";

  public:
    ErrorLoaderIndexPoints(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileCountPoints : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error incorrcet count points!\n";

  public:
    ErrorLoaderFileCountPoints(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

class ErrorLoaderFileCountEdges : public ErrorLoaderFile
{
  private:
    const char *err_index_msg = "Error incorrcet count edges!\n";

  public:
    ErrorLoaderFileCountEdges(const char *classname, int line, char *time) noexcept
    {
        std::snprintf(errormsg, sizebuff, "%s In %s in line %d at %s", err_index_msg, classname, line, time);
    }
    const char *what() const noexcept override
    {
        return errormsg;
    }
};

#endif
