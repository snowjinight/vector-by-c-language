// paratest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



int vec_init(struct VECTOR* p, unsigned int cap)
{
	p->_elem = (int*)malloc(sizeof(int) * cap);
	if (p->_elem == NULL)
	{
		perror("no enough mem");
		return -1;
	}
	p->_size = 0;
	p->_capacity = cap;
	return 0;

}

int copyform_init(struct VECTOR* p, int* const A, rank lo, rank hi)
{
	p->_elem = (int*)malloc(sizeof(int) * (p->_capacity = 2 * (hi - lo)));
	p->_size = 0;
	while (lo < hi)
	{
		p->_elem[p->_size++] = A[lo++];
	}
	return 0;

}

void expand(struct VECTOR *p) 
{ 
	if(p->_size<p->_capacity)
		return;
	T* oldelem = p->_elem;
	p->_elem = (T*)malloc(sizeof(T) * (p->_capacity <<= 1));
	if (p->_elem == NULL)
		perror("no enough memmer");
	for (rank i = 0; i < p->_size; i++)
		p->_elem[i] = oldelem[i];
	free((void*)oldelem);

}
rank insert(struct VECTOR *p, rank r, T val)
{
	p->_expand(p);
	for (rank i = p->_size; i > r; i--)
		p->_elem[i] = p->_elem[i - 1];
	p->_elem[r] = val; p->_size++;
	return r;
}
int check(struct VECTOR *p, int val)
{
	int lo = 0, hi = p->_size;
	while ((hi-- > lo) && (val != p->_elem[hi]))      ;
	return hi;

}

int rmelem(struct VECTOR *p, rank lo, rank hi)
{
	while (hi < p->_size) p->_elem[lo++] = p->_elem[hi++];
	p->_size = lo;

	
	return 0;
}

void display (struct VECTOR *p)
{
	for (rank i = 0; i < p->_size; i++)
	{
		printf("%d ", p->_elem[i]);

	}
	printf("\n");

}



void deconstruct(struct VECTOR *p)
{
	free((void*)p->_elem);
	return;
}



void insert_tail(struct VECTOR* p, T val)
{
	p->_expand(p);
	p->_elem[p->_size++] = val;
}

void init(struct VECTOR* p)
{
		p->_check = check;
		p->_rmelem = rmelem;
		p->_display = display;
		p->_insert = insert;
		p->_vec_init = vec_init;
		p->_deconstruct = deconstruct;
		p->_copyform_init = copyform_init;
		p->_expand = expand;
		p->_insert_tail = insert_tail;
}

