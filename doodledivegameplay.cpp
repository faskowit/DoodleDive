#include "doodledivegameplay.h"
#include "doodledivewindow.h"
#include "doodledude.h"
#include "badplatform.h"

void DoodleDiveGameplay::dummy(int bleh) {

	std::cout << "BLAHHH: " << bleh << std::endl; 
}

DoodleDiveGameplay::DoodleDiveGameplay(QWidget* parentWindow) : 
	QFrame(parentWindow) {
	
	parent_ = static_cast<DoodleDiveWindow*>(parentWindow); 

	parent_->set_health(100); 
	parent_->set_level(1); 
	parent_->set_score(0); 
	
	setFocusPolicy(Qt::StrongFocus); 
	
	pressStart_ = false; 
	
	theDude_ = new DoodleDude(); 
	
	heightCounter = 0;
	moveStop_ = false; 
	moveLength_ = 1; 

} 

DoodleDiveGameplay::~DoodleDiveGameplay() {

	//delete stuff 

}

void DoodleDiveGameplay::game_over() {

	moveStop_ = true; 
	
	QPainter painter(this); 
	
	//QRect
	
	//FINISH UPPPPPPPPP

}

void DoodleDiveGameplay::start_DoodleDive() {
	
	pressStart_ = true; 

	int gameSpeed = 30; 

	startTimer(gameSpeed);  //start time at gameSpeed
	
	populate_frame();

}

void DoodleDiveGameplay::populate_frame() {

	//dummy(75); 

	if (heightCounter % 100 == 0) 
		platformList.push_back(new Platform(60)); 
		
	int badAppear = rand() % 4; 
	
	if (heightCounter % 100 == 1) {
		if (badAppear == 1) 
			badPlatformList.push_back(new BadPlatform(50));
	}
	
	
}

void DoodleDiveGameplay::timerEvent(QTimerEvent* e) {

	//if (theDude_->hasVelocity()) 
		//theDude_->move_without_click();  

	move_everything_up(); 
	heightCounter++; 
	populate_frame(); 
	
	collisionCheck();

	repaint(); 

}

void DoodleDiveGameplay::collisionCheck() {

	moveStop_ = false; 
	QRect* theDudePtr = static_cast<QRect*>(theDude_); 
	
	for (unsigned int i=0; i < platformList.size(); i++) {
		if (theDudePtr->intersects(*(static_cast<QRect*>(platformList[i])))) {
			moveStop_ = true;
			moveLength_ = 1; 
			
			//if(platformList[i]->top() != theDudePtr 
		}
	}
	for (unsigned int i=0; i < badPlatformList.size(); i++) {
		if (theDudePtr->intersects(*(static_cast<QRect*>(badPlatformList[i])))) {
			moveStop_ = true; 
			moveLength_ = 1; 
			int temphealth = parent_->get_health(); 
			temphealth -=10;
			parent_->set_health(temphealth);
		}
	}
		
		
		
	if (parent_->get_health() < 1)
		game_over(); 
}

void DoodleDiveGameplay::paintEvent(QPaintEvent* e) {

	QPainter painter(this); 
	
	if (pressStart_) {
		painter.drawRect(static_cast<QRect>(*theDude_));
		for (unsigned int i = 0; i < platformList.size(); i++) {
			painter.drawRect(*platformList[i]);
		}
		
	}
		

}

void DoodleDiveGameplay::mousePressEvent(QMouseEvent *e) {

	int mouseX, mouseY, distanceLeft, distanceRight; 
	
	mouseX = e->x(); 
	mouseY = e->y(); 

	//distanceLeft = (theDude_->left()) + 25 - 
	
	
	if (mouseY < 100) {
		if (mouseX < ((theDude_->x()) + 25))
			theDude_->floatLeft(); 
		else 
			theDude_->floatRight(); 
	}
	else if (mouseY < 200) {
		if (mouseX < ((theDude_->x()) + 25)) {
			theDude_->floatLeft();
			theDude_->floatLeft(); 
		}
		else {
			theDude_->floatRight();
			theDude_->floatRight(); 
		}
	}
	else if (mouseY < 400) { 
		if (mouseX < ((theDude_->x()) + 25))
			for (int i=0; i < 3; i++)
				theDude_->floatLeft(); 
		else 
			for (int i=0; i < 3; i++)
				theDude_->floatRight(); 
	}
	else {
		if (mouseX < ((theDude_->x()) + 25))
			for (int i=0; i < 6; i++)
				theDude_->floatLeft(); 
		else 
			for (int i=0; i < 6; i++)
				theDude_->floatRight();
	}

}

/*void DoodleDiveGameplay::mouseDoubleClickEvent(QMouseEvent *e) {

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}*/ 

void DoodleDiveGameplay::move_everything_up() {


	if (heightCounter % 20 == 0) 
		moveLength_ = (moveLength_ + 1);

	if(!moveStop_) {	

		for (unsigned int i=0; i < platformList.size(); i++)
			platformList[i]->move_up(moveLength_); 
	}

}






