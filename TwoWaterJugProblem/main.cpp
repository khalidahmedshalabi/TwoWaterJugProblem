/*
	Water Jug Puzzle
	https://en.wikipedia.org/wiki/Water_pouring_puzzle
*/

#include <stdio.h>
#include <stdlib.h>

// This demo is designed for only 2 jugs
const int MAX_JUGS = 2;

// Capacity of each jug
const int JUG_VOL[MAX_JUGS] = { 4, 3 };

// How many liters are currently in each jug
int JUG_FILLED[MAX_JUGS] = { 0, 0 };

// Fill a jug till it's full
void FillJug(int id)
{
	if (id >= MAX_JUGS)
		return;

	printf("> ACTION: Filled jug %d", id + 1);
	JUG_FILLED[id] = JUG_VOL[id];
}

// Empty a jug
void EmptyJug(int id)
{
	if (id >= MAX_JUGS)
		return;

	printf("> ACTION: Emptied jug %d", id + 1);
	JUG_FILLED[id] = 0;
}

// Pour from a jug into the other
void FillJugFromJug(int from_id, int to_id)
{
	// Start and keep pouring as long as we didn't hit the limit nor the jug is empty
	while (JUG_FILLED[to_id] != JUG_VOL[to_id] && JUG_FILLED[from_id] != 0)
	{
		JUG_FILLED[to_id] ++;
		JUG_FILLED[from_id] --;
	}
	printf("> ACTION: Poured from jug %d into jug %d", from_id+1, to_id+1);
}

// Show how many liters are currently in each jug
void DisplayJugs()
{
	printf("\n\n_________\n\n1st Jug\t\t\t2nd Jug\n%d\t\t\t%d\n\n", JUG_FILLED[0], JUG_FILLED[1]);
}

int main()
{
	DisplayJugs();

	// Keep pouring from the larger jug into the smaller
	for (int steps = 0; steps < 6 && JUG_FILLED[0] != 2; ++steps)
	{
		// If the larger jug is empty, fill it so we can continue pouring from it into the smaller jug
		if (JUG_FILLED[0] == 0)
			FillJug(0);

		// If the smaller jug is empty or the larger jug reached its peak, pour into the smaller jug 
		else if (JUG_FILLED[1] == 0 || JUG_FILLED[0] == JUG_VOL[0])
			FillJugFromJug(0, 1);

		// If the smaller jug got full, we empty it so we can continue pouring into it
		else if (JUG_FILLED[1] == JUG_VOL[1])
			EmptyJug(1);

		DisplayJugs();
	}
	return 0;
}
