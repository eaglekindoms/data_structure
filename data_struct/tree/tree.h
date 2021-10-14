//
// Created by eagle on 2021/9/27.
// 树的顺序储存
//

#define MAX_TREE_SIZE 100

typedef int T;
//---------------------------------------------
/* *
 * 双亲表示法
 * 特点：查节点的双亲方便
 * 查节点的孩子需遍历整个数组
 * 删除节点麻烦
 *
 * */

// 树节点定义
typedef struct {
    T data;// 数据域
    int parent;// 父节点索引域
} PTNode;

// 树类型定义
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];//节点数组
    int n;// 节点数
} PTree;
//-------------------------------------------
/* *
 * 孩子表示法：顺序+链式储存
 * 先顺序储存各个节点，各个节点储存孩子链表头指针
 *
 * */
struct CTNode {
    int child;// 孩子索引
    struct CTNode *next;// 下一个孩子
};
// 数组节点
typedef struct {
    T data;// 数据域
    struct CTNode *first;// 第一个孩子
} CTBox;
// 树结构体
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];// 节点数组
    int n;// 节点数
    int r;// 根索引
} CTree;
//-------------------------------------------
/* *
 * 孩子兄弟表示法：链式储存
 * 本质：转为二叉树储存
 * 左指针指向孩子节点，右指针指向兄弟节点
 * 也可用来储存森林，把各个树的根节点视为兄弟关系
 *
 */
typedef struct CSNode {
    T data;// 数据域
    struct CSNode *firstChild;// 第一个孩子节点指针
    struct CSNode *firstSibling;// 第一个兄弟节点指针
} CSNode, *CSTree;
//-------------------------------------------
/* *
 *  树    森林  二叉树
 * 先序 = 先序 = 先序
 * 后序 = 中序 = 中序
 * */