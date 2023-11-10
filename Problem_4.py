# -*- coding: utf-8 -*-
# """
# Created on Tue Nov  7 07:30:00 2023

# @author: Pierre Minga and Halo Kanengiser
# """

# Import the NumPy library with the alias np
import numpy as np
# Import the random module
import random

# Define a function to generate a random simple graph
def generate_random_simple_graph(n, edge_probability=0.5, loop_probability=0.1):
    # Create an empty adjacency matrix filled with zeros
    adjacency_matrix = np.zeros((n, n), dtype=int)

    # Iterate over all pairs of nodes
    for i in range(n):
        for j in range(i + 1, n):
            # Generate a random number and check if it is less than the edge probability
            if random.random() < edge_probability:
                # Set the corresponding entry in the adjacency matrix to 1
                adjacency_matrix[i][j] = 1
                adjacency_matrix[j][i] = 1

    # Iterate over all nodes
    for i in range(n):
        # Generate a random number and check if it is less than the loop probability
        if random.random() < loop_probability:
            # Set the diagonal entry in the adjacency matrix to 1, creating a loop
            adjacency_matrix[i][i] = 1

    # Return the generated adjacency matrix
    return adjacency_matrix

# Set the number of graphs to be generated
graphGenerated = 10
# Iterate to generate and print 10 random simple graphs
for i in range(graphGenerated):
    # Generate a random simple graph with 5 vertices
    random_graph = generate_random_simple_graph(5)
    # Print the generated graph
    print("Simple Graph " + str(i + 1) + "\n", random_graph)
