# ENGG1340 GROUP 62 PROJECT
#### Group members:
- Lam San Wai Iestyn
- Ngo Yan Lun

#### Mentor:
- Woo Chung Yu

## Current Assumptions of the Program:
- Commodity - the 'commodity' we are using in this program has three data fields - Name/Identifier of the item, Manufacturer/Vendor of the item & Quantity of item.
- 'inventory.txt' will be used as the database of the program and is where details regarding the inventory is stored when the program closes, so that the program can be closed and re-opened as necessary. In 'inventory.txt', each commodity is separated by a line, and each data field of the commodity is separated by a space.
- ASSUMPTIONS ON FORMAT: For both manufacturers and item names, within the database they have no spaces and are instead replaced with underscores.

## Problem Statement:
Our program will be aimed to solve the issue of inventory management and tracking. Many brands and stores such as supermarkets need a way to manage their inventory and know what items are in stock and out of stock, and which items are close to potentially running out soon. In order to provide a solution for this issue, our program will allow staff to record and manage commodity inventory in different retail shops in order to keep track of inventory, as well as receiving alerts when items are running out of stock or have run out of stock.

**Features of the Program**
1. Search commodities according to different filters (e.g. in-stock/out-of-stock)
2. Insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement
3. Delete obsolete commodities
4. Update commodity information
5. Automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become "out-of-stock")
6. Deliver alerts when the commodity is "out-of-stock"

*OUR OWN FUNCTIONS*

7. Overflowing alert - if a commodity remains in stock for a very long time, there may be a danger of expiry or change in sale policy. (Concept of first-in-first-out / first-in-late-out)
8. Provide statistics on rate of consumption/sale of each commodity based on data entered by staff, to help management predict how much they would need to procure to continue to match demand.
9. Error handling - basic error handling such as being case-sensitive, or if the user doesn't type the entire name of the commodities - enters invalid data types into certain fields.

## Problem Setting:
This program will be set up to be used in retail stores such as supermarkets, clothing stores, sporting chains, restaurants - etc. This will allow for management to be able to provide up-to-date information of what commodities are in-stock an out-of-stock just by one click, what are the potential commodities might be running out faster than other commodities, and when they will have to order more commodity to keep the store well stocked.
