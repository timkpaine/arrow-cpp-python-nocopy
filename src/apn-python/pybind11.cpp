#include <arrow/c/bridge.h>
#include <apn/apn.h>
#include <apn/bridge.h>
#include <apn-python/pybind11.h>

std::string array_info_py(std::shared_ptr<arrow::Array> arrow_array) {
  return array_info(arrow_array);
}

std::shared_ptr<arrow::Array> create_array_py() {
  return create_array('a');;
}

std::string schema_info_py(std::shared_ptr<arrow::Schema> arrow_schema) {
  return schema_info(arrow_schema);
}

std::shared_ptr<arrow::Schema> create_schema_py() {
  return create_schema();
}

// std::string table_info_py(std::shared_ptr<arrow::Table> table) {
//     return table_info(table);
// }

// std::shared_ptr<arrow::Table> create_table_py() {
//     std::shared_ptr<arrow::Table> arrow_table = create_table();
//     return arrow_table;
//     // PyObject* obj = arrow::py::wrap_table(arrow_table);
//     // return pybind11::cast(obj);
// }