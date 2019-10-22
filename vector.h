#pragma once
#define rank int 
#define T int
typedef struct VECTOR
{
	T *_elem;
	rank _size;
	rank _capacity;

	int (*_check)(struct VECTOR* p, T val); //查找元素，返回位置
	int (*_rmelem)(struct VECTOR* p, rank lo, rank hi); //删除任意区间元素
	void (*_display)(struct VECTOR* p); //打印向量
	int (*_insert)(struct VECTOR* p, rank r, T val); //任意位置插入
	int (*_empty_init)(struct VECTOR* p, rank cap);//空初始化
	void (*_deconstruct)(struct VECTOR* p); //析构
	int (*_copyform_init)(struct VECTOR* p, T* const A, rank lo, rank hi, const int lenA); //区间拷贝初始化
	void (*_expand)(struct VECTOR* p); //动态扩容
	void (*_insert_tail)(struct VECTOR* p, T val); //尾插
	int (*_rm_single)(struct VECTOR* p, rank r);//单个元素删除

}vector, * p_vector;

void construct(struct VECTOR* p); //构造

/*
int check(struct VECTOR *p, int val);
int rmelem(struct VECTOR *p, rank lo, rank hi);
void display(struct VECTOR *p);
rank insert(struct VECTOR *p, rank r, T val);
void expand(struct VECTOR *p);
int vec_init(struct VECTOR *p, unsigned int cap);
void deconstruct(struct VECTOR *p);
int copyform_init(struct VECTOR *p, int* const A, rank lo, rank hi);
void insert_tail(struct VECTOR* p, T val);
void init(struct VECTOR* p);
*/

/*
typedef struct VECTOR_OP
{
	int (*_check)(struct VECTOR *p, int val);
	int (*_remove)(struct VECTOR *p, rank lo, rank hi);
	void (*_display)(struct VECTOR *p);
	rank (*_insert)(struct VECTOR *p, rank r, T val);
	int (*_vec_init)(struct VECTOR *p, unsigned int cap);
	void (*_deconstruct)(struct VECTOR *p);
	int (*_copyform_init)(struct VECTOR *p, int* const A, rank lo, rank hi);

}vector_op;


typedef struct CVEC
{
	vector_pa vp;
	vector_op* vop;

}cvec;
*/
/*
vector_op vec = {
	._check = check,
	._remove = remove,
	._display = display,
	._insert = insert,
	._vec_init = vec_init,
	._deconstruct = deconstruct,
	._copyform_init = copyform_init


};

*/

//cvec vector;
//vector.vop = &vec;


