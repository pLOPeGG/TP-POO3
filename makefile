CC=g++
DEFINE=#-DMAP
CFLAGS=-Wall 
FileName=Executable
OFILE=Application.o ListeT.o Trajet.o TrajetSimple.o Catalogue.o TrajetCompose.o
MAINFILE=Application

.PHONY : clean


$(FileName): $(OFILE)
	$(CC) -o $(FileName) $(CFLAGS) $(DEFINE) $^ 

$(MAINFILE).o : $(MAINFILE).cpp
	$(CC) -c $(CFLAGS) $(DEFINE) $(MAINFILE).cpp

%.o :  %.h %.cpp
	$(CC) -c $(CFLAGS) $(DEFINE) $*.cpp 

clean :
	rm -f $(OFILE) core
