T=int(raw_input())
values=[]
i=1;
x=1000000007
values.append(1);
while i<=T:
	guestval=int(raw_input())
	if(len(values)<guestval):
		j=len(values)
		while (j<guestval):
			power=j/2
			values.append(pow(2,j,x))
			j=j+1
	print values[guestval-1]
	i=i+1	
