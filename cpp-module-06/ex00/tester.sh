#!/bin/bash

exe="./ex00/convert"

valid_inputs=(
"0" "-0" "+0" "123" "-123" "+123" "0.0" "-0.0" "+0.0" "123.456" "-123.456" "+123.456"
".5" "-.5" "+.5" "5." "-5." "+5." "1e10" "-1e10" "+1e10" "1E-10" "-1E-10" "+1E-10"
"123.456f" "-123.456f" "+123.456f" "0.0f" "-0.0f" "+0.0f" ".5f" "-.5f" "+.5f" "5.f" "-5.f" "+5.f"
"nan" "nanf" "inf" "inff" "+inf" "-inf" "+inff" "-inff"
)

char_inputs=(
"-0" "+0" "127" "-127" "+128" "66"
)
int_inputs=(
"-0" "+0" "2147483649" "-2147483648" "-19" "120"
)
float_inputs=(
"f" ".f" "5.f" "-5f" "-inff" "+inff" "inff" "nanf" "1e10f"
"123.456f" "-123.456f" "0.0f" "-0.0f" "+0.0f" ".5f" "-.5f" "+.5f" "5.f" "-5.f" "+5.f"
)
double_inputs=(
"." ".." "1." "-.9" "-inf" "+inf" "inf" "nan" "1e10" "1.337e42" "42p"
"123.456" "-123.456" "0.0" "-0.0" "+0.0" ".5" "-.5" "+.5" "5." "-5." "+5."
)


invalid_inputs=(
"" " " "++123" "+-123" "-+123" "--123" "123..456" "123.45.6" "123f456" "1e" "1e+" "1e-"
"e123" "123e" "123e++5" "123.4.5f" "123.4f5" "0x123" "123abc" "abc123" "NaNabc" "INFxyz"
"." "+" "-" "+." "-." "+.f" "-.f" "f" "12.34ff" "1.2.3f" "12e3.4" "1e2.3"
)

run_test() {
  local input="$1"
  echo "Testing input: '$input'"
  "$exe" "$input"
  echo "----------------------"
}

case "$1" in
  c)
    echo -e "\033[32m============================ CHAR TESTS ============================\033[0m"
    for input in "${char_inputs[@]}"; do run_test "$input"; done
    ;;
  i)
    echo -e "\033[32m============================ INT TESTS ============================\033[0m"
    for input in "${int_inputs[@]}"; do run_test "$input"; done
    ;;
  f)
    echo -e "\033[32m============================ FLOAT TESTS ============================\033[0m"
    for input in "${float_inputs[@]}"; do run_test "$input"; done
    ;;
  d)
    echo -e "\033[32m============================ DOUBLE INPUTS ============================\033[0m"
    for input in "${double_inputs[@]}"; do run_test "$input"; done
    ;;
  v)
    echo -e "\033[32m============================ VALID INPUTS ============================\033[0m"
    for input in "${valid_inputs[@]}"; do run_test "$input"; done
    ;;
  x)
    echo -e "\033[31m============================ INVALID INPUTS ============================\033[0m"
    for input in "${invalid_inputs[@]}"; do run_test "$input"; done
    ;;
  *)
    echo -e "\033[32m============================ VALID INPUTS ============================\033[0m"
    for input in "${valid_inputs[@]}"; do run_test "$input"; done

    echo -e "\033[31m============================ INVALID INPUTS ============================\033[0m"
    for input in "${invalid_inputs[@]}"; do run_test "$input"; done
    ;;
esac