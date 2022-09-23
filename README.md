# Project 1
Problem = imagine in deep space there is a repair space station, space ships arrive w/ damage, if there is docking bay that is free (station has 3) then dock ship for repairs, how long to repair is a function of the sum of the id's broken parts; if no free dock, damage ship waits (FIFO)

## Class Lists
	* Ships
		* Id (100 through 999), determines parts
		* Type (char (H (50%), F(15%), K(10%), and R(5%), O(20%)))
		* List of parts
	* Space Station
		* 3 repair bays
		* ID Name (first one == Zebra)
	* Repair Bays (measures dock time until finished)
		* Ship pointer (current ship, if null == no ship there)
		* Designation (A, B, C)(initially empty)
		* Repair time (sum of IDs of broken parts divided by 5)
	* Parts
		* Part ID #
		* Bool for broken or not

## Data for Parts
H : Part ID = 1-100,
F : Part ID = 75-125,
K : Part ID = 2-200 (only even numbers)
R : Part ID = 1-199 (only odd numbers)
O : Part ID = 200-999; 100 random parts

## Damage
Randomized
To determine if part is broken -> Normal distribution w/ mean of 7 (+- 3), minimum of 1, no maximum
Choose that number of parts from the ship's part list and mark as broken (bool)

## Basic Algorithm
Basic Time Step
Generate damaged ships (0-4)
Check for available bays
If available, dock ship; Else, add to queue of ship pointers
Continue to repair current damaged ships in the docks by decrementing repair time
Check for completed repairs; if 0, exit ship (delete pointer) 
Continue until we stay stop (user input) 

## Random Number Generator
std::default_random_engine * drePrt;
drePrt = new std::default_random_engine(time(NULL));
std::normal_distribution<int> IdList(mean, standardDev);

## Due Date
TO BE DETERMINED