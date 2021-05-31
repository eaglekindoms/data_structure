add_compile_options(-fexec-charset=utf-8)

#-------栈--------
#顺序栈测试
add_executable(test_sq_stack test_code/test_stack_sq.c)
target_sources(test_sq_stack PUBLIC stack/sq_stack.c)
#链栈测试
add_executable(test_link_stack test_code/test_stack_link.c)
target_sources(test_link_stack PUBLIC stack/link_stack.c)
#-------栈--------

#-------线性表--------
add_executable(sequence_table test_code/test_list_sequence.c)
#target_sources(sequence_table PUBLIC list/sequence_table.h)
add_executable(singly_linked_list list/singly_linked_list.c)
add_executable(doubly_linked_list list/doubly_linked_list.c)
#-------线性表--------