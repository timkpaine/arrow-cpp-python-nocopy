#include <arrow/c/bridge.h>
#include <apn-python/common.hpp>
#include <apn/bridge.h>

std::string array_info_py(std::shared_ptr<arrow::Array> array) {
  // ABI unstable!
  // return array_info(array);
  char buffer[100];
  struct ArrowArray c_array;
  (void)ExportArray(*array, &c_array);
  array_info_cabi(&c_array, buffer, 100);
  return std::string(buffer);
}

std::shared_ptr<arrow::Array> create_array_py() {
  arrow::py::import_pyarrow();

  // ABI unstable!
  // std::shared_ptr<arrow::Array> arrow_array = create_array_cabi();
  struct ArrowArray c_array;
  create_array_cabi(&c_array);
  std::shared_ptr<arrow::Array> arrow_array = arrow::ImportArray(&c_array, arrow::int32()).ValueOrDie();
  return arrow_array;
}

std::string schema_info_py(std::shared_ptr<arrow::Schema> schema) {
  // ABI unstable!
  // return schema_info(schema);
  char buffer[100];
  struct ArrowSchema c_schema;
  (void)arrow::ExportSchema(*schema, &c_schema);
  schema_info_cabi(&c_schema, buffer, 100);
  return std::string(buffer);
}

std::shared_ptr<arrow::Schema> create_schema_py() {
  arrow::py::import_pyarrow();

  // ABI unstable!
  // std::shared_ptr<arrow::Schema> arrow_schema = create_schema();

  struct ArrowSchema c_schema;
  create_schema_cabi(&c_schema);
  std::shared_ptr<arrow::Schema> arrow_schema = arrow::ImportSchema(&c_schema).ValueOrDie();
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
