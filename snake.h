#ifndef SNAKE_H
#define SNAKE_H

#define TB_STATE_SANKE 4

#define GAME_WALLWEIGHT 648
#define GAME_WALLHEIGHT 424

//#include "game.h"
//#include <stdio.h>
//#include <windows.h>

enum Movestate{S_none,S_down,S_up,S_left,S_right};
struct Point
{
	int x;
	int y;
};
class Csnake
{
	typedef struct Node{
		Point m_snake;
		Movestate direct;
		struct Node *next;
	}Node,*Snakebody;
public:
	   	
	   int snake_length;
		Snakebody m_snake;
		Movestate snakehead;
		Snakebody t_snake;
		
	
public:
	    void Move(void);
		int Changedirect(Movestate d);
		void Addbody();
		bool IsheadTouchbody(int x, int y);
		int Getlength();
	
public:
		Csnake();
		~Csnake();

	
};


#endif     ///