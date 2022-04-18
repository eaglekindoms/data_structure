#add_compile_options(-fexec-charset=GBK)
#set(CMAKE_ARGS "-Wno-dev")
#-------栈--------
#顺序栈测试
add_executable(test_stack_sq test_code/test_stack.c)
target_sources(test_stack_sq PUBLIC stack/sq_stack.c)

#链栈测试
add_executable(test_stack_link test_code/test_stack.c)
target_sources(test_stack_link PUBLIC stack/link_stack.c)
#-------栈--------

#-------队列--------
#顺序队列测试
add_executable(test_queue_sq test_code/test_queue.c)
target_sources(test_queue_sq PUBLIC queue/sq_queue.c)

#顺序循环队列测试
add_executable(test_queue_sq_circular test_code/test_queue.c)
target_sources(test_queue_sq_circular PUBLIC queue/sq_circular_queue.c)

#链式队列测试
add_executable(test_queue_link test_code/test_queue.c)
target_sources(test_queue_link PUBLIC queue/link_queue.c)

#双端队列测试
add_executable(test_queue_double_end test_code/test_queue_double_end.c)
#-------队列--------

#-------线性表--------
# 单链表
add_executable(linear_list_link_single test_code/test_linear_list.c)
target_sources(linear_list_link_single PUBLIC list/singly_linked_list.c)

# 循环单链表
add_executable(linear_list_link_circular test_code/test_linear_list.c)
target_sources(linear_list_link_circular PUBLIC list/circular_linked_list.c)

# 静态单链表
add_executable(linear_list_link_static test_code/test_linear_list.c)
target_sources(linear_list_link_static PUBLIC list/static_linked_list.c)

# 双链表
add_executable(linear_list_link_double test_code/test_linear_list.c)
target_sources(linear_list_link_double PUBLIC list/doubly_linked_list.c)

# 顺序表
add_executable(test_linear_list_sq test_code/test_linear_list.c)
target_sources(test_linear_list_sq PUBLIC list/sequence_list.c)
#-------线性表--------

#-------二叉树--------
# 链式二叉树
add_executable(test_binary_tree_link test_code/test_binary.c)
target_sources(test_binary_tree_link PUBLIC tree/link_binary_tree.c)

# 线索二叉树
add_executable(test_binary_tree_threaded test_code/test_binary.c)
target_sources(test_binary_tree_threaded PUBLIC tree/threaded_binary_tree.c)

# 二叉堆
add_executable(test_binary_heap test_code/test_heap.c)

# 哈夫曼树
add_executable(test_binary_tree_huffman tree/huffman_tree.c)

# 平衡二叉树
add_executable(avl_tree tree/avl_tree.c)
#-------二叉树--------

#-------图--------
# 基于邻接链表的图
add_executable(test_graph_adjacency_list test_code/test_graph.c)
target_sources(test_graph_adjacency_list PUBLIC graph/adjacency_list_graph.c)
target_sources(test_graph_adjacency_list PUBLIC queue/sq_circular_queue.c)

#基于邻接矩阵的图
add_executable(test_graph_adjacency_matrix test_code/test_graph.c)
target_sources(test_graph_adjacency_matrix PUBLIC graph/adjacency_matrix_graph.c)
target_sources(test_graph_adjacency_matrix PUBLIC queue/sq_circular_queue.c)
#-------图--------