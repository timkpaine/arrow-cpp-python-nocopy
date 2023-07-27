# Demo of C++<->Python for Apache Arrow
This is a small example of building a C++ library which reads and returns array tables and schemas linked against `libarrow` (but **DOES NOT REQUIRE** `pyarrow`), and building a python extension that uses this library to pass arrays and schemas back and forth.
