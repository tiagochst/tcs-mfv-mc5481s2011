#To see all output:
time=3600
all:
	make P10
	make P11
	make P12
	make P20
	make P21
	make P22
	make P30
	make P31
	make P32
	make P40
	make P41
	make P42
	make P50
#	make P51
	make P52

EP1:
	glpsol -m nd30.pli --output nd30.txt --wcpxlp nd30.lp -d nd30.dat

EP2:
	glpsol -m mn27.pli --output mn27.txt --wcpxlp mn27.lp -d mn27.dat

EP3:
	glpsol -m ss2.pli --output ss2.txt --wcpxlp ss2.lp -d ss2.dat

EP4:
	glpsol -m ss15.pli --output ss15.txt --wcpxlp ss15.lp -d ss15.dat

EP5:
	glpsol -m mn22.pli --output mn22.txt --wcpxlp mn22.lp -d mn22.dat

MODEL:
	glpsol -m nd30.pli -d nd30.dat 
	glpsol -m mn27.pli -d mn27.dat
	glpsol -m ss2.pli  -d ss2.dat
	glpsol -m ss15.pli -d ss15.dat
	glpsol -m mn22.pli -d mn22.dat
P10:
	glpsol -m nd30.pli -d nd30/nd30.0.dat --memlim 1000 --tmlim $(time) --output nd30.0.txt --wcpxlp nd30.0.lp 
P11:
	glpsol -m nd30.pli -d nd30/nd30.1.dat --memlim 1000 --tmlim $(time) --output nd30.1.txt --wcpxlp nd30.1.lp 
P12:
	glpsol -m nd30.pli -d nd30/nd30.2.dat --memlim 1000 --tmlim $(time) --output nd30.2.txt --wcpxlp nd30.2.lp 

P20:
	glpsol -m mn27.pli -d mn27/mn27.0.dat --memlim 1000 --tmlim $(time) --output mn27.0.txt --wcpxlp mn27.0.lp 


P21:
	glpsol -m mn27.pli -d mn27/mn27.1.dat --memlim 1000 --tmlim $(time) --output mn27.1.txt --wcpxlp mn27.1.lp 
P22:
	glpsol -m mn27.pli -d mn27/mn27.2.dat --memlim 1000 --tmlim $(time) --output mn27.2.txt --wcpxlp mn27.2.lp 
P30:
	glpsol -m ss2.pli  -d ss2/ss2.0.dat --memlim 1000 --tmlim $(time) --output ss2.0.txt --wcpxlp ss2.0.lp 
P31:
	glpsol -m ss2.pli  -d ss2/ss2.1.dat  --memlim 1000 --tmlim $(time) --output ss2.1.txt --wcpxlp ss2.1.lp 

P32:
	glpsol -m ss2.pli  -d ss2/ss2.2.dat  --memlim 1000 --tmlim $(time) --output ss2.2.txt --wcpxlp ss2.2.lp 

P40:
	glpsol -m ss15.pli -d ss15/ss15.0.dat --memlim 1000 --tmlim $(time) --output ss15.0.txt --wcpxlp ss15.0.lp 

P41:
	glpsol -m ss15.pli -d ss15/ss15.1.dat  --memlim 1000 --tmlim $(time) --output ss15.1.txt --wcpxlp ss15.1.lp 

P42:
	glpsol -m ss15.pli -d ss15/ss15.2.dat --memlim 1000 --tmlim $(time) --output ss15.2.txt --wcpxlp ss15.2.lp 

P50:
	glpsol -m mn22.pli -d mn22/mn22.0.dat --memlim 1000 --tmlim $(time) --output mn22.0.txt --wcpxlp mn22.0.lp 

P51:
	glpsol -m mn22.pli -d mn22/mn22.1.dat  --memlim 1000 --tmlim 3600 --output mn22.1.txt --wcpxlp mn22.1.lp 

P52:
	glpsol -m mn22.pli -d mn22/mn22.2.dat  --memlim 1000 --tmlim $(time) --output mn22.2.txt --wcpxlp mn22.2.lp 


