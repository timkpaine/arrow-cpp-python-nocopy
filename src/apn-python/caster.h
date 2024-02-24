#pragma once
#include <arrow/table.h>
#include <apn-python/common.h>

namespace pybind11 {
namespace detail {
  template <>
  struct type_caster<std::shared_ptr<arrow::Array>> {
  public:
    PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Array>, const_name("arrow::Array"));
    /* Python->C++ */
    bool load(handle src, bool) {
      PyObject* array = src.ptr();
      if(!PyObject_HasAttrString(array, "__arrow_c_array__"))
        return false;;

      // unpack
      value = unpack_array(array);
      return true;
    }

    /* C++ -> Python) */
    static handle cast(std::shared_ptr<arrow::Array> src, return_value_policy /* policy */, handle /* parent */) {
      return pack_array(src);
    }
  };

  template <>
  struct type_caster<std::shared_ptr<arrow::Schema>> {
  public:
    PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Schema>, const_name("arrow::Schema"));
    /* Python->C++ */
    bool load(handle src, bool) {
      PyObject* schema = src.ptr();

      // parse arguments
      if(!PyObject_HasAttrString(schema, "__arrow_c_schema__"))
        return false;

      // unpack
      value = unpack_schema(schema);
      return true;
    }

    /* C++ -> Python) */
    static handle cast(std::shared_ptr<arrow::Schema> src, return_value_policy /* policy */, handle /* parent */) {
      return pack_schema(src);
    }
  };

  // template <>
  // struct type_caster<std::shared_ptr<arrow::Table>> {
  // public:
  //   PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Table>, const_name("pyarrow::Table"));
  //   /* Python->C++ */
  //   bool load(handle src, bool) {
  //     PyObject* source = src.ptr();
  //     if(!arrow::py::is_table(source))
  //       return false;
  //     arrow::Result<std::shared_ptr<arrow::Table>> result = arrow::py::unwrap_table(source);
  //     if(!result.ok())
  //       return false;
  //     value = std::static_pointer_cast<arrow::Table>(result.ValueOrDie());
  //     return true;
  //   }

  //   /* C++ -> Python) */
  //   static handle cast(std::shared_ptr<arrow::Table> src, return_value_policy /* policy */, handle /* parent */) {
  //     return arrow::py::wrap_table(src);
  //   }
  // };

}
}
