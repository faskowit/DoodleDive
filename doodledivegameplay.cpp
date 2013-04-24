#include "doodledivegameplay.h"
#include "doodledivewindow.h"
#include "doodledude.h"

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

} 

DoodleDiveGameplay::~DoodleDiveGameplay() {

	//delete stuff 

}

void DoodleDiveGameplay::start_DoodleDive() {

	//dummy(1);
	
	pressStart_ = true; 

	int gameSpeed = 30; 

	startTimer(gameSpeed);  //start time at gameSpeed






}

void DoodleDiveGameplay::timerEvent(QTimerEvent* e) {

	if (theDude_->hasVelocity()) 
		theDude_->move_without_click();  

	repaint(); 

}

void DoodleDiveGameplay::paintEvent(QPaintEvent* e) {

	//dummy(3); 

	QPainter painter(this); 
	
	if (pressStart_) 
		painter.drawRect(static_cast<QRect>(*theDude_));


}

void DoodleDiveGameplay::mousePressEvent(QMouseEvent *e) {

	int mouseX, mouseY; 
	
	mouseX = e->x(); 
	mouseY = e->y(); 
	
	if (mouseX > (theDude_->left() + 25))
		theDude_->floatRight(mouseX); 
	else 
		theDude_->floatLeft(mouseX); 
		
	
	//dummy(mouseX);
	//dummy(mouseY); 

}

/*void DoodleDiveGameplay::mouseDoubleClickEvent(QMouseEvent *e) {

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}*/ 








