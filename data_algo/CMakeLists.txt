add_subdirectory(other)
add_subdirectory(trains)
add_subdirectory(vtk_learn)
#----- 排序 -----
add_subdirectory(sort/old_sort)
#----- 排序 -----

#----- 字符串匹配 -----
add_executable(test_string_kmp search/string_kmp.c)
#----- 字符串匹配 -----