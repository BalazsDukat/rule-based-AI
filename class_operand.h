/*these have to have a way of referring to Rules they are from.
they will have to use Rule numbers.
That's because of the order of declaration problem,
there would be a circular reference.*/

class Operand
{private:
	string name; //e.g.: A
	bool value;

	vector<int> RNums;
public:
	Operand(const string);
	string ret_name();
	Operand* to_left, *to_right;
	bool ret_value();
	void set_value(const bool);
	void add_RN(int);
	vector<int> i();
};

Operand::Operand(const string n)
{	value = false;
	name = n;
	to_left = NULL;
	to_right = NULL;
}

string Operand::ret_name()
{return name;}

bool Operand::ret_value()
{return value;}

void Operand::set_value(const bool b)
{value = b;}

void Operand::add_RN(int Rn)
{RNums.push_back(Rn);
}

vector<int> Operand::i()
{return RNums;
}
