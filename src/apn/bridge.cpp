#include <arrow/c/bridge.h>
#include <apn/bridge.h>
#include <apn/apn.h>

int array_info_cabi(struct ArrowArray* c_array, char* buffer, size_t size) {
  std::shared_ptr<arrow::Array> arrow_array = arrow::ImportArray(c_array, arrow::int32()).ValueOrDie();
  std::string info                          = array_info(arrow_array);
  strncpy(buffer, info.c_str(), size);
  return 0;
}

int create_array_cabi(struct ArrowArray* c_array) {
  std::shared_ptr<arrow::Array> array = create_array('a');
  (void)arrow::ExportArray(*array, c_array);
  return 0;
}

int schema_info_cabi(struct ArrowSchema* c_schema, char* buffer, size_t size) {
  std::shared_ptr<arrow::Schema> arrow_schema = arrow::ImportSchema(c_schema).ValueOrDie();
  std::string info                            = schema_info(arrow_schema);
  strncpy(buffer, info.c_str(), size);
  return 0;
}

int create_schema_cabi(struct ArrowSchema* c_schema) {
  std::shared_ptr<arrow::Schema> schema = create_schema();
  (void)arrow::ExportSchema(*schema, c_schema);
  return 0;
}
