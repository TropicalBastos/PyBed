#ifndef PYBED_H
#define PYBED_H

#define PYBIND11_LOC "../pybind11/include/pybind11/pybind11.h"
#define PYBIND11_EMBED_LOC "../pybind11/include/pybind11/embed.h"

#include PYBIND11_LOC
#include PYBIND11_EMBED_LOC

#include <string>

namespace py = pybind11;

class PyBed
{
public:
    static PyBed InitWithScript(const char* func);
    static PyBed* InitWithScriptOnHeap(const char* func);

    void InvokeVoid(const char* func) const;

    template<typename T>
    inline T Invoke(const char* func) const
    {
        py::object result = module.attr(func)();
        return result.template cast<T>();
    }

    template<typename T, typename... Args>
    inline T InvokeWithArgs(const char* func, Args... args) const
    {
        py::object result = module.attr(func)(args...);
        return result.template cast<T>();
    }

    template<typename... Args>
    inline void InvokeVoid(const char* func, Args... args) const
    {
        module.attr(func)(args...);
    }

private:
    PyBed(const char* func);
    std::string scriptOrigin;
    py::module module;
    py::scoped_interpreter guard;
};

#endif