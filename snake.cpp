

#include "snake.h"
//#include "game.h"
#include <stdlib.h>
//#include <assert.h>

Csnake::Csnake()
{
	Snakebody p,q;
    m_snake=(Snakebody)malloc(sizeof(Node));
	m_snake->next=NULL;	
	p=m_snake;
    
	/*m_snake.direct=S_none;
	m_snake.m_snake.x=0;
	m_snake.m_snake.y=0;*/

	q=(Snakebody)malloc(sizeof(Node));
	q->direct=S_down;
	q->m_snake.x=3;
	q->m_snake.y=3;
	q->next=p->next;
	p->next=q;
	snake_length=1;
	t_snake=m_snake;
	
}

Csnake::~Csnake()
{
	Snakebody p,q;
	p=m_snake->next;  free(m_snake);
	while(p)
	{ 
	    q=p->next;
		free(p);
		p=q;
	}
}
void Csnake::Move(void)
{
	Snakebody p,k;
	int x1,x2,y1,y2;
	Movestate a,b;
	p=m_snake->next;
    k=p;
	a=k->direct;
	x1=k->m_snake.x;
	y1=k->m_snake.y;
	while(k->next)
	{
		b=a;
		x2=x1;
	    y2=y1;
		
		k=k->next;

		a=k->direct;
		x1=k->m_snake.x;
		y1=k->m_snake.y;

		k->direct=b;
		k->m_snake.x=x2;
		k->m_snake.y=y2;
        

	}

	p->direct=snakehead;
	
	switch(p->direct)       //snakehead's move
	{
	case S_left:
	//	q=(Snakebody)malloc(sizeof(Node));
	//	q->next=NULL;
		p->m_snake.x=p->m_snake.x-3;
        p->m_snake.y=p->m_snake.y;
		break;
	case S_down:
	//	q=(Snakebody)malloc(sizeof(Node));
	//	q->next=NULL;
		p->m_snake.x=p->m_snake.x;
		p->m_snake.y=p->m_snake.y+3;
		break;
	case S_up:
	//	q=(Snakebody)malloc(sizeof(Node));
	//	q->next=NULL;
		p->m_snake.x=p->m_snake.x;
		p->m_snake.y=p->m_snake.y-3;
		break;
	case S_right:
	//	q=(Snakebody)malloc(sizeof(Node));
	//	q->next=NULL;
		p->m_snake.y=p->m_snake.y;
		p->m_snake.x=p->m_snake.x+3;
		break;
//	case S_none:
//		break;
//	default:
//		break;
	}
/*	q->direct=snakehead;
	m_snake->next=q;
	p=p->next;
	while(p)              //snakebody's move
	{
	//	q=p->next;
		//if(q)
		//{
        k=p->next;   
		l=(Snakebody)malloc(sizeof(Node));
		   l->next=NULL;		
		   l->m_snake.x=p->m_snake.x;
		   l->m_snake.y=p->m_snake.y;
		   l->direct=p->direct;
		   q->next=l;
		   q=q->next;
		 //  free(p);
		   p=k;
		    
		//}
	}*/
		
//	while(p)
//	{ 
//	    q=p->next;
//		free(p);
//		p=q;
//	}
}


int Csnake::Changedirect(Movestate d)     // snakehead's direction
{
	switch(d)
	{
	case S_none:
		snakehead=d;
		break;
	case S_up:
		if(snakehead!=S_down)
			snakehead=d;
		break;
	case S_down:
		if(snakehead!=S_up)
		   snakehead=d;
		break;
	case S_left:
		if(snakehead!=S_right)
			snakehead=d;
		break;
	case S_right:
		if(snakehead!=S_left)
		    snakehead=d;
		break;
//	default:
//		break;


	}
	return 1;

}

Csnake::Getlength()
{
     return snake_length;
}

bool Csnake::IsheadTouchbody(int x,int y)
{
	Snakebody p;
	p=m_snake->next;
	p=p->next;
	while(p)
	{
		
		if(p->m_snake.x==x && p->m_snake.y==y)
		    return true;
		p=p->next;
	}
	return false;
}

//void Csnake::Getsnakedata(int **data,Snakebody p,int w,int h)
//{
 //   Snakebody q;
 //   int i,j;
//	q=p;
//	for(i=0;i<h;i++)
//		for(j=0;j<w;j++)

//		{
//		  while(q)
//		  {
//		     if((q->m_snake.x==i)&&(q->m_snake.y==j))
//				 data[i][j]=TB_STATE_SANKE;
//			 q=q->next;
///		  }
//		  q=p;
///		}
//}

void Csnake::Addbody()
{
      Snakebody p,q;
	  int i;
	  p=m_snake->next;
	  q=(Snakebody)malloc(sizeof(Node));
	  if(!q)
		  exit(0);
	  q->next=NULL;
	  for( i=1; i<snake_length; i++)
		  p=p->next;
	  q->direct=p->direct;
	  switch(p->direct)
	  {
	  case S_left:
          q->m_snake.x=p->m_snake.x+3;
		  q->m_snake.y=p->m_snake.y;
		  break;
	  case S_right:
		   q->m_snake.x=p->m_snake.x-3; 
		   q->m_snake.y=p->m_snake.y;
		  break;
	  case S_up:
		   q->m_snake.x=p->m_snake.x;
		    q->m_snake.y=p->m_snake.y+3;
		  break;
	  case S_down:
		   q->m_snake.x=p->m_snake.x;
		    q->m_snake.y=p->m_snake.y-3;
		  break;
	  }
	                                          
	  p->next=q;
	  //q->next=k;
//	  assert(p!=NULL);
	

	  
	  
	  snake_length++;
}



