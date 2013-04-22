#ifndef DOODLE_DIVE_WINDOW_H
#define DOODLE_DIVE_WINDOW_H

#include <QWidget>
#include <QLCDNumber>  
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>

class DoodleDiveWindow : public QWidget  { 
		Q_OBJECT
	
	public:
		DoodleDiveWindow();  
		
	private: 
		DoodleDiveGameplay* gameplay_; 
		
		QPushButton* start_; 
		QPushButton* pause_; 
		QPsuhButton* quit_; 
		 
		int* health_; 
		int* level_; 
		int* score_; 
}; 

