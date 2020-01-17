#include "../include/pybed.h"

PyBed::PyBed(const char* scriptPath) : scriptOrigin(scriptPath), guard{}
{
    module = py::module::import(scriptPath);
}

PyBed PyBed::InitWithScript(const char* scriptPath)
{
    return PyBed(scriptPath);
}

PyBed* PyBed::InitWithScriptOnHeap(const char* scriptPath)
{
    return new PyBed(scriptPath);
}

void PyBed::InvokeVoid(const char* func) const
{
    module.attr(func)();
}