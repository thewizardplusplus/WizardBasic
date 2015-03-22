main:
	$(MAKE) -C wizard-basic-2-compiler
	$(MAKE) -C wizard-basic-2-framework

clean:
	$(MAKE) -C wizard-basic-2-compiler clean
	$(MAKE) -C wizard-basic-2-framework clean
