import re
T=int(raw_input())
check=r'[C?][H?][E?][F?]'
rp='CHEF'
while T>0:
	str=raw_input();
	val=re.sub(check,rp,str)
	valnew=''
	for i in val:
		if i=='?':
			valnew+='A'
		else:
			valnew+=i
		
	print valnew
	T-=1