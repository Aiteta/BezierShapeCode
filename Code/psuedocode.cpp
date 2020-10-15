void findEdge(int find, int order, int* a, int* b) {
	int total = 0;
	for (int i = 1; i < order; i++) {
		if (total == find) {
			*a = i;
			*b = order-i;
		}
		total++;
	}
}

void findTriangle(int find, int order, int* a, int* b, int* c) {
	int total = 0;
	for (int i = 1; i < order-1; i++) {
		for (int j = 1; j < order-i; j++) {
			if (total == find) {
				*a = i;
				*b = j;
				*c = n-i-j;
			}
			total++;
		}
	}
}

void findTetrahedron(int find, int order, int* a, int* b, int* c, int* d) {
	int total = 0;
	for (int i = 1; i < order-2; i++) {
		for (int j = 1; j < order-i-1; j++) {
			for (int k = 1; k < order-i-j; k++) {
				if (total == find) {
					*a = i;
					*b = j;
					*c = k;
					*d = n-i-j-k;
				}
				total++;
			}
		}
	}
}

void findZeta(int i, int j, int k, int l) {

}

int conversionTet(Mesh obj, order) {

	std::vector<double> ogtetnodes
	std::vector<double> tetnodes;
	// Vertices
	// Since Vertex Coordinates will stay the same, no alterations are needed
	for (int i = 0; i < obj.numVert(); i++) {
		tetnodes.push_back(ogtetnodes[3*i]);
		tetnodes.push_back(ogtetnodes[3*i+1]);
		tetnodes.push_back(ogtetnodes[3*i+2]);
	}

	// Edges
	Matrix EdgeSolveMatrix = Matrix(order-1,order-1);
	// Zeta Coordinates (C_ij, a = i, b = j)
	int a;
	int b;
	double* zeta;
	// Combination Coordinates (C_ij, c = i, d = j)
	int c;
	int d;
	// Matrix Setup
	// Column-wise all Coordinates C_ij are the same, Row-wise all parametric Coordinates zeta are the same
	for (int i = 0; i < order-1; i++) {
		findEdge(i,order,&a,&b);
		zeta = findZeta(a,b,0,0);
		for (int j = 0; j < order-1; j++) {
			findEdge(j,order,&c,&d);
			EdgeSolveMatrix[i][j] = combination(c,d,0,0)*pow(zeta[0],c)*pow(zeta[1],d);
		}
	}
	// Note: Might be better to do this with two double for loops

	std::vector<double> ogEdgeNodes;
	std::vector<double> edgeNodes;

	// Set up b vector
	for (int i = 0; i < obj.numEdge(); i++) {
		ColVector EdgeSolveVector0 = ColVector(order-1);
		ColVector EdgeSolveVector1 = ColVector(order-1);
		ColVector EdgeSolveVector2 = ColVector(order-1);
		int* relVerts = findVerticesEdge(i);
		for (int j = 0; j < order-1; j++) {
			int c,d;
			findEdge(j,order,&c,&d);
			zeta = findZeta(a,b,0,0);
			EdgeSolveVector1[j] = ogtetnodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]]
												   -pow(zeta[1],order)*tetnodes[3*relVerts[1]];
			EdgeSolveVector2[j] = ogtetnodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+1]
												   -pow(zeta[1],order)*tetnodes[3*relVerts[1]+1];
			EdgeSolveVector3[j] = ogtetnodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+2]
												   -pow(zeta[1],order)*tetnodes[3*relVerts[1]+2];
		}
		ColVector EdgeSolutionVector0 = Solve(EdgeSolveMatrix,EdgeSolveVector0);
		ColVector EdgeSolutionVector1 = Solve(EdgeSolveMatrix,EdgeSolveVector1);
		ColVector EdgeSolutionVector2 = Solve(EdgeSolveMatrix,EdgeSolveVector2);
		for (int j = 0; j < order-1; j++) {
			edgeNodes.push_back(EdgeSolutionVector0[j]);
			edgeNodes.push_back(EdgeSolutionVector1[j]);
			edgeNodes.push_back(EdgeSolutionVector2[j]);
		}
	}
	

	// Triangle
	Matrix TriangleSolveMatrix = Matrix(order-1,order-1);
	// Zeta Coordinates (C_ijk, a = i, b = j, c = k)
	int a;
	int b;
	int c;
	double* zeta;
	// Combination Coordinates (C_ij, d = i, e = j, f = k)
	int d;
	int e;
	int f;
	// Matrix Setup
	for (int i = 0; i < (order-1)*(order-2)/2; i++) {
		findTriangle(i,order,&a,&b,&c);
		zeta = findZeta(a,b,c,0);
		for (int j = 0; j < (order-1)*(order-2)/2; j++) {
			findTriangle(i,order,&d,&e,&f);
			TriangleSolveMatrix[i][j] = combination(d,e,f,0)*pow(zeta[0],d)*pow(zeta[1],e)*pow(zeta[2],f);
		}
	}

	std::vector<double> ogTriangleNodes;
	std::vector<double> triangleNodes;

	// Set up b vector
	for (int i = 0; i < obj.numTriangle(); i++) {
		ColVector TriangleSolveVector0 = ColVector(order-1);
		ColVector TriangleSolveVector0 = ColVector(order-1);
		ColVector TriangleSolveVector0 = ColVector(order-1);
		int* relVerts = findVertsEdge(i);
		int* relEdges = findEdgesTrig(i);
		for (int j = 0; j < (order-1)*(order-2)/2; j++) {
			int a,b,c;
			findTriangle(j,order,&a,&b,&c);
			zeta = findZeta(a,b,c,0);
			// Addition of knowns from Coordinate and Vertex data
			TriangleSolveVector0[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]];
			TriangleSolveVector1[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+1]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]+1]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]+1];
			TriangleSolveVector2[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+2]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]+2]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]+2];
			// Addition of knowns from Edge Data
			for (int k = 0; k < order-1; k++) {
				int d,e,f;
				findTriangle(k,order,&d,&e,&f);
				TriangleSolveVector0[j] -= pow(zeta[0],d)*pow(zeta[1],e)*pow(zeta[2],f)*tetnodes[3*relVerts[0]];
				TriangleSolveVector1[j] -= pow(zeta[0],d)*pow(zeta[1],e)*pow(zeta[2],f)*tetnodes[3*relVerts[0]+1];
				TriangleSolveVector2[j] -= pow(zeta[0],d)*pow(zeta[1],e)*pow(zeta[2],f)*tetnodes[3*relVerts[0]+2];
			}

		}
		ColVector TrigSolutionVector0 = Solve(TriangleSolveMatrix,TriangleSolveVector0);
		ColVector TrigSolutionVector1 = Solve(TriangleSolveMatrix,TriangleSolveVector1);
		ColVector TrigSolutionVector2 = Solve(TriangleSolveMatrix,TriangleSolveVector2);
		for (int j = 0; j < order-1; j++) {
			triangleNodes.push_back(EdgeSolutionVector0[j]);
			triangleNodes.push_back(EdgeSolutionVector1[j]);
			triangleNodes.push_back(EdgeSolutionVector2[j]);
		}
	}


	// Tetrahedron
	Matrix TriangleSolveMatrix = Matrix(order-1,order-1);
	// Zeta Coordinates (C_ijk, a = i, b = j, c = k)
	int a;
	int b;
	int c;
	int d;
	double* zeta;
	// Combination Coordinates (C_ij, d = i, e = j, f = k)
	int e;
	int f;
	int g;
	int h;
	// Matrix Setup
	for (int i = 0; i < (order-1)*(order-2)*(order-3)/6; i++) {
		findTetrahedron(i,order,&a,&b,&c,&d);
		zeta = findZeta(a,b,c,d);
		for (int j = 0; j < (order-1)*(order-2)/2; j++) {
			findTetrahedron(i,order,&e,&f,&g,&h);
			TriangleSolveMatrix[i][j] = combination(e,f,g,h)*pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h);
		}
	}

	std::vector<double> ogTetraNodes;
	std::vector<double> TetraNodes;

	// Set up b vector
	for (int i = 0; i < obj.numTriangle(); i++) {
		ColVector TetraSolveVector0 = ColVector(order-1);
		ColVector TetraSolveVector1 = ColVector(order-1);
		ColVector TetraSolveVector2 = ColVector(order-1);
		int* relVerts = findVertsTetra(i);
		int* relEdges = findEdgesTetra(i);
		int* relTriag = findTriagTetra(i);
		for (int j = 0; j < (order-1)*(order-2)*(order-3)/6; j++) {
			int a,b,c,d;
			findTetrahedron(j,order,&a,&b,&c,&d);
			zeta = findZeta(a,b,c,d);
			// Addition of knowns from Coordinate and Vertex data
			TriangleSolveVector0[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]]
												  			-pow(zeta[3],order)*tetnodes[3*relVerts[3]];
			TriangleSolveVector1[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+1]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]+1]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]+1]
												  			-pow(zeta[3],order)*tetnodes[3*relVerts[3]+1];
			TriangleSolveVector2[j] = ogTriangleNodes[3*i+j]-pow(zeta[0],order)*tetnodes[3*relVerts[0]+2]
												  			-pow(zeta[1],order)*tetnodes[3*relVerts[1]+2]
												  			-pow(zeta[2],order)*tetnodes[3*relVerts[2]+2]
												  			-pow(zeta[3],order)*tetnodes[3*relVerts[3]+2];
			// Addition of knowns from Edge Data
			for (int k = 0; k < order-1; k++) {
				int e,f,g,h;
				findTetrahedron(k,order,&e,&f,&g,&h);
				TriangleSolveVector0[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relEdges[0]];
				TriangleSolveVector1[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relEdges[0]+1];
				TriangleSolveVector2[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relEdges[0]+2];
			}
			// Addition of knowns from Triangle Data
			for (int k = 0; k < (order-1)*(order-2)/2; k++) {
				int e,f,g,h;
				findTetrahedron(k,order,&e,&f,&g,&h);
				TriangleSolveVector0[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relTriag[0]];
				TriangleSolveVector1[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relTriag[0]+1];
				TriangleSolveVector2[j] -= pow(zeta[0],e)*pow(zeta[1],f)*pow(zeta[2],g)*pow(zeta[3],h)*tetnodes[3*relTriag[0]+2];
			}

		}
		ColVector TrigSolutionVector0 = Solve(TriangleSolveMatrix,TriangleSolveVector0);
		ColVector TrigSolutionVector1 = Solve(TriangleSolveMatrix,TriangleSolveVector1);
		ColVector TrigSolutionVector2 = Solve(TriangleSolveMatrix,TriangleSolveVector2);
		for (int j = 0; j < order-1; j++) {
			triangleNodes.push_back(EdgeSolutionVector0[j]);
			triangleNodes.push_back(EdgeSolutionVector1[j]);
			triangleNodes.push_back(EdgeSolutionVector2[j]);
		}
	}





}
