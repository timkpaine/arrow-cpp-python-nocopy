#include <arrow/python/pyarrow.h>
#include "arrow-python-nocopy/python/extension.hpp"
#include "arrow-python-nocopy/arrow-python-nocopy.hpp"

std::string table_info_py(std::shared_ptr<arrow::Table> table) {
    return table_info(table);
}

std::string schema_info_py(std::shared_ptr<arrow::Schema> schema) {
    return schema_info(schema);
}

std::shared_ptr<arrow::Table> create_table_py() {
    arrow::py::import_pyarrow();
    std::shared_ptr<arrow::Table> arrow_table = create_table();
    return arrow_table;
    // PyObject* obj = arrow::py::wrap_table(arrow_table);
    // return pybind11::cast(obj);
}
