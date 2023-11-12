# Import the NumPy library with the alias np
import numpy as np
# Import the generate_random_simple_graph function from the generate_random_simple_graph module
from generate_random_simple_graph import generate_random_simple_graph

# Define a function to check if a graph represented by an adjacency matrix is connected
def is_connected(adj_matrix):
    # Create an empty dictionary to represent the graph
    graph = {}
    # Iterate over the rows of the adjacency matrix
    for i, row in enumerate(adj_matrix):
        # Find neighbors for each node with a value of 1 in the row
        neighbors = [j for j, value in enumerate(row) if value == 1]
        # Store the neighbors in the graph dictionary
        graph[i] = neighbors

    # Create an empty set to keep track of visited nodes during depth-first search
    visited = set()

    # Define a recursive depth-first search (DFS) function
    def dfs(node):
        # Mark the current node as visited
        visited.add(node)
        # Recursively visit neighbors that haven't been visited yet
        for neighbor in graph[node]:
            if neighbor not in visited:
                dfs(neighbor)

    # Start DFS from node 0
    dfs(0)
    # Check if all nodes have been visited
    return len(visited) == len(graph)

# Example usage
for i in range(10):
    # Generate a random simple graph with 5 vertices
    graph_generated = generate_random_simple_graph(5)
    # Check if the generated graph is connected
    connected = is_connected(graph_generated)
    # Print the result of the connectivity check
    print("Is connected: ", connected)
