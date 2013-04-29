#ifndef DOODLE_DIVE_GAMEPLAY_H
#define DOODLE_DIVE_GAMEPLAY_H

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
	private: 
		DoodleDiveWindow* parent_; 
		DoodleDude* theDude_; 
		
		void collisionCheck();
		void game_over(); 
		
		vector<Platform*> platformList; 
		vector<BadPlatform*> badPlatformList; 
		
		bool moveStop_; 
		int moveLength_; 
		void move_everything_up();
		
		int heightCounter;
		void populate_frame();  
		
		bool pressStart_; 
	
	public slots:
		void start_DoodleDive(); 
	
	
};

#endif
