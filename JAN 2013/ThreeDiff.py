T=int(raw_input())
list=[0,0,0]
while(T>0):
	str=raw_input()
	newlist = [int(n) for n in str.split(' ')]
	newlist.sort()
	FinalVal=1;
	k=0;
	while(k<=2):
		FinalVal*=((newlist[k]-k)%1000000009)%1000000009
		k+=1
	print (FinalVal%1000000009)
	T-=1

