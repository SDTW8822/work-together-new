/* 学生成绩管理系统v4.0

   指针和数组   多门课程、多个学生（学号、成绩、姓名）

  某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）
  //v1.0-v3.0都是“一门功课”，v4.0变成了“多门功课”

 （1）录入每个学生的学号、姓名和考试成绩；
 （2）计算每门课程的总分和平均分；				//比v3.0增加了“多门课程”
 （3）计算每个学生的总分和平均分；				//比v3.0增加的功能
 （4）按照每个学生的总分由高到低排出名次表；	//比v3.0增加的功能
 （5）按照每个学生的总分由低到高排出名次表；	//比v3.0增加的功能
 （6）按照学号由小到大排出成绩表；
 （7）按照姓名的字典顺序排出成绩表；
 （8）按照学号查询学生排名及其各科考试成绩；	//比v3.0增加了“多门课程”
 （9）按照姓名查询学生排名及其各科考试成绩；	//比v3.0增加了“多门课程”
 （10）按照优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60-69分）、不及格（0-59分）5个类别，统计每个类别的人数以及所占的百分比。
 （11）输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。	//比v3.0增加了“多门课程”

  实验要求：使用二维数组作为函数参数。
		菜单驱动，即：程序运行后，先显示菜单，按照用户输入的选项执行相应的操作。

  实验目的：在“学生成绩管理系统V3.0”的基础上，通过增加任务要求，熟悉二维数组作函数参数、模块化程序设计以及增量测试方法。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10		//字符串的最大长度
#define STU_NUM 30		//最多的学生人数
#define COURSE_NUM 6	//最多的考试科目数

//填写函数声明
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], char name_css[][COURSE_NUM], int n, int m);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);  // m门课程，n个学生
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m门课程，n个学生
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m门课程，n个学生
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
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m);	//m门课程，n个学生
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);

int main()
{
	int itemselected;
	int n = 0, m = 0;
	int i;										//变量解释：n是学生人数，m 是课程门数
	float score[STU_NUM][COURSE_NUM];						//这是存放各科成绩的二维数组
	float sum[STU_NUM], aver[STU_NUM];						//sum存放总成绩，aver存放平均成绩
	long num[STU_NUM];										//num是学生学号
	char name[STU_NUM][MAX_LEN];							//name是学生人数
	char name_css[STU_NUM][COURSE_NUM * 10];	//输入学生的个数
	char(*namee)[COURSE_NUM];
	namee = name_css;
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//输入课程的门数
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);
	//输入课程名称
	printf("please input the test name:\n");
	for (i = 0; i < m; i++)
	{
		scanf("%s", name_css[i]);
	}

	printf("————————————————————————————————\n");
	printf("\nManagement for student's scores \n");
	printf("1—input record \n");										//录入每个学生的学号、姓名和考试成绩；
	printf("2—caculate total and average acore of every course \n");	//计算每门课程的总分和平均分；
	printf("3—caculate total and average acore of every student \n");	//计算每个学生的总分和平均分；
	printf("4—sort in descending order by score of sum \n");			//按照每个学生的总分由高到低排出名次表
	printf("5—sort in ascending order by score of sum \n");			//按照每个学生的总分由低到高排出名次表
	printf("6—sort in ascending order by number \n");					//按照学号由小到大排出成绩表
	printf("7—sort in dictionary order by name \n");					//按照姓名的字典顺序排出成绩表；
	printf("8—search by number \n");									//按照学号查询学生排名及其各科考试成绩；
	printf("9—search by name \n");										//按照姓名查询学生排名及其各科考试成绩；
	printf("10—statistic analysis \n");									//统计各个分数段的学生人数及其所占的百分比
	printf("11—list record \n");										//输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("0—exit \n");
	printf("————————————————————————————————\n");
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

/* 显示菜单，并获得用户键盘输入的数据 */
int Menu(void)
{
	int itemSelected;
	printf("\nManagement for student's scores \n");
	printf("1—input record \n");										//录入每个学生的学号、姓名和考试成绩；
	printf("2—caculate total and average acore of every course \n");	//计算每门课程的总分和平均分；
	printf("3—caculate total and average acore of every student \n");	//计算每个学生的总分和平均分；
	printf("4—sort in descending order by score of sum \n");			//按照每个学生的总分由高到低排出名次表
	printf("5—sort in ascending order by score of sum \n");			//按照每个学生的总分由低到高排出名次表
	printf("6—sort in ascending order by number \n");					//按照学号由小到大排出成绩表
	printf("7—sort in dictionary order by name \n");					//按照姓名的字典顺序排出成绩表；
	printf("8—search by number \n");									//按照学号查询学生排名及其各科考试成绩；
	printf("9—search by name \n");										//按照姓名查询学生排名及其各科考试成绩；
	printf("10—statistic analysis \n");									//统计各个分数段的学生人数及其所占的百分比
	printf("11—list record \n");										//输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("0—exit \n");

	printf("please input your choice:\n");
	scanf("%d", &itemSelected);				//读入用户输入

	return itemSelected;
}

/* 输入n个学生的m门课的成绩 */
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

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(float score[][COURSE_NUM],char name_css[], int n, int m)  // m门课程，n个学生
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
		printf("%s 的总分是：%0.2f,平均分是：%0.2f\n", name_css[k], sum[k], aver[k]);
	}
}

/* 计算每个学生各门课程的总分和平均分——有输出 */
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m门课程，n个学生
{

}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m门课程，n个学生
{

}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b))
{

}

/* 使得数据按照升序排序 */
int Ascending(float a, float b)
{
	return a < b;
}


/* 使得数据按照降序排序 */
int Descending(float a, float b)
{
	return a > b;
}


/* 交换两个单精度浮点型数据 */
void SwapFloat(float* x, float* y)
{
	float temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个长整型数据 */
void SwapLong(long* x, long* y)
{
	long temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个字符串 */
void SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

/* 按照选择法，将数组num的元素值按照从小到大排序 */
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}


/* 使用交换法，实现字符串按字典顺序排序 */
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* 按照学号，查找学生成绩并显示查找结果 */
void SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* 按照姓名，查询学生排名并显示查找结果 */
void SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m)	//m门课程，n个学生
{

}

/* 打印学生成绩 */
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{

}

