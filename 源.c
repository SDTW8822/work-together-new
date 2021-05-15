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
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);  // m门课程，n个学生
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m门课程，n个学生
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);	// m门课程，n个学生
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float* x, float* y);
void SwapLong(long* x, long* y);
void SwapChar(char x[], char y[]);
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*nunn)(int a, int b));
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void StatisticAnalysis(float sum[], int n);	
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);

int main()
{
	int itemselected;
	int n = 0, m = 0;
	int i;										//变量解释：n是学生人数，m 是课程门数
	float score[STU_NUM][COURSE_NUM];						//这是存放各科成绩的二维数组
	float sum[STU_NUM], aver[STU_NUM];						//sum存放总每个学生成绩，aver存放平均成绩
	long num[STU_NUM];										//num是学生学号
	char name[STU_NUM][MAX_LEN];							//name是学生姓名
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	//输入课程的门数
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);

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
	printf("10—statistic analysis \n");								//统计各个分数段的学生人数及其所占的百分比
	printf("11—list record \n");										//输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("0—exit \n");
	printf("————————————————————————————————\n");
	printf("please input your choice:\n");
	for (;;)
	{
		scanf("%d", &itemselected);
		switch (itemselected)
		{
		case 1:	ReadScore(num,name,score,n,m);
			printf("please input your choice:\n");
			break;
		case 2:	AverSumofEveryCourse(score,n,m);
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
			AsSortbyNum(num, name, score, sum, aver, n, m,Descending);
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
		case 10: StatisticAnalysis(sum, n);
			printf("please input your choice:\n");
			break;
		case 11: AverSumofEveryStudent_no_out(num, name, score, n, m, sum, aver);	//must run this function first, then run next funcion 
			PrintScore(num, name, score, sum, aver, n, m);
			printf("please input your choice:\n");
			break;
		case 0: 
			printf("End of program!\n");
		default: 
			printf("Input error!\n");
		}
	}
	return 0;
}



/* 输入n个学生的m门课的成绩 */
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m)
{
	int i, k;

	for (i = 0; i < n; i++)
	{	
		printf("please input the student`s name:\t");
		scanf("%s", &name[i]);
		printf("please input the student`s number:\t");
		scanf("%ld", &num[i]);

		for (k = 0; k < m; k++)
		{
			printf("please input the students score(第 %d 门):\t",k+1);
			scanf("%f", &score[i][k]);
		}
		
		
	}
}

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(float score[][COURSE_NUM],int n, int m)  // m门课程，n个学生
{
	int i, j, k;
	k = 0;
	float all[COURSE_NUM] = {0};					//变量解释：数组all 和aver 分别是存放每门课的总成绩和平均成绩
	float aver[COURSE_NUM];
	float(*p)[COURSE_NUM];
	p = score;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			all[i] += score[j][i];
			
		}
		aver[i] = all[i] / m;
	}
	for (k = 0; k < m; k++)
	{
		printf("第 %d 门 成绩总分：%0.2f,平均分：%0.2f\n", k + 1, all[k], aver[k]);
	}
}

/* 计算每个学生各门课程的总分和平均分——有输出 */
void AverSumofEveryStudent(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m门课程，n个学生
{
	int i, j, k;
	char(*np)[MAX_LEN];
	np = name;
	sum[0] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			sum[i] = sum[i] + score[i][j];
		
		}
		aver[i] = sum[i] / m;
	}
	for (k = 0; k < n; k++)
	{
		printf("姓名：%s\t学号：%ld\t 总分：%0.2f \t 平均分：%0.2f", np[k], num[k], sum[k], aver[k]);
	}
}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m门课程，n个学生
{
	int i, j, k;
	
	sum[0] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			sum[i] = sum[i] + score[i][k];

		}
		aver[i] = sum[i] / m;
	}
}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b))
{
	int i, j, k;
	float(*np)[COURSE_NUM];
	char(*p)[MAX_LEN];
	p = name;
	np = score;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(sum[j], sum[k]))  k = j;
		}
		if (k != j)
		{	
			SwapFloat(np + k, np + i);
			SwapFloat(&sum[k], &sum[i]);
			SwapFloat(&aver[k], &aver[i]);
			SwapLong(&num[k], &num[i]);
			SwapChar(p + k, p + i);


		}
	}
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
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*nunn)(float a, float b))
{
	int i, j, k;
	char(*p)[MAX_LEN];
	float(*np)[COURSE_NUM];
	np = score;
	p = name;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*nunn)(num[j], num[k]))  k = j;
		}
		if (k != j)
		{
			SwapFloat(np + k, np + i);
			SwapFloat(&sum[k], &sum[i]);
			SwapFloat(&aver[k], &aver[i]);
			SwapLong(&num[k], &num[i]);
			SwapChar(p + k, p + i);
		}
	}
}


