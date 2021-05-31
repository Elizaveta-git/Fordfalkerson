#include "FordFalkersonAlg.h"

void FordFalkerson::ReadFromFile(string FileName)
{
	ifstream in(FileName);
	int weight;
	string Date;
	if (in.is_open())
	{
		while (getline(in, Date))
		{
			int j = 0;
			string information[3];
			for (int i = 0; i < Date.size(); i++)//getting rid of symbols
			{
				if (Date[i] == ' ' || Date[i] == ';')
				{
					i++;
					j++;
				}
				information[j] += Date[i];
			}
			weight = stoi(information[2]);//converting a string to an integer value
			Ribs.push_back(information[0], information[1], weight);
			Ribs.push_back(information[1], information[0], 0);
		}
	}
	in.close();
}

int FordFalkerson::alg(string Begin, string End)
{
	NodeList Nodes;
	Rib* MaxRib;
	Node* CurNode;
	int result = 0;
	int sup = 0;
	do//While the maximum distance is not zero
	{
		Nodes.push_back(Begin, 0);//add top to the list
		Rib* CurEdge = Ribs.MaxRibFromVertex(Begin, Nodes.Head());//Rib with maximum weight
		int maxDistToVert = CurEdge->weight;
		do//have not reached up
		{
			CurNode = Nodes.Head();
			maxDistToVert = 0;
			while (CurNode != NULL)//We take place on all tops
			{
				MaxRib = Ribs.MaxRibFromVertex(CurNode->vertex, Nodes.Head());//finds an unmarked vertex with a maximum distance from the given
				if (MaxRib != NULL)//if there are unchecked vertices from the top
				{
					if (MaxRib->weight + CurNode->maxDist > maxDistToVert)
					{
						CurEdge = MaxRib;// the maximum path from the vertex found in the previous steps to the new vertex
						maxDistToVert = MaxRib->weight + CurNode->maxDist;//// remember the new maximum distance
					}

				}
				CurNode = CurNode->next;
			}
			if (maxDistToVert == 0)
				break;
			Node* previousNode = Nodes.Find(CurEdge->From); // checked vertex from which the maximum distance is found
			Nodes.push_back(CurEdge->To, previousNode->maxDist + CurEdge->weight); // add the vertex to the list of found
			CurEdge->ToVertexProcessed = true;//mark the vertex as checked
			maxDistToVert = previousNode->maxDist + CurEdge->weight;

		} while (CurEdge->To != End);
		if (maxDistToVert != 0)
		{
			maxDistToVert = Ribs.minRibOfPath();
			Ribs.newWeightOfRibs(maxDistToVert);
		}
		sup = maxDistToVert;
		result += maxDistToVert;
		Nodes.Clear();
		Ribs.makeRibsUncheked();
	} while (sup != 0);
	return result;
}

