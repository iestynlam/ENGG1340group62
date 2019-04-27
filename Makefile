FUNC1 = main.cpp append_item.cpp before_end_program.cpp digit_check.cpp display.cpp edit_item.cpp
FUNC2 = end_program.cpp fill_spaces.cpp find_by_name.cpp s_find_by_name.cpp help.cpp history.cpp
FUNC3 = initialize_list.cpp insert.cpp intro.cpp lowercase.cpp options.cpp print_item.cpp remove.cpp 
FUNC4 = same.cpp search_item.cpp swap_commodity.cpp write_history.cpp

ALLFUNCS = $(FUNC1)$(FUNC2)$(FUNC3)$(FUNC4)

program: $(ALLFUNCS)
	g++ $(ALLFUNCS) -o program
