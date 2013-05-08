#include "doodledivegameplay.h"
#include "doodledivewindow.h"
#include "doodledude.h"
#include "badplatform.h"

/** dummy function a move connvient way to debug with command line*/
void DoodleDiveGameplay::dummy(int bleh) {

	std::cout << "BLAHHH: " << bleh << std::endl; 
}

/** constructor where many of the variables are set */
DoodleDiveGameplay::DoodleDiveGameplay(QWidget* parentWindow) : 
	QFrame(parentWindow) {
	
	//dummy(10101); 
	
	parent_ = static_cast<DoodleDiveWindow*>(parentWindow); 
	
	parent_->set_health(500); 
	parent_->set_level(0); 
	parent_->set_score(0); 
	
	setFocusPolicy(Qt::StrongFocus); 
	
	pressStart_ = false;
	pressPause_ = false;  
	enterName_ = false;
	
	theDude_ = new DoodleDude(); 
	 
	heightCounter = 0;
	moveStop_ = false; 
	moveLength_ = 1; 
	
	monsterTracking_ = 0; 
	
	newGame_ = false;
	gameOver_ = false; 
	
	load_images(); 

} 

DoodleDiveGameplay::~DoodleDiveGameplay() {

	//delete stuff 

}

/** game over stops the movement, writes scores to the file, kills timer, and enables another game
* to start by setting newGame bool false
*/
void DoodleDiveGameplay::game_over() {

	moveStop_ = true; 
	
	killTimer(time_); 
	
	if (newGame_)
		parent_->write_scores(); 
	
	newGame_ = false;
	
}

/** won't let game start unless the name input is not blank or "ENTER NAME" which is what
* it is already initialized to
*/
void DoodleDiveGameplay::check_name() {

	QString name = parent_-> get_name();
	
	if (name == "" || name == "ENTER NAME") {
	
		enterName_ = false;
	}
	else {
		parent_-> set_name (name); 
		enterName_ = true; 
	}
}

/** Initialize all of the variables to start the game, restart if in middle of game*/ 
void DoodleDiveGameplay::start_DoodleDive() {

	check_name(); 
	
	if (pressStart_ == false && enterName_ == true) {
	
		pressStart_ = true;
		newGame_ = true; 

		gameSpeed_ = 35; 


		time_ = startTimer(gameSpeed_);  //start time at gameSpeed
	
		populate_frame();
	} 
	
	else {
	  
	  	/** similar resetting of stuff from constructor */
	  
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
		
		newGame_ = false; 
	
		monsterTracking_ = 0; 
	
		gameOver_ = false; 
	
		/** no need to load images again though */
	}
	
}

/** kill timer, then upon clicking again start timer */
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

