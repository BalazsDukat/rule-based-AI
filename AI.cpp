#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

#include "class_operand.h" //done
#include "class_expression.h" //done
//#include "class_wrapper.h" //done
#include "class_rule.h" //done

#include "op_searcher.h" //done.
#include "expression_builder.h" //done. This calls treebuilder.
#include "setter.h"

int main()//the building of rulebase from file happens only once, so it is just part of main now.
{vector<Rule> RB; //this will store the rules in memory
Operand* ROOT = NULL; //starting for a tree
ifstream rulesfst("rules.txt");
string s, temp;
int i = 0; //this will serve only as an identifier. it really does not matter what it is as long as it is unique.

while(getline(rulesfst,s))
{istringstream in(s);
if((in >> temp) && (temp == "IF"))
	{Rule* Rp = new Rule;
	Rp -> add_IF(exp_builder(in, ROOT, i)); //this will need checks
	string THEN, ELSE;
	if((in >> temp) && (temp == "THEN"))
	{while((in >> temp) && (temp != "ELSE")) Rp -> add_THEN(temp);
	while(in >> temp) Rp -> add_ELSE(temp); cout << "ELSEs added" << endl;
	RB.push_back(*Rp);
	i++; //this is just an indexnumber, identifier for rules.
	}else cerr << "badly formed Rule, has no THEN part!" << endl;
	}
else cerr << "this is not a rule!\n";
}
cout << endl << "Enter the input words or symbols, separate them with spaces or enters." << endl <<
"When finished, press CTRL + z" << endl;
string inputstring;
while(cin >> temp && temp != "") inputstring = inputstring + " " + temp;
cout << endl << inputstring << " **this is the actual input**" << endl;
/*breaking loops: check if the node was set to true
and if yes, then do not process it. (changing setter function)*/
while (inputstring != "")
{vector<Operand*> res_ps;
string results;
istringstream res_to_input(inputstring);
while(res_to_input >> temp)
//temp is really just the universal global string that receives and temporarlily stores whatever is arriving.
{cout << temp << " - ";
Operand* x = ROOT;
if(setter(x, temp))
{cout << " Found it! :) " << x -> ret_name(); //Operand found in the tree
//sth else here? saving pointers?
res_ps.push_back(x);
}
else cout << " Did not find it! :( " << temp << endl;
}
//using saved pointers with a "for"
for(int k = 0; k < res_ps.size(); k++)
{cout << k << " ";
for(int j = 0; j < res_ps[k] -> i().size(); j++) //this will fire the rules
{//if(RB[x -> i()[j]].IF == NULL) cout << " IF-side is NULL!!!!!!!!!!!" << endl;
string res = RB[res_ps[k] -> i()[j]].fire();
cout << res << " " << res_ps[k] -> i()[j] << endl;
/*exceptions? not handled explicitly, problems simply should not be possible*/
results = results + " " + res;
}
}

inputstring = results;
cout << endl << inputstring << endl;
}
cout << "Press any key to exit.";
getch();
}
