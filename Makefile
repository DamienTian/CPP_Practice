.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge_2 - Debug ]----------"
	@cd "Challenge_2" && "$(MAKE)" -f  "Challenge_2.mk"
clean:
	@echo "----------Cleaning project:[ Challenge_2 - Debug ]----------"
	@cd "Challenge_2" && "$(MAKE)" -f  "Challenge_2.mk" clean
