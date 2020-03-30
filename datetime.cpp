/*
#include <iostream>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int y, int m, int d, int hour, int minute, int second); 
  DateTime(const DateTime &dt);
  ~DateTime();
  static void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};

int DateTime::sth = 0;

int main() {
  DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
  DateTime dt2(dt), &dt3 = dt;
  DateTime *dt4 = &dt;
  dt.showTime();
  dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth = 11;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
  year = y; month = m; day = d;
  this->hour = hour; this->minute = minute; this->second = second;
}
DateTime::DateTime(const DateTime &dt)
{
  year = dt.year; month = dt.month; day = dt.day;
  hour = dt.hour; minute = dt.minute; second = dt.second;
}
DateTime::~DateTime() 
{
  std::cout << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout << sth << std::endl;
}
*/
#include<iostream>
using namespace std;
class DateTime{
private:
	int year, month, day;
	int hour, minute, second;
public:
	DateTime();
	~DateTime();
	void showTime();
	void showLunar();//ʵ��2000�������ڵ�ũ������ ...ʵ�����������ĳ�ֻ��2020�� 
};
int main()
{
	DateTime dt;
	dt.showTime();
	dt.showLunar();
	return 0;
}
DateTime::DateTime()
{
	year=2020; month=03; day=22;
	hour=19; minute=57; second=20;
}
DateTime::~DateTime(){
}
void DateTime::showTime()
{
	printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n",year, month, day, hour, minute, second);
}
void DateTime::showLunar()
{
	///////////////////
	string l_year;
	if (month==1&&day<25)
	  l_year="������";
	else
	  l_year="������";
	///////////////////
	int l_month=0, l_day=0;
	int l_mon_length[13]={24,29,30,30,30,29,30,29,29,30,29,30,17};
	string l_mon_name[13]={"����","����","����","����","����","����","����","����","����","����","����","ʮ��","����"};
	///////////////////
	int mon_length[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int total_day=0;
	for (int i=1;i<=12;i++)
	{
		if (i<month)
		  total_day+=mon_length[i];
		else if (i==month)
		{
			total_day+=day;
			break;
		}
	}
	////////////////////
	while(1)
	{
		if (total_day>l_mon_length[l_month])
		{
			total_day-=l_mon_length[l_month];
			l_month++;
		}
		else if (total_day<=l_mon_length[l_month])
		{
			l_day=total_day;
			break;
		}
	}
	if (l_month==0)
	  l_day+=6;
	////////////////////
	string l_day_name[31]={"0","��һ","����","����","����","����","����","����","����","����","��ʮ",
							"ʮһ","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
							"إһ","إ��","إ��","إ��","إ��","إ��","إ��","إ��","إ��","��ʮ"};
	cout<<"��ǰʱ�䣺"<<l_year<<l_mon_name[l_month]<<l_day_name[l_day]<<" ";
	printf("%d:%d:%d\n",hour, minute, second);
}
