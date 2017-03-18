#include <iostream>
#include <Python.h>

int main(void)
{
    std::cout << "Hi!" << std::endl;

    // Try to create an instance of a Python script 10 times.
    {
        Py_Initialize();

        for (int i=0; i<10; i++)
        {
            // Import module.
            PyObject* pModuleName = PyUnicode_FromString("testclass");
            PyObject* pModule = PyImport_Import(pModuleName);

            if (pModule == nullptr)
            {
                PyErr_Print();
                return -1;
            }

            PyObject* pClass = PyObject_GetAttrString(pModule, "testclass");

            if (pClass == nullptr)
            {
                PyErr_Print();
                return -1;
            }

            if (!PyCallable_Check(pClass))
            {
                std::cout << "not callable" << std::endl;
                return -1;
            }

            PyObject* classInstance = PyObject_CallObject(pClass, nullptr);

            if (classInstance == nullptr)
            {
                PyErr_Print();
                return -1;
            }
        }
        Py_Finalize();
    }

}
