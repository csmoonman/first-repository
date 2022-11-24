#include<iostream>
#include<graphics.h> //下载的easyx包含的头文件
#include<vector>
#include<conio.h>
#include<mmsystem.h>//BGM
using namespace std;

constexpr auto swidth = 600;
constexpr auto sheight = 900;
//auto类型：c11新标准引入的类型。由编译器帮助我们去判断类型。
//如auto a=1;则auto为int

//这是用来判断鼠标是否在可点击区域的函数
bool PointInRect(int x, int y, RECT& r)
{
	return (r.left <= x && r.right >= x && r.top <= y && r.bottom >= y);
}

//防止敌机重叠

bool RectCrashRect(RECT &r1,RECT &r2)
{
	RECT r;
	r.left = r1.left - (r2.right - r2.left);
	r.right = r1.right;
	r.top = r1.top - (r2.bottom - r2.top);
	r.bottom = r1.bottom;

	return (r.left < r2.left&& r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);
}


//显示制作人名单
void ProducerIntro()
{
	setbkcolor(RGB(70, 130, 180));
	cleardevice();//以该颜色填充背景

	LPCTSTR DIYintro = _T("张飞驴之父");
	LPCTSTR DIYprogrammer = _T("代码实现：高钰坤");

	RECT DIYintror;

	//cleardevice();
	settextstyle(40, 0, _T("楷体"));
	//对署名详情页DIYintror初始化
	DIYintror.left = swidth / 2 - textwidth(DIYintro) / 2;
	DIYintror.right = DIYintror.left + textwidth(DIYintro);
	DIYintror.top = sheight / 2;
	DIYintror.bottom = DIYintror.top + textheight(DIYintro);

	outtextxy(swidth / 2 - textwidth(DIYintro) / 2, sheight / 3.5, DIYintro);
	outtextxy(swidth / 2 - textwidth(DIYprogrammer) / 2, sheight / 4, DIYprogrammer);
}

//实现一个开始界面
void Welcome()
{
	LPCTSTR title = _T("The war of planes");
	LPCTSTR DIYsign = _T("by Yukun");
	LPCTSTR tplay = _T("开始游戏");
	LPCTSTR texit = _T("退出游戏");

	
	RECT tplayr, texitr, DIYsignr;//三个结构体，判断是否点击;

	BeginBatchDraw();//开始批量绘画

	//设置背景板和字体的颜色
	setbkcolor(RGB(129,216,207));
	cleardevice();//以该颜色填充背景
	settextstyle(60, 0, _T("黑体"));//第一个数字代表字号
	settextcolor(RGB(252,218,94));

	outtextxy(swidth / 2 - textwidth(title) / 2, sheight / 10, title);

	//对署名区域DIYsign初始化
	settextstyle(30, 0, _T("黑体"));
	DIYsignr.left = swidth / 2 - textwidth(DIYsign) / 2;
	DIYsignr.right = DIYsignr.left + textwidth(DIYsign);
	DIYsignr.top = sheight / 6;
	DIYsignr.bottom = DIYsignr.top + textheight(DIYsign);
	outtextxy(swidth / 2 - textwidth(DIYsign) / 2, sheight / 6, DIYsign);
	//textwidth()是获取给定字符串的宽度大小

	settextstyle(40, 0, _T("隶书"));
	tplayr.left = swidth / 2 - textwidth(tplay) / 2;
	tplayr.right = tplayr.left + textwidth(tplay);
	tplayr.top = sheight / 4*1.6;
	tplayr.bottom = tplayr.top + textheight(tplay);

	texitr.left = swidth / 2 - textwidth(texit) / 2;
	texitr.right = texitr.left + textwidth(texit);
	texitr.top = sheight / 4*2;
	texitr.bottom = texitr.top + textheight(texit);

	outtextxy(tplayr.left, tplayr.top, tplay);
	outtextxy(texitr.left, texitr.top, texit);

	EndBatchDraw();//结束批量绘画

	//判断鼠标是否点击
	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_MOUSE);
		if (mess.lbutton)
		{
			if (PointInRect(mess.x, mess.y, tplayr))
			{
				return;
			}
			else if (PointInRect(mess.x, mess.y, texitr))
			{
				exit(0);
			}
			else if (PointInRect(mess.x, mess.y, DIYsignr))
			{
				ProducerIntro();
				//exit(0);
			}
			
		}
	}
}

//几个类：背景、敌机、英雄、子弹

