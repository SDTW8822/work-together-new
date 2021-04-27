/* ѧ���ɼ�����ϵͳv4.0

   ָ�������   ���ſγ̡����ѧ����ѧ�š��ɼ���������

  ĳ������಻����30�ˣ����������ɼ������룩�μ���ĩ���ԣ���಻����6�ţ����������ɼ������룩
  //v1.0-v3.0���ǡ�һ�Ź��Ρ���v4.0����ˡ����Ź��Ρ�

 ��1��¼��ÿ��ѧ����ѧ�š������Ϳ��Գɼ���
 ��2������ÿ�ſγ̵��ֺܷ�ƽ���֣�				//��v3.0�����ˡ����ſγ̡�
 ��3������ÿ��ѧ�����ֺܷ�ƽ���֣�				//��v3.0���ӵĹ���
 ��4������ÿ��ѧ�����ܷ��ɸߵ����ų����α�	//��v3.0���ӵĹ���
 ��5������ÿ��ѧ�����ܷ��ɵ͵����ų����α�	//��v3.0���ӵĹ���
 ��6������ѧ����С�����ų��ɼ���
 ��7�������������ֵ�˳���ų��ɼ���
 ��8������ѧ�Ų�ѯѧ������������ƿ��Գɼ���	//��v3.0�����ˡ����ſγ̡�
 ��9������������ѯѧ������������ƿ��Գɼ���	//��v3.0�����ˡ����ſγ̡�
 ��10���������㣨90-100�֣������ã�80-89�֣����еȣ�70-79�֣�������60-69�֣���������0-59�֣�5�����ͳ��ÿ�����������Լ���ռ�İٷֱȡ�
 ��11�����ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ�����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�	//��v3.0�����ˡ����ſγ̡�

  ʵ��Ҫ��ʹ�ö�ά������Ϊ����������
		�˵������������������к�����ʾ�˵��������û������ѡ��ִ����Ӧ�Ĳ�����

  ʵ��Ŀ�ģ��ڡ�ѧ���ɼ�����ϵͳV3.0���Ļ����ϣ�ͨ����������Ҫ����Ϥ��ά����������������ģ�黯��������Լ��������Է�����
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10		//�ַ�������󳤶�
#define STU_NUM 30		//����ѧ������
#define COURSE_NUM 6	//���Ŀ��Կ�Ŀ��

//��д��������

int main()
{
	int itemselected;
	int n = 0, m = 0;
	float score[STU_NUM][COURSE_NUM];
	float sum[STU_NUM], aver[STU_NUM];
	long num[STU_NUM];
	char name[STU_NUM][MAX_LEN];

	//����ѧ���ĸ���
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//����γ̵�����
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);

	while (1)
	{
		itemselected = Menu();	//��ʾ�˵�������ȡ�û�����
		switch (itemselected)
		{
		case 1:	ReadScore(num, name, score, n, m);
			break;
		case 2:	AverSumofEveryCourse(score, n, m);
			break;
		case 3: AverSumofEveryStudent(num, name, score, n, m, sum, aver);
			break;
		case 4: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			break;
		case 5: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Ascending);
			printf("\nSort in ascending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			break;
		case 6: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			AsSortbyNum(num, name, score, sum, aver, n, m);
			printf("\nsort in ascending order by number:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			break;
		case 7: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyName(num, name, score, sum, aver, n, m);
			printf("\nsort in dictionary order by name:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			break;
		case 8: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			SearchbyNum(num, name, score, sum, aver, n, m);
			break;
		case 9: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			SearchbyName(num, name, score, sum, aver, n, m);
			break;
		case 10: StatisticAnalysis(score, n, m);
			break;
		case 11: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion 
			PrintScore(num, name, score, sum, aver, n, m);
			break;
		case 0: printf("End of program!\n");
			exit(0);
		default: printf("Input error!\n");
		}
	}
	return 0;
}

/* ��ʾ�˵���������û�������������� */
int Menu(void)
{
	int itemSelected;
	printf("\nManagement for student's scores \n");
	printf("1��input record \n");										//¼��ÿ��ѧ����ѧ�š������Ϳ��Գɼ���
	printf("2��caculate total and average acore of every course \n");	//����ÿ�ſγ̵��ֺܷ�ƽ���֣�
	printf("3��caculate total and average acore of every student \n");	//����ÿ��ѧ�����ֺܷ�ƽ���֣�
	printf("4��sort in descending order by score of sum \n");			//����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
	printf("5��sort in ascending order by score of sum \n");			//����ÿ��ѧ�����ܷ��ɵ͵����ų����α�
	printf("6��sort in ascending order by number \n");					//����ѧ����С�����ų��ɼ���
	printf("7��sort in dictionary order by name \n");					//�����������ֵ�˳���ų��ɼ���
	printf("8��search by number \n");									//����ѧ�Ų�ѯѧ������������ƿ��Գɼ���
	printf("9��search by name \n");										//����������ѯѧ������������ƿ��Գɼ���
	printf("10��statistic analysis \n");									//ͳ�Ƹ��������ε�ѧ������������ռ�İٷֱ�
	printf("11��list record \n");										//���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֡�ƽ�����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�
	printf("0��exit \n");

	printf("please input your choice:\n");
	scanf("%d", &itemSelected);				//�����û�����

	return itemSelected;
}

/* ����n��ѧ����m�ſεĳɼ� */
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m)
{

}

/* ����ÿ�ſγ̵��ֺܷ�ƽ���� */
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m)  // m�ſγ̣�n��ѧ��
{

}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m�ſγ̣�n��ѧ��
{

}

/* ����ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֡�������� */
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m�ſγ̣�n��ѧ��
{

}

/* ��ѡ�񷨣�������sum��Ԫ��ֵ���� */
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b))
{

}

/* ʹ�����ݰ����������� */
int Ascending(float a, float b)
{
	return a < b;
}


/* ʹ�����ݰ��ս������� */
int Descending(float a, float b)
{
	return a > b;
}


/* �������������ȸ��������� */
void SwapFloat(float* x, float* y)
{
	float temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* ������������������ */
void SwapLong(long* x, long* y)
{
	long temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* ���������ַ��� */
void SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

/* ����ѡ�񷨣�������num��Ԫ��ֵ���մ�С�������� */
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}


/* ʹ�ý�������ʵ���ַ������ֵ�˳������ */
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* ����ѧ�ţ�����ѧ���ɼ�����ʾ���ҽ�� */
void SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* ������������ѯѧ����������ʾ���ҽ�� */
void SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* ͳ�Ƹ��������ε�ѧ������������ռ�İٷֱ� */
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m)	//m�ſγ̣�n��ѧ��
{

}

/* ��ӡѧ���ɼ� */
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

