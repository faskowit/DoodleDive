#ifndef DOODLE_DIVE_GAMEPLAY_H
#define DOODLE_DIVE_GAMEPLAY_H

#include <QObject> 
#include <QFrame> 
#include <QEvent>  
#include <vector>
#include <QApplication>
#include <QWidget>  

class DoodleDiveGameplay : public QFrame 
{
		Q_OBJECT 
	public:
		DoodleDiveGameplay(QWidget* parent = 0);
		~DoodleDiveGameplay(); 
	
	private: 
		QWidget* parent_; 
	
	public slots:
	
	
};

#endif
