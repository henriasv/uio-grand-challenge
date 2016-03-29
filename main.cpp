// Build command:
// g++ main.cpp -o main

#include <iostream>
#include <fstream>

using namespace std;

// Forward declare functions
void calculateForces(double k, double d, double* forces, double* positions, double* velocities, int numBlocks);
void integrate(double * forces, double * positions, double * velocities, int numBlocks);
double springForce(double k, double d, double x1, double x2);
void writeArrayToFile(ofstream& outFile, double * array, int numBlocks);

int main()
{
	// Choose parameters
	const int numBlocks 		= 70;
	double dt 							= 1e-7;
	double tStop 						= 0.01;
	double t 								= 0;
	double pusherVelocity 	= 4e-4;
	double pusherStiffness 	= 4e6;
	int writeFrequency 			= 10;

	double k		= 2.3e7; // Stiffness between blocks
	double L 		= 0.14; // Physical length of block chain
	double d 		= L/(numBlocks-1); // Distance between blocks in block chain

	// Create output stream
	ofstream outFilePositions("output/positions.bin");

	// Allocate position array:
	double positions[numBlocks];
	// Allocate velocity array:
	double velocities[numBlocks];
	// Allocate force array:
	double forces[numBlocks];

	// Initialize arrays
	for (int i = 0; i<numBlocks; i++)
	{
		positions[i] = d*i;
		velocities[i] = 0;
		forces[i] = 0;
	}

	int counter = 0;
	while (t<tStop)
	{
		// Calculate forces
		calculateForces(k, d, forces, positions, velocities, numBlocks);
		integrate(forces, positions, velocities, numBlocks);

		// modulo operation to check whether to write output to file on this timestep
		if ( (counter%writeFrequency) == 0)
		{
			writeArrayToFile(outFilePositions, positions, numBlocks);
		}
		t += dt;
		counter ++;
	}


	cout << "Ran " << counter << " integration steps" << endl;
	return 0;
}

void calculateForces(double k, double d, double * forces, double * positions, double * velocities, int numBlocks)
{
	// Reset forces
	for (int i = 0; i<numBlocks; i++)
	{
		forces[i] = 0;
	}

	// First block
	forces[0] += springForce(k, d, positions[0], positions[1]);

	// Middle blocks
	for (int i = 1; i<numBlocks-1; i++)
	{
		forces[i] += springForce(k, d, positions[i], positions[i+1])
					+ springForce(k, d, positions[i], positions[i-1]);
	}

	// Last block
	forces[numBlocks-1] += springForce(k, d, positions[numBlocks-1], positions[numBlocks-2]);
}

void integrate(double * forces, double * positions, double * velocities, int numBlocks)
{
	// Euler Cromer
}


double springForce(double & k, double & d, double & x1, double& x2)
{
	return k*(x2-x1-d);
}

void writeArrayToFile(ofstream & outFile, double * array, int numBlocks)
{
	outFile.write(reinterpret_cast<char*>(array), numBlocks*sizeof(double));
}
