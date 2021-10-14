add_subdirectory(other)
add_subdirectory(trains)
#----- 排序 -----
add_executable(test_sort_bubble sort/test_sort.c)
target_sources(test_sort_bubble PUBLIC sort/bubble_sort.c)

add_executable(test_sort_selection sort/test_sort.c)
target_sources(test_sort_selection PUBLIC sort/selection_sort.c)

add_executable(test_sort_insertion sort/test_sort.c)
target_sources(test_sort_insertion PUBLIC sort/insertion_sort.c)

add_executable(test_sort_merge sort/test_sort.c)
target_sources(test_sort_merge PUBLIC sort/merge_sort.c)

add_executable(test_sort_quick sort/test_sort.c)
target_sources(test_sort_quick PUBLIC sort/quick_sort.c)

add_executable(test_sort_shell sort/test_sort.c)
target_sources(test_sort_shell PUBLIC sort/shell_sort.c)
#----- 排序 -----

#----- 字符串匹配 -----
add_executable(test_string_kmp search/string_kmp.c)
#----- 字符串匹配 -----