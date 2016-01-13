main: main.o chance.o block.o ownable.o academic.o gym.o residence.o coopfee.o tuition.o slc.o needleshall.o player.o board.o controller.o graphicsdisplay.o boardnotification.o window.o
	g++ main.o chance.o block.o ownable.o academic.o gym.o residence.o coopfee.o tuition.o slc.o needleshall.o player.o board.o controller.o boardnotification.o graphicsdisplay.o window.o -o bb7k -lX11
main.o: main.cc controller.h board.h player.h graphicsdisplay.h
	g++ -std=c++0x -c main.cc controller.cc board.cc player.cc graphicsdisplay.cc -lX11
ownable.o: ownable.cc ownable.h block.h
	g++ -c ownable.cc
academic.o: academic.cc academic.h ownable.h player.h
	g++ -c academic.cc
gym.o: gym.cc gym.h ownable.h
	g++ -std=c++0x -c gym.cc
residence.o: residence.cc residence.h ownable.h
	g++ -c residence.cc
coopfee.o: coopfee.cc coopfee.h block.h
	g++ -c coopfee.cc
tuition.o: tuition.cc tuition.h block.h player.h
	g++ -c tuition.cc
chance.o: chance.cc chance.h block.h board.h
	g++ -std=c++0x -c chance.cc
slc.o: slc.cc slc.h chance.h board.h player.h
	g++ -std=c++0x -c slc.cc
needleshall.o: needleshall.cc needleshall.h chance.h player.h board.h
	g++ -std=c++0x -c needleshall.cc
boardnotification.o: boardnotification.cc boardnotification.h
	g++ -c boardnotification.cc
player.o: player.cc player.h
	g++ -c player.cc
board.o: board.cc board.h player.h boardnotification.h academic.h slc.h coopfee.h needleshall.h gym.h tuition.h residence.h collectosap.h
	g++ -std=c++0x -c board.cc
graphicsdisplay.o: graphicsdisplay.cc graphicsdisplay.h window.h
	g++ -c graphicsdisplay.cc -lX11
window.o: window.cc window.h
	g++ -c window.cc -lX11
controller.o: controller.cc controller.h boardnotification.h board.h
	g++ -std=c++0x -c controller.cc
block.o: block.cc block.h
	g++ -c block.cc