void Over(unsigned long long &kill)
{
	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("击杀数：%llu"), kill);

	settextcolor(RGB(70, 130, 180));
	outtextxy(swidth / 2 - textwidth(str) / 2, sheight / 5, str);
	//按Enter返回
	LPCTSTR info = _T("按Enter返回");
	settextstyle(20, 0, _T("隶书"));
	outtextxy(swidth - textwidth(info), sheight - textheight(info), info);

	while (true)
	{
		ExMessage mess;
		getmessage(&mess, EM_KEY);
		if (mess.vkcode == 0x0D)
		{
			return;
		}
	}
}

class BK
{
public:
	BK(IMAGE &img)
		:img(img), y(-sheight)
	{

	}
	void Show()
	{
		if (y >= 0) y = -sheight;
		y += 2;
		putimage(0, y, &img);
	}
private:
	IMAGE& img;
	int x, y;
};

class Hero
{
public:
	Hero(IMAGE& img)
		:img(img)
	{
		rect.left = swidth / 2 - img.getwidth() / 2;
		rect.top = sheight - img.getheight() / 2;
		rect.right = rect.left + img.getheight();
		rect.bottom = sheight;
	}
	void Show()
	{
		putimage(rect.left, rect.top, &img);
	}
	void Control()
	{
		ExMessage mess;
		if (peekmessage(&mess, EM_MOUSE))
		{
			rect.left = mess.x - img.getwidth() / 2;
			rect.top = mess.y - img.getheight() / 2;
			rect.right = rect.left + img.getwidth();
			rect.bottom = rect.top + img.getheight();
		}
	}
	RECT& GetRect() { return rect; }
private:
	IMAGE& img;
	RECT rect;

};

class Enemy
{
public:
	Enemy(IMAGE& img, int x, IMAGE*& boom)
		:img(img), isdie(false), boomsum(0)
	{
		selfboom[0] = boom[0];
		selfboom[1] = boom[1];
		selfboom[2] = boom[2];
		rect.left = x;
		rect.right = rect.left + img.getwidth();
		rect.top = -img.getheight();
		rect.bottom = 0;
	}
	bool Show()
	{

		if (isdie)
		{
			if (boomsum == 3)
			{
				return false;
			}
			putimage(rect.left, rect.top, selfboom+boomsum);
			boomsum++;

			return true;
		}

		if (rect.top >= sheight)
		{
			return false;
		}
		rect.top += 4;
		rect.bottom += 4;
		putimage(rect.left, rect.top, &img);

		return true;
	}

	void Isdie()
	{
		isdie = true;
	}

	RECT& GetRect() { return rect; }

private:
	IMAGE& img;
	RECT rect;
	IMAGE selfboom[3];

	bool isdie;
	int boomsum;
};

class Bullet
{
public:
	Bullet(IMAGE& img,RECT pr)
		:img(img)
	{
		rect.left = pr.left + (pr.right - pr.left) / 2 - img.getwidth() / 2;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.top - img.getheight();
		rect.bottom = rect.top + img.getheight();
	}
	bool Show()
	{
		if (rect.bottom <= 0)
		{
			return false;
		}
		rect.top -= 3;
		rect.bottom -= 3;
		putimage(rect.left, rect.top, &img);

		return true;
	}
	RECT& GetRect() { return rect; }

protected:
	IMAGE& img;
	RECT rect;

};

class EBullet :public Bullet
{
public:
	EBullet(IMAGE& img, RECT pr)
		:Bullet(img, pr)
	{
		rect.left = pr.left + (pr.right - pr.left) / 2 - img.getwidth() / 2;
		rect.right = rect.left + img.getwidth();
		rect.top = pr.bottom;
		rect.bottom = rect.top + img.getheight();
	}
	bool Show()
	{
		if (rect.top >= sheight)
		{
			return false;
		}
		rect.top += 5;
		rect.bottom += 5;
		putimage(rect.left, rect.top, &img);

		return true;
	}
};

bool AddEnemy(vector<Enemy*>& es, IMAGE& enemyimg, IMAGE* boom)
{
	Enemy* e = new Enemy(enemyimg, abs(rand()) % (swidth - enemyimg.getwidth()),boom);
	for (auto& i : es)
	{
		if (RectCrashRect(i->GetRect(), e->GetRect()))
		{
			delete e;
			return false;
		}
	} 
	es.push_back(e);
	return true;
}

