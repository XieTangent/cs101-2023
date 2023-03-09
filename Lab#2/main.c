#include <stdio.h>
#include <string.h>

typedef struct employee {
    int id;
    char name[10];
    int age;
    char phone[12];
    float salary;
} employee_t;

void employee_info(employee_t my_emp) {
    printf("id=%d\nname=%s\nage=%d\nphone=%s\nsalary=%f\n",my_emp.id,my_emp.name,my_emp.age,my_emp.phone,my_emp.salary);
}

int main()
{
    employee_t em;
    strcpy (em.name,"IU Lee");
    em.id=69;
    em.age=18;
    strcpy (em.phone,"0937123456");
    em.salary=1000.30;
    printf("size=%dbyte\n",(int)sizeof(em));
    employee_info(em);

    return 0;
}
