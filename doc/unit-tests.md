Compiling/running unit tests
------------------------------------

Unit tests will be automatically compiled if dependencies were met in `./configure`
and tests weren't explicitly disabled.

To run the mineriumd tests launch `src/test/test_minerium`.

To add more mineriumd tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the `test/` directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections.

To run the minerium-qt tests manually, launch `src/qt/test/test_minerium-qt`

To add more minerium-qt tests, add them to the `src/qt/test/` directory and
the `src/qt/test/test_main.cpp` file.
