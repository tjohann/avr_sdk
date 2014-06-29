# only for cleaning :-)

SUBDIRS = example_makefiles

.PHONY: all
all: 
	@echo Cheers

.PHONY: clean
clean:
	rm -f *~ *.o 
	for dir in $(SUBDIRS); do (cd $$dir && $(MAKE) $@); done	


