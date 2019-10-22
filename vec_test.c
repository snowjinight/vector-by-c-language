
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main()
{
	vector vec;
	p_vector p_vec = &vec;
	construct(p_vec);//���캯����ʼ��

	int arr_t[] = { 9,5,4,66,2,3,4,5,77,8,888,7675,4432,45,32,5,66,4234 };

	int  val = 9, rc;


	int len = sizeof(arr_t) / sizeof(int);
	//printf("%d\n", len);
	vec._copyform_init(p_vec, arr_t, 0, len+2, len);

	vec._copyform_init(p_vec, arr_t, 0, len, len);
	vec._insert(p_vec, 1, 1111);
	vec._insert(p_vec, 30, 1111);
	vec._display(p_vec);

	rc = vec._check(p_vec, val);
	printf("rc:%d\n", rc);

	rc = vec._check(p_vec, 1000);
	printf("rc:%d\n", rc);

	//printf("value:%d\n", p_vec->_elem[10]);

	rc=vec._rmelem(p_vec, 0, 7); //����ҿ�
	//printf("size:%d\n", vec._size);
	printf("num of delete:%d\n", rc);
	vec._display(p_vec);


	rc=vec._rmelem(p_vec, -2, 7); //����ҿ�
	printf("num of delete:%d\n", rc);
	vec._display(p_vec);


	vec._deconstruct(p_vec);


	//��������2����һ�ֳ�ʼ��
	vector vec1;
	p_vector p_vec1 = &vec1;
	construct(p_vec1);//���캯����ʼ��

	vec1._empty_init(p_vec1, 10); //֮ǰĬ���˳�ʼ��1

	vec1._insert_tail(p_vec1, 333);
	vec1._insert_tail(p_vec1, 3333);
	vec1._insert_tail(p_vec1, 33333);
	vec1._display(p_vec1);

	vec1._rm_single(p_vec1, 5);
	vec1._display(p_vec1);

	vec1._deconstruct(p_vec1);

	return 0;

}
