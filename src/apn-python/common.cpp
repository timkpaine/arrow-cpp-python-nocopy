#include <arrow/python/pyarrow.h>

#include <apn/bridge.h>

std::string array_info_py(std::shared_ptr<arrow::Array> array) {
  return array_info(array);
}

std::shared_ptr<arrow::Array> create_array_py() {
  arrow::py::import_pyarrow();
  std::shared_ptr<arrow::Array> arrow_array = create_array('a');
  return arrow_array;
}

std::string schema_info_py(std::shared_ptr<arrow::Schema> schema) {
  return schema_info(schema);
}

std::shared_ptr<arrow::Schema> create_schema_py() {
  arrow::py::import_pyarrow();
  std::shared_ptr<arrow::Schema> arrow_schema = create_schema();
  return arrow_schema;
}

// std::string table_info_py(std::shared_ptr<arrow::Table> table) {
//     return table_info(table);
// }

// std::shared_ptr<arrow::Table> create_table_py() {
//     arrow::py::import_pyarrow();
//     std::shared_ptr<arrow::Table> arrow_table = create_table();
//     return arrow_table;
//     // PyObject* obj = arrow::py::wrap_table(arrow_table);
//     // return pybind11::cast(obj);
// }
