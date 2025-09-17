#include "Point.hpp"

int main()
{
	// Define triangle vertices
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	// Points to test
	Point inside(5.0f, 5.0f);     // clearly inside
	Point outside(15.0f, 5.0f);   // clearly outside
	Point edge(5.0f, 0.0f);       // on edge AB
	Point vertex(0.0f, 0.0f);     // exactly vertex A
	Point nearEdge(5.0f, 0.01f); // just above edge AB

	std::cout << "Inside (5,5): " 
				<< (bsp(a, b, c, inside) ? "Inside" : "Outside") 
				<< std::endl;

	std::cout << "Outside (15,5): " 
				<< (bsp(a, b, c, outside) ? "Inside" : "Outside") 
				<< std::endl;

	std::cout << "On edge (5,0): " 
				<< (bsp(a, b, c, edge) ? "Inside" : "Outside") 
				<< std::endl;

	std::cout << "On vertex (0,0): " 
				<< (bsp(a, b, c, vertex) ? "Inside" : "Outside") 
				<< std::endl;

	std::cout << "Near edge (5,0.01): " 
				<< (bsp(a, b, c, nearEdge) ? "Inside" : "Outside") 
				<< std::endl;

    return (0);
}