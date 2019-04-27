all: program

program: main.o initialize_list.o find_by_name.o search_item.o edit_item.o display.o insert.o before_end_program.o
	g++ $^ -o program

main.o: main.cpp intro.cpp lowercase.cpp options.cpp help.cpp remove.cpp history.cpp end_program.cpp
	g++ $^ -c

initialize_list.o: initialize_list.cpp append_item.cpp
	g++ $^ -c

find_by_name.o: find_by_name.cpp s_find_by_name.cpp lowercase.cpp fill_spaces.cpp print_item.cpp
	g++ $^ -c

search_item.o: search_item.cpp fill_spaces.cpp lowercase.cpp print_item.cpp
	g++ $^ -c

edit_item.o: edit_item.cpp print_item.cpp fill_spaces.cpp
	g++ $^ -c

display.o: display.cpp swap_commodity.cpp print_item.cpp
	g++ $^ -c

insert.o: lowercase.cpp fill_spaces.cpp digit_check.cpp print_item.cpp append_item.cpp
	g++ $^ -c

before_end_program.o: same.cpp write_history.cpp
	g++ $^ -c

clean:
	rm -rf *o program