/* 实现字符串按字典顺序排序 */
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	char(*p)[MAX_LEN];
	float(*np)[COURSE_NUM];
	int i, j, k;
	p = name;
	np = score;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)

		{
			if (strcmp(name[i], name[j]) > 0)



			{
				SwapFloat(&sum[j], &sum[i]);
				SwapLong(&num[j], &num[i]);
				SwapFloat(np + i, np + j);
				SwapChar(p + j, p + i);
			}
		}
	}

}

/* 按照学号，查找学生成绩并显示查找结果 */
void SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i, think, cishu = 0;
	long   nums;
	float(*p)[COURSE_NUM];
	think = 0;
	p = score;
	SortbyScore(num, name, score, sum, aver, n, m, Descending);

	printf("******************Whitch ID do you want to know !Please input it :\n");
	scanf("%ld", &nums);
	for (i = 0; i <= n - 1; i++)
	{
		if (num[i] != nums)
		{
			cishu++;
		}
		if (num[i] == nums)
		{
			think = i;
		}

	}

	printf("学号 :%ld\t  姓名 :%s \t 总分 :%0.2f \t   平均分：%0.2f\t 名次：%d\n", num[think], name[think], sum[think],aver[think] ,think + 1);
	printf("各科成绩：%0.2f\n", p[think]);
}

/* 按照姓名，查询学生排名并显示查找结果 */
void SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i, think, cishu = 0;
	char names[1][MAX_LEN];
	float(*p)[COURSE_NUM];
	p = score;
	think = 0;

	SortbyScore(num, name, score, sum, aver, n, m, Descending);

	printf("******************Whitch NAME   do you want to know !Please input it :\n");
	scanf("%s", names[0]);
	for (i = 0; i <= n - 1; i++)
	{
		if (strcmp(name[i], names[0]) != 0)
		{
			cishu++;
		}
		if (strcmp(name[i], names[0]) == 0)
		{
			think = i;
		}

	}

	printf("学号 :%ld\t  姓名 :%s \t 总分 :%0.2f \t   平均分：%0.2f\t 名次：%d\n", num[think], name[think], sum[think], aver[think], think + 1);
	printf("各科成绩：%0.2f\n", p[think]);
}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(float sum[], int n)	//m门课程，n个学生
{
	int i, vgod, gods, jige, unjige;
	i = 0; vgod = 0; gods = 0; jige = 0; unjige = 0;
	for (i = 0; i < n; i++)
	{
		if (sum[i] >= 90)
		{
			vgod++;
		}
		if (sum[i] >= 80 && sum[i] < 90)
		{
			gods++;
		}
		if (sum[i] >= 60)

		{
			jige++;
		}
		if (sum[i] < 60)
		{
			unjige++;
		}
	}

	printf("本次成绩情况如下：\n 优秀率：%1f %%\n 良好率：%1f %%\n 及格率： %1f %%  \n不及格率：%1f %% \n", (float)vgod * 100 / n, (float)gods * 100 / n, (float)jige * 100 / n, (float)unjige * 100 / n);
}


/* 打印学生成绩 */
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i;
	char(*p)[MAX_LEN];
	float(*np)[COURSE_NUM];
	np = score;
	p = name;
	for (i = 0; i < n; i++)
	{
		printf("\t姓名：%s学号 ：%10ld 总分：%4.2f 平均分：%4.2f\n", p[i], num[i], sum[i],aver[i]);
		printf("各科成绩：%0.2f", np[i]);
	}
}

//zwx 完成