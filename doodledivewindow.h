#ifndef DOODLE_DIVE_WINDOW_H
#define DOODLE_DIVE_WINDOW_H

#include <QWidget>
#include <QLCDNumber>  
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QObject>

class DoodleDiveWindow : public QWidget  { 
		Q_OBJECT
	
	public:
		DoodleDiveWindow();  
		int get_health(); 
		void set_health(int); 
		int get_level(); 
		void set_level(int); 
		double get_score(); 
		void set_score(double); 
		
	private: 
		DoodleDiveGameplay* gameplay_; 
		
		QPushButton* start_; 
		QPushButton* pause_; 
		QPsuhButton* quit_; 
		 
		int health_; 
		int level_; 
		double score_; 
}; 

#endif

