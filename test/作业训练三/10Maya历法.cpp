#include<iostream>
#include<string>
using namespace std;
void turn(int x,string a,int y){//转换函数
	int z=0,days,month,year,date;
	string c;
	if(a=="pop")z=1;
	else if(a=="no")z=2;
	else if(a=="zip")z=3;	
	else if(a=="zotz")z=4;
	else if(a=="tzec")z=5;
	else if(a=="xul")z=6;
	else if(a=="yoxkin")z=7;
	else if(a=="mol")z=8;	
	else if(a=="chen")z=9;
	else if(a=="yax")z=10;
	else if(a=="zac")z=11;
	else if(a=="ceh")z=12;
	else if(a=="macc")z=13;
	else if(a=="kankin")z=14;
	else if(a=="muan")z=15;
	else if(a=="pax")z=16;
	else if(a=="koyab")z=17;
	else if(a=="cumhu")z=18;
	else if(a=="uayet")z=19;
	days=x+1+(z-1)*20+y*365;//算出是世界开始的第几天
	date=days%13;
	if(date==0) date+=13; 
	month=days%20;
	year=days/260;//260天为1年
	switch(month){//将月份期间转化为字符串
		case 1:c="imix";break;
		case 2:c="ik";break;
		case 3:c="akbal";break;
		case 4:c="kan";break;
		case 5:c="chicchan";break;
		case 6:c="cimi";break;	
		case 7:c="manik";break;
		case 8:c="lamat";break;
		case 9:c="muluk";break;	
		case 10:c="ok";break;
		case 11:c="chuen";break;
		case 12:c="eb";break;
		case 13:c="ben";break;
		case 14:c="ix";break; 	
		case 15:c="mem";break;
		case 16:c="cib";break;
		case 17:c="caban";break;
		case 18:c="eznab";break;
		case 19:c="canac";break;
		case 0:c="ahau";break;		
	} 
	cout<<date<<' '<<c<<' '<<year<<endl;
}
int main(){
	int n;
	cin>>n;
	int num[n][2];
	string mon[n];
	char point;
	for(int i=0;i<n;i++)cin>>num[i][0]>>point>>mon[i]>>num[i][1];
	for(int i=0;i<n;i++)turn(num[i][0],mon[i],num[i][1]);
	return 0;
}
