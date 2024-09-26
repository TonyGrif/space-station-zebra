# Space Station Zebra

## Requirements
* [GCC Compiler](https://gcc.gnu.org/)
* [CMake](https://cmake.org/)

### Optional Requirements
* [GNU Make](https://www.gnu.org/software/make/)

## Running Instructions
Use the provided makefile by running `make`

Imagine in deep space there is a space station designed to repair docked space ships. Space ships will arrive with damage and, if there is docking bay that is free, then the ship will dock for repairs; if there is no free dock, the damaged ship waits in the queue.

## Class Lists
	* Space Station
		* 3 repair bays
		* Queue of ships waiting for a free dock
		* Station ID name
	* Repair Bays 
		* Repair counter - measures dock time until ship is fully repaired
		* Ship pointer 
			* Pointer to the current ship
			* If null, no ship is currently docked
		* Designation
	* Ships
		* Id (1 through 999 sequential)
		* Type 
			* H, F, K, R, or O
			* Determines parts 
		* Collection of parts
	* Parts
		* Part ID #
		* Bool for broken or not

## Data for Parts
	* H - Humans
		* 20% chance of being ship
		* Part ID = 1-100
		* 5% chance of a broken part
		* 1-5 time steps required per broken part
	* F -  
		* 15% chance of being ship
		* Part ID = 75-150  
		* 8% chance of a broken part
		* 2-7 time steps required per broken part
	* K - 
		* 10% chance of being ship  
		* Part ID = 2-200 (only even numbers)
		* 6% chance of a broken part
		* 2-6 time steps required per broken part
	* R -   
		* 5% chance of being ship
		* Part ID = 1-199 (only odd numbers)
		* 6% chance of a broken part
		* 3-7 time steps required per broken part
	* O - Other
		* 20% chance of being ship
		* Part ID = 200-999  
		* 7% chance of a broken part
		* 1-10 time steps required per broken part

## Output
Output will be generated in a diary format describing the current status of each of the objects in play

## Due Date
October 10th, 2022

## Grade Recieved
TBD
