key=int(input("enter key"))
stringv=input("Enter string")
a=[]
for i in stringv:
	if i == ' ':
		a.append(i)
	else:
		k=ord(i)-key
		if(k<97):
			diff=97-k
			k=123-diff
		elif(k<65):
			diff=65-k
			k=91-diff
		a.append(chr(k))
sent=''.join(a)
print (sent)
