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
	
	parent_->set_health(500); 
	parent_->set_level(0); 
	parent_->set_score(0); 
	
	setFocusPolicy(Qt::StrongFocus); 
	
	pressStart_ = false;
	pressPause_ = false;  
	
	theDude_ = new DoodleDude(); 
	 
	heightCounter = 0;
	moveStop_ = false; 
	moveLength_ = 1; 
	
	
	gameOver_ = false; 
	
	load_images(); 

} 

DoodleDiveGameplay::~DoodleDiveGameplay() {

	//delete stuff 

}

void DoodleDiveGameplay::game_over() {

	moveStop_ = true; 
	
	killTimer(time_); 
	
}

void DoodleDiveGameplay::start_DoodleDive() {
	
	if (pressStart_ == false) {
	
		pressStart_ = true; 

		gameSpeed_ = 35; 

		time_ = startTimer(gameSpeed_);  //start time at gameSpeed
	
		populate_frame();
	} 
	
	else {
	
		depopulate_lists();
	
		parent_->set_health(500); 
		parent_->set_level(0); 
		parent_->set_score(0);	
		
		pressStart_ = false;
		pressPause_ = false;
		
		theDude_ = new DoodleDude(); 
	 
		heightCounter = 0;
		moveStop_ = false; 
		moveLength_ = 1; 
	
	
		gameOver_ = false; 
	
		load_images(); 
	}
	
}

void DoodleDiveGameplay::pause_DoodleDive() {

	if (pressStart_ == true) {
	
		if (!pressPause_) {
			pressPause_ = true; 
			killTimer(time_); 
		}
		else {
			pressPause_ = false; 
			time_ = startTimer(gameSpeed_); 
		}
	}	
}

void DoodleDiveGameplay::populate_frame() {
	
	if(moveLength_ > 10) 
		if (heightCounter % 24 == 0)
			monsterList.push_back(new Monster());
			
	if (parent_->get_level() > 4) {
		if (heightCounter % (150-(10 * parent_->get_level())) == 0)
			monsterList.push_back(new Monster()); 
	}
	
	if (heightCounter % 100 == 0) {
		monsterList.push_back(new Monster()); 
	}

	if (heightCounter % 50 == 0) 
		platformList.push_back(new Platform(60)); 
		
	int badAppear = rand() % 4;
	
	if (heightCounter % 30 == 0) {
		if (badAppear == 1) 
			badPlatformList.push_back(new BadPlatform(5));
	}
	
	if (heightCounter % 471 == 0)
		haloList.push_back(new Halo());
	
	
}

void DoodleDiveGameplay::depopulate_lists() {

	for (unsigned int i=0; i < platformList.size(); i++) {
		delete platformList[i]; 
		platformList.erase(platformList.begin() + i);
	}
	for (unsigned int i=0; i < badPlatformList.size(); i++) {
		delete badPlatformList[i]; 
		badPlatformList.erase(badPlatformList.begin() + i);
	}
	for (unsigned int i=0; i < haloList.size(); i++) {
		delete haloList[i]; 
		haloList.erase(haloList.begin() + i);
	}	 

}
void DoodleDiveGameplay::timerEvent(QTimerEvent* e) {
	
	if(e) {}; 
	
	collisionCheck();
	
	parent_->update_display();
	
	if (!moveStop_) {

	move_everything_up(); 
	heightCounter++; 
	populate_frame();  
	
	}

	move_others(); 

	repaint(); 

}

void DoodleDiveGameplay::collisionCheck() {

	bool healthChange = false; 
	bool monsterHit = false;
	bool hitByMonster = false; 
	bool haloHit = false; 

	moveStop_ = false; 
	QRect* theDudePtr = static_cast<QRect*>(theDude_); 
	
	for (unsigned int i=0; i < platformList.size(); i++) {
		if (platformList[i]->y() > 0) {
			if (theDudePtr->intersects(*(static_cast<QRect*>(platformList[i])))) {
				moveStop_ = true;
				moveLength_ = 1; 
			}
		}
		else {
			delete platformList[i]; 
			platformList.erase(platformList.begin() + i);
		}
	}
	for (unsigned int i=0; i < badPlatformList.size(); i++) {
		if (theDudePtr->intersects(*(static_cast<QRect*>(badPlatformList[i])))) {
			//moveStop_ = true; 
			moveLength_ = 1; 
			healthChange = true; 
		}	
	}
	for (unsigned int i=0; i < monsterList.size(); i++) {
		if (theDudePtr->intersects(*(static_cast<QRect*>(monsterList[i])))) {
			moveStop_ = true;
			moveLength_ = 1; 
			hitByMonster = true;   
		}
	}
	
	for (unsigned int i=0; i < fireballList.size(); i++) { 
		for (unsigned int j=0; j < monsterList.size(); j++) {
			if (static_cast<QRect*>(monsterList[j])->intersects
				(*(static_cast<QRect*>(fireballList[i])))) {
				
				delete monsterList[j]; 
				monsterList.erase(monsterList.begin() + j);
				delete fireballList[i]; 
				fireballList.erase(fireballList.begin() + i);
				monsterHit = true; 
			}
		}
	}
	
	for (unsigned int i=0; i < haloList.size(); i++) {
		if (theDudePtr->intersects(*(static_cast<QRect*>(haloList[i])))) { 
			haloHit = true;   
		}
	}
	
	if (haloHit) {
	
	int temphealth = parent_->get_health(); 
	temphealth += 30;
	parent_->set_health(temphealth);
	 
	}
	
	if (hitByMonster) {
	
	int temphealth = parent_->get_health(); 
	temphealth -= 75;
	parent_->set_health(temphealth);
	
	}
	
	if (monsterHit) {
	
		int temphealth = parent_->get_health(); 
		temphealth += 20;
		parent_->set_health(temphealth); 
		
		int tempscore = parent_->get_score(); 
		tempscore += 30;
		parent_->set_score(tempscore); 
	}
	
	if (healthChange) {
	
		int temphealth = parent_->get_health(); 
		temphealth--;
		parent_->set_health(temphealth);
		parent_->update_display(); 
	}
		
	if (parent_->get_health() < 1)
		gameOver_ = true; 
}

