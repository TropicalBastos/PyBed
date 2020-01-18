// MIT License

// Copyright (c) 2020 Ian Bastos

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef PYBED_H
#define PYBED_H

#include "./pybind11/pybind11.h"
#include "./pybind11/embed.h"

#include <string>

namespace py = pybind11;

class PyBed
{
public:
    static PyBed InitWithScript(const char* func);
    static PyBed* InitWithScriptOnHeap(const char* func);

    void InvokeVoid(const char* func) const;

    py::module GetPyBindModule() const;

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