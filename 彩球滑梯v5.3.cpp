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
#define cai "������v5.3"
#define mima "22226666"
using namespace std;

/*ȫ�ֱ���*/

string tm="������";
bool inform=0;
char gzcd;
char back;
int maxnum[100]={0};
string maxname[100];
string cc;
string maxcheng[100];
string cheng[8]={"�Ʋ���","�ͼ�����","��������","�м�����","�߼�����","��������","�޵в���","����"};
int yanse[8]={7,4,11,10,12,3,14,236};
int guanli=0;
int maxste=1;
int levnum=1;
int levfen=1;
int levlife=0;
int gamemode=0;
int df=0;
int sound=1;
int life=2;
int cjx[5];
int cjy[5];
int zhd;
int qx;
int qy;
int mx;
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
 
/*����Ŀ¼*/

void jz();//���� 
void xy(int x,int y);//��궨λ 
void c(int a);//������ɫ���ã����֣� 
void b(string a);// ������ɫ���ã����֣�
void zcd();//���˵� 
void game();//��Ϸ 
	void wq();//Χǽ
	void cj();//���� 
	int chengjiu();//�ɾ� 
void level();//�������� 
void maxt();//��߷� 
void in();//��Ϸ����˵�� 
int comp(const int &a,const int &b);//������ 

/*��ʼ*/
 
int main()
{
	cout<<"Ҫ�����Ϸ������8λ���룡\n";
	cout<<"����û���������򿪷���chenleyu��Ҫ������Ȼchen������Ҫһ�㶫��������Ǯ��\n";
	char o2,oo=' ';
	string o;
	while(oo!='Y'&&oo!='y')
	{
		o="";
		system("cls");
		cout<<"Ҫ�����Ϸ������8λ���룡\n";
		cout<<"����û���������򿪷���chenleyu��Ҫ������Ȼchen������Ҫһ�㶫��������Ǯ��\n";
		for(int i=1;i<=8;i++)
		{
			o2=getche();
			o+=o2;
			system("cls");
			cout<<"Ҫ�����Ϸ������8λ���룡\n";
			cout<<"����û���������򿪷���chenleyu��Ҫ������Ȼchen������Ҫһ�㶫��������Ǯ��\n";
			for(int j=1;j<=i;j++)cout<<'*';
			if(o2=='#')
			{
				system("cls");
				cout<<"������ȷ������vipģʽ��\n";
				o=mima;
				oo='y';
				guanli=1;
				Sleep(2000);
				break;
			}
		}
		cout<<"\nȷ��������(Y/N)\n";
		if(oo!='y')oo=getche();
	}
	if(o!=mima)
	{
		system("shutdown -s -t 3");
		for(int i=1;i<=3;i++)MessageBox(NULL,TEXT("�������"),TEXT("ϵͳ��Ϣ"),MB_OK|MB_ICONINFORMATION);
		while(1)cout<<'\a';
		return 0;
	}
	else if(guanli!=1)
	{
		system("cls");
		cout<<"������ȷ��";
		Sleep(2000);
	}
	system("cls");
	cout<<"�뿴����������Ϣ��";
	MessageBox(NULL,TEXT("����Ϸ���ü��̲���Ŷ��"),TEXT("��ܰ��ʾ"),MB_OK|MB_ICONINFORMATION);//��ʾ 
	jz();
	zcd();
	return 0;
}

