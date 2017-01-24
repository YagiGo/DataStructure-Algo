Status DeleteK(SqList &a, int i, int k)
{
	if(i < 0 || i > a.length - 1 || k < 0 || k > a.length - i) return INFEASIBLE;
	else
	{
		for(count = i+k-1; count < i; count--)
		{
			a.elem[count] = a.elem[count + 1];
			a.length--;
		}
	}
}