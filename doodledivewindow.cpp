#include "doodledivewindow.h"

/** This constuctor will be the window that houses the gameplay and buttons */
DoodleDiveWindow::DoodleDiveWindow() {
	
	setWindowTitle("Doodle Dive!"); 
	
	QVBoxLayout* vertLayout = new QVBoxLayout;
	QHBoxLayout* horzLayout = new QHHoxLayout;   
	
	/**Horizontal elements: gameplay and vertical elements */
	
	gameplay_ = new DoodleDiveGameplay(this); 
	gameplay_ -> setfixedSize(400, 800); 
	
	/**Vertical elements: start, stop, quit, score, level, health*/
	
	start_ = new QPushButton("START");
	stop_ = new QPushButton("PAUSE"); 
	quit_ = new QPushButton("QUIT"); 
	
	//connect functions here
	connect(quit_, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	/** Code to implement to show scores */
	
	QLabel* scoreLabel = new QLabel("SCORE"); 
	QLabel* levelLabel = new QLabel("LEVEL"); 
	QLabel* healthLabel = new QLabel("HEALTH"); 
	
	scoreLabel->setAlignment(Qt::AlignHCenter); 
	levelLabel->setAlignment(Qt::AlignHCenter); 
	healthLabel->setAlignment(Qt::AlignHCenter); 
	
	QLCDNumber* scoreLCD* = new QLCDNumber (4); 
	QLCDNumber* levelLCD* = new QLCDNumber (2); 
	QLCDNumber* healthLCD* = new QLCDNumber (3); 
	
	scoreLCD->setSegmentStyle(QLCDNumber::Outline);
	levelLCD->setSegmentStyle(QLCDNumber::Outline);
	healthLCD->setSegmentStyle(QLCDNumber::Outline);
	
	socreLCD->display(score_); 
	levelLCD->display(level_); 
	healthLCD->display(health_); 
	
	/** Adding buttons and scores to a vertical layout */  
	
	vertLayout->addWidget(start_); 
	vertLayout->addWidget(stop_); 
	vertLayout->addWidget(quit_);
	
	vertLayout->addWidget(scoreLabel);
	vertLayout->addWidget(scoreLCD); 
	
	vertLayout->addWidget(levelLabel); 
	vertLayout->addWidget(levelLCD); 
	
	vertLayout->addWidget(healthLabel); 
	vertLayout->addWidget(healthLCD); 
	
	/** Adding gameplay and vertLayout to horzLayout */
	
	horzLayout->addWidget(gameplay); 
	horzLayout->addLayout(vertLayout); 
	
	/** Set layout of DoodleDiveWindow (widget) */
	
	setLayout(horzLayout); 
}

DoodleDiveWindow::~DoodleDiveWindow() {

	std::cout << "DoodleDiveWinow destructor called" << std::endl; 
}

/** Getters and Setters BELOW */ 

int DoodleDiveWindow::get_health() {

	return health_;
}
 
void DoodleDiveWindow::set_health(int health) {

	health_ = health; 
}

int DoodleDiveWindow::get_level() {

	return level_;
}

void DoodleDiveWindow::set_level(int level) {

	level_ = level; 
}

double DoodleDiveWindow::get_score() {

	return score_; 
}

void DoodleDiveWindow::set_score(double score) {

	score_ = score; 
} 
				
		

