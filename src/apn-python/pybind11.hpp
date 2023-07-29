#pragma once
#include <pybind11/pybind11.h>
#include <arrow/python/pyarrow.h>
#include <apn/apn.hpp>
#include <apn-python/caster.hpp>
#include <apn-python/common.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pybind11extension, m) {
  arrow::py::import_pyarrow();
  m.doc() = "pybind11";
  m.def("array_info", &array_info_py);
  m.def("create_array", &create_array_py);
  m.def("schema_info", &schema_info_py);
  m.def("create_schema", &create_schema_py);
  // m.def("table_info", &table_info_py, "");
  // m.def("create_table", &create_table_py, "");
}
