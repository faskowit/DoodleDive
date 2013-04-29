#include "doodledivewindow.h"

/** This constuctor will be the window that houses the gameplay and buttons */
DoodleDiveWindow::DoodleDiveWindow() {
	
	//std::cout << "BLLLLOOOP"<< std::endl; 
	
	setWindowTitle("Doodle Dive!"); 
	
	QVBoxLayout* vertLayout = new QVBoxLayout;
	QHBoxLayout* horzLayout = new QHBoxLayout;  
	
	/**Horizontal elements: gameplay and vertical elements */
	
	gameplay_ = new DoodleDiveGameplay(this); 
	gameplay_ -> setFixedSize(400, 600); 
	
	/**Vertical elements: start, stop, quit, score, level, health*/
	
	start_ = new QPushButton("START");
	pause_ = new QPushButton("PAUSE"); 
	quit_ = new QPushButton("QUIT"); 
	
	//connect functions here
	connect(quit_, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start_, SIGNAL(clicked()), gameplay_, 
		SLOT(start_DoodleDive())); 
	connect(pause_, SIGNAL(clicked()), gameplay_, 
		SLOT(pause_DoodleDive()));
	
	/** Code to implement to show scores */
	
	
	QLabel* scoreLabel = new QLabel("SCORE"); 
	QLabel* levelLabel = new QLabel("LEVEL"); 
	QLabel* healthLabel = new QLabel("HEALTH"); 
	
	scoreLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	levelLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	healthLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	
	
	scoreLCD_ = new QLCDNumber (4); 
	levelLCD_ = new QLCDNumber (2); 
	healthLCD_ = new QLCDNumber (3); 
	
	scoreLCD_->setSegmentStyle(QLCDNumber::Outline);
	levelLCD_->setSegmentStyle(QLCDNumber::Outline);
	healthLCD_->setSegmentStyle(QLCDNumber::Outline);
	
	scoreLCD_->display(score_); 
	levelLCD_->display(level_); 
	healthLCD_->display(health_); 
	
	/** Adding buttons and scores to a vertical layout */  
	
	vertLayout->addWidget(start_); 
	vertLayout->addWidget(pause_); 
	vertLayout->addWidget(quit_);
	
	vertLayout->addWidget(scoreLabel);
	vertLayout->addWidget(scoreLCD_); 
	
	vertLayout->addWidget(levelLabel); 
	vertLayout->addWidget(levelLCD_);
	
	vertLayout->addWidget(healthLabel); 
	vertLayout->addWidget(healthLCD_); 
	
	/** Adding gameplay and vertLayout to horzLayout */
	
	horzLayout->addWidget(gameplay_); 
	horzLayout->addLayout(vertLayout); 
	
	/** Set layout of DoodleDiveWindow (widget) */
	
	setLayout(horzLayout); 
}

void DoodleDiveWindow::update_display() {

	scoreLCD_->display(score_); 
	levelLCD_->display(level_); 
	healthLCD_->display(health_); 
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
				
DoodleDiveGameplay* DoodleDiveWindow::get_gameplay() {

	return gameplay_; 
}		

