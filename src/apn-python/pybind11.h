#pragma once
#include <pybind11/pybind11.h>
#include <apn-python/caster.h>
#include <apn-python/common.h>

namespace py = pybind11;

LIB_EXPORT std::string array_info_py(std::shared_ptr<arrow::Array>);
LIB_EXPORT std::shared_ptr<arrow::Array> create_array_py();

LIB_EXPORT std::string schema_info_py(std::shared_ptr<arrow::Schema>);
LIB_EXPORT std::shared_ptr<arrow::Schema> create_schema_py();

// LIB_EXPORT std::string table_info_py(std::shared_ptr<arrow::Table>);
// LIB_EXPORT std::shared_ptr<arrow::Table> create_table_py();

PYBIND11_MODULE(pybind11extension, m) {
  m.doc() = "pybind11";
  m.def("array_info", &array_info_py);
  m.def("create_array", &create_array_py);
  m.def("schema_info", &schema_info_py);
  m.def("create_schema", &create_schema_py);
  // m.def("table_info", &table_info_py, "");
  // m.def("create_table", &create_table_py, "");
}
