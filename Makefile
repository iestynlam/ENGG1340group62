all: main

main.o: initialize_list.o intro.cpp lowercase.cpp options.cpp help.cpp search_item.o display.o find_by_name.o edit_item.o insert.o remove.cpp history.cpp before_end_program.o end_program.cpp

initialize_list.o: initialize_list.cpp append_item.cpp

s_find_by_name.o: s_find_by_name.cpp lowercase.cpp

find_by_name.o: find_by_name.cpp s_find_by_name.o fill_spaces.cpp print_item.cpp

search_item.o: search_item.cpp fill_spaces.cpp lowercase.cpp print_item.cpp

edit_item.o: edit_item.cpp print_item.cpp fill_spaces.cpp

display.o: display.cpp swap_commodity.cpp print_item.cpp

insert.o: lowercase.cpp fill_spaces.cpp digit_check.cpp print_item.cpp append_item.cpp

before_end_program.o: same.cpp write_history.cpp

clean:
