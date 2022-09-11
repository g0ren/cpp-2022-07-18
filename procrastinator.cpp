#include <iostream>
using namespace std;

class Procrastination {
protected:
	Procrastination *next;
public:
	virtual void execute()=0;
	virtual ~Procrastination() {
	}
};

class WithinAnHour;
class Tomorrow;
class ByNextWeek;
class InAMonth;

class WithinAnHour: public Procrastination {
public:
	WithinAnHour();
	void execute() {
		cout
				<< "I'll do it in an hour, right after I finish this episode of Hunter X Hunter!"
				<< endl;
		this->next->execute();
	}

};

class Tomorrow: public Procrastination {
public:
	Tomorrow();
	void execute() {
		cout
				<< "I'm tired from watching anime all day today, I'll do it first thing tomorrow"
				<< endl;
		this->next->execute();
	}
};

class ByNextWeek: public Procrastination {
public:
	ByNextWeek();
	void execute() {
		cout
				<< "This week it's too busy, all my favorite titles published new seasons in the same time. "
				<< "But by next week I'll do it for sure!" << endl;
		this->next->execute();
	}
};

class InAMonth: public Procrastination {
public:
	InAMonth();
	void execute() {
		cout
				<< "Okay, time to stop procrastinating and finish everything by the end of the month. "
				<< "No more anime until I'm done! " << endl
				<< "I'll just finish this episode of Hunter X Hunter and start right away."
				<< endl;
		this->next->execute();
	}
};

WithinAnHour::WithinAnHour() {
	this->next = new Tomorrow;
}

Tomorrow::Tomorrow() {
	this->next = new ByNextWeek;
}

ByNextWeek::ByNextWeek() {
	this->next = new InAMonth;
}

InAMonth::InAMonth() {
	this->next = nullptr;
}

int main() {
	Procrastination *ill_do_it_right_now = new WithinAnHour;
	ill_do_it_right_now->execute();
	return 0;
}
