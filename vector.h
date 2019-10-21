#pragma once
#define rank unsigned int 
#define T int
typedef struct VECTOR
{
	int* _elem;
	rank _size;
	rank _capacity;


}vector_pa, * p_vector;

int check(p_vector p, int val);
int remove(p_vector p, rank lo, rank hi);
void display(p_vector p);

typedef struct VECTOR_OP
{
	int (*_check)(p_vector p, int val);
	int (*_remove)(p_vector p, rank lo, rank hi);
	void (*_display)(p_vector p);
	rank (*_insert)(p_vector p, rank r, T val);
	int (*_vec_init)(p_vector p, unsigned int cap);
	void (*_deconstruct)(p_vector p);
	int (*_copyform_init)(p_vector p, int* const A, rank lo, rank hi);

}vector_op;


typedef struct CVEC
{
	vector_pa vp;
	vector_op* vop;

}cvec;



