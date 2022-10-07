#include<iostream>

using namespace std;

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
	virtual void printCh()
	{
		cout << "skill:" << Skill << endl << "HP:" << hp << endl << "level:" << level << endl;
		cout << "damage:" << damage << endl;
	}
	virtual void heal()
	{
		hp += 4;
	}
	virtual void hit(player &pl)
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
	void sharpBlHit(player &p)
	{
		damage += 2;
		hit(p);
		damage -= 2;
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
	void healpl(player &p)
	{
		p.plusHP(10);
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
	void hit(player &p)
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
	void stealDamage(player &p)
	{
		p.damage -= 2;
	}
};

int main()
{
	wizard w;
	warior war;
	doctor d;
	thief t;
	//w.printCh();
	cout << endl;
	war.printCh();
	cout << "after" << endl;

	w.hit(war); 
	cout << endl;
	war.printCh();
	d.healpl(war);
	cout << endl;
	war.printCh();
	t.stealDamage(w);
	w.printCh();
	return 0;
}