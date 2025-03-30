#include<iostream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#undef UNICODE
#undef _UNICODE
using namespace std;
#define ChangeColor(a) system("color 7a")
#define MAXSIZE 150
struct statistics {
	double ConsistentTime[MAXSIZE] = { 0 };
	double InconsistTime[MAXSIZE] = { 0 };
	int WrongTimes = 0;
	int ConsistentTimes=0;
	int InconsistTimes=0;
};
enum {
	red=4,
	blue=1,
	yellow=6,
	black=0,
	green=2,
	purple=5
};
void CoutFont(int font) {
	//随机生成字体，范围0-6
	switch (font) {
	case red:
		//outtextxy(40,20,L"红色");
		printf("\n\n\n	红色\n\n");
		break;
	case blue:
		//outtextxy(40, 20, L"蓝色");
		printf("\n\n\n	蓝色\n\n");
		break;
	case yellow:
		//outtextxy(40, 20, L"黄色");
		printf("\n\n\n	黄色\n\n");
		break;
	case black:
		//outtextxy(40, 20, L"黑色");
		printf("\n\n\n	黑色\n\n");
		break;
	case 3:
	case green:
		//outtextxy(40, 20, L"绿色");
		printf("\n\n\n	绿色\n\n");
		break;
	case purple:
		//outtextxy(40, 20, L"紫色");
		printf("\n\n\n	紫色\n\n");
		break;
	}
}
/*
    0 = 黑色       
    1 = 蓝色       
    2 = 绿色            
    4 = 红色      
    5 = 紫色       
    6 = 黄色 

    7 = 白色       F = 亮白色
*/
int ChangeFontColor(int randcolor) {
	switch(randcolor) {
	case red:
		system("color 74");
		return red;
		break;
	case blue:
		system("color 71");
		return blue;
		break;
	case 3:
	case green:
		system("color 72");
		return green;
		break;
	case black:
		system("color 70");
		return black;
		break;
	case purple:
		system("color 75");
		return purple;
		break;
	case yellow:
		system("color 76");
		return yellow;
		break;
	}
}
void test(statistics &name, double difftime, int color, int randfont, bool i,int n) {
	if (color == randfont && i == true) {
		//颜色匹配,且判断正确
		name.ConsistentTime[n] = difftime;
		name.ConsistentTimes++;
	}
	else if ((color != randfont) && i == false) {
		//颜色不匹配，且判断正确
		name.InconsistTime[n] = difftime;
		name.InconsistTimes++;
	}
	else {
		name.WrongTimes++;
	}
}
int main() {
	char c;
	srand((unsigned int)time(NULL));
	time_t start, end;
	string name;
	printf("输入编号\n>>>");
	cin >> name;
	printf("输入测试次数（<=199次）\n>>>");
	int n;
	cin >> n;
	statistics Name;
	system("cls");
	system("color 70");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	printf("1.注意切换至大写\n2.按	“F”	或	“J”	以开始\n3.若字体颜色与含义相同，按“F”\n4.若字体颜色与含义不相同，按“J”\n\n");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	_getch();
	system("cls");
	char ch;
	int randfont;
	int randcolor;
	int color;
	for (int i = 0; i < n; i++) {
		int flag = rand() % 2;
		if (flag == 1) {
			randfont = rand() % 6;
			randcolor = rand() % 6;
			color = ChangeFontColor(randcolor);
			CoutFont(randfont);
		}
		else {
			randfont = rand() % 6;
			color = ChangeFontColor(randfont);
			CoutFont(randfont);
		}
		start = clock();
		ch = _getch();
		if (ch == 'F') {
			end = clock();
			test(Name, difftime(end, start), color, randfont, true, i);
			printf("%lf", difftime(end, start));
			Sleep(1000 + rand() % 800);
		}
		else if (ch == 'J') {
			end = clock();
			test(Name, difftime(end, start), color, randfont, false, i);
			printf("%lf", difftime(end, start));
			Sleep(1000 + rand() % 800);
		}

		system("cls");
	}

	cout << "受试者>>>" << name << endl;
	cout << "匹配时，反应时间" << endl;
	int m;
	for (int i = 0, m = 0; i < Name.ConsistentTimes;)
	{
		if (Name.ConsistentTime[m] > 0) {
			printf("%lf\n", Name.ConsistentTime[m]);
			i++;
		}
		m++;
	}
	cout << "不匹配时，反应时间" << endl;
	for (int i = 0, m = 0; i < Name.InconsistTimes;)
	{
		if (Name.InconsistTime[m] > 0) {
			printf("%lf\n", Name.InconsistTime[m]);
			i++;
		}
		m++;
	}
	cout << "错误次数：" << Name.WrongTimes<<endl;
	cout << "输入#停止测试，输入其它开始下一轮测试" << endl;
}