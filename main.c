#include "Includes.h"

typedef struct Node{
	uint lastvisit;
	Coord pos;
	uint numadj;
	struct Node* *adj;
}Node;

// have a partial traversal
// have a global toggle reset
// maybe have master list
// for more complex pattern finding keep a traversal history of N nodes

int main(int argc, char const *argv[])
{
	const Length window = {800, 600};
	init(window);
	printf("%u\n",(uint)sizeof(int));
	Node* nodes = malloc(sizeof(Node)*3);
	memset(nodes, 0, sizeof(Node)*3);
	for(uint i = 0; i < 3; i++){
		nodes[i].numadj = 2;
		nodes[i].adj = malloc(sizeof(Node*)*2);
		nodes[i].adj[0] = &(nodes[wrap(i-1,0,3)]);
		nodes[i].adj[1] = &(nodes[wrap(i+1,0,3)]);
	}

	while(1){
		Ticks frameStart = getTicks();
		clear();



		draw();
		events(frameStart + TPF);
	}
	return 0;
}
