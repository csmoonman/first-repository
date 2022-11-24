#include<iostream>
#include<graphics.h> //���ص�easyx������ͷ�ļ�
#include<vector>
#include<conio.h>
#include<mmsystem.h>//BGM
using namespace std;

constexpr auto swidth = 600;
constexpr auto sheight = 900;
//auto���ͣ�c11�±�׼��������͡��ɱ�������������ȥ�ж����͡�
//��auto a=1;��autoΪint

//���������ж�����Ƿ��ڿɵ������ĺ���
bool PointInRect(int x, int y, RECT& r)
{
	return (r.left <= x && r.right >= x && r.top <= y && r.bottom >= y);
}

//��ֹ�л��ص�

bool RectCrashRect(RECT &r1,RECT &r2)
{
	RECT r;
	r.left = r1.left - (r2.right - r2.left);
	r.right = r1.right;
	r.top = r1.top - (r2.bottom - r2.top);
	r.bottom = r1.bottom;

	return (r.left < r2.left&& r2.left <= r.right && r.top <= r2.top && r2.top <= r.bottom);
}


//��ʾ����������
void ProducerIntro()
{
	setbkcolor(RGB(70, 130, 180));
	cleardevice();//�Ը���ɫ��䱳��

	LPCTSTR DIYintro = _T("�ŷ�¿֮��");
	LPCTSTR DIYprogrammer = _T("����ʵ�֣�������");

	RECT DIYintror;

	//cleardevice();
	settextstyle(40, 0, _T("����"));
	//����������ҳDIYintror��ʼ��
	DIYintror.left = swidth / 2 - textwidth(DIYintro) / 2;
	DIYintror.right = DIYintror.left + textwidth(DIYintro);
	DIYintror.top = sheight / 2;
	DIYintror.bottom = DIYintror.top + textheight(DIYintro);

	outtextxy(swidth / 2 - textwidth(DIYintro) / 2, sheight / 3.5, DIYintro);
	outtextxy(swidth / 2 - textwidth(DIYprogrammer) / 2, sheight / 4, DIYprogrammer);
}

//ʵ��һ����ʼ����
void Welcome()
{
	LPCTSTR title = _T("The war of planes");
	LPCTSTR DIYsign = _T("by Yukun");
	LPCTSTR tplay = _T("��ʼ��Ϸ");
	LPCTSTR texit = _T("�˳���Ϸ");

	
	RECT tplayr, texitr, DIYsignr;//�����ṹ�壬�ж��Ƿ���;

	BeginBatchDraw();//��ʼ�����滭

	//���ñ�������������ɫ
	setbkcolor(RGB(129,216,207));
	cleardevice();//�Ը���ɫ��䱳��
	settextstyle(60, 0, _T("����"));//��һ�����ִ����ֺ�
	settextcolor(RGB(252,218,94));

	outtextxy(swidth / 2 - textwidth(title) / 2, sheight / 10, title);

	//����������DIYsign��ʼ��
	settextstyle(30, 0, _T("����"));
	DIYsignr.left = swidth / 2 - textwidth(DIYsign) / 2;
	DIYsignr.right = DIYsignr.left + textwidth(DIYsign);
	DIYsignr.top = sheight / 6;
	DIYsignr.bottom = DIYsignr.top + textheight(DIYsign);
	outtextxy(swidth / 2 - textwidth(DIYsign) / 2, sheight / 6, DIYsign);
	//textwidth()�ǻ�ȡ�����ַ����Ŀ�ȴ�С

	settextstyle(40, 0, _T("����"));
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

	EndBatchDraw();//���������滭

	//�ж�����Ƿ���
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

//�����ࣺ�������л���Ӣ�ۡ��ӵ�

void Over(unsigned long long &kill)
{
	TCHAR* str = new TCHAR[128];
	_stprintf_s(str, 128, _T("��ɱ����%llu"), kill);

	settextcolor(RGB(70, 130, 180));
	outtextxy(swidth / 2 - textwidth(str) / 2, sheight / 5, str);
	//��Enter����
	LPCTSTR info = _T("��Enter����");
	settextstyle(20, 0, _T("����"));
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

	//loadimage(&heroimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\meimage.jpg"),70,90)//��
	loadimage(&heroimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\wzf.jpg"), 70, 90);//ս�� ���Ϸ�
	loadimage(&enemyimg2, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\lijun.jpg"),50,65);//�л�1 ���
	loadimage(&enemyimg1, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\wugang.jpg"), 50, 65);//�л�2 ���
	loadimage(&bkimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\bkimg.JPG"), swidth, sheight * 2);
	loadimage(&bulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\bulletimg.jpg"),20,30);//�ӵ�
	//loadimage(&bulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\lijun.jpg"), 20, 30);//�ӵ� ���
	loadimage(&ebulletimg, _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\wugang.jpg"), 20, 30);//�ӵ� ���

	loadimage(&eboom[0], _T("C:\\Users\\gwwqqqand001\\Desktop\\���\\Visual Studio\\�ɻ���ս\\pictures\\wugang.jpg"), 50, 70);

	BK bk = BK(bkimg);
	Hero hp = Hero(heroimg);

	//��һ��ʢװ�л�������
	vector<Enemy*> es1;//���
	vector<Enemy*> es2;//���
	vector<Bullet*> bs;
	vector<EBullet*> ebs;
	int bsing = 0;//��¼֡��

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
		//��ͣ����
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
			//printf_s("%llu\n", bs.size());  ����ӵ�����
			else
			{
				bsit++;
			}
		}

		auto ebsit = ebs.begin();
		while (ebsit != ebs.end())
		{
			//��������л��ӵ�
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
	//easyx��ʼ��
	initgraph(swidth, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE);
	//�м�����'|��  ����EW_NOMINIMI  ���û�ͼ���ڵ���С����Ŧ
	//EW_SHOWCONSOLE	��ʾ����̨����
	//������������easyx��ͷ�ļ���

	bool is_live = true;//�����ж��Ƿ���
	
	while (is_live)
	{
		Welcome();

		is_live = Play();
	}

	return 0;
}