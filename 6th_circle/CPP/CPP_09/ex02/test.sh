#!/bin/bash

PASS=0
FAIL=0

check() {
    local desc="$1"
    local input="$2"
    local expected="$3"

    result=$(./PergeMe $input 2>&1 | grep "After" | sed 's/After:  *//')
    
    if [ "$result" = "$expected" ]; then
        echo "✓ $desc"
        PASS=$((PASS + 1))
    else
        echo "✗ $desc"
        echo "  input:    $input"
        echo "  expected: $expected"
        echo "  got:      $result"
        FAIL=$((FAIL + 1))
    fi
}

check_error() {
    local desc="$1"
    local input="$2"

    result=$(./PergeMe $input 2>&1)
    if echo "$result" | grep -q "Error\|error\|can't"; then
        echo "✓ $desc"
        PASS=$((PASS + 1))
    else
        echo "✗ $desc"
        echo "  expected error but got: $result"
        FAIL=$((FAIL + 1))
    fi
}

echo "=== 基本ケース ==="
check "要素1つ"           "1"             "1"
check "要素2つ 順序通り"  "1 2"           "1 2"
check "要素2つ 逆順"      "2 1"           "1 2"
check "要素3つ"           "3 1 2"         "1 2 3"
check "要素5つ"           "5 3 1 4 2"     "1 2 3 4 5"
check "ソート済み"        "1 2 3 4 5"     "1 2 3 4 5"
check "逆順"              "5 4 3 2 1"     "1 2 3 4 5"

echo ""
echo "=== 奇数個ケース ==="
check "3個"               "3 1 2"         "1 2 3"
check "5個"               "5 3 1 4 2"     "1 2 3 4 5"
check "7個"               "7 3 1 4 2 8 6" "1 2 3 4 6 7 8"
check "9個"               "4 3 2 1 8 7 6 5 9" "1 2 3 4 5 6 7 8 9"

echo ""
echo "=== Jacobsthal境界ケース ==="
check "pend_size=1"       "2 1"               "1 2"
check "pend_size=2"       "4 3 2 1"           "1 2 3 4"
check "pend_size=3"       "6 5 4 3 2 1"       "1 2 3 4 5 6"
check "pend_size=4"       "4 3 2 1 8 7 6 5"   "1 2 3 4 5 6 7 8"
check "pend_size=5"       "10 9 8 7 6 5 4 3 2 1" "1 2 3 4 5 6 7 8 9 10"

echo ""
echo "=== エラーケース ==="
check_error "引数なし"     ""
check_error "負の数"       "-1 2 3"
check_error "0"            "0 1 2"
check_error "文字列"       "1 2 abc"
check_error "小数"         "1 2 3.5"
check_error "重複"         "1 2 1"

echo ""
echo "=== 大規模ケース ==="
input_asc=$(seq 1 3000 | tr '\n' ' ')
input_desc=$(seq 3000 -1 1 | tr '\n' ' ')
expected=$(seq 1 3000 | tr '\n' ' ' | sed 's/ $//')

result_asc=$(./PergeMe $input_asc 2>&1 | grep "After" | sed 's/After:  *//')
result_desc=$(./PergeMe $input_desc 2>&1 | grep "After" | sed 's/After:  *//')

if [ "$result_asc" = "$expected" ]; then
    echo "✓ 3000個昇順"
    PASS=$((PASS + 1))
else
    echo "✗ 3000個昇順"
    FAIL=$((FAIL + 1))
fi

if [ "$result_desc" = "$expected" ]; then
    echo "✓ 3000個降順"
    PASS=$((PASS + 1))
else
    echo "✗ 3000個降順"
    FAIL=$((FAIL + 1))
fi

echo ""
echo "=== 結果 ==="
echo "PASS: $PASS"
echo "FAIL: $FAIL"