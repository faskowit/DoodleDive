#ifndef DOODLE_DIVE_GAMEPLAY_H
#define DOODLE_DIVE_GAMEPLAY_H

#include <QRect>
#include <iostream>
#include <QObject> 
#include <QPainter>
#include <QFrame> 
#include <QEvent>  
#include <queue>
#include <list>
#include <QApplication>
#include <QWidget>  
#include <QMouseEvent> 
#include "doodledivewindow.h"
#include "platform.h"
#include "badplatform.h"
#include "monster.h"
#include "fireball.h"
#include "halo.h"
#include <QPixmap>
#include <QImage>
#include <QBrush>

using namespace std; 

class DoodleDiveWindow;
class DoodleDude;
class Platform; 

class DoodleDiveGameplay : public QFrame 
{
		Q_OBJECT 
	public:
		DoodleDiveGameplay(QWidget* parent = 0);
		~DoodleDiveGameplay(); 
		void dummy(int bleh = 0); 
		void timerEvent(QTimerEvent*); 
		void paintEvent(QPaintEvent*);
		void mousePressEvent(QMouseEvent *);
		void keyPressEvent(QKeyEvent *); 
	private: 
		DoodleDiveWindow* parent_; 
		DoodleDude* theDude_; 
		
		int time_;
		int gameSpeed_;  
		
		void collisionCheck();
		void game_over(); 
		
		vector<Platform*> platformList; 
		vector<BadPlatform*> badPlatformList; 
		vector<Monster*> monsterList; 
		vector<Fireball*> fireballList; 
		vector<Halo*> haloList; 
		
		bool moveStop_; 
		int moveLength_; 
		void move_everything_up();
		
		void move_others(); 
		
		int heightCounter;
		void populate_frame();  
		
		bool pressStart_;
		bool pressPause_; 
		bool gameOver_;  
		
		void update_timer();
		
		void load_images(); 
		
		QImage* haloImage_; 
		QImage* platformImage_; 
		QImage* monsterImage_; 
		QImage* theDudeImage_;
		QImage* fireballImage_;
		
		void depopulate_lists();
	
	public slots:
		void start_DoodleDive(); 
		void pause_DoodleDive(); 
		
	
};

#endif
