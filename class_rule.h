class Rule
{private:
	Condition* IF;
	string THEN, ELSE;
public://
	Rule();
	void add_IF(Condition*);
	void add_THEN(string);
	void add_ELSE(string);
	string fire();
};

Rule::Rule() {IF = NULL;}

void Rule::add_IF(Condition* c) {IF = c;}

void Rule::add_THEN(string s) {THEN += " " + s;}
//input for the next run!! 

void Rule::add_ELSE(string s) {ELSE += " " + s;}
//as above

string Rule::fire()
{cout << " firing Rule!" << endl;
if(IF -> ret_value() == true) return THEN;
return ELSE;
}
