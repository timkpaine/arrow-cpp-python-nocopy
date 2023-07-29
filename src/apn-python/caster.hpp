#pragma once

namespace pybind11 { namespace detail {
    template <> struct type_caster<std::shared_ptr<arrow::Array> > {
    public:
        PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Array>, const_name("pyarrow::Array"));
        /* Python->C++ */
        bool load(handle src, bool) {
            arrow::py::import_pyarrow();
            PyObject *source = src.ptr();
            if (!arrow::py::is_array(source))
                return false;
            arrow::Result<std::shared_ptr<arrow::Array>> result = arrow::py::unwrap_array(source);
            if(!result.ok())
                return false;
            value = std::static_pointer_cast<arrow::Array>(result.ValueOrDie());
            return true;
        }

        /* C++ -> Python) */
        static handle cast(std::shared_ptr<arrow::Array> src, return_value_policy /* policy */, handle /* parent */) {
            arrow::py::import_pyarrow();
            return arrow::py::wrap_array(src);
        }
    };

    template <> struct type_caster<std::shared_ptr<arrow::Schema> > {
    public:
        PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Schema>, const_name("pyarrow::Schema"));
        /* Python->C++ */
        bool load(handle src, bool) {
            arrow::py::import_pyarrow();
            PyObject *source = src.ptr();
            if (!arrow::py::is_schema(source))
                return false;
            arrow::Result<std::shared_ptr<arrow::Schema>> result = arrow::py::unwrap_schema(source);
            if(!result.ok())
                return false;
            value = std::static_pointer_cast<arrow::Schema>(result.ValueOrDie());
            return true;
        }

        /* C++ -> Python) */
        static handle cast(std::shared_ptr<arrow::Schema> src, return_value_policy /* policy */, handle /* parent */) {
            arrow::py::import_pyarrow();
            return arrow::py::wrap_schema(src);
        }
    };

    template <> struct type_caster<std::shared_ptr<arrow::Table> > {
    public:
        PYBIND11_TYPE_CASTER(std::shared_ptr<arrow::Table>, const_name("pyarrow::Table"));
        /* Python->C++ */
        bool load(handle src, bool) {
            arrow::py::import_pyarrow();
            PyObject *source = src.ptr();
            if (!arrow::py::is_table(source))
                return false;
            arrow::Result<std::shared_ptr<arrow::Table>> result = arrow::py::unwrap_table(source);
            if(!result.ok())
                return false;
            value = std::static_pointer_cast<arrow::Table>(result.ValueOrDie());
            return true;
        }

        /* C++ -> Python) */
        static handle cast(std::shared_ptr<arrow::Table> src, return_value_policy /* policy */, handle /* parent */) {
            arrow::py::import_pyarrow();
            return arrow::py::wrap_table(src);
        }
    };

}}
