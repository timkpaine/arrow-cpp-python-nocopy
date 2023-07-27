#include <arrow/builder.h>
#include "arrow-python-nocopy/arrow-python-nocopy.hpp"

std::string table_info(std::shared_ptr<arrow::Table> t) {
    return t->ToString();
}

std::string schema_info(std::shared_ptr<arrow::Schema> s) {
    return s->ToString();
}

std::shared_ptr<arrow::Table> create_table() {
  // builders
  // int builder
  arrow::Int32Builder int32builder;
  int32_t values_a[3] = {1, 2, 3};
  int32builder.AppendValues(values_a, 3);
  std::shared_ptr<arrow::Array> array_a = *(int32builder.Finish());

  // float builder
  arrow::FloatBuilder floatbuilder;
  float values_b[3] = {1.1, 2.2, 3.3};
  floatbuilder.AppendValues(values_b, 3);
  std::shared_ptr<arrow::Array> array_b = *(floatbuilder.Finish());

  // string builder
  arrow::StringBuilder stringbuilder;
  const char* values_c[3] = {"abc", "def", "ghi"};
  stringbuilder.AppendValues(values_c, 3);
  std::shared_ptr<arrow::Array> array_c = *(stringbuilder.Finish());

  // fields / schema
  std::shared_ptr<arrow::Field> field_a = arrow::field("a", arrow::int32());
  std::shared_ptr<arrow::Field> field_b = arrow::field("b", arrow::float32());
  std::shared_ptr<arrow::Field> field_c = arrow::field("c", arrow::binary());
  std::shared_ptr<arrow::Schema> schema = arrow::schema({field_a, field_b, field_c});


  // record batch for ref
//   std::shared_ptr<arrow::RecordBatch> rbatch = arrow::RecordBatch::Make(schema, 3, {array_a, array_b, array_c});

  // chunked arrays, for ref
  arrow::ArrayVector vecs_a{array_a};
  arrow::ArrayVector vecs_b{array_b};
  arrow::ArrayVector vecs_c{array_c};
  std::shared_ptr<arrow::ChunkedArray> chunks_a =std::make_shared<arrow::ChunkedArray>(vecs_a);
  std::shared_ptr<arrow::ChunkedArray> chunks_b =std::make_shared<arrow::ChunkedArray>(vecs_b);
  std::shared_ptr<arrow::ChunkedArray> chunks_c =std::make_shared<arrow::ChunkedArray>(vecs_c);
  std::shared_ptr<arrow::Table> table = arrow::Table::Make(schema, {chunks_a, chunks_b, chunks_c}, 3);
  return table;
}
