#include <sstream>
#include "tree_builder.h"

Condition* exp_builder(istringstream& in, Operand*& ROOT, int& i)
{string temp;
in >> temp;
Condition* C = NULL;
if(temp == "(")
		{Expression* E = new Expression;
		E -> set_l(exp_builder(in, ROOT, i));
		in >> temp;
		E -> set_op(temp);
		E -> set_r(exp_builder(in, ROOT, i));
		in >> temp;//here this should consume the closing ), but also makes it necessary to use it
		C = E;
		}
else	{Operand* p = builder(ROOT,temp,i);
		Wrapper* wp = new Wrapper;
		wp -> assign(p);
		C = wp;
		}
return C;
}