bool Play()
{
	setbkcolor(WHITE);
	cleardevice();
	bool is_play = true;

	IMAGE heroimg, enemyimg1, enemyimg2, bkimg;
	IMAGE ebulletimg, bulletimg;
	IMAGE eboom[3];

	//loadimage(&heroimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\meimage.jpg"),70,90)//我
	loadimage(&heroimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\wzf.jpg"), 70, 90);//战机 王柘钒
	loadimage(&enemyimg2, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\lijun.jpg"),50,65);//敌机1 李军
	loadimage(&enemyimg1, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\wugang.jpg"), 50, 65);//敌机2 伍刚
	loadimage(&bkimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\bkimg.JPG"), swidth, sheight * 2);
	loadimage(&bulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\bulletimg.jpg"),20,30);//子弹
	//loadimage(&bulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\lijun.jpg"), 20, 30);//子弹 李军
	loadimage(&ebulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\wugang.jpg"), 20, 30);//子弹 伍刚

	loadimage(&eboom[0], _T("C:\\Users\\gwwqqqand001\\Desktop\\大二\\Visual Studio\\飞机大战\\pictures\\wugang.jpg"), 50, 70);

	BK bk = BK(bkimg);
	Hero hp = Hero(heroimg);

	//做一个盛装敌机的容器
	vector<Enemy*> es1;//李军
	vector<Enemy*> es2;//伍刚
	vector<Bullet*> bs;
	vector<EBullet*> ebs;
	int bsing = 0;//记录帧数

	unsigned long long kill = 0;

	for (int i = 0; i < 5; i++)
	{
		AddEnemy(es2, enemyimg2,eboom);
	}

	/*
	for (int i = 0; i < 5; i++)
	{
		es1.push_back(new Enemy(enemyimg1, abs(rand()) % (swidth - enemyimg1.getwidth())));
	}
	*/

	while (is_play)
	{
		bsing++;
		if (bsing % 10 == 0)
		{
			bs.push_back(new Bullet(bulletimg, hp.GetRect()));
		}

		if (bsing == 30)
		{
			bsing = 0;
			for (auto& i : es2)
			{
				ebs.push_back(new EBullet(ebulletimg, i->GetRect()));
			}
		}
		
		BeginBatchDraw();

		bk.Show();
		Sleep(3);
		flushmessage();
		Sleep(1);
		hp.Control();
		//暂停功能
		if(_kbhit())
		{
			char v = _getch();
			if (v == 0x20)
			{
				Sleep(500);
				while (true)
				{
					if (_kbhit())
					{
						v = _getch();
						if (v == 0x20)
						{
							break;
						}
					}
					Sleep(16);
				}
				
			}
		}
		
		hp.Show();

		auto bsit = bs.begin();
		while (bsit != bs.end())
		{
			if (!(*bsit)->Show())
			{
				bsit = bs.erase(bsit);
			}
			//printf_s("%llu\n", bs.size());  输出子弹容器
			else
			{
				bsit++;
			}
		}

		auto ebsit = ebs.begin();
		while (ebsit != ebs.end())
		{
			//如果碰到敌机子弹
			if (RectCrashRect((*ebsit)->GetRect(), hp.GetRect()))
			{
				is_play = false;
				break;
			}
			else if (!(*ebsit)->Show())
			{
				ebsit = ebs.erase(ebsit);
			}
			else
			{
				ebsit++;
			}
		}

		auto it1 = es2.begin();
		while (it1 != es2.end())
		{
			if (RectCrashRect((*it1)->GetRect(), hp.GetRect()))
			{
				is_play = false;
			}
			auto bit = bs.begin();
			while (bit != bs.end())
			{
				if (RectCrashRect((*bit)->GetRect(), (*it1)->GetRect()))
				{
					(*it1)->Isdie();
					delete(*bit);
					bs.erase(bit);

					kill++;

					break;
				}
				bit++;
			}
			if (!(*it1)->Show())
			{
				delete (*it1);
				es2.erase(it1);
				it1 = es2.begin();
			}
			else
			{
				it1++;
			}
		}
	
		for (int i = 0; i < 5 - es2.size() ; i++)
		{
			AddEnemy(es2, enemyimg2,eboom);
		}
		

		EndBatchDraw();
	}
	Over(kill);

	return true;
}

int main()
{
	//easyx初始化
	initgraph(swidth, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE);
	//中间用了'|‘  隔开EW_NOMINIMI  禁用绘图窗口的最小化按纽
	//EW_SHOWCONSOLE	显示控制台窗口
	//这俩个都存在easyx的头文件中

	bool is_live = true;//用来判断是否存活
	
	while (is_live)
	{
		Welcome();

		is_live = Play();
	}

	return 0;
}