
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"



int vec_init(struct VECTOR* p, rank cap)
{
	if (cap < 1)
	{
		printf("invalid parameter\n");
		return -2;
	}
	p->_deconstruct(p);
	p->_elem = (T*)malloc(sizeof(T) * cap);
	if (p->_elem == NULL)
	{
		perror("no enough mem");
		return -1;
	}
	p->_size = 0;
	p->_capacity = cap;
	return 0;
}

int copyform_init(struct VECTOR* p, T* const A, rank lo, rank hi, const int lenA)
{
	if (lo<0 || hi>lenA)
	{
		printf("invalid parameters\n");
		return -2;
	}
	p->_deconstruct(p);
	p->_elem = (T*)malloc(sizeof(T) * (p->_capacity = 2 * (hi - lo)));
	if (p->_elem == NULL)
	{
		return -1;
	}
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
int insert(struct VECTOR *p, rank r, T val)
{
	if (r > p->_size)
	{
		printf("out of memory boundary\n");
		return -1;
	}
	p->_expand(p);
	for (rank i = p->_size; i > r; i--)
		p->_elem[i] = p->_elem[i - 1];
	p->_elem[r] = val; p->_size++;
	return r;
}
int check(struct VECTOR *p, T val)
{
	int lo = 0, hi = p->_size;
	while ((hi-- > lo) && (val != p->_elem[hi]))      ;
	return hi;
}

int rmelem(struct VECTOR *p, rank lo, rank hi)
{
	if (lo<0 || hi>p->_size)
	{
		perror("operate memory where beyond allocated ");
		//printf("strerror:%s\n", strerror(errno));
		return -1;
	}
	while (hi < p->_size) p->_elem[lo++] = p->_elem[hi++];
	p->_size = lo;
	return hi-lo;
}

int rm_single(struct VECTOR* p, rank r)
{
	if (p->_rmelem(p, r, r + 1) == -1)
	{
		perror("overflow");
		//printf("strerror:%s\n", strerror(errno));
		return -1;
	}
	return 0;
}

void display (struct VECTOR *p)
{
	printf("size:%d\n", p->_size);
	for (rank i = 0; i < p->_size; i++)
	{
		printf("%d ", p->_elem[i]);
	}
	printf("\n");

}

void deconstruct(struct VECTOR *p)
{
	if (p->_elem != NULL)
	{
		free((void*)p->_elem);
		p->_elem = NULL;
	}
	return;
}


void insert_tail(struct VECTOR* p, T val)
{
	p->_expand(p);
	p->_elem[p->_size++] = val;
}

void construct(struct VECTOR* p)
{
		p->_elem = NULL;
		p->_capacity = 0;
		p->_size = 0;
		p->_check = check;
		p->_rmelem = rmelem;
		p->_display = display;
		p->_insert = insert;
		p->_empty_init = vec_init;
		p->_deconstruct = deconstruct;
		p->_copyform_init = copyform_init;
		p->_expand = expand;
		p->_insert_tail = insert_tail;
		p->_rm_single = rm_single;
		p->_empty_init(p, 1);
}

