typedef struct {
	char *ch;
	int last;
}StringType;
void StrAssign(StringType &t, StringType s);
int StringCompare(StringType s, StringType t);
int StrLength(StringType s);
StringType Concat(StringType s, StringType t);
StringType SubString(StringType s, int start, int len);
StringType Reverse(StringType &s)
{
	StringType t;
	if(s.last == 0) return s;
	else
	{
		char c = s.ch; c += s.ch + s.last;
		if(!(t.ch = (char *) malloc(sizeof(char)))) exit(OVERFLOW); t.ch = *c;
		s.last--;
		t.last++;
		int i = 2;
		while(*c)
		{
			char c = s.ch; c += s.ch + s.last;
			if(!(t.ch = (char *) remalloc(sizeof(char) * i))) exit(OVERFLOW); t.ch = *c;
			s.last--;
			i++;
			t.last++;
		}
	}
	free(s.ch);
	return t;
}
/* 递归算法的reverse函数 */
StringType ReverseRecurrence(StringType &s, int i = 1)
{
	StringType t;
	if(s.last == 0) free(s.ch); return t;
	else
	{
		char c = s.ch; c += s.ch + s.last;
		if(!(t.ch = (char *) remalloc(sizeof(char) * i))) exit(OVERFLOW); t.ch = *c;
		s.last--;
		t.last++;
		i++;
		while(*c)
		{
			ReverseRecurrence(s, i);
		}
	}

}
void remove(StringType s, StringType t, StringType r, int pos[])
{
	int j = &t, i = &s, k = 0;
	StringType l;
	int len_s = StrLength(s), len_t = StrLength(t);
	char c1 = SubString(s, i, 1);
	char c2 = SubString(t, j, 1);
	while(len_t)
	{
		char c1 = SubString(t, j, 1);
		while(len_s)
		{
			char c2 = SubString(s, i, 1);
			if(!StringCompare(c1,c2)) {
				pos[k] = i; Concat(r,c1); k++; break;
			}
			else {len_s--; i++};
		}
		len_t--; j++;
	}
	i = &s; j = &r; int len_r = StrLength(r);
	while(len_r)
	{
		char c1 = SubString(r, j, 1);
		while(len_s)
		{
			char c2 = SubString(s, i, 1);
			if(!StringCompare(c1,c2)) {
				StrDelete(s,i,1;)
			}
			else {len_s--; i++};
		}
		len_r--; j++;
	}
	StrAssign(r,s);
}
void Replace(StringType &S, StringType T, StringType V)
{
	StrAssign(S,T);
	StrAssign(T,V);
	StrAssign(V,S);
}
void removeIdentical(StringType S, StringType T)
{
	int len_t = StrLength(T); len_s = StrLength(S);
	int i = &S; j = &T;
	while(len_s)
	{
		if(!StringCompare(SubString(T,j,len_t), SubString(S,i,len_t)))
		{
			StrDelete(S,i,len_t);
			i++; len_s--;
		}
		else {i++; len_s--;}
	}
}


