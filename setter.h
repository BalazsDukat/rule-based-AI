bool setter(Operand*& c, string& t)
{if(c == NULL) return false;
else
    if(t == c -> ret_name()) 
	{if(c -> ret_value() == true)
	return false; //if the Operand has been set already, just quit here with a false.
	c -> set_value(true); //otherwise continue as normal.
	return true;
	}
    else
	    {if(t > c -> ret_name())
	    	{c = c -> to_right; cout << " going RIGHT";//go right (might be NULL)
			}
	    else //t was not equal with c's retname, and wasn't greater either, so it has to be smaller
		    {c = c -> to_left; cout << " going LEFT";//go left (might be NULL)
			}
	    }
return setter(c,t);
}
