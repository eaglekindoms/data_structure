add_executable(test_sort_bubble test_sort.c)
target_sources(test_sort_bubble PUBLIC bubble_sort.c)

add_executable(test_sort_selection test_sort.c)
target_sources(test_sort_selection PUBLIC selection_sort.c)

add_executable(test_sort_insertion test_sort.c)
target_sources(test_sort_insertion PUBLIC insertion_sort.c)

add_executable(test_sort_merge test_sort.c)
target_sources(test_sort_merge PUBLIC merge_sort.c)

add_executable(test_sort_quick test_sort.c)
target_sources(test_sort_quick PUBLIC quick_sort.c)

add_executable(test_sort_shell test_sort.c)
target_sources(test_sort_shell PUBLIC shell_sort.c)