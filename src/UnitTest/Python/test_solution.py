import open3d as o3d
import numpy as np
import pytest

"""
Unit test for Python binding identically_colored_connected_components()
The test case is the mesh that is given as an example in assignment.pdf (Intel ISL assignment)
"""

def test_identically_colored_connected_components():
    mesh = o3d.geometry.TriangleMesh(
    vertices=o3d.utility.Vector3dVector(np.array([
    [0.000000, 1.000000, 0.000000],[0.000000, 2.000000, 0.000000],
    [1.000000, 0.500000, 0.000000],[1.000000, 1.500000, 0.000000],[1.000000, 2.500000, 0.000000],
    [2.000000, 1.000000, 0.000000],[2.000000, 2.000000, 0.000000]
    ])),
    triangles=o3d.utility.Vector3iVector(np.array([[0, 2, 3], [0, 3, 1], [1, 3, 4], [2, 5, 3], [3, 5, 6], [3, 6, 4]])),
    #vertex_colors = o3d.utility.Vector3dVector(np.array([[1,0,0],[0,1,0],[0,0,1],[1,0,0],[0,1,0],[1,0,0],[1,0,0]])),
    )
    mesh.vertex_colors = o3d.utility.Vector3dVector(np.array([[1,0,0],[0,1,0],[0,0,1],[1,0,0],[0,1,0],[1,0,0],[1,0,0]]))
    conn_components_gt = [[0, 3, 5, 6], [1, 4], [2]]
    conn_components_res = mesh.identically_colored_connected_components()
    for i in range(len(conn_components_res)):
        assert conn_components_gt[i] == list(conn_components_res[i])
