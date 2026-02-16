#!/bin/bash

# Цвета
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Путь к папке со скриптом
SCRIPT_DIR=$(dirname "$(realpath "$0")")
CALC="$SCRIPT_DIR/../rpncalc"

if [ ! -f "$CALC" ]; then
    echo -e "${RED}Ошибка: калькулятор не найден. Сначала выполните make.${NC}"
    exit 1
fi

cd "$SCRIPT_DIR" || exit

$CALC < test_case.txt > output.txt

if diff -u expected_output.txt output.txt; then
    echo -e "${GREEN}Все тесты пройдены!${NC}"
    rm output.txt
    exit 0
else
    echo -e "${RED}Тесты не пройдены. Различия выше.${NC}"
    exit 1
fi