Operand* builder(Operand*& c, string& t, int& RN) //this does not even need the prev. pointer!
{if(c == NULL) 
	{c = new Operand(t); 
	c -> add_RN(RN);
	cout << " new Operand created " << c -> ret_name() << endl;
	}
else
{if(t < c -> ret_name()) return builder(c -> to_left,t, RN);
    else
        if(t > c -> ret_name()) return builder(c -> to_right,t, RN);
        else c -> add_RN(RN);//if it is neither smaller, nor greater, it has to be equal, so just add the number
}
return c;
}
