 #!/bin/bash
for i in $( ls inst_fim/*.in ); do
    echo $i
	cp $i verifica.dat
	./heur $i -o $i.out -t 120
done
