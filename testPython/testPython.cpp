#include "Python.h"


int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		return -1;
	}
	PyRun_SimpleString("print('a+b = c') ");
	PyObject *pModule, *pFunc;
	// pName = PyUnicode_FromString("pytest");
	pModule = PyImport_ImportModule("pytest");
	if (!pModule)
	{
		return -1;
	}
	pFunc = PyObject_GetAttrString(pModule, "addFun");
	if (!pFunc)
	{
		return -1;
	}
	PyObject_CallFunction(pFunc, "ii", 1, 2); // ע�����ֵ��ø�ʽ����i����ʾ���ͣ�����i��ʾ����������
	
	// Py_DECREF(pFunc);
	PyObject *obj = Py_BuildValue("s", "parseAPT.py");
	FILE *fp = _Py_fopen_obj(obj, "r+");
	if (fp == NULL)
		return -1;
	PyRun_SimpleFile(fp, "parseAPT.py");

	Py_Finalize();
	getchar();
	return 0;


}