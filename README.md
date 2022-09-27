# Project 1
Imagine in deep space there is a space station designed to repair docked space ships. Space ships will arrive with damage and, if there is docking bay that is free, then the ship will dock for repairs; if there is no free dock, the damaged ship waits in the queue.

## Class Lists
	* Space Station
		* 3 repair bays
		* Queue of ships waiting for a free dock
		* Station ID name (first one == Zebra)
	* Repair Bays 
		* Repair counter (Measures dock time until finished)
			* Repair time (sum of IDs of broken parts divided by 5)
		* Ship pointer (pointer to the current ship; if null == no ship there)
		* Designation (A, B, C)
	* Ships
		* Id (1 through 999 sequential)
		* Type (char (H (50%), F(15%), K(10%), and R(5%), O(20%))), determines parts 
		* Collection of parts
			* Number of parts is a normal distribution with a mean of 7 (+-3) and a minimum of 1
	* Parts
		* Part ID #
		* Bool for broken or not

## Data for Parts
	* H : Part ID = 1-100,  
	* F : Part ID = 75-150,  
	* K : Part ID = 2-200 (only even numbers)  
	* R : Part ID = 1-199 (only odd numbers)  
	* O : Part ID = 200-999  

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
October 3rd, 2022