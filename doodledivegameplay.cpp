#include "doodledivegameplay.h"
#include "doodledivewindow.h"

DoodleDiveGameplay::DoodleDiveGameplay(QWidget* parentWindow) : 
	QFrame(parentWindow) {
	
	parent_ = parentWindow; 

	static_cast<DoodleDiveWindow*>(parentWindow)->set_health(100); 
	static_cast<DoodleDiveWindow*>(parentWindow)->set_level(1); 
	static_cast<DoodleDiveWindow*>(parentWindow)->set_score(0); 
	
	setFocusPolicy(Qt::StrongFocus); 

} 

DoodleDiveGameplay::~DoodleDiveGameplay() {

	//delete stuff 

}


