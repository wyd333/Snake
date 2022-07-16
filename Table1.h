
#ifndef TABLE_H
#define TABLE_H

#define TB_STATE_OK 0
#define TB_STATE_FRUIT 1
#define TB_STATE_POISONLFRUIT 2
#define TB_STATE_WALL 3

#include "snake.h"

class Table
{
public:
	Table();
	~Table();

public:
	void Addfruit(int x,int y);
	void Tablesnakemove();
	void Tablesnakedirect(Movestate e);
	Csnake* Getsnake();
	void ClearFruit(int x,int y);
	void InitialWall(int w,int h);
public:
	int **Wall;
	int m_table_weigth;
	int m_table_heigth;
	int fruit_number;
//	int poisonalfruit_number;
	Csnake m_m_snake;
};


                         
#endif