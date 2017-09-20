class Condition
{public:
	virtual bool ret_value() = 0;
};

class Expression : public Condition //derived class 1
{public:
	bool ret_value();
	//specific to Expressions only:
	void set_op(const string);
	void set_l(Condition*);
	void set_r(Condition*);
private:
	Condition* left;
	Condition* right;
	string Operator;
};

bool Expression::ret_value()
{cout << "\n returning Expression_value ";
bool retv = false;
	if(Operator == "AND")
	{	cout << Operator << endl;
		if((left -> ret_value() == true) && (right -> ret_value() == true)) retv = true;
	}
	if(Operator == "OR") 
	{	cout << Operator << endl;
		if((left -> ret_value() == true) || (right -> ret_value() == true)) retv = true;
	}
	if(Operator == "XOR") 
	{	cout << Operator << endl;
		if((left -> ret_value() == true) ^ (right -> ret_value() == true)) retv = true;
	}
	cout << "TESTING Expression's ret_value() ";
return retv;
}

void Expression::set_op(const string o)
{Operator = o;}

void Expression::set_l(Condition* l)
{left = l;}

void Expression::set_r(Condition* r)
{right = r;}

class Wrapper : public Condition //derived class 2
{private:
	Operand* Op;
public:
	Wrapper(); //def.const., this has to take a valid pointer!
	void assign(Operand*);
	bool ret_value();
};

Wrapper::Wrapper()
{Op = NULL;}

void Wrapper::assign(Operand* O)
{Op = O;}

bool Wrapper::ret_value()
{cout << "\n returning Operand_value ";
if(Op != NULL) return Op -> ret_value();
return false; //if something goes wrong.
}
