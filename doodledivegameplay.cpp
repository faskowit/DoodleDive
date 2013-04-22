#include "doodledivegameplay.h"

DoodleDiveGameplay::DoodleDiveGameplay(QWidget* parentWindow) : 
	QFrame(0) {

	parentWindow->set_health(100); 
	parentWindow->set_level(1); 
	parentWindow->set_score(0); 
	
	setFoucsPolicy(Qt::StrongFocus); 

} 

DoodleDiveGamePlay::~DoodleDiveGameplay() {

}


