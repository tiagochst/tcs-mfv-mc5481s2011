# Author: TCS


RA=ra082941-ra082335
file=relatorio

report:
	latex $(file).tex
	latex $(file).tex
	dvips $(file).dvi -o
	ps2pdf13 $(file).ps
	make clean

# TO DO: remove useless files
delivery: 
	mkdir $(RA)
	cp relatorio.pdf $(RA)
	cp -rap parte1 parte2 $(RA)
	tar -zcvf $(RA).tar.gz $(RA)
	rm -rf $(RA)

clean:
	rm *.dvi *.aux *.ps *.toc *.log