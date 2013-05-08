#include "doodledivewindow.h"


/** write scores to a file. Name then score. One line per pair */
void DoodleDiveWindow::write_scores() {

	//std::cout << "WRITING" << std::endl; 
	
	Scores temp;
	
	temp.score_ = get_score();
	temp.name_ = playerName_.toStdString();
	
	scoresList.push_back(temp); 

	ofstream fout;
	
	fout.open("doodleresults.txt");
	
	for (unsigned int i=0; i < scoresList.size(); i++) {
	
		fout << scoresList[i].name_ << " " 
			<< scoresList[i].score_ << endl; 
	
	}

}

/* Read in scores.  If no scores to read in, the high score 0 and name is is "none" */
void DoodleDiveWindow::read_scores() {

	//std::cout<<"READING" << std::endl;  

	ifstream fin;
	Scores temp;  
	float score, scoreHigh;  
	string name, nameHigh; 
	
	scoreHigh = 0; 
	nameHigh = "none";
	
	highScore_->name_ = nameHigh; 
	highScore_->score_ = scoreHigh; 
	
	fin.open("doodleresults.txt");
	
	//std::cout<<"open" << std::endl;
	
	if (fin.fail())
		return; 
	
	fin >> name; 
	
	if (fin.bad()) 
		return; 
	
	while (!(fin.eof())) {
	
		fin >> score; 
		
		if (score >= scoreHigh) {
			scoreHigh = score; 
			nameHigh = name; 
		}
	
		temp.name_ = name;
		temp.score_ = score; 
		scoresList.push_back(temp);
		
		fin >> name; 	
	
	}
	
	highScore_->name_ = nameHigh; 
	highScore_->score_ = scoreHigh; 

}

/** This constuctor will be the window that houses the gameplay and buttons */
DoodleDiveWindow::DoodleDiveWindow() {

	highScore_ = new Scores(); 

	read_scores(); 
	
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
	nameBox_ = new QLineEdit("ENTER NAME"); 
	
	//connect functions here
	connect(quit_, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start_, SIGNAL(clicked()), gameplay_, 
		SLOT(start_DoodleDive())); 
	connect(pause_, SIGNAL(clicked()), gameplay_, 
		SLOT(pause_DoodleDive()));
	
	/** Code to implement to show scores */
	
	//std::cout<<"CHECKKKK"<< std::endl;
	
	QString* highName = new QString(QString::fromStdString(highScore_->name_)); 
	//highName = &(QString::fromStdString(highScore_->name_));
	 
	
	highScoreName_ = new QLabel(*highName); 
	
	QLabel* scoreLabel = new QLabel("SCORE"); 
	QLabel* levelLabel = new QLabel("LEVEL"); 
	QLabel* healthLabel = new QLabel("HEALTH"); 
	QLabel* nameLabel = new QLabel("NAME"); 
	QLabel* highLabel = new QLabel("HIGH SCORE");
	QLabel* highNameLabel = new QLabel(*highName); 
	
	scoreLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	levelLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	healthLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	nameLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	highLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom); 
	highNameLabel->setAlignment(Qt::AlignRight | Qt::AlignBottom); 
	
	scoreLCD_ = new QLCDNumber (4); 
	levelLCD_ = new QLCDNumber (2); 
	healthLCD_ = new QLCDNumber (3); 
	highLCD_ = new QLCDNumber (4); 
	
	highLCD_-> setSegmentStyle(QLCDNumber::Outline);
	scoreLCD_->setSegmentStyle(QLCDNumber::Outline);
	levelLCD_->setSegmentStyle(QLCDNumber::Outline);
	healthLCD_->setSegmentStyle(QLCDNumber::Outline);
	
	highLCD_->display(highScore_->score_);
	scoreLCD_->display(score_); 
	levelLCD_->display(level_); 
	healthLCD_->display(health_); 
	
	/** Adding buttons and scores to a vertical layout */  
	
	vertLayout->addWidget(start_); 
	vertLayout->addWidget(pause_); 
	vertLayout->addWidget(quit_);
	
	vertLayout->addWidget(nameLabel); 
	vertLayout->addWidget(nameBox_); 
	
	vertLayout->addWidget(highLabel); 
	vertLayout->addWidget(highNameLabel); 
	vertLayout->addWidget(highLCD_); 
	
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

	//std::cout << "DoodleDiveWinow destructor called" << std::endl; 
}

/** Getters and Setters BELOW */ 

void DoodleDiveWindow::set_name(QString name) {

	playerName_ = name;
}

QString DoodleDiveWindow::get_name() const {

	return nameBox_->text();  

}

int DoodleDiveWindow::get_health() const {

	return health_;
}
 
void DoodleDiveWindow::set_health(int health) {

	health_ = health;  
}

int DoodleDiveWindow::get_level() const {

	return level_;
}

void DoodleDiveWindow::set_level(int level) {

	level_ = level; 
}

double DoodleDiveWindow::get_score() const {

	return score_; 
}

void DoodleDiveWindow::set_score(double score) {

	score_ = score;  
} 
				
DoodleDiveGameplay* DoodleDiveWindow::get_gameplay() {

	return gameplay_; 
}		

