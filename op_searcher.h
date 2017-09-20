bool searcher(Operand* p, Operand* c, string t)
{if(c == NULL) return false; //previous becomes relevant, insertion happens
else
    if(t == c -> ret_name()) return true; //current becomes relevant, that matches with input
    else
	    {p = c; //save current position, we will go somewhere
	    if(t > c -> ret_name())
	    	{c = c -> to_right; cout << " going RIGHT";//go right (might be NULL)
			}
	    else //t was not equal with c's retname, and wasn't greater either, so it has to be smaller
		    {c = c -> to_left; cout << " going LEFT";//go left (might be NULL)
			}
	    }
return searcher(p,c,t);
}
