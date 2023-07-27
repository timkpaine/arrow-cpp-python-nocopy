#pragma once

#include <string>

#include <arrow/table.h>

#include <arrow-python-nocopy/exports.hpp>
#include <arrow-python-nocopy/arrow-python-nocopy.hpp>

LIB_EXPORT std::string table_info(std::shared_ptr<arrow::Table>);
LIB_EXPORT std::string schema_info(std::shared_ptr<arrow::Schema>);
LIB_EXPORT std::shared_ptr<arrow::Table> create_table();
