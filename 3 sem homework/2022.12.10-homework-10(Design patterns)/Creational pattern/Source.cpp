#include<iostream>
#include<vector>
using namespace std; // возьмем игру из 4 домашней и доработаем её (Factory Method)

class player
{
protected:
	char Skill;
	int hp;
	int level;
	int damage;
	friend class doctor;
	friend class thief;
public:
	player()
	{
		skillSet('n');
		level = 1;
		damage = 1;
		hp = 100;
	}
	player(int hp, int lvl, int dam, char sk)
	{
		skillSet(sk);
		level = lvl;
		damage = dam;
		this->hp = hp;
	}
	virtual ~player() {}
	virtual void who() = 0;
	virtual void printCh()
	{
		cout << "skill:" << Skill << endl << "HP:" << hp << endl << "level:" << level << endl;
		cout << "damage:" << damage << endl;
	}
	virtual void heal()
	{
		hp += 4;
	}
	virtual void hit(player& pl)
	{
		pl.takeDamage(this->damage);
	}
	void takeDamage(int damage)
	{
		hp -= damage;
	}

	void skillSet(char s)
	{
		if (Skill == 'n')
		{
			switch (s)
			{
			case 'd':
				damage += 3;
				Skill = 'd';
				break;
			case 'h':
				hp += 6;
				Skill = 'h';
				break;
			default:
				Skill = 'n';
			}
		}
	}
	void plusHP(int hp)
	{
		this->hp += hp;
	}
};

class warior : public player
{
public:
	warior()
	{
		skillSet('n');
		level = 1;
		damage = 20;
		hp = 110;
	}
	warior(int hp, int lvl, int dam, char sk)
	{
		skillSet(sk);
		level = lvl;
		damage = dam;
		this->hp = hp;
	}
	warior operator=(const warior& w)
	{
		this->hp = w.hp;
		this->level = w.level;
		this->damage = w.damage;
		this->Skill = w.Skill;
		return *this;
	}
	void sharpBlHit(player& p)
	{
		damage += 2;
		hit(p);
		damage -= 2;
	}
	void who()
	{
		cout << "warior" << endl;
	}
};
class heavy_warior : public warior
{
public:
	heavy_warior()
	{
		skillSet('n');
		level = 1;
		damage = 16;
		hp = 135;
	}
	heavy_warior(char skill, int lvl)
	{
		skillSet(skill);
		level = lvl;
		damage = 16;
		hp = 135;
	}
	void tank()
	{
		if (damage != 0)
		{
			hp += 5;
			damage -= 2;
		}
	}
	void who()
	{
		cout << "heavy_warior" << endl;
	}
};

class doctor : public player
{
public:
	doctor()
	{
		skillSet('n');
		level = 1;
		damage = 9;
		hp = 100;
	}
	doctor(char skill, int lvl)
	{
		skillSet(skill);
		level = lvl;
		damage = 9;
		hp = 100;
	}
	void heal()
	{
		hp += 8;
	}
	void healpl(player& p)
	{
		p.plusHP(10);
	}
	void who()
	{
		cout << "doctor" << endl;
	}
};

class wizard : public player
{
	int mana;
public:
	wizard()
	{
		mana = 50;
		skillSet('n');
		level = 1;
		damage = 7;
		hp = 100;
	}
	wizard(char skill, int lvl)
	{
		mana = 50;
		skillSet(skill);
		level = lvl;
		damage = 7;
		hp = 100;
	}
	void hit(player& p)
	{
		if (mana > 19)
		{
			damage = 20;
			player::hit(p);
			mana -= 10;
			damage = 7;
		}
		else
		{
			player::hit(p);
		}
	}
	void printCh()
	{
		cout << "skill:" << Skill << endl << "mana:" << mana << endl << "HP:" << hp << endl << "level:" << level << endl;
		cout << "damage:" << damage << endl;
	}
	void who()
	{
		cout << "wizard" << endl;
	}
};

class thief : public player
{
public:
	thief()
	{
		skillSet('n');
		level = 1;
		damage = 11;
		hp = 110;
	}
	thief(char skill, int lvl)
	{
		skillSet(skill);
		level = lvl;
		damage = 11;
		hp = 110;
	}
	void stealDamage(player& p)
	{
		p.damage -= 2;
	}
	void who()
	{
		cout << "thief" << endl;
	}
};

class Factory
{
public:
	virtual player* createPlayer() = 0;
	virtual ~Factory() {}
};

class wariorFactory : public Factory
{
public:
	player* createPlayer() 
	{
		return new warior;
	}
};

class  heavy_wariorFactory : public Factory
{
public:
	player* createPlayer() 
	{
		return new heavy_warior;
	}
};

class doctorFactory : public Factory
{
public:
	player* createPlayer() 
	{
		return new doctor;
	}
};

class wizardFactory : public Factory
{
public:
	player* createPlayer() 
	{
		return new wizard;
	}
};

class thiefFactory : public Factory
{
public:
	player* createPlayer() 
	{
		return new thief;
	}
};

int main()
{
	wariorFactory* warF = new wariorFactory;
	heavy_wariorFactory* HwaF = new heavy_wariorFactory;
	doctorFactory* docF = new doctorFactory;
	wizardFactory* wizF = new wizardFactory;
	thiefFactory* thiF = new thiefFactory;

	vector<player*> v;

	v.push_back(warF->createPlayer());
	v.push_back(warF->createPlayer());

	v.push_back(HwaF->createPlayer());

	v.push_back(docF->createPlayer());
	v.push_back(thiF->createPlayer());
	v.push_back(wizF->createPlayer());
	for (int i = 0; i < v.size(); i++) v[i]->who();

	return 0;
}