void DoodleDiveGameplay::paintEvent(QPaintEvent* e) {	

	if(e) {};  

	QPainter painter(this); 
	if (gameOver_) {
		game_over(); 
		painter.drawPixmap(rect(), QPixmap("gameover.png"))	;
	}
	else if (pressStart_) {
		if (heightCounter % 33 < 11) 
			painter.drawPixmap(rect(), QPixmap("background1.png"));
		else if (heightCounter % 33 < 22) 
			painter.drawPixmap(rect(), QPixmap("background2.png"));
		else 
			painter.drawPixmap(rect(), QPixmap("background3.png"));
	
		painter.drawImage(static_cast<QRect>(*theDude_), *theDudeImage_);
		for (unsigned int i = 0; i < platformList.size(); i++) {
			painter.drawImage(*platformList[i], *platformImage_);
		} 
		for (unsigned int i = 0; i < badPlatformList.size(); i++) {
			painter.fillRect(*badPlatformList[i], Qt::DiagCrossPattern);
			painter.drawRect(*badPlatformList[i]);
		}
		for (unsigned int i = 0; i < monsterList.size(); i++) {
			painter.drawImage(*monsterList[i], *monsterImage_);
		}
		for (unsigned int i = 0; i < fireballList.size(); i++) {
			painter.drawImage(*fireballList[i], *fireballImage_);
		}
		for (unsigned int i = 0; i < haloList.size(); i++) {
			painter.drawImage(*haloList[i], *haloImage_); 
		}
	} 
	else {
		painter.drawPixmap(rect(), QPixmap("opening.png"));
	}
		

}

void DoodleDiveGameplay::mousePressEvent(QMouseEvent *e) {

	int mouseX, mouseY;
	
	mouseX = e->x(); 
	mouseY = e->y();
	
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
			for (int i=0; i < 8; i++)
				theDude_->floatLeft(); 
		else 
			for (int i=0; i < 8; i++)
				theDude_->floatRight();
	}

}

/*void DoodleDiveGameplay::mouseDoubleClickEvent(QMouseEvent *e) {

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}*/ 

void DoodleDiveGameplay::move_others() { 

	for (unsigned int i=0; i < badPlatformList.size(); i++) 
		badPlatformList[i]->move_horizontal();
		
	for (unsigned int i=0; i < monsterList.size(); i++)
		monsterList[i]->move_up(moveLength_ + 2);
			
	for (unsigned int i=0; i < fireballList.size(); i++)
		fireballList[i]->fired_shot(); 
	
}

void DoodleDiveGameplay::move_everything_up() {

	if (heightCounter % 20 == 0) 
		moveLength_ = (moveLength_ + 1);
		
	if (moveLength_ > 10) {
	
		int tempscore = parent_->get_score(); 
		tempscore += 5;
		parent_->set_score(tempscore); 
	}
	
	if (heightCounter % 513 == 0) {
	
		int templevel = parent_->get_level(); 
		templevel += 1;
		parent_->set_level(templevel); 
	
	}
	
//~~~~~~~~~~~~~~~~~~

	if(!moveStop_) {	

		for (unsigned int i=0; i < platformList.size(); i++)
			platformList[i]->move_up(moveLength_);
			
		for (unsigned int i=0; i < badPlatformList.size(); i++) {
			badPlatformList[i]->move_up(moveLength_);
		} 		
		for (unsigned int i=0; i < haloList.size(); i++)
			haloList[i]->move_up(moveLength_);
		}

}

void DoodleDiveGameplay::keyPressEvent(QKeyEvent* e) {

	if (e->key() == Qt::Key_Space) { 
		if (fireballList.size() < 1)
			fireballList.push_back(new Fireball(theDude_)); 
		else {
			delete fireballList[0]; 
			fireballList.erase(fireballList.begin()); 
			fireballList.push_back(new Fireball(theDude_));	
		}
	}
		
}

void DoodleDiveGameplay::update_timer() {

	killTimer(time_); 
	
	time_ += 3; 
	
	startTimer(time_); 
}

void DoodleDiveGameplay::load_images() {


	haloImage_ = new QImage("halo.png"); 
	
	platformImage_ = new QImage("platform.png");
	
	monsterImage_ = new QImage("monster.png"); 

	theDudeImage_ = new QImage("dude.png");
	
	fireballImage_ = new QImage("fireball.png"); 

}










