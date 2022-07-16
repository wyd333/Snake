

#include "Table1.h"



Table::Table()
{
	m_table_heigth=m_table_weigth=0;
	fruit_number=0;
//	fruit_number=poisonalfruit_number=0;
//	Wall=NULL;

}

Table::~Table()                       //
{
    int i;
	for(i=0;i<m_table_heigth;i++)
	{
		delete[] Wall[i];
	}
	delete[] Wall;
}

void Table::Addfruit(int x,int y)                                   //
{
    if((x>0) && (x<m_table_heigth-1) && (y>0) && (y<m_table_weigth-1))
	{	Wall[x][y]=TB_STATE_FRUIT;    fruit_number++; }
}


void Table::InitialWall(int w,int h)             //
{
    int i,j;
//	if(Wall!=NULL)
	//	delete Wall;

	m_table_weigth=w;
	m_table_heigth=h;
	Wall=new int*[m_table_heigth];
	for(i=0;i<h;i++)
		Wall[i]=new int[w];
	for(i=0;i<m_table_heigth;i++)
		for(j=0;j<m_table_weigth;j++)
            Wall[i][j]=TB_STATE_OK;

	for(i=0;i<m_table_heigth;i++)
	{	
		Wall[i][0]=TB_STATE_WALL;
	    Wall[i][m_table_weigth-1]=TB_STATE_WALL;
	}
	for(j=0;j<m_table_weigth;j++)
	{
		Wall[0][j]=TB_STATE_WALL;
		Wall[m_table_heigth-1][j]=TB_STATE_WALL;
	}
}


//DEL void Table::Addpoisonalfruit(int x,int y)
//DEL {
//DEL 	if( x>0 && x<m_table_heigth-1 && y>0 && y<m_table_weigth-1 )
//DEL 	{  Wall[x][y]=TB_STATE_POISONLFRUIT;   poisonalfruit_number++; }
//DEL }

void Table::Tablesnakedirect(Movestate e)           //
{
    m_m_snake.Changedirect(e);
	
}


Csnake *Table::Getsnake()        //
{
	return &m_m_snake;
}



void Table::Tablesnakemove()        //
{
	m_m_snake.Move();
}

void Table::ClearFruit(int x,int y )
{
	Wall[x][y]=TB_STATE_OK;
	fruit_number--;
}


