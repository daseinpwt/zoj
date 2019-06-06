#!/bin/bash
BUILD_DIR="build"
WORK_DIR="check"

mkdir -p ${WORK_DIR}
while true; do
    python3 make_data.py > ${WORK_DIR}/input
    ${BUILD_DIR}/1029.out < ${WORK_DIR}/input > ${WORK_DIR}/output
    ${BUILD_DIR}/std < ${WORK_DIR}/input > ${WORK_DIR}/stdout

    if ! diff ${WORK_DIR}/output ${WORK_DIR}/stdout > /dev/null; then
        printf "Found difference!\n"
        printf "=== output ===\n"
        cat ${WORK_DIR}/output
        printf "=== stdout ===\n"
        cat ${WORK_DIR}/stdout
        break
    fi
done