import pandas as pd
import pyarrow as pa
from arrow_python_nocopy import schema_info, table_info, create_table


class TestAll:
    def test_create_arrow_table_in_python(self):
        df = pd.DataFrame({"a": [1, 2, 3], "b": [1.1, 2.2, 3.3], "c": ["abc", "def", "ghi"]})
        arrow_table = pa.Table.from_pandas(df)
        arrow_schema = pa.Schema.from_pandas(df)
        assert schema_info(arrow_schema) == 'a: int64\nb: double\nc: string'
        assert (
            table_info(arrow_table)
            == 'a: int64\nb: double\nc: string\n-- schema metadata --\npandas: \'{"index_columns": [{"kind": "range", "name": null, "start": 0, "\' + 563\n----\na:\n  [\n    [\n      1,\n      2,\n      3\n    ]\n  ]\nb:\n  [\n    [\n      1.1,\n      2.2,\n      3.3\n    ]\n  ]\nc:\n  [\n    [\n      "abc",\n      "def",\n      "ghi"\n    ]\n  ]\n'
        )

    def test_create_arrow_table_in_cpp(self):
        pa = create_table()
        df = pa.to_pandas()
        assert (
            df.to_json() == '{"a":{"0":1,"1":2,"2":3},"b":{"0":1.1000000238,"1":2.2000000477,"2":3.2999999523},"c":{"0":"abc","1":"def","2":"ghi"}}'
        )
