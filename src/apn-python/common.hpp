#pragma once
#include <arrow/python/pyarrow.h>
#include <apn/apn.hpp>
#include <apn-python/caster.hpp>

LIB_EXPORT std::string array_info_py(std::shared_ptr<arrow::Array> array);
LIB_EXPORT std::shared_ptr<arrow::Array> create_array_py();

LIB_EXPORT std::string schema_info_py(std::shared_ptr<arrow::Schema> schema);
LIB_EXPORT std::shared_ptr<arrow::Schema> create_schema_py();

LIB_EXPORT std::string table_info_py(std::shared_ptr<arrow::Table> table);
LIB_EXPORT std::shared_ptr<arrow::Table> create_table_py();
