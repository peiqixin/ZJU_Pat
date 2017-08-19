#include <stdio.h>
#include <float.h>
typedef struct 	_int_param{
	int param1;
	int param2;
}INT_PARAM;
typedef struct _double_param{
	double param1;
	double param2;
}DOUBLE_PARAM;
// ADDFUNC是一个函数指针，指向一个返回类型为void* 参数为void*的函数
typedef void* (*ADDFUNC)(void*);
void* int_add(void *w_param)
{
	INT_PARAM* IParam = (INT_PARAM*)w_param;
	int res = IParam->param2 + IParam->param1;
	return (void*)&res;
}

void* double_add(void *w_param)
{
	DOUBLE_PARAM* DParam = (DOUBLE_PARAM*)w_param;
	double res = DParam->param1 + DParam->param2;
	return (void*)&res;
}

void* add_func(ADDFUNC f, void* w_param)
{
	//return (*f)(w_param);  //实际调用方式
	return f(w_param);
}

int main(int argc, char const *argv[])
{
	INT_PARAM val1 = {1, 2};
	DOUBLE_PARAM val2 = {10.1, 10.2};
	void* res1 = add_func(int_add, &val1);
	printf("res1 = %d\n", *((int*)res1));
	printf("res2 = %f\n", *((double*)add_func(double_add, &val2)));
	return 0;
}