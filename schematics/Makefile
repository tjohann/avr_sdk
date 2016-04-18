# only for cleaning :-)

SUBDIRS = atmega32_board

.PHONY: all
all: 
	@echo Cheers

.PHONY: clean
clean:
	rm -f *~ *.o 
	for dir in $(SUBDIRS); do (cd $$dir && $(MAKE) $@); done	


