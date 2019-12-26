<p align="center">
<img src="docs/_static/open3d_logo_horizontal.png" width="320" />
</p>

# Open3D: A Modern Library for 3D Data Processing

Open3D is an open-source library that supports rapid development of software that deals with 3D data. The Open3D frontend exposes a set of carefully selected data structures and algorithms in both C++ and Python. The backend is highly optimized and is set up for parallelization. We welcome contributions from the open-source community.

## Added new feature (Assignment)
##### Identically Colored Connected Components
* Implemented a cpp function open3d::geometry::TriangleMesh::IdenticallyColoredConnectedComponents() that returns list of identically connected components
* The returned list is sorted ascendingly by the smallest element in each list and and within each list, the vertices are sorted ascendingly by their indices.
* open3d.geometry.TriangleMesh.identically_colored_connected_components : A python binding of above cpp function is also provided
* solution.py and Solution.cpp are provided in examples folder for showing usage
* Cpp and Python Unit tests are integrated at respective unittest folders

The algorithm (Breadth-First-Search) followed to find connected components has been explained in respective code sections (as comments). Please read them

##### How to build (Mac-OS)
* Clone (recursively) this git repo to your local system (say, $OPEN3D_REPO)
```bash
  git clone --recursive https://github.com/rpratesh/Open3D_IntelHW.git
```
* Run *util/scripts/install-deps-osx.sh*. Use homebrew to manage dependencies
```bash
  cd $OPEN3D_REPO
  mkdir build
  cd build
  #sudo may be needed to install Open3D to a system location.
  sudo cmake -DPYTHON_INCLUDE_DIR=/usr/local/bin/python3 -DBUILD_UNIT_TESTS=ON  ..
  sudo make -j$(sysctl -n hw.physicalcpu)
  #Remove any previously installed open3d python packages
  sudo pip3 uninstall open3d
  # Create Python package in build/lib/python_package
  sudo make python-package
  #Install python package
  sudo pip3 install -e lib/python_package/
  #Check python installation
  python3 -c "import open3d"
  #Install the Open3D as a C++ library (headers and binaries):
  sudo make install
  #Run cpp unittest
  ./bin/unitTests
  #Before running python unit-test
  pip3 install pytest
  #Run python unittest
  pytest -s ../src/UnitTest/Python/
  #Run cpp example
  ./bin/examples/Solution ../test_mesh.ply ../results_cpp.txt
  #Run python example
  python3 ../examples/Python/Basic/solution.py ../test_mesh.ply ../results_py.txt
 
```
  

## Core features

* 3D data structures
* 3D data processing algorithms
* Scene reconstruction
* Surface alignment
* 3D visualization
* Python binding 

## Citation
Please cite [our work](https://arxiv.org/abs/1801.09847) if you use Open3D.

```
@article{Zhou2018,
	author    = {Qian-Yi Zhou and Jaesik Park and Vladlen Koltun},
	title     = {{Open3D}: {A} Modern Library for {3D} Data Processing},
	journal   = {arXiv:1801.09847},
	year      = {2018},
}
```
