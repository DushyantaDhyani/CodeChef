def eval(x):
	x=int(x)
	i=1;
	lim=x/2
	finalval=1
	denom=1
	while i<=lim:
		denom*=i
		finalval*=x
		x-=1
		i+=1
	finalval/=denom
	return (finalval/2)
T=int(raw_input())
N=0
MOD=1000000007 
val=0
while T>0:
	N=int(raw_input())
	str=raw_input()
	val=2**(N-1)%MOD
	if(N%2==0):
		val-=eval(N)%MOD
	print val%MOD
	T-=1
