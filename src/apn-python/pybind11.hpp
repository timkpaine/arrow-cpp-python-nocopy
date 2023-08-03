#pragma once
#include <dlfcn.h>
#include <pybind11/pybind11.h>
#include <arrow/python/pyarrow.h>
#include <arrow/python/lib_api.h>
#include <apn-python/caster.hpp>
#include <apn-python/common.hpp>

namespace py = pybind11;

// LIB_EXPORT PyObject* table_info_py_raw(PyObject*, PyObject*);
PYBIND11_MODULE(pybind11extension, m) {
  py::module_::import("pyarrow");
  // dlopen("arrow_python.so", RTLD_LAZY);
  // dlopen("libarrow_python.so", RTLD_LAZY);
  import_pyarrow__lib();
  m.doc() = "pybind11";
  m.def("array_info", &array_info_py);
  m.def("create_array", &create_array_py);
  m.def("schema_info", &schema_info_py);
  m.def("create_schema", &create_schema_py);
  // m.def("table_info", &table_info_py, "");
  // m.def("create_table", &create_table_py, "");
}
