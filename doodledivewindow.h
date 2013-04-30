#ifndef DOODLE_DIVE_WINDOW_H
#define DOODLE_DIVE_WINDOW_H

#include <iostream>
#include <QWidget>
#include <QLCDNumber>  
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QObject>
#include <QLabel>
#include "doodledivegameplay.h"

/** @DoodleDiveWindow class will hold buttons and gameplay
* it will also hold the score, level, and health
* implement game play within the gameplay_ object within the window
*/

class DoodleDiveGameplay;

class DoodleDiveWindow : public QWidget  { 
		Q_OBJECT
	
	public:
		DoodleDiveWindow();  
		~DoodleDiveWindow(); 
		int get_health() const; 
		void set_health(int); 
		int get_level() const; 
		void set_level(int); 
		double get_score() const; 
		void set_score(double); 
		DoodleDiveGameplay* get_gameplay(); 
		void update_display(); 
	private: 
		DoodleDiveGameplay* gameplay_; 
		
		QPushButton* start_; 
		QPushButton* pause_; 
		QPushButton* quit_; 
		
		QLCDNumber* scoreLCD_;
		QLCDNumber* levelLCD_; 
		QLCDNumber* healthLCD_;
		 
		int health_; 
		int level_; 
		double score_; 
}; 

#endif

