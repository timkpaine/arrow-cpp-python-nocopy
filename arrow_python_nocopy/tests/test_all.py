import pandas as pd
import pyarrow as pa
from arrow_python_nocopy import array_info, create_array
from arrow_python_nocopy import schema_info, create_schema
# from arrow_python_nocopy import table_info, create_table
from arrow_python_nocopy import _df, _table

class TestAll:
    def test_create_array_in_python(self):
        table = _table()
        array = table.columns[0].chunk(0)
        assert array_info(array) == '[\n  1,\n  2,\n  3\n]'

    def test_create_schema_in_python(self):
        schema = pa.Schema.from_pandas(_df())
        assert schema_info(schema) == 'a: int64\nb: double\nc: string'

    def test_create_array_in_cpp(self):
        array = create_array()
        assert (
            str(array) == '[\n  1,\n  2,\n  3\n]'
        )

    def test_create_schema_in_cpp(self):
        schema = create_schema()
        assert (
            str(schema) == 'a: int32\nb: float\nc: binary'
        )