/**Put new things into the game play at certain points in the game decided by moveHeight
* and move length.   
* ~~ NOTE ~~ : higher levels get harder as levels > 4. Increasingly, more monster will spawn.
*/
void DoodleDiveGameplay::populate_frame() {
	
	if(moveLength_ > 10) 
		if (heightCounter % 24 == 0)
			monsterList.push_back(new Monster());
			
	if (parent_->get_level() > 3) {
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

/**for when we want to restart game, clear the lists of stuff*/
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
	for (unsigned int i=0; i < monsterList.size(); i++) {
		delete monsterList[i];
		monsterList.erase(monsterList.begin() + i);
	}
}

/** every interval of the timer this will execute, here we check for collisions and see if moving
* then we repaint everything after processing all move, populate, and check collision stuff 
*/
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

/** Where we see if theDude has collided with any of the platforms or monsters, or if the bullets
* have collided with any of the monsters 
* Also, if item is in the list and it is out of view, it is deallocated and removed from list. 
* In this function we also handle the changes to score, health, and level based on gameplay
*/
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
		if (badPlatformList[i]->y() > 0) {
			if (theDudePtr->intersects(*(static_cast<QRect*>(badPlatformList[i])))) {
				//moveStop_ = true; 
				moveLength_ = 1; 
				healthChange = true; 
			}
		}
		else {
			delete badPlatformList[i]; 
			badPlatformList.erase(badPlatformList.begin() + i);
		}	
	}
	for (unsigned int i=0; i < monsterList.size(); i++) {
		if (monsterList[i]->y() > 0) {
			if (theDudePtr->intersects(*(static_cast<QRect*>(monsterList[i])))) {
				moveStop_ = true;
				moveLength_ = 1; 
				hitByMonster = true;   
			}
		}
		else {
			delete monsterList[i]; 
			monsterList.erase(monsterList.begin() + i);
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
		if (fireballList[i]->y() > 800) {
			delete fireballList[i]; 
			fireballList.erase(fireballList.begin() + i);	
		}
	}
	
	for (unsigned int i=0; i < haloList.size(); i++) {
		if (haloList[i]->y() > 0) {
			if (theDudePtr->intersects(*(static_cast<QRect*>(haloList[i])))) { 
				haloHit = true;   
			}
		}
		else  {
			delete haloList[i]; 
			haloList.erase(haloList.begin() + i);
		}
	}
	
	/** Handle the gameplay events below */
	
	if (haloHit) {
	
	int temphealth = parent_->get_health(); 
	temphealth += 30;
	if (temphealth > 1000)
		temphealth = 999; 
	parent_->set_health(temphealth);
	 
	}
	
	if (hitByMonster) {
	
	int temphealth = parent_->get_health(); 
	temphealth -= 75;
	if (temphealth < 0)
		temphealth = 0; 
	parent_->set_health(temphealth);
	
	}
	
	if (monsterHit) {
	
		int temphealth = parent_->get_health(); 
		temphealth += 20;
		if (temphealth > 1000)
			temphealth = 999;
		parent_->set_health(temphealth); 
		
		int tempscore = parent_->get_score(); 
		tempscore += 30;
		parent_->set_score(tempscore); 
	}
	
	if (healthChange) {
	
		int temphealth = parent_->get_health(); 
		temphealth -= 4;
		parent_->set_health(temphealth);
		parent_->update_display(); 
	}
		
	if (parent_->get_health() < 1)
		gameOver_ = true; 
}
/** paint everything for the game here*/
void DoodleDiveGameplay::paintEvent(QPaintEvent* e) {	

	if(e) {};  

	QPainter painter(this); 
	if (gameOver_) {
		game_over(); 
		painter.drawPixmap(rect(), QPixmap("gameover.png"))	;
	}
	else if (pressStart_) {
	
		if (readBackgrounds_ == false) {
			if (heightCounter % 33 < 11) 
				painter.drawPixmap(rect(), QPixmap("background1.png"));
			else if (heightCounter % 33 < 22) 
				painter.drawPixmap(rect(), QPixmap("background2.png"));
			else 
				painter.drawPixmap(rect(), QPixmap("background3.png"));
		}
		else {
			int level = ((parent_->get_level()) % 3);
			if (level == 1) {
				if (heightCounter % 33 < 11) 
					painter.drawPixmap(rect(), *backgroundList[0]);
				else if (heightCounter % 33 < 22) 
					painter.drawPixmap(rect(), *backgroundList[1]);
				else 
					painter.drawPixmap(rect(), *backgroundList[2]);
			}
			else if (level == 0) {
				if (heightCounter % 33 < 11) 
					painter.drawPixmap(rect(), *backgroundList[3]);
				else if (heightCounter % 33 < 22) 
					painter.drawPixmap(rect(), *backgroundList[4]);
				else 
					painter.drawPixmap(rect(), *backgroundList[5]);
			}
			else {
				if (heightCounter % 33 < 11) 
					painter.drawPixmap(rect(), *backgroundList[6]);
				else if (heightCounter % 33 < 22) 
					painter.drawPixmap(rect(), *backgroundList[7]);
				else 
					painter.drawPixmap(rect(), *backgroundList[8]);
			}
		}
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
/** handle mouse press events to move theDude!!!! the closer the mouse is to the bottom, the farther he moves*/
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

/**moves related not explicitly to moving up and/or not going to stop when in contact with platform*/
void DoodleDiveGameplay::move_others() { 

	for (unsigned int i=0; i < badPlatformList.size(); i++) 
		badPlatformList[i]->move_horizontal();
		
	for (unsigned int i=0; i < monsterList.size(); i++) {
		monsterList[i]->move_up(moveLength_ + 2);
		if (moveStop_ && monsterList.size()> 0)
			monsterList[i]->monster_attack(theDude_);
	}
			
	for (unsigned int i=0; i < fireballList.size(); i++)
		fireballList[i]->fired_shot(); 
	
	if (monsterTracking_ > 0)	
		monsterTracking_ --; 
		
	if (monsterTracking_) {
		for (unsigned int i=0; i < fireballList.size(); i++) 
			fireballList[i]->tracking(); 
	}
	
	
}
/** move stuff up, will stop when in contact with platform, also increases the rate of moving upwards*/
void DoodleDiveGameplay::move_everything_up() {

	/** below are aspects dependent on movement of theDude */

	/** if move down 20 units, add to how fast theDude falls*/
	if (heightCounter % 20 == 0) 
		moveLength_ = (moveLength_ + 1);
		
	/** start to accumulate score if theDude is falling fast */
	if (moveLength_ > 10) {
	
		int tempscore = parent_->get_score(); 
		tempscore += 5;
		parent_->set_score(tempscore); 
	}
	
	/** level up here */
	if (heightCounter % 413 == 0) {
	
		int templevel = parent_->get_level(); 
		templevel += 1;
		parent_->set_level(templevel);  
	
	}
	
	/** move stuff up below if not stopped on a platform */

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

/**shooting fireballs.  YOU ONLY GET ONE AT A TIME. so you cannot spam
* activate monster tracking by pressing G while the fireball is shot.
*/
void DoodleDiveGameplay::keyPressEvent(QKeyEvent* e) {

	if (e->key() == Qt::Key_Space) { 
		if (fireballList.size() < 1) {
			fireballList.push_back(new Fireball(theDude_));
			monsterTracking_ = 0; 
		}
		else {
			delete fireballList[0]; 
			fireballList.erase(fireballList.begin()); 
			fireballList.push_back(new Fireball(theDude_));	
			monsterTracking_ = 0; 
		}
	}
	if (e->key() == Qt::Key_G) {
		//if (fireballList.size() < 1)
			//fireballList.push_back(new Fireball(theDude_)); 
		if (monsterList.size() > 0) {
				fireballList[0]->set_tracking_loc
						(monsterList[monsterList.size()-1]);
			monsterTracking_ = 100 + ((rand() % 5) * 20); 
			}
		else {
			//delete fireballList[0]; 
			//fireballList.erase(fireballList.begin()); 
			monsterTracking_ = 0; 
		}
	}
		
}

void DoodleDiveGameplay::update_timer() {

	killTimer(time_); 
	
	time_ += 3; 
	
	startTimer(time_); 
}

/** Load image names from a file, then load in images for background all at same time, so as not to
* slow down program.  If the file does not load names correctly, load hard-coded images.
*/
void DoodleDiveGameplay::load_images() {

	ifstream fin; 
	fin.open("backgrounds.txt");
	string tempString;
	
	if (fin.fail()) {
		readBackgrounds_ = false; 
		return; 
	}
	
	fin >> tempString; 
	
	if (fin.bad()) {
		readBackgrounds_ = false; 
		return; 
	}
	
	while (!(fin.eof())) {
	
		QString tempPixName(QString::fromStdString(tempString));
		QPixmap* background = new QPixmap(tempPixName); 
		backgroundList.push_back(background); 
		fin >> tempString; 	
	}
	
	haloImage_ = new QImage("halo.png"); 
	platformImage_ = new QImage("platform.png");
	monsterImage_ = new QImage("monster.png"); 
	theDudeImage_ = new QImage("dude.png");
	fireballImage_ = new QImage("fireball.png"); 
	readBackgrounds_ = true; 
}










