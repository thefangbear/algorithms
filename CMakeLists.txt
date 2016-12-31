cmake_minimum_required(VERSION 3.5)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(DSFOLDER
        ds/hash_table.c
        ds/linked_list.c)
set(FUNCTIONSFOLDER
        functions/x86_asm_swap.c)
set(SORTFOLDER
        sort/kandr_qsort_impl.c
        sort/libc_qsort.c
        sort/radix_sort.c
        sort/stdc_qsort.c
        sort/stooge_sort.c)
set(MONTECARLOFOLDER )
set(SOURCE_FILES
        ${DSFOLDER}
        ${FUNCTIONSFOLDER}
        ${SORTFOLDER}
        ${MONTECARLOFOLDER})
add_executable(algorithms ${SOURCE_FILES})