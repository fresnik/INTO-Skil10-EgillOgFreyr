SUBDIRS = src tests
     
.PHONY: subdirs $(SUBDIRS)
     
subdirs: $(SUBDIRS)
     
src:
	$(MAKE) -C $@
     
tests: src
	$(MAKE) -C $@ run