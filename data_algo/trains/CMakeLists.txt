#---------排序------------
add_executable(week01_sort_algo week01_sort_algo.c)
file(GLOB sort_impl ../sort/*.c)
#add_library(sort_lib STATIC ${sort_impl})
#target_link_libraries(week01_sort_algo sort_lib)
target_sources(week01_sort_algo PUBLIC ${sort_impl})
#---------排序------------
add_executable(day002 day002.c)
add_executable(day003 day003.c)