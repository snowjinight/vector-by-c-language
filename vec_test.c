#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main()
{
	vector_pa vec;
	p_vector p_vec = &vec;

	int arr_t[] = { 9,5,4,66,2,3,4,5,77,8,888,7675,4432,45,32,5,66,4234 };

	int  val = 9, rc;

	/*
	vec._size = sizeof(arr_t)/sizeof(int);
	vec._capacity = vec._size * 2;
	vec._elem = arr_t;
	*/
	int len = sizeof(arr_t) / sizeof(int);
	vector_op_o._copyform_init(p_vec, arr_t, 0, len);
	vector_op_o._insert(p_vec, 1, 1111);
	vector_op_o._display(p_vec);

	rc = vector_op_o._check(p_vec, val);
	printf("%d\n", rc);

	printf("value:%d\n", p_vec->_elem[10]);

	vector_op_o._remove(p_vec, 0, 7); //×ó±ÕÓÒ¿ª

	printf("size:%d\n", vec._size);

	vector_op_o._display(p_vec);

	vector_op_o._deconstruct(p_vec);

	return 0;

}