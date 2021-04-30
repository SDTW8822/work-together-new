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
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], char name_css[][COURSE_NUM], int n, int m);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);  // m�ſγ̣�n��ѧ��
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m�ſγ̣�n��ѧ��
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m�ſγ̣�n��ѧ��
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float* x, float* y);
void SwapLong(long* x, long* y);
void SwapChar(char x[], char y[]);
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m);	//m�ſγ̣�n��ѧ��
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);

int main()
{
	int itemselected;
	int n = 0, m = 0;
	int i;										//�������ͣ�n��ѧ��������m �ǿγ�����
	float score[STU_NUM][COURSE_NUM];						//���Ǵ�Ÿ��Ƴɼ��Ķ�ά����
	float sum[STU_NUM], aver[STU_NUM];						//sum����ܳɼ���aver���ƽ���ɼ�
	long num[STU_NUM];										//num��ѧ��ѧ��
	char name[STU_NUM][MAX_LEN];							//name��ѧ������
	char name_css[STU_NUM][COURSE_NUM * 10];	//����ѧ���ĸ���
	char(*namee)[COURSE_NUM];
	namee = name_css;
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//����γ̵�����
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);
	//����γ�����
	printf("please input the test name:\n");
	for (i = 0; i < m; i++)
	{
		scanf("%s", name_css[i]);
	}

	printf("����������������������������������������������������������������\n");
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
	printf("����������������������������������������������������������������\n");
	printf("please input your choice:\n");
	for (;;)
	{
		scanf("%d", &itemselected);
		switch (itemselected)
		{
		case 1:	ReadScore(num, name, score, name_css, n, m);
			printf("please input your choice:\n");
			break;
		case 2:	AverSumofEveryCourse(score, n, name_css, m);
			printf("please input your choice:\n");
			break;
		case 3: AverSumofEveryStudent(num, name, score, n, m, sum, aver);
			printf("please input your choice:\n");
			break;
		case 4: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
			break;
		case 5: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Ascending);
			printf("\nSort in ascending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
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
			printf("please input your choice:\n");
			break;
		case 8: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			SearchbyNum(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
			break;
		case 9: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion
			SortbyScore(num, name, score, sum, aver, n, m, Descending);			//sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(num, name, score, sum, aver, n, m);
			SearchbyName(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
			break;
		case 10: StatisticAnalysis(score, n, m);
			printf("please input your choice:\n");
			break;
		case 11: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion 
			PrintScore(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
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
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM],char name_css[][COURSE_NUM], int n, int m)
{
	int i, j, k,x;
	char(*namee)[COURSE_NUM];
	namee = name_css;
	for (i = 0,j=0; i < n&&j<m; i++,j++)
	{
		printf("please input the student`s name:\t");
		scanf("%s", name[i]);
		printf("please input the student`s number:\t");
		scanf("%ld", num[i]);
		printf("please input the score in this order:");
		for (x = 0; x < m; x++)
{
			printf("%s\t", name_css[x]);
		}
		scanf("%f", score[i]);
	}
}

/* ����ÿ�ſγ̵��ֺܷ�ƽ���� */
void AverSumofEveryCourse(float score[][COURSE_NUM],char name_css[], int n, int m)  // m�ſγ̣�n��ѧ��
{
	int i, j, k;
	float sum[COURSE_NUM] = {0};
	float aver[COURSE_NUM];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
{
			sum[i] += score[i][j];

}
		aver[i] = sum[i] / n;
	}
	for (k = 0; k < m; k++)
	{
		printf("%s ���ܷ��ǣ�%0.2f,ƽ�����ǣ�%0.2f\n", name_css[k], sum[k], aver[k]);
	}
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

