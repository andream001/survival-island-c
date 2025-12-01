CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BUILD = build
SRC = src
INC = include
OBJS = $(BUILD)/inventory.o $(BUILD)/linked_list.o $(BUILD)/search.o $(BUILD)/escape_tower.o

all: $(BUILD) $(BUILD)/survival1 $(BUILD)/survival2 $(BUILD)/survival3

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/inventory.o: $(SRC)/inventory.c $(INC)/inventory.h | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/linked_list.o: $(SRC)/linked_list.c $(INC)/linked_list.h | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/search.o: $(SRC)/search.c $(INC)/search.h | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/escape_tower.o: $(SRC)/escape_tower.c $(INC)/escape_tower.h | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/main.o: $(SRC)/main.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/main2.o: $(SRC)/main2.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/main3.o: $(SRC)/main3.c | $(BUILD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(BUILD)/survival1: $(OBJS) $(BUILD)/main.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD)/survival2: $(OBJS) $(BUILD)/main2.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD)/survival3: $(OBJS) $(BUILD)/main3.o
	$(CC) $(CFLAGS) -o $@ $^

run: $(BUILD)/survival3
	./$(BUILD)/survival3

clean:
	rm -rf $(BUILD)

.PHONY: all run clean
