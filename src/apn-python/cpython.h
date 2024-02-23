#pragma once
#include "Python.h"
#include <apn-common/exports.h>

LIB_EXPORT PyObject* array_info_py(PyObject*, PyObject*);
LIB_EXPORT PyObject* create_array_py(PyObject*, PyObject*);
LIB_EXPORT PyObject* schema_info_py(PyObject*, PyObject*);
LIB_EXPORT PyObject* create_schema_py(PyObject*, PyObject*);

// LIB_EXPORT PyObject* table_info_py_raw(PyObject*, PyObject*);
// LIB_EXPORT PyObject* create_table_py_raw(PyObject*, PyObject*);

static PyMethodDef cpythonextension_methods[] = {
  {"array_info", (PyCFunction)array_info_py, METH_VARARGS},
  {"create_array", (PyCFunction)create_array_py, METH_NOARGS},
  {"schema_info", (PyCFunction)schema_info_py, METH_VARARGS},
  {"create_schema", (PyCFunction)create_schema_py, METH_NOARGS},
  {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef cpythonextension_module = {
  PyModuleDef_HEAD_INIT, "cpythonextension", "cpython", -1, cpythonextension_methods};

PyMODINIT_FUNC PyInit_cpythonextension(void) {
  Py_Initialize();
  return PyModule_Create(&cpythonextension_module);
}
