#!/bin/bash

cd "$(dirname "$0")"
lcov -t "ComplexNumber" --no-external -o complex_number.info -c -d .
lcov --remove complex_number.info 'complex_number/catch.hpp' -o complex_number_filtered.info
genhtml -o report complex_number_filtered.info
rm complex_number.info
rm complex_number_filtered.info
xdg-open ./report/index.html
