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
	//����������壬��Χ0-6
	switch (font) {
	case red:
		//outtextxy(40,20,L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	case blue:
		//outtextxy(40, 20, L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	case yellow:
		//outtextxy(40, 20, L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	case black:
		//outtextxy(40, 20, L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	case 3:
	case green:
		//outtextxy(40, 20, L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	case purple:
		//outtextxy(40, 20, L"��ɫ");
		printf("\n\n\n	��ɫ\n\n");
		break;
	}
}
/*
    0 = ��ɫ       
    1 = ��ɫ       
    2 = ��ɫ            
    4 = ��ɫ      
    5 = ��ɫ       
    6 = ��ɫ 

    7 = ��ɫ       F = ����ɫ
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
		//��ɫƥ��,���ж���ȷ
		name.ConsistentTime[n] = difftime;
		name.ConsistentTimes++;
	}
	else if ((color != randfont) && i == false) {
		//��ɫ��ƥ�䣬���ж���ȷ
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
	printf("������\n>>>");
	cin >> name;
	printf("������Դ�����<=199�Σ�\n>>>");
	int n;
	cin >> n;
	statistics Name;
	system("cls");
	system("color 70");
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
	printf("1.ע���л�����д\n2.��	��F��	��	��J��	�Կ�ʼ\n3.��������ɫ�뺬����ͬ������F��\n4.��������ɫ�뺬�岻��ͬ������J��\n\n");
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

	cout << "������>>>" << name << endl;
	cout << "ƥ��ʱ����Ӧʱ��" << endl;
	int m;
	for (int i = 0, m = 0; i < Name.ConsistentTimes;)
	{
		if (Name.ConsistentTime[m] > 0) {
			printf("%lf\n", Name.ConsistentTime[m]);
			i++;
		}
		m++;
	}
	cout << "��ƥ��ʱ����Ӧʱ��" << endl;
	for (int i = 0, m = 0; i < Name.InconsistTimes;)
	{
		if (Name.InconsistTime[m] > 0) {
			printf("%lf\n", Name.InconsistTime[m]);
			i++;
		}
		m++;
	}
	cout << "���������" << Name.WrongTimes<<endl;
	cout << "����#ֹͣ���ԣ�����������ʼ��һ�ֲ���" << endl;
}