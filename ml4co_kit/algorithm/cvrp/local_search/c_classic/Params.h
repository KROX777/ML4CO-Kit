/*MIT License

Copyright(c) 2020 Thibaut Vidal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#ifndef PARAMS_H
#define PARAMS_H

#include "CircleSector.h"
#include <string>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <climits>
#include <algorithm>
#include <unordered_set>
#define MY_EPSILON 0.001 // Precision parameter, used to avoid numerical instabilities
#define PI 3.14159265359

struct Client
{
	int custNum;			// Index of the customer	
	double coordX;			// Coordinate X
	double coordY;			// Coordinate Y
	double serviceDuration; // Service duration
	double demand;			// Demand
	int polarAngle;			// Polar angle of the client around the depot, measured in degrees and truncated for convenience
};

class Params
{
public:

	/* PARAMETERS OF THE GENETIC ALGORITHM */
	int nbGranular			= 20;		// Granular search parameter, limits the number of moves in the RI local search
	int mu					= 25;		// Minimum population size
	int lambda				= 40;		// Number of solutions created before reaching the maximum population size (i.e., generation size)
	int nbElite				= 4;		// Number of elite individuals (reduced in HGS-2020)
	int nbClose				= 5;		// Number of closest solutions/individuals considered when calculating diversity contribution
	double targetFeasible   = 0.2;		// Reference proportion for the number of feasible individuals, used for the adaptation of the penalty parameters
	
	/* ADAPTIVE PENALTY COEFFICIENTS */
	double penaltyCapacity;				// Penalty for one unit of capacity excess (adapted through the search)
	double penaltyDuration;				// Penalty for one unit of duration excess (adapted through the search)

	/* DATA OF THE PROBLEM INSTANCE */			
	bool isRoundingInteger ;								// Distance calculation convention
	bool isDurationConstraint ;								// Indicates if the problem includes duration constraints
	int nbClients ;											// Number of clients (excluding the depot)
	int nbVehicles ;										// Number of vehicles
	double durationLimit;									// Route duration limit
	double vehicleCapacity;									// Capacity limit
	double totalDemand ;									// Total demand required by the clients
	double maxDemand;										// Maximum demand of a client
	double maxDist;											// Maximum distance between two clients
	std::vector < Client > cli ;							// Vector containing information on each client
	std::vector < std::vector < double > > timeCost ;		// Distance matrix
	std::vector < std::vector < int > > correlatedVertices;	// Neighborhood restrictions: For each client, list of nearby customers

	// Initialization from a given data set
	Params(float* nodes_coords, float *demands, int nodes_num, int corrds_scale, int demands_scale, int seed);
};
#endif

