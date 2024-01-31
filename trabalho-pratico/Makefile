CC=gcc

CFLAGS=-Wall -Iinclude `pkg-config --cflags glib-2.0`

LDFLAGS=`pkg-config --libs glib-2.0` -lm

EXECUTABLES=programa-principal programa-testes

all: $(EXECUTABLES)

programa-principal: src/structs_c/struct_list.o src/main.o src/structs_c/struct_hash.o src/structs_c/struct_flights.o src/structs_c/struct_passengers.o src/structs_c/struct_reservations.o src/structs_c/struct_users.o src/parser_c/parser.o src/catalogs_c/catalog_users.o src/catalogs_c/catalog_flights.o src/catalogs_c/catalog_passengers.o src/catalogs_c/catalog_reservations.o src/catalogs_c/catalog_users_aux.o src/catalogs_c/catalog_flights_aux.o src/catalogs_c/catalog_passengers_aux.o src/catalogs_c/catalog_reservations_aux.o src/catalogs_c/catalogs.o src/general_functions_c/general_functions.o src/queries_c/query1_output.o src/queries_c/query1.o src/queries_c/query2_output.o src/queries_c/query2.o src/queries_c/query8_output.o src/queries_c/query8.o src/queries_c/query9_output.o src/queries_c/query9.o src/queries_c/query4.o src/interpreter_c/interpreter.o src/mode_c/batch.o src/queries_c/query3.o src/queries_c/query3_output.o src/queries_c/query5.o src/queries_c/query5_output.o src/queries_c/query4_output.o src/start.o src/menu_c/menu.o src/menu_c/interface.o src/mode_c/interactive.o src/queries_c/query6.o src/queries_c/query6_output.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

programa-testes: src/main_tests.o src/structs_c/struct_list.o src/structs_c/struct_hash.o src/structs_c/struct_flights.o src/structs_c/struct_passengers.o src/structs_c/struct_reservations.o src/structs_c/struct_users.o src/parser_c/parser.o src/catalogs_c/catalog_users.o src/catalogs_c/catalog_flights.o src/catalogs_c/catalog_passengers.o src/catalogs_c/catalog_reservations.o src/catalogs_c/catalog_users_aux.o src/catalogs_c/catalog_flights_aux.o src/catalogs_c/catalog_passengers_aux.o src/catalogs_c/catalog_reservations_aux.o src/catalogs_c/catalogs.o src/general_functions_c/general_functions.o src/queries_c/query1_output.o src/queries_c/query1.o src/queries_c/query2_output.o src/queries_c/query2.o src/queries_c/query9_output.o src/queries_c/query9.o src/queries_c/query4.o src/interpreter_c/interpreter_tests.o src/mode_c/batch_tests.o src/queries_c/query3.o src/queries_c/query3_output.o src/queries_c/query5.o src/queries_c/query5_output.o src/queries_c/query4_output.o src/start_tests.o src/menu_c/interface.o src/queries_c/query8.c src/queries_c/query8_output.o src/queries_c/query6.o src/queries_c/query6_output.o 
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

src/structs_c/struct_list.o: src/structs_c/struct_list.o

src/structs_c/struct_flights.o: src/structs_c/struct_flights.c

src/structs_c/struct_passengers.o: src/structs_c/struct_passengers.c

src/structs_c/struct_reservations.o: src/structs_c/struct_reservations.c

src/structs_c/struct_users.o: src/structs_c/struct_users.c

src/structs_c/struct_hash.o: src/structs_c/struct_hash.c

src/general_functions_c/general_functions.o: src/general_functions_c/general_functions.c

src/catalogs_c/catalog_reservations_aux.o: src/catalogs_c/catalog_reservations_aux.c

src/catalogs_c/catalog_passengers_aux.o: src/catalogs_c/catalog_passengers_aux.c

src/catalogs_c/catalog_flights_aux.o: src/catalogs_c/catalog_flights_aux.c

src/catalogs_c/catalog_users_aux.o: src/catalogs_c/catalog_users_aux.c

src/catalogs_c/catalog_reservations.o: src/catalogs_c/catalog_reservations.c

src/catalogs_c/catalog_passengers.o: src/catalogs_c/catalog_passengers.c

src/catalogs_c/catalog_flights.o: src/catalogs_c/catalog_flights.c

src/catalogs_c/catalog_users.o: src/catalogs_c/catalog_users.c

src/catalogs_c/catalogs.o: src/catalogs_c/catalogs.c

src/parser_c/parser.o: src/parser_c/parser.c

src/queries_c/query1.o: src/queries_c/query1.c

src/queries_c/query1_output.o: src/queries_c/query1_output.c

src/queries_c/query2.o: src/queries_c/query2.c

src/queries_c/query2_output.o: src/queries_c/query2_output.c

src/queries_c/query3.o: src/queries_c/query3.c

src/queries_c/query3_output.o: src/queries_c/query3_output.c

src/queries_c/query4.o: src/queries_c/query4.c

src/queries_c/query4_output.o: src/queries_c/query4_output.c

src/queries_c/query5.o: src/queries_c/query5.c

src/queries_c/query5_output.o: src/queries_c/query5_output.c

src/queries_c/query6.o: src/queries_c/query6.c

src/queries_c/query6_output.o: src/queries_c/query6_output.c

src/queries_c/query8.o: src/queries_c/query8.c

src/queries_c/query8_output.o: src/queries_c/query8_output.c

src/queries_c/query9.o: src/queries_c/query9.c

src/queries_c/query9_output.o: src/queries_c/query9_output.c

src/interpreter_c/interpreter.o: src/interpreter_c/interpreter.c

src/interpreter_c/interpreter_tests.o: src/interpreter_c/interpreter_tests.c

src/mode_c/batch.o: src/mode_c/batch.c

src/mode_c/batch_tests.o: src/mode_c/batch_tests.c

src/mode_c/interactive.o: src/mode_c/interactive.c

src/menu_c/menu.o: src/menu_c/menu.c

src/menu_c/interface.o: src/menu_c/interface.c

src/start.o: src/start.c

src/start_tests.o : src/start_tests.c

src/main_tests.o: src/main_tests.c

src/main.o: src/main.c


clean:
	rm -f  programa-testes programa-principal src/*.o src/menu_c/*.o src/mode_c/interactive.o src/catalogs_c/*.o src/general_functions_c/*.o src/interpreter_c/*.o src/parser_c/*.o src/queries_c/*.o src/structs_c/*.o Resultados/*.csv Resultados/*.txt src/mode_c/batch.o 

txt:
	rm -f Resultados/*.csv Resultados/*.txt

ex:
	./programa-principal ../../data_small/data/ ../../data_small/input.txt

mex:
	./programa-principal

test: 
	./programa-testes ../../data_small/data/ ../../data_small/input.txt ../../data_small/outputs

valgrind: programa-principal
	valgrind --leak-check=full --track-origins=yes ./programa-principal ../../data_small/data/ ../../Downloads/data_large/input.txt

leaks:
	leaks --atExit --list -- ./programa-principal ../../data_small/data/ ../../data_small/input.txt