#pragma once
#include <pybind11/pybind11.h>
#include <arrow/python/pyarrow.h>
#include <arrow-python-nocopy/arrow-python-nocopy.hpp>
#include <arrow-python-nocopy/python/caster.hpp>

namespace py = pybind11;

LIB_EXPORT std::string table_info_py(std::shared_ptr<arrow::Table> table);
LIB_EXPORT std::string schema_info_py(std::shared_ptr<arrow::Schema> schema);
LIB_EXPORT std::shared_ptr<arrow::Table> create_table_py();

PYBIND11_MODULE(extension, m) {
  arrow::py::import_pyarrow();
  m.doc() = "";
  m.def("table_info", &table_info_py, "");
  m.def("schema_info", &schema_info_py, "");
  m.def("create_table", &create_table_py, "");
}
