#pragma once
#include <string>
#include <arrow/table.h>
#include <arrow/python/pyarrow.h>
#include <apn-common/exports.h>

LIB_EXPORT char* array_info_py(std::shared_ptr<arrow::Array> array);
LIB_EXPORT std::shared_ptr<arrow::Array> create_array_py();

LIB_EXPORT char* schema_info_py(std::shared_ptr<arrow::Schema> schema);
LIB_EXPORT std::shared_ptr<arrow::Schema> create_schema_py();

LIB_EXPORT char* table_info_py(std::shared_ptr<arrow::Table> table);
LIB_EXPORT std::shared_ptr<arrow::Table> create_table_py();
