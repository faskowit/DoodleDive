#ifndef DOODLE_DIVE_GAMEPLAY_H
#define DOODLE_DIVE_GAMEPLAY_H

#include <iostream>
#include <QObject> 
#include <QPainter>
#include <QFrame> 
#include <QEvent>  
#include <vector>
#include <QApplication>
#include <QWidget>  
#include <QMouseEvent> 
#include "doodledivewindow.h"

class DoodleDiveWindow;
class DoodleDude;

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
		
		bool pressStart_; 
	
	public slots:
		void start_DoodleDive(); 
	
	
};

#endif
