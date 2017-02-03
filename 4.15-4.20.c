 #define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1]
void StrAssign(SString &T, SString chars)
{
	if(!T) T = NULL;
	if(chars[0] <= MAXSTRLEN)
	{
		T[1...S[0]] = chars[1...chars[0]];
	}
	else
	{
		T[1...MAXSTRLEN] = chars[1...MAXSTRLEN];
		printf("String has been cut\n");
	}
}
int StrCompare(SString S, SString T)
{
	if(S[0] > T[0]) return 1;
	else if(S[0] < T[0]) return -1;
	else if(S[0] == T[0] ) return 0;
}
void Replace(SString &S, SString T, SString V)
{
		S[1...T[0]] =T[1...T[0]];
		T = NULL;
		T[1...V[0]] = V[1...V[0]];
		V = NULL;
		V[1...V[0]] = S[1...T[0]];
}
void Counter(SString S)
{
	int i = 1; count[MAXSTRLEN] = 0;
	int charnumber;
	while(i < S[0])
	{
		switch(S[i]) {
			case 'A': count[0]++;
			case 'B': count[1]++;
			/*.
			/*.
			/*.
			/*all the ascii char
			*/
			case '_':count[k-1]++;
			case ' ':count[k]++;
		}
	}
	for(j = 0; j <=k; j++)
	{
		if(count[k] != 0) charanumber++; 
	}
	return charanumber;
}
