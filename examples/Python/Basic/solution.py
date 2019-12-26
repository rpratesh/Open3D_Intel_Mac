import open3d as o3d
import sys

"""
Function to print the output to stdout in format specified in assignment.pdf
"""
def print_cc(conn_components):
    print("[",end="")
    for vector in conn_components:
        print(list(vector),end=", ")
    print("]",end="")

"""
Function to print the output to file in format specified in assignment.pdf
"""
def print_cc_file(conn_components,filename):
    file = open(filename,"w")
    for vector in conn_components:
        vector_str = (str(list(vector))+"\n")
        file.write(vector_str.replace("[","").replace("]",""))
    file.close()

# Read triangle mesh "test_mesh.ply"
mesh = o3d.io.read_triangle_mesh(sys.argv[1])

# Then get connected components
connected_components = mesh.identically_colored_connected_components()
print_cc(connected_components)
print_cc_file(connected_components,sys.argv[2])

# Print connected_components in the specified format
