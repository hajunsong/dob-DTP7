#include <stdio.h>

extern void* createTestWidget();  //

static void*    s_widget_ptr;      //static void*를 선언

void* cui_get_widget()           //corecon에서 함수를
{
    if(s_widget_ptr == NULL)
        s_widget_ptr = (void*)createTestWidget(); //return할 함수 포인터

    return s_widget_ptr;	//static void*를 return 해준다.
}
