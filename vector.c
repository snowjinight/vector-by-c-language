// paratest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"





//typedef struct vector* p_vector;

void expand(p_vector p) 
{ 
	if(p->_size<p->_capacity)
		return;
	T* oldelem = p->_elem;
	p->_elem = (T*)malloc(sizeof(T) * (p->_capacity <<= 1));
	if (p->_elem == NULL)
		perror("no enough memmer");
	for (int i = 0; i < p->_size; i++)
		p->_elem[i] = oldelem[i];
	free(oldelem);

}
rank insert(p_vector p, rank r, T val)
{
	expand(p);
	for (int i = p->_size; i > r; i--)
		p->_elem[i] = p->_elem[i - 1];
	p->_elem[r] = val; p->_size++;
	return r;
}
int check(p_vector p, int val)
{
	int lo = 0, hi = p->_size;
	while ((hi-- > lo) && (val != p->_elem[hi]))      ;
	return hi;

}

int remove(p_vector p, int lo, int hi)
{
	while (hi < p->_size) p->_elem[lo++] = p->_elem[hi++];
	p->_size = lo;

	
	return 0;
}

void display (p_vector p)
{
	for (int i = 0; i < p->_size; i++)
	{
		printf("%d ", p->_elem[i]);

	}
	printf("\n");

}

int vec_init(p_vector p,  unsigned int cap)
{
	p->_elem = (int*)malloc(sizeof(int) * cap);
	if(p->_elem == NULL)
	{
		perror("no enough mem");
		return -1;
	}
	p->_size = 0;
	p->_capacity = cap;
	return 0;

}

void deconstruct(p_vector p)
{
	free(p->_elem);
}

int copyform_init(p_vector p, int * const A, rank lo, rank hi)
{
	p->_elem = (int*)malloc(sizeof(int) * 2*(hi-lo));
	p->_size = 0;
	while (lo < hi)
	{
		p->_elem[p->_size++] = A[lo++];
	}
	return 0;

}


vector_op vector_op_o = {
	._check = check,
	._remove = remove,
	._display = display,
	._insert = insert,
	._vec_init= vec_init,
	._deconstruct=deconstruct,
	._copyform_init= copyform_init


};







// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
