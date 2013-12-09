#Optimized Version 
T=int(raw_input())
i=1;
while i<=T:
	guestval=int(raw_input())
	powerval=guestval/2
	if (guestval%2)!=0:
		powerval=powerval+2
		value=(pow(2,powerval,1000000007)-2)
	else:
		value=3*pow(2,powerval,1000000007)-2
	print value
	i=i+1
