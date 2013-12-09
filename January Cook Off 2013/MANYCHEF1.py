import re
T=int(raw_input())
check=r'[C?][H?][E?][F?]'
rp='CHEF'
while T>0:
	str=raw_input();
	strnew=list(str)
	limit=len(strnew)-4
	while limit>=0:
		strtemp="".join(strnew[limit:limit+4])
		re.search(check,strtemp)
		print val
		limit-=4
	T-=1