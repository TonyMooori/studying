/* �L�ł�������C    P155 */

#include <stdio.h>

int main(void){
    int a;
    int *lpa;
    
    lpa = &a;
    
    printf("�K���Ȑ����l����� --- ");
    scanf("%d",&a);
    printf("�ϐ�a��%d���������܂���\n",a);
    printf("�ϐ�a�̃A�h���X��%p�ł�\n",&a);
    printf("�ϐ�a���w���Ă���|�C���^��lpa�ł�(lpa �� %p)\n",lpa);
    printf("*lpa�̒l��%d�ł�\n",*lpa);
    
    return 0;
}