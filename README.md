# ENGG1340 GROUP 62 PROJECT
#### Group members:
- Lam San Wai Iestyn
- Ngo Yan Lun

#### Mentor:
- Woo Chung Yu

## Current Assumptions of the Program:
- Commodity - the 'commodity' we are using in this program has three data fields - Name/Identifier of the item, Manufacturer/Vendor of the item & Quantity of item.
- 'inventory.txt' will be used as the database of the program and is where details regarding the inventory is stored when the program closes, so that the program can be closed and re-opened as necessary. In 'inventory.txt', each commodity is separated by a line, and each data field of the commodity is separated by a space. No duplicates exist within the file.
- ASSUMPTIONS ON FORMAT: For both manufacturers and item names, within the database they have no spaces and are instead replaced with underscores.

## Problem Statement:
Our program will be aimed to solve the issue of inventory management and tracking. Many brands and stores such as supermarkets need a way to manage their inventory and know what items are in stock and out of stock, and which items are close to potentially running out soon. In order to provide a solution for this issue, our program will allow staff to record and manage commodity inventory in different retail shops in order to keep track of inventory, as well as receiving alerts when items are running out of stock or have run out of stock.

**Features of the Program**
1. Search commodities according to different filters (e.g. in-stock/out-of-stock)
2. Insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement
3. Delete obsolete commodities
4. Edit/update commodity information
5. Automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become "out-of-stock")
6. Deliver alerts when the commodity is "out-of-stock"

*OUR OWN FUNCTIONS*

7. Show inventory history so that the users can see what previous iterations of the inventory have been for each time the program has been opened.
8. Error-handling, for functions such as search, delete, and edit, the program is able to return choices for the user to pick from if their search term is a substring of item names, and can also handle spaces in user input when inputting strings. The program can also handle different cases, e.g. searching "APPle" will still be able to find "apple" in the commodity system.

## Problem Setting:
This program will be set up to be used in retail stores such as supermarkets, clothing stores, sporting chains, restaurants - etc. This will allow for management to be able to provide up-to-date information of what commodities are in-stock and out-of-stock just by one click, as well as viewing commodities by quantity, and being able to easily search by name/manufacturer to see what is currently in stock.

## Compilation & Execution Instructions:
To compile and execute the program, open the directory in command prompt and run the following commands:
- make program
- ./program

The file comes with 3 example 'inventory.txt' to use with the program, which are three situations in which this program could foreseeably be used. To use these files, the items have to be named exactly 'inventory.txt'.
### Case 1:
Music Store, "sample1_inventory.txt"

### Case 2:
Clothing & Apparel Store, "sample2_inventory.txt"

## Case 3:
Tech Store, "sample3_inventory.txt"