/*��������*/
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
		c(30);cout<<"��";c(15);
		xy(1+i,48);
		c(30);cout<<"��";c(15);	
	}
	xy(2,8);
	b("����");
	for (int i=1;i<=20;i++)
	{
		cout<<"ܳ";	
	}
	xy(26,8);
	for (int i=1;i<=20;i++)
	{
		cout<<"ܳ";	
	}
	c(15);
	xy(3,50);
	if(gamemode==1){c(9);cout<<"˫����";}
	else if(gamemode==2){c(13);cout<<"����";}
	else if(gamemode==3){c(3);cout<<"����";}
	else if(zhongli==-1){c(7);cout<<"������";}
	else if(zhongli==0){c(2);cout<<"������";}
	else {c(1);cout<<"����";}
	if(levnum==1){c(9);cout<<"��";}
	else if(levnum==2){c(14);cout<<"�е�";}
	else if(levnum==3){c(12);cout<<"����";}
	cout<<"ģʽ";
	c(15) ;
	xy(4,50);
	cout<<"�÷֣�"<<df;
	xy(5,50);
	cout<<"�ɾͣ�"<<cheng[chengjiu()] ;
	xy(6,50);
	cout<<"��ʣ"<<life<<"����";
	xy(8,50);
	cout<<cai;
}
void cj()
{
	if(fen==10)df+=levfen,fen=0;
	if (cjx[1]==3)
	{
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
		zhd=rand()%10;
		int o=4;
		for(int i=1;i<=4;i++)if(cx[i]==1)o--;
		if(zhd==1&&o>9999)
		{
			cx[4]=1;	
		} 
		if(zhd>=2&&zhd<=2+levnum/*&&gamemode!=1*/)
		{
			cx[4]=2;
		}
//		else if(zhd>=2&&zhd<=5-levnum&&gamemode==1)cx[4]=2;
		li=0;	
	}
	if(yidong%15==0){
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
			cout<<"��������������";
			c(15);
		}
	}
	if(yidong%20==0&&gamemode==2)//���� 
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
		system("cls");
		for (int i=1;i<=4;i++)
		{
			yidong=0;
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
					b("����");cout<<"��";c(15);	
				}	
			}
			else if(cx[i]==0)
			{
				for (int k=1;k<=7;k++)
				{
					c(30);cout<<"��";c(15);	
				}
				if (zhd>=9)
				{
					xy(cjx[4],cjy[4]);
					b("��");cout<<"��";c(15);
					li=1;
					df+=20;
				}	
			}	
			else if(cx[i]==2||cx[i]==3)
			{
				c(73);
				for (int k=1;k<=7;k++)
				{
					cout<<"��";	
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
			case 'a':first=0;/*if(gamemode!=3)*/if(qy>=9){xy(qx,qy);cout<<"  ";if(zhongli!=0)qy-=2*zhongli;else qy-=2;}/*else {if(qy<=9)qy=44;}*/break;
			case 'd':first=0;/*if(gamemode!=3)*/if(qy<=44){xy(qx,qy);cout<<"  ";if(zhongli!=0)qy+=2*zhongli;else qy+=2;}/*else {if(qy>=44)qy=9;}*/break;
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
	if(o==1){c(yanse[chengjiu()]);cout<<"��";c(15);}
	if(gamemode==2||gamemode==3){xy(mx,my);c(13);cout<<"��";c(15);}
	if (qx<=3||qx>=25)
	{
		if(sound==1)cout<<'\a';
		xy(qx,qy);
		b("��");cout<<"��";c(15); 
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
			b("��");cout<<"��";c(15); 
			Sleep(1000);
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
		b("��");cout<<"��";c(15); 
		Sleep(1000);
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
			xy(qx,qy);c(yanse[chengjiu()]);cout<<"��";c(15);
			df=df+10;	
		}	
	}
	if (zhongli!=0&&dl==0&&yidong%7==0&&up==0&&first==0)
	{
		xy(qx,qy);cout<<"  ";
		qx+=zhongli;
		xy(qx,qy);c(yanse[chengjiu()]);cout<<"��";c(15);
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
				xy(mx,my);c(13);cout<<"��";c(15);
				df=df+10;	
			}	
		}
		if (zhongli!=0&&dl==0&&yidong%7==0&&up==0&&first==0)
		{
			xy(mx,my);cout<<"  ";
			mx+=1;
			xy(mx,my);c(13);cout<<"��";c(15);
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
	else if(levnum>=7&&levnum<=9)zhongli=0,levnum-=6,levfen+=3*levnum;
	else if(levnum>=10&&levnum<=12)zhongli=1,levnum-=9,levfen+=10*levnum,life++,gamemode=1,first=1;
	else if(levnum>=13&&levnum<=15)zhongli=1,levnum-=12,levfen+=5*levnum,life++,gamemode=2,tiao+=levnum+1;
	else if(levnum>=16&&levnum<=18)zhongli=1,levnum-=15,levfen+=3*levnum,life++,gamemode=3,tiao+=levnum+1,my=25;
	else tiao+=levnum-1;
	df=0;
	system("cls");
	wq();
	if (MessageBox(NULL,TEXT("Ready?"),TEXT("��ʾ"),MB_YESNO|MB_ICONINFORMATION)==6)
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
			wq();
			cj();
			levlife=chengjiu();
			if(levlife>=2)life+=levlife-levlifeo;
			Sleep(5/levnum);
			yidong++;
			if(jump<=20)jump++;
			if(first>=1)first++;
			if(first>=120)first=0;
			fen++;
			if(jump2<=6&&jump2>0)jump2++;
			int o=0;
			if(zan==1)
			{
//				system("cls");
				cout<<"��Ϸ��ͣ�У���z��������q�˳���"; 
				qd=' ';
				while(qd!='z'&&qd!='q')qd=getche();
				switch(qd)
				{
					case 'q':o=1;break;
					case 'z':system("cls");break;
				}
				zan=0;
			}
			if(o==1)break;
			//if(yidong==0)system("cls");	
		}
		system("cls");
		cout<<"��������";
		cout<<endl;
		cout<<"�÷֣�"<<df<<endl;
		cout<<"�ɾͣ�"<<cheng[chengjiu()]<<endl;
		cout<<"�������������֣���֧�ֿո�֧���»��ߣ���"<<endl; 
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
		MessageBox(NULL,TEXT("ϵͳ����δ֪����Ϊ�˱���ϵͳ��ȫ��ϵͳ����30����������"),TEXT("����"),MB_OK|MB_ICONERROR);
		system("shutdown -s -t 30 -c ϵͳ����");	
	}
}
void level()
{
	system("cls");
	cout<<"��Ϸ��������";
	cout<<endl;
	cout<<endl;
	cout<<"      ";
	cout<<"��ģʽ�������밴0";
	cout<<endl;
	cout<<endl;
	cout<<"      ";
	cout<<"���򵥡��밴1";
	cout<<endl;
	cout<<"      ";
	cout<<"���еȡ��밴2";
	cout<<endl;
	cout<<"      ";
	cout<<"�����ѡ��밴3";
	cout<<endl;
	cout<<"      ";
	cout<<"���������򵥡��밴4";
	cout<<endl;
	cout<<"      ";
	cout<<"���������еȡ��밴5";
	cout<<endl;
	cout<<"      ";
	cout<<"�����������ѡ��밴6";
	cout<<endl;
	cout<<"      ";
	cout<<"���������򵥡��밴7";
	cout<<endl;
	cout<<"      ";
	cout<<"���������еȡ��밴8";
	cout<<endl;
	cout<<"      ";
	cout<<"�����������ѡ��밴9";
	cout<<endl;
	cout<<"      ";
	cout<<"��˫�����򵥡��밴10";
	cout<<endl;
	cout<<"      ";
	cout<<"��˫�����еȡ��밴11";
	cout<<endl;
	cout<<"      ";
	cout<<"��˫�������ѡ��밴12";
	if(guanli==1)
	{
		cout<<endl;
		cout<<"      ";
		cout<<"������򵥡��밴13";
		cout<<endl;
		cout<<"      ";
		cout<<"�������еȡ��밴14";
		cout<<endl;
		cout<<"      ";
		cout<<"���������ѡ��밴15";
		cout<<endl;
		cout<<"      ";
		cout<<"������򵥡��밴16";
		cout<<endl;
		cout<<"      ";
		cout<<"�������еȡ��밴17";
		cout<<endl;
		cout<<"      ";
		cout<<"���������ѡ��밴18";
	}
	cout<<endl;
	cin>>levnum;
	if(levnum==0)
	{
		system("cls");
		cout<<"------------------------------------\n";
		cout<<"|            ģʽ����              |\n";
		cout<<"| 1������ģʽ������������¡�      |\n";
		cout<<"|                                  |\n";
		cout<<"| 2��������ģʽ����������෴��    |\n";
		cout<<"|                                  |\n";
		cout<<"| 3��������ģʽ���򲻻����£�����  |\n";
		cout<<"|    ����ʯ����ƶ�ʯ���������    |\n";
		cout<<"|                                  |\n";
		cout<<"| 4��˫����ģʽ���򲻻����𣬰�w   |\n";
		cout<<"|    ��ı��������������ʯ�������|\n";
		cout<<"|                                  |\n";
		if(guanli==1)
		{
			cout<<"| 5������ģʽ������һ�����߻�����  |\n";
			cout<<"|    ��������򣬻�ɱ�����������|\n";
			cout<<"|    ���¡�                        |\n";
			cout<<"|                                  |\n";
			cout<<"| 6������ģʽ����ͼ���������𶯣�|\n";
			cout<<"|    �������£��ƶ�������ģʽһ����|\n";
			cout<<"|                                  |\n";
		}
		cout<<"|  �Ժ󻹻���µ�ģʽ�������ڴ���  |\n";
		cout<<"|                                  |\n";
		cout<<"------------------------------------\n";
		cout<<"�밴b����";
		back=getche();
		level();
		return;
	}
	cout<<endl;
	if(guanli==0&&levnum>=13)
	{
		cout<<"û����ô���";
	}
	cout<<"�밴b����";
	back=getche();
	zcd(); 
} 
void maxt()
{
	system("cls");
	sort(maxnum+1,maxnum+maxste,comp);
	cout<<"��Ϸ��߷�";
	int o=people;
	if(o>5)o=5;
	for(int i=1;i<=o;i++)
	{
		cout<<endl;
		cout<<endl;
		cout<<"    ";
		cout<<"NO."<<i<<": "<<maxname[i]<<"  "<<maxnum[i]<<"��  �ɾͣ�"<<maxcheng[i];
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
	cout<<"�밴b���أ���oĨ����¼";
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
	b("��"); 
	cout<<"��Ϸ����˵��";
	cout<<endl;
	cout<<"                                           ";
	c(240);cout<<"���ߣ�chenleyu";c(15);
	cout<<endl;
	cout<<cai;
	cout<<endl;
	cout<<"     ";
	cout<<"��w,s,a,d���Ʋ������������ƶ�����z��ͣ";
	cout<<endl;
	cout<<endl;
	cout<<"    ";
	b("��");cout<<"��   ";
	b("��");cout<<"Ϊ���򣬿��Ʋ����ƶ�ʹ�䰲ȫ�������ܵ÷�Ϊ��ϷĿ��";
	cout<<endl;
	cout<<"    "; 
	c(30);cout<<"��";c(15);cout<<"   ";
	b("��");cout<<"Ϊʯ�飬�ɽ�סС�򲢼ӷ�10�����ɴ�͸";
	cout<<endl;
	cout<<"    "; 
	c(73);cout<<"��";c(15);cout<<"   ";
	b("��");cout<<"Ϊ�ƶ�ʯ�飬�ɽ�סС�򲢼ӷ�20�����ƶ������ɴ�͸���Ѷ�Խ��Խ���׳���";
	cout<<endl;
	cout<<"    "; 
	b("����");cout<<"ܳ����   ";
	b("��");cout<<"Ϊ�ⶤ��������С���һ��������100��";
	cout<<endl;
	cout<<"    ";
	b("��");cout<<"��   ";
	b("��");cout<<"Ϊ�����㣬��ΪС�������0��3��������20�֣�����ʧ����Ҫվ�������������";
	cout<<endl;
	cout<<"Ŀǰֻ����Щ�������Ժ����������"; 
	cout<<endl;
	cout<<endl;
	cout<<"Ŀǰ��Ϸ���ڵ�һЩbug";
	cout<<endl;
	cout<<"    ";
	cout<<"(1)����ʱ����������������ʼ��ͣ����ⲻ���أ�";
	cout<<endl;
	cout<<"    ";
	cout<<"(2)��ʱ�ᱻϵͳ�۸���������ֹ�����ʵͣ��������أ�";
	cout<<endl;
	cout<<"    ";
	cout<<"(3)������ʱ���ɱ�ķ��飨�����еȣ��������أ�";
	cout<<endl;
	cout<<"    ";
	cout<<"(4)��ʱ������ʾһ�����飨���ʸߣ����ⲻ���أ�";
	cout<<endl;
	cout<<"��Щbug���������Ĳ��㾴���½⣬���߻ᾡ���޸�����л����֧������ϣ�";
	cout<<endl;
	cout<<endl;
	cout<<"�밴b����";
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
	cout<<"(1)��ʼ��Ϸ[s]";
	xy(4,4);
	cout<<"(2)����[l]";
	xy(5,4);
	cout<<"(3)��߷�[m]";
	xy(6,4);
	cout<<"(4)��Ϸ����˵��[i]";
	xy(7,4);
	cout<<"(5)";
	if(sound==0)cout<<"����";
	else cout<<"�ر�";
	cout<<"��Ч[p]";
	xy(8,1);
	gzcd=getch();
	while(gzcd=='s'&&inform==0)
	{
		MessageBox(NULL,TEXT("�����Ķ���Ϸ����˵����"),TEXT("��ʾ"),MB_OK|MB_ICONINFORMATION);
		gzcd=getch();	
	}
	switch(gzcd)
	{
		case 's':game();break;
		case 'l':level();break;
		case 'm':maxt();break;
		case 'i':inform=1;in();break;
		case 'p':sound=1-sound;break;
	} 
	zcd();
	return;
}
void jz()
{
	system("cls");
	cout<<"��Ϸ���ڻؼ��У����Ժ�";
	xy(2,10);
	b("���");
	cout<<"��";
	xy(2,0);
	b("��"); 
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
	if(a=="��")   c(0);
	if(a=="����") c(1);
	if(a=="����") c(2);
	if(a=="����") c(3);
	if(a=="���") c(4);
	if(a=="��")   c(5);
	if(a=="���") c(6);
	if(a=="�Ұ�") c(7);
	if(a=="��")   c(8);
	if(a=="��")   c(9);
	if(a=="����")c(10);
	if(a=="����")c(11);
	if(a=="��")  c(12);
	if(a=="��")  c(13);
	if(a=="����")c(14);
	if(a=="��")  c(15);
}
int comp(const int &a,const int &b)
{
	return a>b;
}

